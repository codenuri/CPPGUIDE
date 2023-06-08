

// T44. Use function templates to deduce class 
//      template argument types
//     

template<typename T> 
T square(T a)
{
	return a * a;
}

template<typename T> class List
{
public:
	List(int sz, T value) {}
};

// 클래스 템플릿을 직접 사용하면 타입 추론이 되지 않기 때문에 복잡해 보입니다
// 타입추론이 필요하면 함수 템플릿을 도움함수로 만드세요

template<typename T>
List<T> make_list(int size, T value)
{
	return List<T>(size, value);
}

int main()
{
	// 다음중 쉬워 보이는 것은 ?
	square<int>(3);	// 이 표기법이 정확한 표기법
	square(3);      // 타입인자 생략 가능
					// 이경우, 함수 인자를 보고 T의 타입을 컴파일러가 추론
					// 타입 생략이 쉬워 보입니다.

	// 아래 코드를 생각해 봅시다.
	List<int> s1(10, 3); // 정확한 표기법 - 타입 인자 전달
//	List      s2(10, 3); // 생성자 인자를 통한 타입 추론 ??
						 // C++17 이후 부터 가능.
	auto s2 = make_list<int>(10, 3);
}







