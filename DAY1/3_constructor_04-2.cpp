#include <iostream>

// Base-from-Member

class Buffer
{
	char* buff;
public:
	Buffer(int size) : buff(new char[size])
	{
		std::cout << "버퍼 크기 " << size << "로 초기화" << std::endl;
	}
	~Buffer() { delete[] buff; }

	void useBuffer() { std::cout << "버퍼 사용" << std::endl; }
};

class Stream
{
public:
	Stream(Buffer& buf) { buf.useBuffer(); }
};
//---------------------------------------------

// PipeStream 이 사용할 버퍼를 가진 기반 클래스
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




