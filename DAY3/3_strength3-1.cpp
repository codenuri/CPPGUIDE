#include <memory>

int main()
{
	// 핵심 1. unique_ptr 이 자원을 삭제 할때 직접 delete 하지 않고
	//		  템플릿 2번째 인자로 받은 함수객체 사용합니다.
	std::unique_ptr<int> up(new int); 

					// => std::make_unique<int>() 가 더 좋습니다.
									

	std::default_delete<int> p;
}

template <class _Ty>
struct default_delete { // default deleter for unique_ptr
    constexpr default_delete() noexcept = default;

    template <class _Ty2, enable_if_t<is_convertible_v<_Ty2*, _Ty*>, int> = 0>
    default_delete(const default_delete<_Ty2>&) noexcept {}

    void operator()(_Ty* _Ptr) const noexcept 
    { 
        static_assert(0 < sizeof(_Ty), "can't delete an incomplete type");
        
        delete _Ptr;
    }
};