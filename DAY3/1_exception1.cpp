// C.42: If a constructor cannot construct a valid object, 
//       throw an exception
#include <iostream>
#include <string>

class FileStream
{
	FILE* file;
public:
	// �����ڴ� ��ȯ Ÿ���� ����, ���� ��ȯ �Ҽ� �����ϴ�.
	// => �����ڰ� ���� ������ �ܺο� �˸��� �ִ� ������ ����� ���� �Դϴ�.
	FileStream(const std::string& name)
	{
		// name �� ���� ���� �ʴ´ٸ� ?
		throw std::runtime_error("file not found");
	}
};

int main()
{

}
