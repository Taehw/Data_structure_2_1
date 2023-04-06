#include <stdio.h>
#include <string.h>

struct student1 //성과 학번 이름을 멤버변수로 가지는 구조체 student1 선언
{
    char lastName;
    int studentId;
    char grade;
};

typedef struct //typedef를 이용해 구조체 student1과 동일한 멤버변수를 가지는 구조체 student2 선언
{
    char lastName;
    int studentId;
    char grade;
} student2;


int main()
{
    printf("[-----[Tae Hwa Kim]   [2020039079]-----]\n");
    //student1 구조체의 변수 st1을 선언하고 초기화, 초기화할때 사용되는 값들은 멤버변수에 순서대로 대입
    //이후 st1 구조체 변수의 해당 멤버변수 값을 차례대로 출력
    struct student1 st1 = {'A', 100, 'A'};  
    printf("st1.lastName = %c\n", st1.lastName);
    printf("st1.studentId = %d\n", st1.studentId);
    printf("st1.grade = %c\n", st1.grade);

    //student2 구조체의 변수 st2을 선언하고 초기화, 초기화할때 사용되는 값들은 멤버변수에 순서대로 대입
    //이후 st2 구조체 변수의 해당 멤버변수 값을 차례대로 출력(student1의 멤버변수와 동일하나 초기화된 값이 다르므로 출력결과는 다름)
    student2 st2 = {'B', 200, 'B'};
    printf("\nst2.lastName = %c\n", st2.lastName);
    printf("st2.studentId = %d\n", st2.studentId);
    printf("st2.grade = %c\n", st2.grade);

    //student2 구조체의 변수 st3을 선언
    student2 st3;
    st3 = st2; //st2 구조체 변수의 값을 st3에 복사, 아래의 값들은 위의 st2 구조체 변수의 각 멤버변수 값과 동일하게 나온다
    printf("\nst3.lastName = %c\n", st3.lastName);
    printf("st3.studentId = %d\n", st3.studentId);
    printf("st3.grade = %c\n", st3.grade);

    /* equality test */
    if (memcmp(&st3, &st2, sizeof(student2)) == 0) 
    //<string.h>헤더파일에 정의된 memcmp()함수를 사용하여 두 구조체 변수의 멤버변수들이 모두 같은지를 확인
    //st3와 st2는 student2의 구조체 변수이므로 멤버변수가 모두 같다. 그러므로 출력값은 equal이 된다.
        printf("equal\n");
    else
        printf("not equal\n");
    return 0;
}