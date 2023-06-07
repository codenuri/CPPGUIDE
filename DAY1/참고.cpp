// ���� ���� ����� ������.. C/C++�� ����Ʈ�� ���� �Դϴ�.

auto n = 10;		// R/W ����
const auto c = 10;	// R ������


// => �Ųٷ� �����ϸ� ���� ? 
// => �Լ��� ���� rust �� ä���� ���, �Ʒ� �ڵ�� rust
let c = 10;		// R�� ����
let mut n = 10; // R/W ����

// C++ ��� �Լ��ȿ����� R/W �����մϴ�.(����Ʈ)
// Read �� �Ϸ��� const �� ���Դϴ�.
class Test
{
	void mf1() {}       // R/W ����
	void mf1() const {} // R  ����
	
	// �Ųٷ� �����ظ� ���� ? - Swift �� ����
	void mf1() {}     // R�� ����
	void mf1() mut {} // R/W ����
};

// move�� ������, C++�� ����Ʈ�� ���� �Դϴ�.
std::string s = "hello";

std::string s1 = s;				// copy
std::string s2 = std::move(s);	// move

// ������ �Ųٷ� �ϸ� => �Ʒ� �ڵ尡 rust �Դϴ�.
let s : String = "hello";

let s1 = s;         // move
let s2 = s.clone(); // copy