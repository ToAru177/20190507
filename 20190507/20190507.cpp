//#include <iostream>
//#include <cstring>
//
//using namespace std;

/*
	
	���ø�(Template)

	1.	���ø��� �ǹ�
		����(����) -> ������

		���ݱ��� �츮�� �ڵ��ϴ� ����� ������ ���� ���� �ڵ� �� ������ �ؼ� �����Ŵ.

		�׷���, ��ü���⿡�� ��ü�� ������,
		Ŭ������ ������� ��ü�� �����ؼ� ����Կ�����
		Ŭ������ ��ü�� ���� Ʋ�̶�� ���� �� ������,
		Template������ Ʋ���� �ٸ�.

		��	�������� Ư��
			������ Ʋ�� �̹� ���� �Ǿ� ������, ������ ���� ���� �Ǿ� ���� �ʾ�, ���� �����ؾ� ��.

			��ü���⿡���� ���ø� -> �Լ� ���ø�
			
		��	�Լ� ���ø��� Ư��
				-	�Լ� ���ø��� ����� �Լ��� ����� ��.
				-	�ڷ����� �����Ǿ� ���� �ʾƼ�, ���� �ڷ����� �����ؾ� ��.

				// �Ϲ����� �Լ�
				int Add(int num1, int num2)
				{
					return num1 + num2;
				}

				// �Լ� ���ø�
				template <typename T>			// T��� �̸��� �̿��ؼ� �Ʒ��� �Լ� ���ø����� ���� �Ѵٴ� �ǹ�.
				T Add(T num1, T num2)
				{
					return num1 + num2;
				}

				int�� ������ T�� �������. �̴� �ڷ����� �������� ���� ����������,
				���߿� T�� ����ؼ� ���� �ڷ����� �����ϰڴٴ� �ǹ� ��.

		1.1 �Լ� ���ø� ����

		1.2	�Ϲ� �Լ��� �Լ� ���ø��� ���� �ִ� ���
			�ϳ��� �ڵ忡 �Ϲ��Լ��� �Լ� ���ø��� �Բ� ����ϴ��� ���������� ������ �Ǿ� ��� ����.
			������, �Լ� ���ø��� ������ ��Ȳ���� ������ ����� �Ϲ� �Լ����� �����ϴ� ���� ���� ����.

		1.3	���� �ٸ� ��(Type)�� ���� �Լ� ���ø� ����

		1.4	�Լ� ���ø��� Ư��ȭ(Specialization)

	2.	Ŭ���� ���ø�
		�Լ� ���ø�ó�� Ŭ������ ���ø����� ���ǰ� ����.
		Ŭ���� ���ø��� ������� �����Ϸ��� ����� ���� Ŭ������ "���ø� Ŭ����"��� ��.

		2.1	Ŭ���� ���ø� �⺻ ����

		2.2	Ŭ���� ���ø��� ����� ������ �ڵ� �и�

		2.3	Ŭ���� ���ø��� ����� ������ ���� �и�

		2.4	Ŭ���� ���ø� Ȱ��

*/

/*
// 1.1 �Լ� ���ø� ����

// �Լ� ���ø�
template <typename T>
T Add(T num1, T num2) {
	return num1 + num2;
}

// ���ø� �Լ�(������ �Լ�, Generated Function)
// �Լ� ���ø��� ������� �����ϵ� �� ������� �Լ�.
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
// 1.2	�Ϲ� �Լ��� �Լ� ���ø��� ���� �ִ� ���

template <typename T>
T Add(T num1, T num2) {
	cout << "T Add() ȣ�� ��" << endl;
	return num1 + num2;
}

int Add(int num1, int num2) {
	cout << "int Add() ȣ�� ��" << endl;
	return num1 + num2;
}

double Add(double num1, double num2) {
	cout << "double Add() ȣ�� ��" << endl;
	return num1 + num2;
}

int main(void) {

	cout << Add(10, 20) << endl;					// int Add() ȣ��
	cout << Add(10.5, 20.2) << endl;				// double Add() ȣ��
	cout << Add<int>(11, 22) << endl;				// T Add() ȣ��
	cout << Add<double>(11.222, 22.111) << endl;	// T Add() ȣ��

	return 0;
}
*/

