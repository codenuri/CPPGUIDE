
int main()
{
	auto swap1 = [](auto& a, auto& b) { auto c = a; a = b; b = c; };

	int n1 = 10;
	double d1 = 3.4;

	swap1(n1, d1); // 되는게 좋을까요 ? 에러가 좋을까요 ?
}