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

  constexpr explicit shared_ptr(std::nullptr_t) noexcept
      : cblock(nullptr),
        ptr(nullptr) {}

  template<typename Y>
  explicit shared_ptr(Y* ptr)
      : shared_ptr(ptr, std::default_delete<Y>()) {}

  template<typename Y, typename D>
  shared_ptr(Y* ptr, D deleter) : ptr(ptr) {
    try {
      cblock = new regular_control_block<Y, D>(ptr, deleter);
    } catch (...) {
      deleter(ptr);
      throw;
    }
  }

  template<class Deleter>
  shared_ptr(std::nullptr_t, Deleter d)
      : cblock(nullptr),
        ptr(nullptr) {}

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
      unlink_cblock();
      cblock = other.cblock;
      ptr = other.ptr;
      other.ptr = nullptr;
      other.cblock = nullptr;
    }
    return *this;
  }

  ~shared_ptr() {
    unlink_cblock();
  }

  void swap(shared_ptr& other) noexcept {
    using std::swap;
    swap(cblock, other.cblock);
    swap(ptr, other.ptr);
  }

  void reset() noexcept {
    shared_ptr<T>(nullptr).swap(*this);
  }

  template<typename U>
  void reset(U* new_ptr) {
    shared_ptr<T>(new_ptr).swap(*this);
  }

  template<typename U, typename D>
  void reset(U* new_ptr, D deleter) {
    shared_ptr<T>(new_ptr, deleter).swap(*this);
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

  template<typename U>
  bool operator==(const shared_ptr<U>& other) const noexcept {
    return other.get() == get();
  }

  bool operator==(std::nullptr_t) const noexcept {
    return get() == nullptr;
  }

  template<typename U>
  bool operator!=(const shared_ptr<U>& other) const noexcept {
    return !(*this == other);
  }

  bool operator!=(std::nullptr_t) const noexcept {
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

  void unlink_cblock() {
    if (cblock != nullptr) {
      cblock->del_ref();
      if (cblock->ref_count() == 0) {
        cblock->delete_object();
        if (cblock->weak_count() == 0) {
          delete cblock;
        }
      }
    }
  }
};

template<typename T, typename... Args>
shared_ptr<T> make_shared(Args&& ... args) {
  shared_ptr<T> res;
  inplace_control_block<T>* cblock;
  try {
    cblock = new inplace_control_block<T>(std::forward<Args>(args)...);
  } catch (...) {
    delete cblock;
    throw;
  }
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
      unlink_cblock();
      cblock = other.cblock;
      ptr = other.ptr;
      other.cblock = nullptr;
      other.ptr = nullptr;
    }
    return *this;
  }

  ~weak_ptr() {
    unlink_cblock();
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

  explicit operator bool() const noexcept {
    return cblock != nullptr && cblock->ref_count() != 0;
  }

 private:
  control_block* cblock;
  T* ptr;

  void unlink_cblock() {
    if (cblock != nullptr) {
      cblock->del_weak();
      if (cblock->ref_count() == 0 && cblock->weak_count() == 0) {
        delete cblock;
      }
    }
  }
};
}
