// 없어도 되지만, 안전하고 성능 코드를 위해서 필요한 기법들
// 1. [[nodiscard]]

template<typename T>
const T& max1(const T& lhs, const T& rhs)
{
	return lhs < rhs ? rhs : lhs;
}

// [[ ]]  : attribute 문법
//          C++ 컴파일러에게 지시하는 문법
template<typename T>
[[nodiscard]]
const T& max2(const T& lhs, const T& rhs)
{
	return lhs < rhs ? rhs : lhs;
}

int main()
{
	// 함수 호출후 결과를 받지 않고 있다..
	max1(1, 2);	
	max2(1, 2);
}