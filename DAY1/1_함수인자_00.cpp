// F16 ~ F20  ( 10 page ~)
// F.16 : For "in" parameters, pass cheaply - copied types by value and others by reference to const
// F.17 : For "in-out" parameters, pass by reference to non - const
// F.18 : For "will-move-from" parameters, pass by X&& and std::move the parameter
// F.19 : For "forward" parameters, pass by TP&& and only std::forward the parameter
// F.20 : For "out" output values, prefer return values to output parameters

// ������ ����
// smkang @ codenuri.co.kr
// 
// 1. github.com/codenuri/CPPGUIDE
//    ���� DAY1.zip �����ø� �˴ϴ�.

// 2. �ֿ� ���� : C++ �� �ڵ��� �ۼ��� ���Ѿ��ϴ�
//             �پ��� ��Ģ��..
// 
// => ��ó : "C++ Core guideline" => ���� �˻�

// 3. �ǽ� ȯ�� : visual studio community
//				2019, 2022, 
//				g++�� �ǵ��� �ֽ� ���� ����
//-----------------------------------------
// 1. DAY1.zip ���� Ǯ�� ������
// 2. DAY1.sln ������ VS ���� ���� ������
// 
// 3. ���� �����ؾ� �մϴ�.
//    => ������Ʈ �޴�, �Ӽ� �޴�
//    => Ctrl + F5�� ���� ���� ������ Ȯ���� ������

// 4. ������ ���忡�� ����/�߰� �ϴ� ���