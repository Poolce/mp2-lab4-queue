#pragma once
#include <iostream>
using namespace std;

template <class T>
class TQueue {
private:
	T* arr;
	int max_size;
	int head, tail;
	int count;
public:
	TQueue(int _size = 20);
	~TQueue();
	TQueue(const TQueue& qu);

	TQueue<T>& operator=(const TQueue<T>& qu);
	bool operator==(const TQueue<T>& qu) const;
	bool operator!=(const TQueue<T>& qu) const;

	bool empty() const;
	bool full() const;
	void clear();

	int get_max_size();
	int get_count();
	int get_head();

	void push(T elem);
	T pop();

	friend ostream& operator<<(std::ostream& out, const TQueue& qu) {
		out << "[ ";
		for (int t_count = qu.count, i = qu.head; t_count > 0; t_count--) {
			out << qu.arr[i] << ' ';
			i = (++i) % qu.max_size;
		}
		out << "]";

		return out;
	}
};

template<class T>
TQueue<T>::TQueue(int _size) {
	if (_size < 2) {
		throw "Queue max_size cannot be < 2";
	}

	max_size = _size;
	arr = new T[max_size];

	count = 0;
	tail = -1, head = 0;
}

template<class T>
TQueue<T>::~TQueue() {
	delete[] arr;
}

template<class T>
TQueue<T>::TQueue(const TQueue& qu) {
	max_size = qu.max_size;

	count = qu.count;
	tail = qu.tail, head = qu.head;

	arr = new T[max_size];
	for (int t_count = count, i = head; t_count > 0; t_count--) {
		arr[i] = qu.arr[i];
		i = (++i) % max_size;
	}
}

template<class T>
TQueue<T>& TQueue<T>::operator=(const TQueue<T>& qu) {
	if (this == &qu) {
		return *this;
	}

	if (max_size != qu.max_size) {
		max_size = qu.max_size;
		delete[] arr;
		arr = new T[max_size];
	}
	count = qu.count;
	tail = qu.tail, head = qu.head;

	for (int t_count = count, i = head; t_count > 0; t_count--) {
		arr[i] = qu.arr[i];
		i = (++i) % max_size;
	}

	return *this;
}

template<class T>
bool TQueue<T>::operator==(const TQueue<T>& qu) const {
	if ((max_size != qu.max_size) || (count != qu.count) || (head != qu.head) || (tail != qu.tail)) {
		return false;
	}

	for (int t_count = count, i = head; t_count > 0; t_count--) {
		if (arr[i] != qu.arr[i]) {
			return false;
		}
		i = (++i) % max_size;
	}

	return true;
}

template<class T>
bool TQueue<T>::operator!=(const TQueue<T>& qu) const {
	return !operator==(qu);
}

template<class T>
bool TQueue<T>::empty() const {
	return (count == 0);
}

template<class T>
bool TQueue<T>::full() const {
	return (count == max_size);
}

template<class T>
void TQueue<T>::clear() {
	count = 0;
	tail = -1, head = 0;
}

template<class T>
int TQueue<T>::get_max_size() {
	return max_size;
}

template<class T>
int TQueue<T>::get_count() {
	return count;
}

template<class T>
int TQueue<T>::get_head() {
	return head;
}

template<class T>
void TQueue<T>::push(T elem) {
	if (full()) {
		throw "Can't push to a full queue";
	}

	tail = (++tail) % max_size;
	arr[tail] = elem;
	count++;
}

template<class T>
T TQueue<T>::pop() {
	if (empty()) {
		throw "Can't pop from an empty queue";
	}

	T elem = arr[head];
	head = (++head) % max_size;
	count--;

	return elem;
}