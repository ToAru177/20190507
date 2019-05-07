#ifndef _RANGE_CHECKING_ARRAY_H_
#define _RANGE_CHECKING_ARRAY_H_

#include <iostream>

using namespace std;

template <typename T>
class RangeCheckingArray {
private:
	T * arr;
	int arrlen;
	// ���� ������
	RangeCheckingArray(const RangeCheckingArray &ref) {}
	// ���� ������
	RangeCheckingArray& operator=(const RangeCheckingArray &ref) {}


public:
	//������
	RangeCheckingArray(int len);
	// ������
	T& operator[] (int idx);
	// ��¿�
	T operator[] (int idx) const;
	// ����� ��� ����
	int GetArrLen() const;
	// �Ҹ���
	~RangeCheckingArray();

};

#endif // !_RANGE_CHECKING_ARRAY_H_
