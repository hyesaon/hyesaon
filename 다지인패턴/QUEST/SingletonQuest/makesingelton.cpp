#include "makesingelton.h"

template<typename classname>
classname* makesingelton<classname>::m_This = NULL;	//이 선언이 없으면 m_This가 정의되지 않은것으로 간주된다.
//그러나 헤더에 쓰면 재정의 오류가 뜬다. cpp에 정의해줘야함
//c++에서 static변수는 객체기반이 아니라 클래스기반. >>클래스 내부에서 선언하고 초기화하면 클래스만들때마다 초기화 되어서 안된다.
//전역변수와 비슷한 성질을 지니고있기 때문에 main문에 들어가기전에 할당이된다(데이터영역)
