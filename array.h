#pragma once

#include "iterator.h"

#include <initializer_list>
#include <exception>

namespace nstd {

	template <typename T, size_t size>
	class array {
	public:
		array();
		array(std::initializer_list<T> il);
		array(const array<T, size> &obj);
		array(array<T, size> &&obj);

		array<T, size> &operator=(array<T, size> rhs);

		T &operator[](size_t idx);
		const T &operator[](size_t idx) const;

		typedef nstd_prot::iterator<T, array<T, size>> iterator;

		iterator begin();
		const iterator begin() const;
		iterator end();
		const iterator end() const;

		const size_t length;
		const bool empty;

	private:
		T data[size];
	};

	template <typename T, size_t size>
	array<T, size>::array() : length(size), empty(size ? false : true) {}

	template <typename T, size_t size>
	array<T, size>::array(std::initializer_list<T> il) : array<T, size>() {
		if (il.size() > size) throw std::exception("Initializer list too big");
		std::initializer_list<T>::iterator it = il.begin();
		for (size_t i = 0; it != il.end(); ++it, ++i) {
			data[i] = *it;
		}
	}

	template <typename T, size_t size>
	array<T, size>::array(const array<T, size> &obj) : array<T, size>() {
		for (size_t i = 0; i < size; ++i) {
			data[i] = obj[i];
		}
	}

	template <typename T, size_t size>
	array<T, size>::array(array<T, size> &&obj) : array<T, size>() {
		std::swap(obj.data, data);
	}

	template <typename T, size_t size>
	array<T, size> &array<T, size>::operator=(array<T, size> rhs) {
		std::swap(rhs.data, data);
		return *this;
	}

	template <typename T, size_t size>
	T &array<T, size>::operator[](size_t idx) {
		if (idx >= size) throw std::exception("Index out of bounds");
		return data[idx];
	}

	template <typename T, size_t size>
	const  T &array<T, size>::operator[](size_t idx) const {
		if (idx >= size) throw std::exception("Index out of bounds");
		return data[idx];
	}

	template <typename T, size_t size>
	typename array<T, size>::iterator array<T, size>::begin() {
		return iterator(&data[0]);
	}

	template <typename T, size_t size>
	const typename array<T, size>::iterator array<T, size>::begin() const {
		return iterator(&data[0]);
	}

	template <typename T, size_t size>
	typename array<T, size>::iterator array<T, size>::end() {
		return iterator(&data[size]);
	}

	template <typename T, size_t size>
	const typename array<T, size>::iterator array<T, size>::end() const {
		return iterator(&data[size]);
	}

	template <typename T, size_t size>
	inline bool operator==(const array<T, size> &lhs, const array<T, size> &rhs) {
		for (size_t i = 0; i < size; ++i) {
			if (lhs[i] != rhs[i]) return false;
		}
		return true;
	}

	template <typename T, size_t size>
	inline bool operator!=(const array<T, size> &lhs, const array<T, size> &rhs) {
		return !operator==(lhs, rhs);
	}

	template <typename T, size_t size>
	inline bool operator< (const array<T, size> &lhs, const array<T, size> &rhs) {
		for (size_t i = 0; i < size; ++i) {
			if (lhs[i] > rhs[i]) return false;
		}
		return true;
	}

	template <typename T, size_t size>
	inline bool operator> (const array<T, size> &lhs, const array<T, size> &rhs) {
		return operator< (rhs, lhs);
	}

	template <typename T, size_t size>
	inline bool operator<= (const array<T, size> &lhs, const array<T, size> &rhs) {
		return !operator> (lhs, rhs);
	}

	template <typename T, size_t size>
	inline bool operator>= (const array<T, size> &lhs, const array<T, size> &rhs) {
		return !operator< (lhs, rhs);
	}

}
