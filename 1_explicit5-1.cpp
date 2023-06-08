// 1_explicit5-1.cpp
class istream
{
public:
	bool fail() { return true; }

	explicit operator bool() { return fail() ? false : true; }
};
istream cin;
 
int main()
{
	bool b1 = cin;
	bool b2 = static_cast<bool>(cin);
}