
int main()
{
	auto swap1 = [](auto& a, auto& b) { auto c = a; a = b; b = c; };

	int    n1 = 10;
	double d1 = 3.4;

	swap1(n1, d1);	// 되는게 좋을까요 ? 에러가 좋을까요 ?
					// 에러 아님.
					// generic lambda(auto인자)는 2개가 서로 다른 템플릿이므로


	// C++20 에서 추가된 "template lambda" 라는 문법.
	auto swap2 = []<typename T>(T& a, T& b) { auto c = a; a = b; b = c; };

	swap2(n1, d1); // error
	swap2(n1, n1); // ok

}