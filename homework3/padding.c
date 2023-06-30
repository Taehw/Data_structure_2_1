#include <stdio.h>

//성과 학번 학년을 멤버변수로 가지는 student 구조체 선언
struct student 
{
    char lastName[13]; //배열의 크기가 13인 char형 배열 선언
    int studentId;     
    short grade;       
};

int main()
{

    printf("[-----[Tae Hwa Kim]   [2020039079]-----]\n");

    struct student pst; //student의 구조체 변수 pst를 선언

    printf("size of student = %ld\n", sizeof(struct student)); 
    //student 구조체의 크기를 출력 char 배열의 크기인 13+padding 3, int의 크기 4, short의 크기 2+padding 2
    //16+4+4인 24가 출력된다.
    printf("size of int = %ld\n", sizeof(int));  //int 자료형의 크기인 4를 출력
    printf("size of short = %ld\n", sizeof(short)); //short 자료형의 크기인 2를 출력
    
    return 0;   
}