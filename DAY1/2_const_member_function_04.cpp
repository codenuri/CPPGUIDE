#include <iostream>

class Test
{
	int value;
public:
	Test(int value) : value(value) {}

	void f1()			// void f1(Test* this)
	{
		int* p = &value; // ok
	}

	void f2() const		// void f2(const Test* this)
	{
//		int* p = &value; // error
				// &(this->value) �ε�.. this �� const* 

		const int* p1 = &value; // ok

//		int* p1 = static_cast<int*>(&value); // error. ��������žȵ�
		int* p1 = const_cast<int*>(&value);  // ok
		int* p2 = &(const_cast<Test*>(this)->value);  // ok
	}

};

int main()
{
	Test t(10);
	t.f1();
}


