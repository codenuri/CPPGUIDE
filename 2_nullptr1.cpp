// ES.47: Use nullptr rather than 0 or NULL 

int main()
{
	// null 포인터를 사용할때는 0 대신 nullptr 이좋다.
	int* p1 = 0;		// bad
	int* p2 = nullptr;	// good
}
