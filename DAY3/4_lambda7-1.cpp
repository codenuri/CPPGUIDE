
int main()
{
	auto swap1 = [](auto& a, auto& b) { auto c = a; a = b; b = c; };

	int n1 = 10;
	double d1 = 3.4;

	swap1(n1, d1); // �Ǵ°� ������� ? ������ ������� ?
}