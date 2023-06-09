// SL.con.1: Prefer using STL array or vector instead of a C array
// SL.con.2: Prefer using STL vector by default unless 
//           you have a reason to use a different container
// SL.con.3: Avoid bounds errors - [] vs at()

#include <iostream>
#include <array>
#include <vector>

// 예전에 만들어 놓았던 함수. 인자로 배열 주소와 갯수를 받는다.
void foo(int* p, int sz) {}

int main()
{
	int x[10]          = { 1,2,3,4,5,6,7,8,9,10 }; // 배열은 크기 변경 안됨 
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 }; // 크기 변경 가능.

	// 배열 과 vector : 모두 연속된 메모리 사용.
	// 단, vector 는 크기 변경가능. 
	
	foo(x, 10); // 배열인 경우

	// foo 에 vector 보내기
	//foo(&v, v.size()); // error

	foo(&v[0],    v.size()); // ok.. 예전에 사용하던 기법
	foo(v.data(), v.size()); // ok.. 

	// 배열    : 모든 요소가 stack 에 있다
	// vector : 모든 요소가 heap 에 있다.
	// std::array : raw array 와 완전히 동일한 구조..
	//				하지만 멤버 함수가 있으므로 편리하다.

	std::array<int, 5> arr = { 1,2,3,4,5 };

	int sz = arr.size();
}

template<typename T, int N>
struct array
{
	T buff[N];

	constexpr int size() const { return 5; }

};

