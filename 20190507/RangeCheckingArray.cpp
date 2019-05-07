#include "RangeCheckingArray.h"
#include <iostream>



// ������
template <typename T>
RangeCheckingArray<T>::RangeCheckingArray(int len) : arrlen(len)
{
	arr = new T[len];
}


// [] ������ �����ε�
template <typename T>
T& RangeCheckingArray<T>::operator[](int idx) {
	if (idx < 0 || idx > arrlen) {
		cout << "�迭�� ������ ������ϴ�." << endl;
		exit(1);
	}
	return arr[idx];
}


// const [] ������ �����ε�
template <typename T>
T RangeCheckingArray<T>::operator[](int idx) const {
	if (idx < 0 || idx > arrlen) {
		cout << "�迭�� ������ ������ϴ�." << endl;
		exit(1);
	}
	return arr[idx];
}

// GetArrLen()
template <typename T>
int RangeCheckingArray<T>::GetArrLen() const {
	return arrlen;
}

// �Ҹ���
template <typename T>
RangeCheckingArray<T>::~RangeCheckingArray() {
	delete[]arr;
}