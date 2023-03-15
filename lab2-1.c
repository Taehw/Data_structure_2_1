#include <stdio.h>
int main()
{
char charType;
int integerType;
float floatType;
double doubleType;

printf("[----- [Tae Hwa Kim] [2020039079] -----] \n");

printf("Size of char: %ld byte\n",sizeof(charType)); //char타입형 변수 charType의 크기를 출력
printf("Size of int: %ld bytes\n",sizeof(integerType)); //int 타입형 변수 intergerType의 크기를 출력
printf("Size of float: %ld bytes\n",sizeof(floatType)); //float 타입형 변수 floatTyper의 크기를 출력
printf("Size of double: %ld bytes\n",sizeof(doubleType)); //double 타입형 변수 doubleType의 크기를 출력

printf("-----------------------------------------\n");

printf("Size of char: %ld byte\n",sizeof(char)); //문자형 자료형인 char의 크기를 출력
printf("Size of int: %ld bytes\n",sizeof(int)); //정수형 자료형인 int의 크기를 출력
printf("Size of float: %ld bytes\n",sizeof(float)); //실수형 자료형인 float 크기를 출력
printf("Size of double: %ld bytes\n",sizeof(double)); //실수형 자료형인 double 크기를 출력

printf("-----------------------------------------\n");

//아래 4줄의 코드는 모두 해당자료의 포인터 변수의 크기를 출력하는 코드들이다. 포인터 변수의 크기는 어떤 자료형이든지 간에
//그 값이 모두 동일하므로 4개의 자료형모두 포인터 변수의 값인 4bytes를 출력한다.
printf("Size of char*: %ld byte\n",sizeof(char*)); 
printf("Size of int*: %ld bytes\n",sizeof(int*));
printf("Size of float*: %ld bytes\n",sizeof(float*));
printf("Size of double*: %ld bytes\n",sizeof(double*));


return 0;
}