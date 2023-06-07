#include <iostream>

template<typename T> class vector
{
	T* buff;
	int size;
public:
	vector(int sz)
		: buff(new T[sz]), size(sz) {}

	~vector() { delete[] buff; }

//	T& operator[](int idx) { return buff[idx]; }
//	const T& operator[](int idx) const { return buff[idx]; }

	// C++23 부터는 아래 처럼 하면 위2개가 자동생성됩니다.
	template<typename U> 
	decltype(auto) operator[](this U& self, int idx)
	{
		return self.buff[idx];
	}

	// explicit object parameter 장점
	// 1. 한개의 템플릿으로 "동일이름의 const, non-const"모두 제공
	// 2. recursive 가능한 람다 표현식 만들기
	// 3. 캐스팅 없는 CRTP 가능.
};


int main()
{
	int n1 = 0;

	vector<int> v1(10);
	const vector<int> v2(10);

	n1 = v1[0]; // O		
	n1 = v2[0]; // O	
	v1[0] = 10; // O	
	v2[0] = 10; // X	

}