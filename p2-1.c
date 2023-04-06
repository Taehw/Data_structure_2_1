#include <stdio.h>

#define MAX_SIZE 100 

float sum1(float list[], int);
float sum2(float *list, int);
float sum3(int n, float *list);

float input[MAX_SIZE], answer;
int i;

void main(void)
{
    //input 배열에 0부터 MAX_size-1까지의 값을 할당
    for(i=0; i < MAX_SIZE; i++)
        input[i] = i;

    printf("[-----[Tae Hwa Kim]   [2020039079]-----]\n");

    //아래 코드에서는 3개의 함수 sum1(), sum2(), sum3()를 호출하여 각각의 함수가 전달 받은 배열의 합을 계산

    printf("--------------------------------------\n");
    printf(" sum1(input, MAX_SIZE) \n"); //input배열과 배열의 크기를 인자로 줌
    printf("--------------------------------------\n");
    printf("input \t= %p\n", input); 

    answer = sum1(input, MAX_SIZE); //함수 sum1()이 반환한 결과를 answer변수에 저장
    printf("The sum is: %f\n\n", answer); //input배열의 원소를 모두 더한값, 즉 0부터 99까지으 합인 4950을 반환 아래는 모두 이와 같다.

    printf("--------------------------------------\n");
    printf(" sum2(input, MAX_SIZE) \n"); //위와 동일하게 input배열과 배열의 크기를 인자로줌
    printf("--------------------------------------\n");
    printf("input \t= %p\n", input);

    answer = sum2(input, MAX_SIZE); //함수 sum2()가 반환한 결과를 answer변수에 저장
    printf("The sum is: %f\n\n", answer); 

    printf("--------------------------------------\n");
    printf(" sum3(MAX_SIZE, input) \n"); //인자를 전달하는 순서를 바꿔서 배열의 크기와 배열을 전달
    printf("--------------------------------------\n");

    printf("input \t= %p\n", input); 
    answer = sum3(MAX_SIZE, input); //함수 sum3()가 반환한 결과를 answer변수에 저장
    printf("The sum is: %f\n\n", answer);
}

float sum1(float list[], int n) //함수 sum1()은 배열을 값으로 받음
{
    printf("list \t= %p\n", list);
    printf("&list \t= %p\nin", &list);

    int i;
    float tempsum = 0;
    for(i = 0; i < n; i++)
        tempsum += list[i]; //list 배열의 원소의 값을 모두 더하여 tempsum에 저장하고 반환한다. 이때 input배열의 원소의 합인 4959이 저장
    return tempsum;
}

float sum2 (float *list, int n) //함수 sum2()는 포인터를 이용하여 배열을 전달받음.
{
    printf("list \t= %p\n", list);
    printf("&list \t= %p\n\n", &list);
    
    int i;
    float tempsum = 0;
    for (i = 0; i < n; i++)
        tempsum += *(list + i); //*(list + i)는 포인터가 가리키는 값을 참조하므로 위와 동일하게 input배열안의 값들이 tempsum에 저장된다.
    return tempsum;
}

/* stack variable reuse test */ 
float sum3(int n, float *list) // 매개변수의 순서가 달라지면서 스택에 쌓인 변수위치도 달라지므로 리스트의 주소값이 달라진다.
{
    printf("list \t= %p\n", list);
    printf("&list \t= %p\n\n", &list);

    int i;
    float tempsum = 0;
    for (i = 0; i < n; i++)
        tempsum += *(list + i);
    return tempsum;
}
