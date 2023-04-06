#include <stdio.h>
#include <stdlib.h>

void main()
{
    int list[5]; //크기가 5인 정수형 배열을 선언
    int *plist[5] = {NULL,}; //크기가 5인 정수형 포인터 배열을 선언하고 모두 NULL로 초기화


    plist[0] = (int *)malloc(sizeof(int)); //plist 배열의 첫번째 요소에 int타입의 크기만큼 동적으로 메모리를 할당


    list[0] = 1; 
    list[1] = 100;

    *plist[0] = 200; //plist 배열의 첫번째 요소가 가리키는 메모리 공간에 200을 저장

    printf("[-----[Tae Hwa Kim]   [2020039079]-----]\n");

    printf("list[0] = %d\n", list[0]); //list의 첫번째 요소의 값 출력
    printf("&list[0] = %p\n", &list[0]); //list의 첫번째 요소의 주소값 출력
    printf("list = %p\n", list); //list 배열의 이름으로써 list배열의 첫번째 요소의 주소값을 출력
    printf("&list = %p\n", &list); //위의 이유와 동일

    printf("----------------------------------------\n\n");
    printf("list[1] = %d\n", list[1]); //list의 두번째 요소의 값을 출력
    printf("&list[1] = %p\n", &list[1]); //list의 두번째 요소의 주소값을 출력
    printf("*(list+1) = %d\n", *(list + 1)); //*(list+1)은 list+1이 가리키는 주소에 저장된 값을 가리키는 포인터이므로, 배열에서 두 번째 요소의 값을 출력
    printf("list+1 = %p\n", list+1); //list+1이 가리키는 주소값을 출력, list의 두번째 요소의 주소값을 출력

    printf("----------------------------------------\n\n");
    printf("*plist[0] = %d\n", *plist[0]); //plist[0]이 가리키는 주소에 있는 값을 출력, 앞에서 plist[0]의 메모리 주소에 200을 대입했으므로 출력값은 200.
    printf("&plist[0] = %p\n", &plist[0]); //plist[0]의 주소값을 출력
    printf("&plist = %p\n", &plist); //plist의 시작 주소를 의미하므로, 위와 동일하게 plist[0]의 주소값을 출력
    printf("plist = %p\n", plist); //plist 배열의 값, 즉 첫 번째 요소인 plist[0]의 주소를 출력. plist는 배열의 첫번째 주소를 가리키는 포인터 상수
    printf("plist[0] = %p\n", plist[0]); 
    //plist[0]이 가리키는 주소를 출력.  위에서 plist[0]에 메모리를 할당한 후, 그 주소를 가리키게 되었으므로, 출력값은 동적으로 할당한 메모리의 주소입니다.
    printf("plist[1] = %p\n", plist[1]);
    printf("plist[2] = %p\n", plist[2]);
    printf("plist[3] = %p\n", plist[3]);
    printf("plist[4] = %p\n", plist[4]);
    //plist[1]부터 plist[4]까지는 모두 NULL값을 가리키므로 모두 0이 출력

    free(plist[0]);
    // plist 배열의 첫 번째 요소가 가리키는 메모리를 해제

}