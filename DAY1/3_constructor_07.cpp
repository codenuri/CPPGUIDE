class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b) {  }

	// 아무 일도 하지 않은 디폴트 생성자를 만드는 방법
	
	// 1. 사용자가 직접 만든다. - bad
	// Point() {}

	// 2. 컴파일러에게 요청한다. - good
	Point() = default;

	// 항상 사용자가 직접 만드는 것 보다는 
	// 가능하면 컴파일러가 만드는 것이 좋습니다.
};

int main()
{
	Point p1(1, 2); // ok

	Point p2; // ??
}