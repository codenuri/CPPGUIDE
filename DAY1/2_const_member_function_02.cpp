// 상수 멤버 함수는 선택이 아닌 필수 입니다.
// => 아래 get_area() 는 반드시 상수 멤버함수로 했어야 합니다.

// 객체의 상태를 변경하지 않은 모든 멤버함수(getter) 는
// 
// "반드시" 상수 멤버 함수가 되어야 합니다.
class Rect
{
	int x, y, w, h;
public:
	Rect(int x, int y, int w, int h) : x{ x }, y{ y }, w{ w }, h{ h } {}

	//int get_area() { return w * h; } // wrong
	int get_area() const { return w * h; } // good!
};

//void foo(Rect r) // call by value => 복사본 생성, 나쁜 코드!!
void foo(const Rect& r) // good
{
	int n = r.get_area(); // ???
}

int main()
{
	Rect r(1, 2, 3, 4);   // 상수 객체 아님..
	int n = r.get_area(); // ok. 
	foo(r);
}