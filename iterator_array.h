#pragma once

// http://www.cplusplus.com/reference/iterator/
// https://stackoverflow.com/questions/4421706/what-are-the-basic-rules-and-idioms-for-operator-overloading

namespace nstd {

	template <typename T>
	class iterator_array {
	public:
		iterator_array();
		iterator_array(T *ptr);
		iterator_array(const iterator_array<T> &) = default;
		iterator_array(iterator_array<T> &&) = default;

		iterator_array<T> &operator=(T *ptr);
		iterator_array<T> &operator=(iterator_array<T> rhs);

		iterator_array<T> &operator+=(size_t n);
		iterator_array<T> &operator-=(size_t n);

		template <typename Tx> friend size_t operator-(const iterator_array<Tx> &lhs, const iterator_array<Tx> &rhs);

		iterator_array<T> &operator++();
		iterator_array<T> operator++(int);
		iterator_array<T> &operator--();
		iterator_array<T> operator--(int);

		template <typename Tx> friend inline bool operator==(const iterator_array<Tx> &lhs, const iterator_array<Tx> &rhs);
		template <typename Tx> friend inline bool operator< (const iterator_array<Tx> &lhs, const iterator_array<Tx> &rhs);

		T &operator*();
		const T &operator*() const;
		T *operator->();
		const T *operator->() const;

	private:
		T * data_ptr;
	};

	template <typename T>
	iterator_array<T>::iterator_array() : data_ptr(nullptr) {}

	template <typename T>
	iterator_array<T>::iterator_array(T *ptr) : data_ptr(ptr) {}

	template <typename T>
	iterator_array<T> &iterator_array<T>::operator=(T *ptr) {
		data_ptr = ptr;
		return *this;
	}

	template <typename T>
	iterator_array<T> &iterator_array<T>::operator=(iterator_array<T> rhs) {
		data_ptr = rhs.data_ptr;
		return *this;
	}

	template <typename T>
	iterator_array<T> &iterator_array<T>::operator+=(size_t n) {
		data_ptr += n;
		return *this;
	}

	template <typename T>
	iterator_array<T> &iterator_array<T>::operator-=(size_t n) {
		data_ptr -= n;
		return *this;
	}

	template <typename T> 
	size_t operator-(const iterator_array<T> &lhs, const iterator_array<T> &rhs) {
		return lhs.data_ptr - rhs.data_ptr;
	}

	template <typename T>
	iterator_array<T> &iterator_array<T>::operator++() {
		data_ptr++;
		return *this;
	}

	template <typename T>
	iterator_array<T> iterator_array<T>::operator++(int) {
		iterator_array<T> tmp(data_ptr);
		++(*this);
		return tmp;
	}

	template <typename T>
	iterator_array<T> &iterator_array<T>::operator--() {
		data_ptr--;
		return *this;
	}

	template <typename T>
	iterator_array<T> iterator_array<T>::operator--(int) {
		iterator_array<T> tmp(data_ptr);
		--(*this);
		return tmp;
	}

	template <typename T>
	inline bool operator==(const iterator_array<T> &lhs, const iterator_array<T> &rhs) {
		return lhs.data_ptr == rhs.data_ptr;
	}

	template <typename T>
	inline bool operator!=(const iterator_array<T> &lhs, const iterator_array<T> &rhs) {
		return !operator==(lhs, rhs);
	}

	template <typename T>
	inline bool operator< (const iterator_array<T> &lhs, const iterator_array<T> &rhs) {
		return lhs.data_ptr < rhs.data_ptr;
	}

	template <typename T>
	inline bool operator> (const iterator_array<T> &lhs, const iterator_array<T> &rhs) {
		return operator< (rhs, lhs);
	}

	template <typename T>
	inline bool operator<=(const iterator_array<T> &lhs, const iterator_array<T> &rhs) {
		return !operator> (lhs, rhs);
	}

	template <typename T>
	inline bool operator>=(const iterator_array<T> &lhs, const iterator_array<T> &rhs) {
		return !operator< (lhs, rhs);
	}

	template <typename T>
	T &iterator_array<T>::operator*() {
		return *data_ptr;
	}

	template <typename T>
	const T &iterator_array<T>::operator*() const {
		return *data_ptr;
	}

	template <typename T>
	T *iterator_array<T>::operator->() {
		return data_ptr;
	}

	template <typename T>
	const T *iterator_array<T>::operator->() const {
		return data_ptr;
	}

	template <typename T>
	inline iterator_array<T> operator+(iterator_array<T> lhs, size_t rhs) {
		lhs += rhs;
		return lhs;
	}

	template <typename T>
	inline iterator_array<T> operator+(size_t lhs, iterator_array<T> rhs) {
		return operator+(rhs, lhs);
	}

	template <typename T>
	inline iterator_array<T> operator-(iterator_array<T> lhs, size_t rhs) {
		lhs -= rhs;
		return lhs;
	}

	template <typename T>
	inline iterator_array<T> operator-(size_t lhs, iterator_array<T> rhs) {
		return operator-(rhs, lhs);
	}

}
