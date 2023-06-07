// F16 ~ F20  ( 10 page ~)
// F.16 : For "in" parameters, pass cheaply - copied types by value and others by reference to const
// F.17 : For "in-out" parameters, pass by reference to non - const
// F.18 : For "will-move-from" parameters, pass by X&& and std::move the parameter
// F.19 : For "forward" parameters, pass by TP&& and only std::forward the parameter
// F.20 : For "out" output values, prefer return values to output parameters

// 강석민 강사
// smkang @ codenuri.co.kr
// 
// 1. github.com/codenuri/CPPGUIDE
//    에서 DAY1.zip 받으시면 됩니다.

// 2. 주요 내용 : C++ 로 코딩을 작성시 지켜야하는
//             다양한 규칙들..
// 
// => 출처 : "C++ Core guideline" => 구글 검색

// 3. 실습 환경 : visual studio community
//				2019, 2022, 
//				g++은 되도록 최신 버전 권장
//-----------------------------------------
// 1. DAY1.zip 압축 풀러 보세요
// 2. DAY1.sln 파일을 VS 에서 열어 보세요
// 
// 3. 버전 설정해야 합니다.
//    => 프로젝트 메뉴, 속성 메뉴
//    => Ctrl + F5로 빌드 문제 없는지 확인해 보세요

// 4. 파일을 빌드에서 제외/추가 하는 방법