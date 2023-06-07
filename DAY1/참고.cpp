// 변수 보다 상수가 좋은데.. C/C++은 디폴트가 변수 입니다.

auto n = 10;		// R/W 가능
const auto c = 10;	// R 만가능


// => 거꾸로 생각하면 어떨까요 ? 
// => 함수형 언어와 rust 가 채택한 방식, 아래 코드는 rust
let c = 10;		// R만 가능
let mut n = 10; // R/W 가능

// C++ 멤버 함수안에서는 R/W 가능합니다.(디폴트)
// Read 만 하려면 const 를 붙입니다.
class Test
{
	void mf1() {}       // R/W 가능
	void mf1() const {} // R  가능
	
	// 거꾸로 생각해면 어떨까요 ? - Swift 의 선택
	void mf1() {}     // R만 가능
	void mf1() mut {} // R/W 가능
};

// move가 빠른데, C++은 디폴트가 복사 입니다.
std::string s = "hello";

std::string s1 = s;				// copy
std::string s2 = std::move(s);	// move

// 생각을 거꾸로 하면 => 아래 코드가 rust 입니다.
let s : String = "hello";

let s1 = s;         // move
let s2 = s.clone(); // copy