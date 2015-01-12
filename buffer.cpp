#include "buffer.h"
Buffer::Buffer(unsigned max_size)
        : size(max_size), rx_(0), count(0), data_(new int[max_size]) {

}
bool Buffer::push(int v) {
    if (count == size)
        return false;
    data_[(rx_ + count) % size] = v;
    count++;
    return true;
}
bool Buffer::pop(int& v) {
    if (count == 0)
        return false;
    v = data_[rx_];
    rx_++;
    count--;
    if (rx_ == size)
        rx_ = 0;
    return true;
}
Buffer::~Buffer() {
    delete[] data_;
}
bool Buffer::isEmpty() const {
    return (count == 0);
}


