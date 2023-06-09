#include <iostream>
#include <array>
#include <vector>

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 }; 

	// SL03. 잘못된 인덱스를 사용하지 말라.
	// v[10] = 0; // ??


	// vector 사용시. [], at()

	// 아래 2줄의 의미는 동일합니다.
	v.at(3) = 10; // 잘못된 인덱스 전달시 예외 발생
	v[3] = 10;    // 잘못된 인덱스 전달했는지 조사 안함.(빠르다.)
					// 단, 잘못된 인덱스 전달시.. 잘못된 메모리 참조. 


	try
	{
		v.at(15) = 100; // 예외 발생
	//	v[15] = 100;	// 예외 없음. 잘못된 메모리 참조!!!
	}
	catch (std::out_of_range& e)
	{
		std::cout << e.what() << std::endl;
	}

	// 다음중 좋은 코드는 ?
	auto sz = v.size();

	for (int i = 0; i < sz; i++)
	{
		// i 가 잘못될 확률이 없습니다.
		// 인덱스 조사할 필요 없습니다.
		v.at(i) = 10;	// bad.. 
		v[i] = 10;		// good
	}
}



