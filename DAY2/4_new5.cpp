#include <iostream>
#include <type_traits>

class Point
{
	int x;
	int y;
public:
	// Point �� ����Ʈ �����ڰ� �����ϴ�.
	Point(int a, int b) : x(a), y(b) {}
	~Point() {}
};

// STL �� vector �� ������ ���ô�.
template<typename T> class vector
{
	T* buff;
	int size;
public:
	vector(int sz) : size(sz)
	{
		buff = static_cast<T*>(operator new(sizeof(T) * size));

		for (int i = 0; i < size; i++)
		{
			new(&buff[i]) T; 
		}
	}
	vector(int sz, const T& value) : size(sz)
	{
		buff = static_cast<T*>(operator new(sizeof(T) * size));

		for (int i = 0; i < size; i++)
		{
			new(&buff[i]) T(value); 
		}
	}
	~vector()
	{
		for (int i = 0; i < size; i++)
			buff[i].~T();
		operator delete(buff);
	}

	vector(const vector& other) : size(other.size)
	{
		// 1. �޸� �Ҵ�
		//buff = new T[size]; // �����ڵ�..	 �޸� �Ҵ� + ����Ʈ ������ ȣ��
							// �׷���, �Ʒ� �ڵ忡�� �ᱹ �������(�Ǵ� memcpy)�ϰ� �˴ϴ�.

		buff = static_cast<T*>(operator new(sizeof(T) * size));


		// 2. other.buff �� this->buffer �� �����ؾ� �մϴ�.
		//    �ּ��� �ڵ�� ????
		if (std::is_trivially_copy_constructible_v<T>)
		{
			memcpy(this->buff, &(other.buff), sizeof(T) * size); //???
		}
		else
		{
			for( int i =0 ; i < size; i++)
			{
				new(&buff[i]) T(other.buff[i]);
			}
		}
	}
};
// C++ �������� ���� �Ʒ� 2�� �� ��� �˴ϴ�.
// bitwise copy     : �� �ڵ忡�� memcpy ����
// member wise copy : �� �ڵ忡�� �Ʒ� �ڵ�(�� ��� ���� ����(���� ������ ���))




int main()
{
	vector<Point> v1(5, Point(0, 0));

	vector<Point> v2 = v1; // ���� �����ڸ� ������ ���ô�.
}