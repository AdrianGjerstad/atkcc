#ifndef ATKCC_INCLUDE_CORE_BUFFER_H_
#define ATKCC_INCLUDE_CORE_BUFFER_H_

#include <vector>
#include <cstddef>
#include <functional>

namespace atk {

class buffer {
public:
  buffer(const std::size_t& buffer_size) {
    samples_.resize(buffer_size, 0);
  }

  buffer(const std::vector<double>& samples) {
    samples_ = samples;
  }

  buffer(const buffer& cpy) {
    samples_ = cpy.samples_;
  }

  double& operator[](const std::size_t& index) {
    return samples_[index];
  }

  const double& operator[](const std::size_t& index) const {
    return samples_[index];
  }

  const std::size_t size() const {
    return samples_.size();
  }

  const double& at(const std::size_t& index) const {
    return samples_.at(index);
  }

  void set(const std::size_t& index, double sample) {
    samples_[index] = sample;
  }

  buffer& operator=(const buffer& cpy) {
    samples_ = cpy.samples_;
    return (*this);
  }

  void clear() {
    samples_.assign(0, samples_.size());
  }

  void foreach(const std::function<void(double&)>& callback) {
    for(std::size_t i = 0; i < samples_.size(); ++i) {
      callback(samples_[i]);
    }
  }

  void foreach(const std::function<double(double)>& callback) {
    for(std::size_t i = 0; i < samples_.size(); ++i) {
      samples_[i] = callback(samples_[i]);
    }
  }
private:
  std::vector<double> samples_;
};

} // namespace atk

#endif  // ATKCC_INCLUDE_CORE_BUFFER_H_

