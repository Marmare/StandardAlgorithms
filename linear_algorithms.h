#pragma once

#include "iterator.h"

using namespace nstd_prot;

namespace nstd {

	template <typename T, class Ts>
	iterator<T, Ts> binary_search(const iterator<T, Ts> &first, const iterator<T, Ts> &last, const T &x) {
		iterator<T, Ts> mid = first + (last - first) / 2;
		if (first == last) return last;
		else if (*mid == x) return mid;
		else if (*mid < x) return binary_search(mid+1, last, x);
		else return binary_search(first, mid-1, x);
	}

}