#include "RangeCheckingArray.h"
#include <iostream>



// 생성자
template <typename T>
RangeCheckingArray<T>::RangeCheckingArray(int len) : arrlen(len)
{
	arr = new T[len];
}


// [] 연산자 오버로딩
template <typename T>
T& RangeCheckingArray<T>::operator[](int idx) {
	if (idx < 0 || idx > arrlen) {
		cout << "배열의 범위를 벗어났습니다." << endl;
		exit(1);
	}
	return arr[idx];
}


// const [] 연산자 오버로딩
template <typename T>
T RangeCheckingArray<T>::operator[](int idx) const {
	if (idx < 0 || idx > arrlen) {
		cout << "배열의 범위를 벗어났습니다." << endl;
		exit(1);
	}
	return arr[idx];
}

// GetArrLen()
template <typename T>
int RangeCheckingArray<T>::GetArrLen() const {
	return arrlen;
}

// 소멸자
template <typename T>
RangeCheckingArray<T>::~RangeCheckingArray() {
	delete[]arr;
}