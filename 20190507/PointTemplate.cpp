#include "PointTemplate.h"
#include <iostream>

using namespace std;

// 생성자
template <typename T>
Point<T>::Point(T x, T y) : xpos(x), ypos(y) {	}

// 함수
template <typename T>
void Point<T>::ShowPosition() const {
	cout << '[' << xpos << ", " << ypos << ']' << endl;
}
