#ifndef CIRCULAR_BUFFER_AVG_CIRCULAR_BUFFER_AVG_H
#define CIRCULAR_BUFFER_AVG_CIRCULAR_BUFFER_AVG_H

#include <array>

namespace circular_buffer_avg {

template<typename T, size_t _Size>
class CircularBufferAvg {
 public:
  inline double GetAvg() const noexcept { return avg_; }

  // returns current avg
  inline double AddValue(const T& value) noexcept {
    if (max_size_reached_ >= _Size) {
      avg_ += (double(value) - buffer_[insert_index_]) / _Size;
      ++insert_index_ %= _Size;
      return avg_;
    }
    avg_ = (avg_ * insert_index_ + value) / (insert_index_ + 1);
    buffer_[insert_index_] = value;
    ++insert_index_ %= _Size;
    max_size_reached_++;
    return avg_;
  }

  void Clear() {
    avg_ = 0;
    insert_index_ = 0;
    max_size_reached_ = 0;
  }

 private:
  std::array<T, _Size> buffer_;
  double avg_ = 0.;
  size_t insert_index_ = 0;
  size_t max_size_reached_ = 0;
};

}

#endif // CIRCULAR_BUFFER_AVG_CIRCULAR_BUFFER_AVG_H
