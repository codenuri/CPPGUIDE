#include <iostream>
#include <string>

void f1(int  arg) {}
void f2(int& arg) { arg = 100; }


template<typename F, typename T>
void forward_argument(F f, T&& arg)
{
	f( std::forward<T>(arg) );
}

int main()
{
	int n = 10;

	forward_argument(f1, 10);
	forward_argument(f2, n);
	const int c = 10;
	forward_argument(f1, c);
}


