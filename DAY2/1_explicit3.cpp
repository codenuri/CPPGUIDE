// 변환 연산자 와 explicit 이야기
// explicit
// 1. 생성자에 붙이기 - C++98 시절 부터 있던 문법
// 2. 변환 연산자에 붙이기 - C++11 부터 가능.
class Point
{
	int x;
	int y;
public:
	Point(int a, int b) : x(a), y(b) {}

	// 변환 연산자 : 객체가 다른 타입으로 변환될때 사용
	// 특징 : 함수 이름에 반환 타입이 포함되어 있습니다.
	//       리턴타입을 별도로 표기 하지 않습니다.
	explicit operator int() { return x; }
};

int main()
{
	Point pt(1, 2);


	int n = pt; // Point => int로 변환
				// pt.operator int() 라는 함수 가 필요.
				// explicit 인 경우 에러(암시적 변환 안됨)

	int n1 = static_cast<int>(pt); // ok..!
}