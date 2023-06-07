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