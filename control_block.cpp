#include "control_block.h"

control_block::control_block() noexcept
    : n_refs(0),
      n_weak(0) {}

void control_block::add_ref() noexcept {
  n_refs++;
  n_weak++;
}

void control_block::add_weak() noexcept {
  n_weak++;
}

void control_block::del_ref() noexcept {
  n_refs--;
  n_weak--;
  if (n_refs == 0) {
    delete_object();
    if (n_weak == 0) {
      delete this;
    }
  }
}

void control_block::del_weak() noexcept {
  n_weak--;
  if (n_refs == 0 && n_weak == 0) {
    delete this;
  }
}

std::size_t control_block::ref_count() const noexcept {
  return n_refs;
}

std::size_t control_block::weak_count() const noexcept {
  return n_weak;
}