/*
// 1.3	���� �ٸ� ��(Type)�� ���� �Լ� ���ø� ���� ����
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

// 1.4	�Լ� ���ø��� Ư��ȭ(Specialization) ����

/*
// 1.4.1 Ư��ȭ �ϱ��� ������ �ִ� ����.
// �Ʒ��� �ڵ�� ���������� ������ ������,
// ������ ��ɻ� ������ ����.
// �̷��� ������ �ذ��ϴ� ����� Ư��ȭ ��.
template <typename T>
T Max(T a, T b) {
	return a > b ? a : b;
}

int main() {

	cout << Max(11, 12) << endl;			// ������ ���� �������� ��.
	cout << Max('T', 'Q') << endl;			// ������ ���� �������� ��.
	cout << Max("Simple", "Best") << endl;	// const char * => �ּҸ� �������� ��.

	return 0;
}
*/

/*
// 1.4.2 �������� ������ Ư��ȭ ����
template <typename T>
T Max(T a, T b) {
	// ������ 1 : ���ڿ� ���̸� �Ǵ��ϴ� ����??
	// ������ 2 : ���������� �Ǵ��ϴ� ����??
	return a > b ? a : b;
}

// �Ű������� ���ڿ� -> ������ ����� ���ڿ�
// char* �� �Լ��� �̷��� ���ø� �ϴ�, char* �� �Լ��� �ʿ��� ��쿡�� ������  ������ ����,
// �Ʒ��� �Լ��� ����ض�� ���� �����Ϸ����� �˷���.
template <>
char* Max(char* a, char* b) {
	cout << "char* Max(char* a, char* b)" << endl;
	return strlen(a) > strlen(b) ? a : b;
}

// �Ű������� ���ڿ� -> ���ڿ� ��ü
// const char* �� �Լ��� �̷��� ���ø� �ϴ�, const char* �� �Լ��� �ʿ��� ��쿡�� ������  ������ ����,
// �Ʒ��� �Լ��� ����ض�� ���� �����Ϸ����� �˷���.
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
// 2.1	Ŭ���� ���ø� �⺻ ����

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
	// Template�� �ڷ����� ������� ������ ���� ���� �߻�
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
//	2.2	Ŭ���� ���ø��� ����� ������ �и�

template <typename T>

class Point {
private:
	T xpos, ypos;

public:
	Point(T x = 0, T y = 0);
	void ShowPosition() const;
};

// ������
template <typename T>
Point<T>::Point(T x, T y) : xpos(x), ypos(y) {	}

// �Լ�
template <typename T>
void Point<T>::ShowPosition() const {
	cout << '[' << xpos << ", " << ypos << ']' << endl;
}


int main() {
	// Template�� �ڷ����� ������� ������ ���� ���� �߻�
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
// 2.3	Ŭ���� ���ø��� ����� ������ ���� �и�

#include "PointTemplate.h"
#include "PointTemplate.cpp"

int main() {
	// Template�� �ڷ����� ������� ������ ���� ���� �߻�
	Point<int> pos1(1, 3);
	pos1.ShowPosition();

	Point<double> pos2(2.4, 3.6);
	pos2.ShowPosition();

	Point<char> pos3('P', 'F');
	pos3.ShowPosition();

	return 0;
}
*/

// 2.4	Ŭ���� ���ø� Ȱ��

#include "Point.h"
//#include "Point.cpp"
#include "RangeCheckingArray.h"
#include "RangeCheckingArray.cpp"


int main(void) {
	// int ���� ���
	RangeCheckingArray<int> intArr(3);
	intArr[0] = (1, 2);
	intArr[1] = (3, 4);
	intArr[2] = (5, 6);

	for (int i = 0; i < 3; i++)
		cout << intArr[i] << endl;

	// Point ��ü�� ���
	RangeCheckingArray<Point> objArr(3);
	objArr[0] = Point(1, 2);
	objArr[1] = Point(3, 4);
	objArr[2] = Point(5, 6);

	for (int i = 0; i < 3; i++)
		cout << objArr[i] << endl;


	// Point ��ü�� �ּ��� ���
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
