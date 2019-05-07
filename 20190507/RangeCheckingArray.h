#ifndef _RANGE_CHECKING_ARRAY_H_
#define _RANGE_CHECKING_ARRAY_H_

#include <iostream>

using namespace std;

template <typename T>
class RangeCheckingArray {
private:
	T * arr;
	int arrlen;
	// 복사 생성자
	RangeCheckingArray(const RangeCheckingArray &ref) {}
	// 대입 생성자
	RangeCheckingArray& operator=(const RangeCheckingArray &ref) {}


public:
	//생성자
	RangeCheckingArray(int len);
	// 수정용
	T& operator[] (int idx);
	// 출력용
	T operator[] (int idx) const;
	// 저장된 요소 갯수
	int GetArrLen() const;
	// 소멸자
	~RangeCheckingArray();

};

#endif // !_RANGE_CHECKING_ARRAY_H_
