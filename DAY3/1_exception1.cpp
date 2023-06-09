// C.42: If a constructor cannot construct a valid object, 
//       throw an exception
#include <iostream>
#include <string>

class FileStream
{
	FILE* file;
public:
	// 생성자는 반환 타입이 없고, 값을 반환 할수 없습니다.
	// => 생성자가 실패 했을때 외부에 알릴수 있는 유일한 방법은 예외 입니다.
	FileStream(const std::string& name)
	{
		// name 이 존재 하지 않는다면 ?
		throw std::runtime_error("file not found");
	}
};

int main()
{

}
