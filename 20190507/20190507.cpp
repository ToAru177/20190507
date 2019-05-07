//#include <iostream>
//#include <cstring>
//
//using namespace std;

/*
	
	템플릿(Template)

	1.	템플릿의 의미
		형판(形板) -> 모형자

		지금까지 우리가 코딩하는 방법은 형판이 없이 직접 코딩 및 컴파일 해서 실행시킴.

		그래서, 객체지향에서 객체를 생성시,
		클래스를 기반으로 객체를 생성해서 사용함에따라
		클래스를 객체를 위한 틀이라고 말할 수 있으나,
		Template에서의 틀과는 다름.

		▶	모형자의 특성
			모형의 틀은 이미 결정 되어 있지만, 모형의 색은 결정 되어 있지 않아, 직접 결정해야 함.

			객체지향에서의 템플릿 -> 함수 템플릿
			
		▶	함수 템플릿의 특성
				-	함수 템플릿의 기능은 함수를 만들어 냄.
				-	자료형이 결정되어 있지 않아서, 직접 자료형을 결정해야 함.

				// 일반적인 함수
				int Add(int num1, int num2)
				{
					return num1 + num2;
				}

				// 함수 템플릿
				template <typename T>			// T라는 이름을 이용해서 아래의 함수 템플릿으로 정의 한다는 의미.
				T Add(T num1, T num2)
				{
					return num1 + num2;
				}

				int형 선언을 T로 대신했음. 이는 자료형을 결정짓지 않은 상태임으로,
				나중에 T를 대신해서 실제 자료형을 결정하겠다는 의미 임.

		1.1 함수 템플릿 예제

		1.2	일반 함수와 함수 템플릿이 같이 있는 경우
			하나의 코드에 일반함수와 함수 템플릿을 함께 사요하더라도 문법적으로 구분이 되어 사용 가능.
			하지만, 함수 템플릿을 정의한 삼황에서 동일한 기능의 일반 함수까지 정의하는 것은 좋지 않음.

		1.3	서로 다른 형(Type)에 대해 함수 템플릿 선언

		1.4	함수 템플릿의 특수화(Specialization)

	2.	클래스 템플릿
		함수 템플릿처럼 클래스도 템플릿으로 정의가 가능.
		클래스 템플릿을 기반으로 컴파일러가 만들어 내는 클래스를 "템플릿 클래스"라고 함.

		2.1	클래스 템플릿 기본 예제

		2.2	클래스 템플릿의 선언과 정의의 코드 분리

		2.3	클래스 템플릿의 선언과 정의의 파일 분리

		2.4	클래스 템플릿 활용

*/

/*
// 1.1 함수 템플릿 예제

// 함수 템플릿
template <typename T>
T Add(T num1, T num2) {
	return num1 + num2;
}

// 템플릿 함수(생성된 함수, Generated Function)
// 함수 템플릿을 기반으로 컴파일된 후 만들어진 함수.
int Add(int num1, int num2) {
	return num1 + num2;
}

int main(void) {

	cout << Add<int>(10, 20) <<endl;
	cout << Add<double>(10.5, 20.2) <<endl;
	cout << Add<int>(11.222, 22.111) <<endl;
	cout << Add<double>(11.222, 22.111) <<endl;
	
	cout << endl;

	cout << Add(10, 20) <<endl;
	cout << Add(10.5, 20.2) <<endl;
	cout << Add(11.222, 22.111) <<endl;
	cout << Add(11.222, 22.111) <<endl;

	return 0;
}
*/

/*
// 1.2	일반 함수와 함수 템플릿이 같이 있는 경우

template <typename T>
T Add(T num1, T num2) {
	cout << "T Add() 호출 됨" << endl;
	return num1 + num2;
}

int Add(int num1, int num2) {
	cout << "int Add() 호출 됨" << endl;
	return num1 + num2;
}

double Add(double num1, double num2) {
	cout << "double Add() 호출 됨" << endl;
	return num1 + num2;
}

int main(void) {

	cout << Add(10, 20) << endl;					// int Add() 호출
	cout << Add(10.5, 20.2) << endl;				// double Add() 호출
	cout << Add<int>(11, 22) << endl;				// T Add() 호출
	cout << Add<double>(11.222, 22.111) << endl;	// T Add() 호출

	return 0;
}
*/

/*
// 1.3	서로 다른 형(Type)에 대해 함수 템플릿 선언 예제
template <class T1, class T2>
void ShowData(double num) {
	cout << (T1)num << ", " << (T2)num << endl;
}

int main() {

	ShowData<char, int>(65);
	ShowData<char, int>(67);
	ShowData<char, double>(66.7);

	return 0;
}
*/

// 1.4	함수 템플릿의 특수화(Specialization) 예제

/*
// 1.4.1 특수화 하기전 문제가 있는 예제.
// 아래의 코드는 문법상으로 문제가 없지만,
// 논리적인 기능상에 문제가 있음.
// 이러한 문제를 해결하는 방법이 특수화 임.
template <typename T>
T Max(T a, T b) {
	return a > b ? a : b;
}

int main() {

	cout << Max(11, 12) << endl;			// 데이터 값을 기준으로 비교.
	cout << Max('T', 'Q') << endl;			// 데이터 값을 기준으로 비교.
	cout << Max("Simple", "Best") << endl;	// const char * => 주소를 기준으로 비교.

	return 0;
}
*/

