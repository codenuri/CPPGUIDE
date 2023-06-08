// C46.인자가 한개인 생성자는 explicit 로 하는 것이 좋다.
// => 안전성 safety..

class Vector
{
public:
	// explicit 생성자 
	// 1. 직접 초기화만 가능하고, 복사 초기화는 사용할수 없다.
	// 2. 변환의 용도로 사용될수 없다.
	explicit Vector(int sz) {}
};

void fn(Vector v) {} // 인자를 받는 것은 "Vector v = 10" 의 코드입니다.

int main()
{
	// 핵심 1. 인자가 한개인 생성자가 있다면 아래 4가지 형태로
	// 객체 생성이 가능합니다.
	Vector v1(10);		// C++98  direct initialization
	Vector v2 = 10;		// C++98  copy   initialization
	Vector v3{ 10 };	// C++11  direct initialization
	Vector v4 = { 10 };	// C++11  copy   initialization

	// 핵심 2. 인자가 한개인 생성자는 변환의 용도로도 사용가능합니다.
	Vector v5(1);
	v5 = 10;	// int 인 10일 vector 로 변환 가능해야 합니다.
				// 10 => Vector 로 변환 되어야 한다.
				// 10을 생성자로 보내서 Vector 임시객체를 생성후 v5에 대입

	// 핵심 3. 복사 초기화는 버그의 원인이 되곤합니다.
	fn(10);
}




