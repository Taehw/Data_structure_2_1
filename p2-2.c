#include <stdio.h>

void print_one(int *ptr, int rows);

int main()
{

    printf("[-----[Tae Hwa Kim]   [2020039079]-----]\n");

    int one[] = {0, 1, 2, 3, 4}; //크키가 5이며 0,1,2,3,4로 초기화된 int형 배열 one 선언
    // 아래 3개의 코드들은 모두 배열 one의 시작주소를 출력한다.
    printf("one = %p\n", one); 
    printf("&one = %p\n", &one);
    printf("&one[0] = %p\n", &one[0]);
    printf("\n");

    //print_one 함수를 호출하여 배열 one의 첫번재 원소의 주소를 인자로 넘겨주고
    //배열 one의 원소들의 주소와 그에 해당하는 값을 확인

    printf("------------------------------------\n");
    printf(" print_one(&one[0], 5) \n"); 
    printf("------------------------------------\n");
    print_one(&one[0], 5);

    //one배열 자체를 인자로 넘겨줌. one 이름자체가 해당 배열의 첫번째 원소의 주소와 같으므로
    //출력결과는 위와 같다.
    printf("------------------------------------\n");
    printf(" print_one(one, 5) \n");
    printf("------------------------------------\n");
    print_one(one, 5);


    return 0;
}

//정수형 배열의 주소와 배열의 크기를 받아와서, 배열의 원소들의 주소와 그에 해당하는 값을 출력하는 함수
//ptr 포인터 변수를 통해 인자로 전달된 배열의 첫 번째 원소의 주소를 참조하며 
//이를 이용하여 배열의 각 원소들의 주소와 값을 출력. 이때 ptr + i는 ptr이 가리키는 메모리 주소에서 i를 더한 값이다. 
//*(ptr + i)는 ptr이 가리키는 메모리 주소에서 i만큼 떨어진 곳에 있는 정수형 변수의 값을 가져온다. 즉, ptr[i]와 같은 의미를 가진다.
void print_one(int *ptr, int rows)
{

    int i;
    printf ("Address \t Contents\n");
    for (i = 0; i < rows; i++)
        printf("%p \t %5d\n", ptr + i, *(ptr + i));
    printf("\n");
}

