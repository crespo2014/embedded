template<class T>
class Buffer
{
	const unsigned size;
	unsigned rx_;     // where to read
	unsigned count;   //usage
	T * const data_;
	/*
	 Buffer(const Buffer&) = delete;
	 Buffer(const Buffer&&) = delete;
	 Buffer& operator =(const Buffer&) = delete;
	 Buffer& operator =(const Buffer&&) = delete;
	 */

public:
	Buffer(unsigned max_size);
	bool push(T v);
	bool pop(T& v);
	~Buffer();
	bool isEmpty() const;

};

template<class T>
Buffer<T>::Buffer(unsigned max_size) :
		size(max_size), rx_(0), count(0), data_(new int[max_size])
{

}

template<class T>
bool Buffer<T>::push(T v)
{
	if (count == size)
		return false;
	data_[(rx_ + count) % size] = v;
	count++;
	return true;
}

template<class T>
bool Buffer<T>::pop(T& v)
{
	if (count == 0)
		return false;
	v = data_[rx_];
	rx_++;
	count--;
	if (rx_ == size)
		rx_ = 0;
	return true;
}

template<class T>
Buffer<T>::~Buffer()
{
	delete[] data_;
}

template<class T>
bool Buffer<T>::isEmpty() const
{
	return (count == 0);
}
