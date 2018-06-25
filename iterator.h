#pragma once

// http://www.cplusplus.com/reference/iterator/
// https://stackoverflow.com/questions/4421706/what-are-the-basic-rules-and-idioms-for-operator-overloading

namespace nstd_prot {

	// if no overloads defined defaults to array iterator
	template <typename T, class Ts>
	class iterator {
	public:
		iterator();
		iterator(T *ptr);
		iterator(const iterator<T, Ts> &) = default;
		iterator(iterator<T, Ts> &&) = default;

		iterator<T, Ts> &operator=(T *ptr);
		iterator<T, Ts> &operator=(iterator<T, Ts> rhs);

		iterator<T, Ts> &operator+=(size_t n);
		iterator<T, Ts> &operator-=(size_t n);

		template <typename Tx, class Ty> friend size_t operator-(const iterator<Tx, Ty> &lhs, const iterator<Tx, Ty> &rhs);

		iterator<T, Ts> &operator++();
		iterator<T, Ts> operator++(int);
		iterator<T, Ts> &operator--();
		iterator<T, Ts> operator--(int);

		template <typename Tx, class Ty> friend inline bool operator==(const iterator<Tx, Ty> &lhs, const iterator<Tx, Ty> &rhs);
		template <typename Tx, class Ty> friend inline bool operator< (const iterator<Tx, Ty> &lhs, const iterator<Tx, Ty> &rhs);

		T &operator*();
		const T &operator*() const;
		T *operator->();
		const T *operator->() const;

	private:
		T * data_ptr;
	};

	template <typename T, class Ts>
	iterator<T, Ts>::iterator() : data_ptr(nullptr) {}

	template <typename T, class Ts>
	iterator<T, Ts>::iterator(T *ptr) : data_ptr(ptr) {}

	template <typename T, class Ts>
	iterator<T, Ts> &iterator<T, Ts>::operator=(T *ptr) {
		data_ptr = ptr;
		return *this;
	}

	template <typename T, class Ts>
	iterator<T, Ts> &iterator<T, Ts>::operator=(iterator<T, Ts> rhs) {
		data_ptr = rhs.data_ptr;
		return *this;
	}

	template <typename T, class Ts>
	iterator<T, Ts> &iterator<T, Ts>::operator+=(size_t n) {
		data_ptr += n;
		return *this;
	}

	template <typename T, class Ts>
	iterator<T, Ts> &iterator<T, Ts>::operator-=(size_t n) {
		data_ptr -= n;
		return *this;
	}

	template <typename T, class Ts> 
	size_t operator-(const iterator<T, Ts> &lhs, const iterator<T, Ts> &rhs) {
		return lhs.data_ptr - rhs.data_ptr;
	}

	template <typename T, class Ts>
	iterator<T, Ts> &iterator<T, Ts>::operator++() {
		data_ptr++;
		return *this;
	}

	template <typename T, class Ts>
	iterator<T, Ts> iterator<T, Ts>::operator++(int) {
		iterator<T, Ts> tmp(data_ptr);
		++(*this);
		return tmp;
	}

	template <typename T, class Ts>
	iterator<T, Ts> &iterator<T, Ts>::operator--() {
		data_ptr--;
		return *this;
	}

	template <typename T, class Ts>
	iterator<T, Ts> iterator<T, Ts>::operator--(int) {
		iterator<T> tmp(data_ptr);
		--(*this);
		return tmp;
	}

	template <typename T, class Ts>
	inline bool operator==(const iterator<T, Ts> &lhs, const iterator<T, Ts> &rhs) {
		return lhs.data_ptr == rhs.data_ptr;
	}

	template <typename T, class Ts>
	inline bool operator!=(const iterator<T, Ts> &lhs, const iterator<T, Ts> &rhs) {
		return !operator==(lhs, rhs);
	}

	template <typename T, class Ts>
	inline bool operator< (const iterator<T, Ts> &lhs, const iterator<T, Ts> &rhs) {
		return lhs.data_ptr < rhs.data_ptr;
	}

	template <typename T, class Ts>
	inline bool operator> (const iterator<T, Ts> &lhs, const iterator<T, Ts> &rhs) {
		return operator< (rhs, lhs);
	}

	template <typename T, class Ts>
	inline bool operator<=(const iterator<T, Ts> &lhs, const iterator<T, Ts> &rhs) {
		return !operator> (lhs, rhs);
	}

	template <typename T, class Ts>
	inline bool operator>=(const iterator<T, Ts> &lhs, const iterator<T, Ts> &rhs) {
		return !operator< (lhs, rhs);
	}

	template <typename T, class Ts>
	T &iterator<T, Ts>::operator*() {
		return *data_ptr;
	}

	template <typename T, class Ts>
	const T &iterator<T, Ts>::operator*() const {
		return *data_ptr;
	}

	template <typename T, class Ts>
	T *iterator<T, Ts>::operator->() {
		return data_ptr;
	}

	template <typename T, class Ts>
	const T *iterator<T, Ts>::operator->() const {
		return data_ptr;
	}

	template <typename T, class Ts>
	inline iterator<T, Ts> operator+(iterator<T, Ts> lhs, size_t rhs) {
		lhs += rhs;
		return lhs;
	}

	template <typename T, class Ts>
	inline iterator<T, Ts> operator+(size_t lhs, iterator<T, Ts> rhs) {
		return operator+(rhs, lhs);
	}

	template <typename T, class Ts>
	inline iterator<T, Ts> operator-(iterator<T, Ts> lhs, size_t rhs) {
		lhs -= rhs;
		return lhs;
	}

	template <typename T, class Ts>
	inline iterator<T, Ts> operator-(size_t lhs, iterator<T, Ts> rhs) {
		return operator-(rhs, lhs);
	}

}