/*
// 1.4.2 문제점을 개선한 특수화 예제
template <typename T>
T Max(T a, T b) {
	// 문제점 1 : 문자열 길이를 판단하는 건지??
	// 문제점 2 : 사전순서를 판단하는 건지??
	return a > b ? a : b;
}

// 매개변수가 문자열 -> 변수에 저장된 문자열
// char* 형 함수는 이렇게 제시를 하니, char* 형 함수가 필요한 경우에는 별도로  만들지 말고,
// 아래의 함수를 사용해라는 것을 컴파일러에게 알려줌.
template <>
char* Max(char* a, char* b) {
	cout << "char* Max(char* a, char* b)" << endl;
	return strlen(a) > strlen(b) ? a : b;
}

// 매개변수가 문자열 -> 문자열 자체
// const char* 형 함수는 이렇게 제시를 하니, const char* 형 함수가 필요한 경우에는 별도로  만들지 말고,
// 아래의 함수를 사용해라는 것을 컴파일러에게 알려줌.
template <>
const char* Max(const char* a, const char* b) {
	cout << "const char* Max(const char* a, const char* b)" << endl;
	return strcmp(a, b) > 0 ? a : b;
}


int main() {

	cout << Max(11, 12) << endl;			
	cout << Max('T', 'Q') << endl;			
	cout << Max("Simple", "Best") << endl;	

	char str1[] = "Simple";
	char str2[] = "Best";

	cout << Max(str1, str2) << endl;

	return 0;
}
*/

/*
// 2.1	클래스 템플릿 기본 예제

template <typename T>

class Point {
private:
	T xpos, ypos;

public:
	Point(T x = 0, T y = 0) : xpos(x), ypos(y) { }
	void ShowPosition() const {
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
};

int main() {
	// Template의 자료형을 명시하지 않으면 문법 오류 발생
	Point<int> pos1(1, 3);
	pos1.ShowPosition();

	Point<double> pos2(2.4, 3.6);
	pos2.ShowPosition();

	Point<char> pos3('P', 'F');
	pos3.ShowPosition();

	return 0;
}
*/

/*
//	2.2	클래스 템플릿의 선언과 정의의 분리

template <typename T>

class Point {
private:
	T xpos, ypos;

public:
	Point(T x = 0, T y = 0);
	void ShowPosition() const;
};

// 생성자
template <typename T>
Point<T>::Point(T x, T y) : xpos(x), ypos(y) {	}

// 함수
template <typename T>
void Point<T>::ShowPosition() const {
	cout << '[' << xpos << ", " << ypos << ']' << endl;
}


int main() {
	// Template의 자료형을 명시하지 않으면 문법 오류 발생
	Point<int> pos1(1, 3);
	pos1.ShowPosition();

	Point<double> pos2(2.4, 3.6);
	pos2.ShowPosition();

	Point<char> pos3('P', 'F');
	pos3.ShowPosition();

	return 0;
}
*/


/*
// 2.3	클래스 템플릿의 선언과 정의의 파일 분리

#include "PointTemplate.h"
#include "PointTemplate.cpp"

int main() {
	// Template의 자료형을 명시하지 않으면 문법 오류 발생
	Point<int> pos1(1, 3);
	pos1.ShowPosition();

	Point<double> pos2(2.4, 3.6);
	pos2.ShowPosition();

	Point<char> pos3('P', 'F');
	pos3.ShowPosition();

	return 0;
}
*/

// 2.4	클래스 템플릿 활용

#include "Point.h"
//#include "Point.cpp"
#include "RangeCheckingArray.h"
#include "RangeCheckingArray.cpp"


int main(void) {
	// int 형인 경우
	RangeCheckingArray<int> intArr(3);
	intArr[0] = (1, 2);
	intArr[1] = (3, 4);
	intArr[2] = (5, 6);

	for (int i = 0; i < 3; i++)
		cout << intArr[i] << endl;

	// Point 객체인 경우
	RangeCheckingArray<Point> objArr(3);
	objArr[0] = Point(1, 2);
	objArr[1] = Point(3, 4);
	objArr[2] = Point(5, 6);

	for (int i = 0; i < 3; i++)
		cout << objArr[i] << endl;


	// Point 객체의 주소인 경우
	typedef Point * POINT_PTR;
	RangeCheckingArray<POINT_PTR> objPtrArr(3);
	objPtrArr[0] = new Point(10, 20);
	objPtrArr[1] = new Point(30, 40);
	objPtrArr[2] = new Point(50, 60);

	for (int i = 0; i < objPtrArr.GetArrLen(); i++)
		cout << *(objPtrArr[i]) << endl;

	delete objPtrArr[0];
	delete objPtrArr[1];
	delete objPtrArr[2];

	return 0;
}
