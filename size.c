#include<stdio.h>
#include<stdlib.h>
void main()
{
    int** x; //이중포인터 x선언

    printf("[-----[Tae Hwa Kim]   [2020039079]-----]\n");

    printf("sizeof(x) = %lu\n", sizeof(x)); 
    //x 자체의 크기를 출력합니다. 이중 포인터는 주소값을 저장하므로, 주소값을 저장하는 데 필요한 크기인 4바이트가 출력
    printf("sizeof(*x) = %lu\n", sizeof(*x));
    //x가 가리키는 포인터 변수의 크기를 출력합니다. 포인터 변수는 주소값을 저장하므로, 주소값을 저장하는 데 필요한 크기인 4바이트가 출력
    printf("sizeof(**x) = %lu\n", sizeof(**x));
    //이중 포인터 변수 x가 가리키는 포인터 변수가 가리키는 int 변수의 크기인 4를 출력합니다.
}