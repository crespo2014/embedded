class Buffer {
    const unsigned size;
    unsigned rx_;   // where to read
    unsigned count;   //usage
    int * const data_;
    /*
    Buffer(const Buffer&) = delete;
    Buffer(const Buffer&&) = delete;
    Buffer& operator =(const Buffer&) = delete;
    Buffer& operator =(const Buffer&&) = delete;
    */

public:
   explicit  Buffer(unsigned max_size) : size(max_size),rx_(0),count(0),data_(new int[max_size]) 
    {

    }
    bool push(int v) {
        if (count == size)
            return false;
        data_[(rx_ + count) % size] = v;
        count++;
        return true;
    }
    bool pop(int& v) {
        if (count == 0)
            return false;
        v = data_[rx_];
        rx_++;
        count--;
        if (rx_ == size)
            rx_ = 0;
        return true;
    }
    ~Buffer() {
        delete[] data_;
    }
    bool isEmpty() const
    {
        return (count == 0);
    }

};
