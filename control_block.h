#pragma once
#include <cstddef>
#include <utility>

struct control_block {
  control_block() noexcept;

  void add_ref() noexcept;
  void add_weak() noexcept;
  void del_ref() noexcept;
  void del_weak() noexcept;

  std::size_t ref_count() const noexcept;
  std::size_t weak_count() const noexcept;

  virtual ~control_block() = default;
  virtual void delete_object() noexcept = 0;

 private:
  std::size_t n_refs;
  std::size_t n_weak; // >= 1 if there is at least one ref
};

template<typename T, typename D>
struct regular_control_block final : control_block, D {
  explicit regular_control_block(T* ptr, D deleter)
      : ptr(ptr),
        D(std::move(deleter)) {
    add_ref();
  }

  ~regular_control_block() override = default;

  void delete_object() noexcept override {
    static_cast<D&>(*this)(ptr);
  }

  T* get() const noexcept {
    return ptr;
  }

 private:
  T* ptr;
};

template<typename T>
struct inplace_control_block final : control_block {
  template<typename... Args>
  explicit inplace_control_block(Args&& ... args) {
    new(&data) T(std::forward<Args>(args)...);
    add_ref();
  }

  ~inplace_control_block() override = default;

  void delete_object() noexcept override {
    get()->~T();
  }

  T* get() noexcept {
    return reinterpret_cast<T*>(&data);
  }

 private:
  std::aligned_storage_t<sizeof(T), alignof(T)> data;
};
