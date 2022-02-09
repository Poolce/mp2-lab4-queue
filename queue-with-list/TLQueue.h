#pragma once
#include <iostream>
using namespace std;

template <class T>
struct TNode {
	T value;
	TNode* next;
};

template <class T>
class TLQueue {
private:
	TNode<T>* first;
	TNode<T>* last;
public:
	TLQueue();
	~TLQueue();
	TLQueue(const TLQueue& qu);

	TLQueue<T>& operator=(const TLQueue<T>& qu);
	bool operator==(const TLQueue<T>& qu) const;
	bool operator!=(const TLQueue<T>& qu) const;

	bool empty() const;
	void clear();

	void push(T value);
	T pop();

	T get_first() const;
	T get_last() const;

	friend ostream& operator<<(ostream& out, const TLQueue& qu) {
		TNode<T>* node = qu.first;
		out << "[ ";
		while (node != nullptr) {
			out << node->value << " ";
			node = node->next;
		}
		out << "]";
		return out;
	}
};

template <class T>
TLQueue<T>::TLQueue() {
	first = last = nullptr;
}

template <class T>
TLQueue<T>::~TLQueue() {
	clear();
}

template <class T>
TLQueue<T>::TLQueue(const TLQueue& qu) {
	first = last = nullptr;
	if (!qu.empty()) {
		TNode<T>* new_node;
		new_node = new TNode<T>;
		new_node->value = qu.first->value;
		new_node->next = nullptr;
		first = new_node;

		TNode<T>* prev_new_node = new_node;
		TNode<T>* other_node = qu.first->next;

		while (other_node != nullptr) {
			new_node = new TNode<T>;
			new_node->value = other_node->value;
			new_node->next = nullptr;

			prev_new_node->next = new_node;

			prev_new_node = new_node;
			other_node = other_node->next;
		}
		last = prev_new_node;
	}
}

template <class T>
TLQueue<T>& TLQueue<T>::operator=(const TLQueue<T>& qu) {
	if (this == &qu) {
		return *this;
	}

	clear();
	if (!qu.empty()) {
		TNode<T>* new_node;
		new_node = new TNode<T>;
		new_node->value = qu.first->value;
		new_node->next = nullptr;
		first = new_node;

		TNode<T>* prev_new_node = new_node;
		TNode<T>* other_node = qu.first->next;

		while (other_node != nullptr) {
			new_node = new TNode<T>;
			new_node->value = other_node->value;
			new_node->next = nullptr;

			prev_new_node->next = new_node;

			prev_new_node = new_node;
			other_node = other_node->next;
		}
		last = prev_new_node;
	}
}

template <class T>
bool TLQueue<T>::operator==(const TLQueue<T>& qu) const {
	TNode<T>* node = first;
	TNode<T>* node_other = qu.first;

	while (node != nullptr && node_other != nullptr) {
		if (node->value != node_other->value) {
			return false;
		}
		node = node->next;
		node_other = node_other->next;
	}

	if (node != nullptr || node_other != nullptr) {
		return false;
	}

	return true;
}

template <class T>
bool TLQueue<T>::operator!=(const TLQueue<T>& qu) const {
	return !operator==(qu);
}

template <class T>
bool TLQueue<T>::empty() const {
	return first == nullptr;
}

template <class T>
void TLQueue<T>::clear() {
	TNode<T>* node;
	while (first != nullptr) {
		node = first;
		first = first->next;
		delete node;
	}
	last = nullptr;
}

template <class T>
void TLQueue<T>::push(T value) {
	TNode<T>* new_node = new TNode<T>();
	new_node->value = value;
	new_node->next = nullptr;

	if (last != nullptr) {
		last->next = new_node;
	}
	else {
		first = new_node;
	}

	last = new_node;
}

template <class T>
T TLQueue<T>::pop() {
	if (empty()) {
		throw "Can't pop from an empty queue";
	}

	T value = first->value;
	TNode<T>* old_first = first;
	first = old_first->next;
	delete old_first;

	if (first == nullptr) {
		last = nullptr;
	}

	return value;
}

template <class T>
T TLQueue<T>::get_first() const {
	if (empty()) {
		throw "Can't get first element of an empty queue";
	}
	return first->value;
}

template <class T>
T TLQueue<T>::get_last() const {
	if (empty()) {
		throw "Can't get last element of an empty queue";
	}
	return last->value;
}