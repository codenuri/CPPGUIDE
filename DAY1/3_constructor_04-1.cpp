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
// Stream �� ��� ����� ���� �޾Ƽ� IPC ����� �ϴ� Ŭ����
class PipeStream : public Stream
{
	Buffer buffer{ 1024 };
public:
	PipeStream() : Stream(buffer)
	{
	}
};

int main()
{
	PipeStream ps;
}




