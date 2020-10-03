#pragma once

#include "control_block.h"
#include <memory>
namespace {
template<typename T>
struct weak_ptr;

template<typename T>
struct shared_ptr {
  constexpr shared_ptr() noexcept
      : cblock(nullptr),
        ptr(nullptr) {}

  constexpr shared_ptr(std::nullptr_t) noexcept
      : shared_ptr() {}

  template<typename Y>
  explicit shared_ptr(Y* ptr)
      : shared_ptr(ptr, std::default_delete<Y>()) {}

  template<typename Y, typename D>
  shared_ptr(Y* ptr, D deleter)
  try : ptr(ptr),
        cblock(new regular_control_block<Y, D>(ptr, std::move(deleter))) {}
  catch (...) {
    deleter(ptr);
    throw;
  }

  template<class D>
  shared_ptr(std::nullptr_t, D deleter)
      : shared_ptr() {}

  template<typename U>
  shared_ptr(const shared_ptr<U>& other, T* ptr) noexcept
      : cblock(other.cblock),
        ptr(ptr) {
    if (cblock != nullptr) {
      cblock->add_ref();
    }
  }

  template<typename U>
  shared_ptr(shared_ptr<U>&& other, T* ptr) noexcept
      : cblock(other.cblock),
        ptr(ptr) {
    other.cblock = nullptr;
    other.ptr = nullptr;
  }

  shared_ptr(const shared_ptr& other) noexcept
      : cblock(other.cblock),
        ptr(other.ptr) {
    if (cblock != nullptr) {
      cblock->add_ref();
    }
  }

  template<typename Y>
  shared_ptr(const shared_ptr<Y>& other) noexcept
      : cblock(other.cblock),
        ptr(other.ptr) {
    if (cblock != nullptr) {
      cblock->add_ref();
    }
  }

  shared_ptr(shared_ptr&& other) noexcept
      : shared_ptr() {
    other.swap(*this);
  }

  template<typename Y>
  shared_ptr(shared_ptr<Y>&& other) noexcept
      : shared_ptr() {
    other.swap(*this);
  }

  shared_ptr& operator=(const shared_ptr& other) {
    if (this != &other) {
      shared_ptr<T>(other).swap(*this);
    }
    return *this;
  }

  shared_ptr& operator=(shared_ptr&& other) {
    if (this != &other) {
      shared_ptr<T>(std::move(other)).swap(*this);
    }
    return *this;
  }

  ~shared_ptr() {
    if (cblock != nullptr) {
      cblock->del_ref();
    }
  }

  void swap(shared_ptr& other) noexcept {
    using std::swap;
    swap(cblock, other.cblock);
    swap(ptr, other.ptr);
  }

  void reset() noexcept {
    reset < T > (nullptr);
  }

  template<typename U>
  void reset(U* ptr) {
    reset(ptr, std::default_delete<U>());
  }

  template<typename U, typename D>
  void reset(U* new_ptr, D new_deleter) {
    if (cblock != nullptr) {
      cblock->del_ref();
    }
    try {
      ptr = new_ptr;
      cblock = new regular_control_block<U, D>(new_ptr, std::move(new_deleter));
    }
    catch (...) {
      new_deleter(new_ptr);
      throw;
    }
  }

  T* get() const noexcept {
    return ptr;
  }

  T& operator*() const noexcept {
    return *ptr;
  }

  T* operator->() const noexcept {
    return ptr;
  }

  size_t use_count() const noexcept {
    return cblock == nullptr ? 0 : cblock->ref_count();
  }

  explicit operator bool() const noexcept {
    return get() != nullptr;
  }

  template<typename U, typename... Args>
  friend shared_ptr<U> make_shared(Args&& ... args);

  friend weak_ptr<T>;

  template<typename U> friend
  struct shared_ptr;

 private:
  control_block* cblock;
  T* ptr;
};

template<typename T, typename... Args>
shared_ptr<T> make_shared(Args&& ... args) {
  shared_ptr<T> res;
  auto* cblock = new inplace_control_block<T>(std::forward<Args>(args)...);
  res.ptr = cblock->get();
  res.cblock = cblock;
  return res;
}

template<typename T, typename U>
bool operator==(const shared_ptr<T>& lhs,
                const shared_ptr<U>& rhs) noexcept {
  return lhs.get() == rhs.get();
}

template<typename T, typename U>
bool operator!=(const shared_ptr<T>& lhs,
                const shared_ptr<U>& rhs) noexcept {
  return !(lhs == rhs);
}

template<typename T>
bool operator==(std::nullptr_t, const shared_ptr<T>& rhs) noexcept {
  return rhs.get() == nullptr;
}

template<typename T>
bool operator!=(std::nullptr_t, const shared_ptr<T>& rhs) noexcept {
  return !(rhs == nullptr);
}

template<typename T>
bool operator==(const shared_ptr<T>& lhs, std::nullptr_t) noexcept {
  return lhs.get() == nullptr;
}

template<typename T>
bool operator!=(const shared_ptr<T>& lhs, std::nullptr_t) noexcept {
  return !(lhs.get() == nullptr);
}

template<typename T>
struct weak_ptr {
  constexpr weak_ptr() noexcept
      : cblock(nullptr),
        ptr(nullptr) {}

  weak_ptr(const weak_ptr& other) noexcept
      : cblock(other.cblock),
        ptr(other.ptr) {
    if (cblock != nullptr) {
      cblock->add_weak();
    }
  }

  template<typename Y>
  weak_ptr(const weak_ptr<Y>& other) noexcept
      : cblock(other.cblock),
        ptr(other.ptr) {
    if (cblock != nullptr) {
      cblock->add_weak();
    }
  }

  weak_ptr(const shared_ptr<T>& other) noexcept
      : cblock(other.cblock),
        ptr(other.ptr) {
    if (cblock != nullptr) {
      cblock->add_weak();
    }
  }

  weak_ptr(weak_ptr<T>&& other) noexcept
      : weak_ptr() {
    other.swap(*this);
  }

  template<typename U>
  weak_ptr(weak_ptr<U>&& other) noexcept
      : weak_ptr() {
    other.swap(*this);
  }

  weak_ptr& operator=(const weak_ptr& other) {
    if (this != &other) {
      weak_ptr<T>(other).swap(*this);
    }
    return *this;
  }

  weak_ptr& operator=(weak_ptr&& other) {
    if (this != &other) {
      weak_ptr<T>(std::move(other)).swap(*this);
    }
    return *this;
  }

  ~weak_ptr() {
    if (cblock != nullptr) {
      cblock->del_weak();
    }
  }

  void swap(weak_ptr& other) noexcept {
    using std::swap;
    swap(cblock, other.cblock);
    swap(ptr, other.ptr);
  }

  shared_ptr<T> lock() const noexcept {
    shared_ptr<T> res;
    if (cblock != nullptr && cblock->ref_count() != 0) {
      res.ptr = ptr;
      res.cblock = cblock;
      cblock->add_ref();
    }
    return res;
  }

 private:
  control_block* cblock;
  T* ptr;
};
}
