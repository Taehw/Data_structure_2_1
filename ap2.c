#include <stdio.h>
#include <stdlib.h>
void main()
{
    int list[5]; // 크기가 5인 정수형 배열 list 선언
    int *plist[5]; // 크기가 5인 정수형 포인터 배열 plist 선언

    list[0] = 10;
    list[1] = 11;

    plist[0] = (int*)malloc(sizeof(int)); //plist 배열의 첫번째 요소에 int타입의 크기만큼 동적으로 메모리를 할당

    printf("[-----[Tae Hwa Kim]   [2020039079]-----]\n");

    printf("list[0] \t= %d\n", list[0]);   //list[0]의 값을 출력   
    printf("list \t\t= %p\n", list); //list 배열의 이름으로써 첫번째 요소의 주소값을 추력
    printf("&list[0] \t= %p\n", &list[0]); //list[0]이 가리키는 주소값을 출력. 위와 동일.
    printf("list + 0 \t= %p\n", list+0); //list+0은 list첫번째 요소의 주소를 나타내므로 list[0]의 주소값을 출력한다.
    printf("list + 1 \t= %p\n", list+1); //list+1은 list두번째 요소의 주소를 나타내므로 list[1]의 주소값을 출력한다.
    printf("list + 2 \t= %p\n", list+2); //list+2는 list세번째 요소의 주소를 나타내므로 list[2]의 주소값을 출력한다.
    printf("list + 3 \t= %p\n", list+3); //list+3은 list네번째 요소의 주소를 나타내므로 list[3]의 주소값을 출력한다.
    printf("list + 4 \t= %p\n", list+4); //list+4는 list다섯번째 요소의 주소를 나타내므로 list[4]의 주소값을 출력한다.
    printf("&list[4] \t= %p\n", &list[4]); //list[4]의 주소값을 출력
    
    free(plist[0]); //plist 배열의 첫번째 요소에 동적으로 할당된 메모리 해제
}