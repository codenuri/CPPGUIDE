// F.4: If a function might have to be evaluated at compile time, 
//      declare it constexpr
//
// F.5: If a function is very small and time - critical, declare it inline

template<typename T> 
[[nodiscard]] const T& max1(const T& lhs, const T& rhs)
{
	return lhs < rhs ? rhs : lhs;
}

template<typename T> 
[[nodiscard]] inline const T& max2(const T& lhs, const T& rhs)
{
	return lhs < rhs ? rhs : lhs;
}

template<typename T> 
[[nodiscard]] constexpr const T& max3(const T& lhs, const T& rhs)
{
	return lhs < rhs ? rhs : lhs;
}

int main()
{
	int ret1 = max1(1, 2); // 실행시간에 호출..
						   // call max1
	int ret2 = max2(1, 2); // 컴파일 시간에 max2 기계어 치환

	int ret3 = max3(1, 2); // 컴파일 시간에 함수 실행
						   // int ret3 = 2; 의 기계어로 결정
							// 단, 이경우, 컴파일 시간에 할수도 있고
							// 실행시간에 할수도 있습니다.

	constexpr int ret4 = max3(1, 2);  // 이 경우는 항상 컴파일 시간에 수행
}

// 그럼.. 모든 함수를 constexpr 하면 좋지 않나요 ?
// => 화면 출력, 메모리 할당, 파일 열기등은 컴파일 시간에 할수 없습니다.
// => 하지만 inline 치환은 가능합니다.



