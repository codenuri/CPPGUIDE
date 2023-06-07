#include <iostream>

// Base-from-Member

class Buffer
{
	char* buff;
public:
	Buffer(int size) : buff(new char[size])
	{
		std::cout << "���� ũ�� " << size << "�� �ʱ�ȭ" << std::endl;
	}
	~Buffer() { delete[] buff; }

	void useBuffer() { std::cout << "���� ���" << std::endl; }
};

class Stream
{
public:
	Stream(Buffer& buf) { buf.useBuffer(); }
};
//---------------------------------------------

// PipeStream �� ����� ���۸� ���� ��� Ŭ����
class PipeBuffer
{
protected:
	Buffer buffer{ 1024 };
};

class PipeStream : public PipeBuffer,  public Stream
{
public:
	PipeStream() : Stream(buffer) // : PipeBuffer(), Stream(buffer)
	{
	}
};

int main()
{
	PipeStream ps;
}




