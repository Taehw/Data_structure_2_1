#include <stdio.h>
int main()
{
int i, *p; //변수 i 와 포인터 p 선언

i = 10; // 정수형 변수 i를 10으로 초기화 

printf("value of i = %d\n", i);  //i의 값을 출력
printf("address of i = %p\n", &i); //i의 주소값을 출력
printf("value of p = %p\n", p); //포인터 p의 값을 출력하는 문장이나 포인터 p가 가리키는 값이 없으므로 00000000(null)을 출력
printf("address of p = %p\n", &p); //포인터 p의 주소값을 출력

p = &i; //p에 i의 주소값을 저장

printf("\n\n----- after p = &i ------------\n\n"); 
printf("value of p = %p\n", p);     // i의 주소값이 할당된 p의 값을 출력
printf("address of p = %p\n", &p);  // i의 주소값이 할당된 p의 주소를 출력
printf("dereferencing *p = %d\n", *p); //간접참조 연산자를 사용하여 p가 저장한 주소가 가리키는 i의 값을 출력
return 0;
}

/*pointer-test.c는 주소연산자인 '&'를 사용하여 해당 값의 메모리 주소를 출력해보고 
간접 참조 연산자인 '*'을 사용하여 변수에 할당된 메모리 주소를 활용하는 방법을 알아보는 등
c에서 사용되는 포인터의 기초적인 사용법을 다루고 있는 프로그램입니다. */