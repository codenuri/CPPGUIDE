class Point
{
	int x{ 0 };
	int y{ 0 };
public:
	explicit Point() = default;

	// 인자가 한개가 아닌 없거나 여러개 있을때도
	// explicit 가능합니다.
	explicit Point(int x, int y) : x{ x }, y{ y } {}
};

void fn(Point pt) {} // Point pt = {1,2}

int main()
{
	// C++11 부터는 아래처럼 함수 인자를 전달해도 됩니다.
	// => 실제로 많이 사용됩니다.
	fn( { 1,2 } );
	fn({}); // 디폴트 생성자가 explicit 가 아니면 ok
			// explicit 라면 error
			// 허용하지 않는 경우가 많습니다.

}


