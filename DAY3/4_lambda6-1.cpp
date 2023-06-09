
// F.53: Avoid capturing by reference in lambdas 
//       that will be used non - locally, 
//       including returned, stored on the heap, or passed to another thread

#include <vector>
#include <functional>
#include <vector>

std::function<int(int, int)> f;

void foo()
{
	int num = 10;
	f = [&num](int a, int b) { return a + b + num; };

} // <== 함수 호출이 종료 되었으므로 지역변수 "num" 파괴!!
  // <== 람다표현식 "f" 가 가진 reference 멤버는 dangling reference 가 됩니다.


void goo()
{
	int ret = f(1, 2); // 1 + 2 + num 인데. num 은 이미 파괴됨.
						// 미정의 동작 발생.. 
}

// 람다표현식을 반환하는 함수
// => 이 경우에도 지역변수를 참조 캡쳐하지 마세요.
auto hoo()
{
	int num = 10;
	return [&num](int a, int b) { return a + b + num; };
	
}


int main()
{
	foo();
	goo();


}