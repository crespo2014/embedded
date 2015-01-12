class Buffer {
    const unsigned size;
    unsigned rx_;     // where to read
    unsigned count;   //usage
    int * const data_;
    /*
    Buffer(const Buffer&) = delete;
    Buffer(const Buffer&&) = delete;
    Buffer& operator =(const Buffer&) = delete;
    Buffer& operator =(const Buffer&&) = delete;
    */

public:
   explicit  Buffer(unsigned max_size);
    bool push(int v);
    bool pop(int& v);
    ~Buffer();
    bool isEmpty() const;

};
