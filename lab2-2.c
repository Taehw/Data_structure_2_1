#include <stdio.h>
int main()
{
int i;  //정수형 변수 i 선언
int *ptr; // 정수를 가리키는 포인터 ptr 선언
int **dptr; //이중포인터 dptr 선언, 이후 코드에서 포인터 ptr의 주소를 저장하게됨
i = 1234; //변수 i에 1234를 대입


printf("[----- [Tae Hwa Kim] [2020039079] -----] \n");

printf("[checking values before ptr = &i] \n"); //포인터 ptr이 i의 주소를 가리키기 전이라고 알려주는 문장
printf("value of i == %d\n", i); //i의 값을 출력
printf("address of i == %p\n", &i); //메모리에 저장된 i의 주소값을 출력
printf("value of ptr == %p\n", ptr); //포인터 p의 값을 출력하는 문장이나 포인터 p가 가리키는 값이 없으므로 00000000(null)을 출력
printf("address of ptr == %p\n", &ptr); //포인터 prt의 주소값을 출력

ptr = &i; /* ptr is now holding the address of i */
printf("\n[checking values after ptr = &i] \n");
printf("value of i == %d\n", i); //i의 값을 출력
printf("address of i == %p\n", &i); //i의 주소값을 출력
printf("value of ptr == %p\n", ptr); //i의 주소값이 할당된 포인터 ptr의 값을 출력-->i의 주소값이 출력됨
printf("address of ptr == %p\n", &ptr); //포인터 ptr의 주소값을 출력
printf("value of *ptr == %d\n", *ptr);  //간접참조 연산자를 활용하여 포인터 ptr에 할당된 i의 주소값이 가리키는 값을 출력

dptr = &ptr; /* dptr is now holding the address of ptr */
printf("\n[checking values after dptr = &ptr] \n"); 
printf("value of i == %d\n", i); //i의 값을 출력
printf("address of i == %p\n", &i); //i의 주소값을 출력
printf("value of ptr == %p\n", ptr); //i의 주소값이 할당된 포인터 ptr의 값을 출력-->i의 주소값이 출력됨
printf("address of ptr == %p\n", &ptr); //포인터 ptr의 주소값을 출력
printf("value of *ptr == %d\n", *ptr); //간접참조 연산자를 활용하여 포인터 ptr에 할당된 i의 주소값이 가리키는 값을 출력-->i의 값인 1234를 출력
printf("value of dptr == %p\n", dptr); //이중포인터 dptr의 값을 출력-->해당 포인터에는 ptr의 주소값이 할당되었으므로 ptr의 주소값을 출력한다
printf("address of dptr == %p\n", &dptr); //dptr의 주소값을 출력
printf("value of *dptr == %p\n", *dptr); //간접참조 연산자를 활용하여 포인터 dptr에 할당된 포인터 ptr의 값, 즉 i의 주소값이 출력됨
printf("value of **dptr == %d\n", **dptr); //**dptr은 *&i로 바꿔 생각할수 있다. 즉 i의 주소값이 가리키는 i의 값인 1234를 출력한다.


//아래코드는 포인터 ptr이 가리키는 i의 값을 1234에서 7777로 변경하는 코드이다. 
//그러므로 기존의 *ptr,**dptr은 i의 값을 출력하였으므로 아래코드들의 모든 출력값은 7777이 된다.
*ptr = 7777; /* changing the value of *ptr */
printf("\n[after *ptr = 7777] \n"); 
printf("value of i == %d\n", i); //
printf("value of *ptr == %d\n", *ptr);
printf("value of **dptr == %d\n", **dptr);


//**dptr = 8888; 또한 위와같이 이중포인터 dptr이 최종적으로 가리키는 i의 값을 8888로 변경하는 코드이다.
//그러므로 위에서 설명한 바와 같이 아래코드들의 출력값 또한 모두 8888이 된다.
**dptr = 8888; /* changing the value of **dptr */
printf("\n[after **dptr = 8888] \n");
printf("value of i == %d\n", i);
printf("value of *ptr == %d\n", *ptr);
printf("value of **dptr == %d\n", **dptr);
return 0;
}

//해당 프로그램은 기존 pointer-test.c에서 진행하였던 포인터의 기초적인 사용법을 다루고 있음과 동시에
//이중포인터를 활용하여 포인터에 접근해 그 값과 주소값을 알아보는 등 포인터에 대해 좀더 심화적인 부분을 다루고 있는 프로그램이다