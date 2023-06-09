#include <memory>

int main()
{
	// �ٽ� 1. unique_ptr �� �ڿ��� ���� �Ҷ� ���� delete ���� �ʰ�
	//		  ���ø� 2��° ���ڷ� ���� �Լ���ü ����մϴ�.
	std::unique_ptr<int> up(new int); 

					// => std::make_unique<int>() �� �� �����ϴ�.
									

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