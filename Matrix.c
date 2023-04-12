#include <stdio.h>
#include <stdlib.h>

void print_matrix(int row, int columm, int** matrix); //행렬을 출력하는 함수 print_matrix 선언
void free_matrix(int row, int** matrix); //동적할당된 이차원배열을 해제하는 함수 free_matrix 선언
void addition_matrix(int row1, int row2, int columm1, int columm2, int** matrix1, int **matrix2);//행렬의 합을 출력하는 함수 addition_matrix 선언
void subtration_matrix(int row1, int row2, int columm1, int columm2, int** matrix1, int **matrix2);//행렬의 차를 출력하는 함수 subtraction_matrix 선언
void transepose_matrix(int row1, int columm1, int** matrix1); //행렬의 전치행렬을 출력
void multiply_matrix(int row1, int columm1, int row2, int columm2, int** matrix1, int **matrix2); //행렬의 곱을 출력하는 함수 multiply_matrix 선언

int main(void)
{
    int row_A, columm_A, row_B, columm_B, i; //A, B 각각의 행과 열의 개수를 저장한 정수형 변수 row_A, columm_A, row_B, columm_B 선언

    printf("[----- [Taehwa kim] [2020039079] -----]\n");
    printf("\n");

    //행렬 A의 행과 열의 개수를 입력받음
    printf("Please enter a row of matrix A : "); 
    scanf("%d", &row_A); 
    printf("Please enter a columm of matrix A : ");
    scanf("%d", &columm_A); 

    //행렬 B의 행과 열의 개수를 입력받음
    printf("Please enter a row of matrix B : ");
    scanf("%d", &row_B); 
    printf("Please enter a columm of matrix B : ");
    scanf("%d", &columm_B); 

    //A를 이중포인터로 선언하고 A의 각각의 행에 동적할당
    int ** A = (int**)malloc(sizeof(int*) * row_A);
    for(int i = 0; i < row_A; i++)
    {
        *(A + i) = (int *)malloc(sizeof(int) *columm_A);
    } //for문을 이용하여 A의 각 열에도 동적할당

    //B를 이중포인터로 선언하고 B의 각각의 행에 동적할당
    int ** B = (int**)malloc(sizeof(int*) * row_B);
    for(int i = 0; i < row_B; i++)
    {
        *(B + i) = (int *)malloc(sizeof(int) *columm_B);
    } //for문을 이용하여 B의 각 열에도 동적할당

    for(i = 0; i < row_A ; i++)
    {
        for(int j = 0; j < columm_A ;j++)
        {
            printf("Enter the element [%d][%d]of matrix A : ", i, j);
            scanf("%d", &A[i][j]);
        }
    } //이중 for문을 이용하여 행렬 A의 각 요소들에 임의의 값을 할당.

    for(i = 0; i < row_B ; i++)
    {
        for(int j = 0; j < columm_B ;j++)
        {
            printf("Enter the element [%d][%d]of matrix B : ", i, j);
            scanf("%d", &B[i][j]);
        }
    } //이중 for문을 이용하여 행렬 B의 각 요소들에 임의의 값을 할당.
    
    printf("matrix A\n");
    print_matrix(row_A, columm_A, A); //행렬 A를 출력
    printf("\n");
    printf("matrix B\n");
    print_matrix(row_B, columm_B, B); //행렬 B를 출력
    printf("\n");
    printf("A+B\n");
    addition_matrix(row_A, row_B, columm_A, columm_B, A, B); //행렬 A+B를 출력
    printf("\n"); 
    printf("A-B\n");
    subtration_matrix(row_A, row_B, columm_A, columm_B, A, B); //행렬 A-B를 출력
    printf("\n");
    printf("A*B\n");
    multiply_matrix(row_A, columm_A, row_B, columm_B, A, B); //행렬 A*B를 출력
    printf("\n");
    printf("transepose of matrix A\n");
    transepose_matrix(row_A, columm_A, A); //A의 전치행렬을 출력
    printf("\n");
    printf("transepose of matrix B\n");
    transepose_matrix(row_B, columm_B, B); //B의 전치행렬을 출력
    printf("\n");
    free_matrix(row_A, A); //free_matrix함수를 이용하여 행렬 A의 각각의 행에 동적할당을 해제해줌
    free_matrix(row_B, B); //free_matrix함수를 이용하여 행렬 B의 각각의 행에 동적할당을 해제해줌
}

//행렬을 출력하는 함수.
void print_matrix(int row, int columm, int** matrix){
    int i, j;

    for(i = 0; i < row; i++) //이중 for문을 이용하여 매개변수로 받은 행렬 각각의 요소값을 출력하도록 하였다.
    {
        for(j = 0; j < columm; j++)
        {
            printf("%3d", *(*(matrix+i)+j)); //*(*(matrix+i)+j)은 matrix[i][j]와 같은 의미를 기잔다
        }
        printf("\n");
    }
}
//동적할당된 행렬을 해제해주는 함수
void free_matrix(int row, int** matrix){
    for(int i=0 ; i < row ; i++){
        free(*(matrix+i)); //*(matrix+i)은 matrix[i], 즉 행렬의 행을 의미한다. 각 행에 동적할당을 해제해준다.
    }
}
//행렬 A, B의 덧셈을 계산하는 함수
void addition_matrix(int row1, int row2, int columm1, int columm2, int** matrix1, int **matrix2){
    int** add_matrix = (int**)malloc(sizeof(int *) * row1); //행렬의 합을 저장할 이차원 배열 add_matrix에 동적할당
    for(int i = 0; i < row1; i++)
    {
        *(add_matrix + i) = (int *)malloc(sizeof(int) *columm1); //add_matrix 각 열에 동적할당 
    }
    int i, j;

    if(row1==row2 && columm1 == columm2) //행렬의 덧셈 성립 조건을 검사 행렬 A,B의 열과 행이 각각 같은지 검사
    {
        for(i=0; i < row1 ; i++) 
        {
            for(j =0; j< columm1; j++)
            {
                add_matrix[i][j] = matrix1[i][j] + matrix2[i][j]; 
            }
            printf("\n");
        } //이중 for문을 이용하여 add_matrix의 각요소에 행렬의 합을 계산하여 대입 
    } 
    else
    {
        printf("Cannot output sum because the number of rows and columns is different."); 
    } //열과 행이 다를시 출력할수 없음을 사용에게 알려주는 문구를 출력

    print_matrix(row1, columm1, add_matrix); //add_matrix 출력
    free_matrix(row1, add_matrix); //add_matrix에 할당된 동적할당 해제 
}
//행렬 A, B의 뺄셈을 계산하는 함수
void subtration_matrix(int row1, int row2, int columm1, int columm2, int** matrix1, int **matrix2){
    int** sub_matrix = (int**)malloc(sizeof(int *) * row1); //행렬의 차를 저장할 이차원 배열 sub_matrix에 입력받은 행의 갯수만큼 동적할당.
    for(int i = 0; i < row1; i++) 
    { 
        *(sub_matrix + i) = (int *)malloc(sizeof(int) *columm1);
    } //for문을 이용하여 sub_matrix 행렬의 각열에도 동적할당
    int i, j;
    
    if(row1==row2 && columm1==columm2) //덧셈을 계산하는 행렬과 동일하게 각각의 행렬의 행과 열의 개수가 같은지 검사
    {
        for(i=0; i < row1 ; i++)
        {
            for(j =0; j< columm1; j++)
            {
                sub_matrix[i][j] = matrix1[i][j] - matrix2[i][j];
            }
            printf("\n");
        } //이중 for문을 이용하여 sub_matrix행렬의 A, B각 행렬요소의 결과값을 저장.
    }
    else
    {
        printf("Cannot output subtration because the number of rows and columns is different.");
    } //행과 열의 개수가 다를시 계산이 불가한 점을 사용자에게 알려줌

    print_matrix(row1, columm1, sub_matrix); //sub_matrix 출력
    free_matrix(row1, sub_matrix); //sub_matrix에 할당된 동적할당 해제
}
//행렬 A, B의 곱셈을 계산하는 함수
void multiply_matrix(int row1, int columm1, int row2, int columm2, int** matrix1, int **matrix2){
    int** multiply_matrix = (int**)malloc(sizeof(int *) * row1); //이차원 배열 multiply_matrix에 동적할당
    for(int i = 0; i < row1; i++)
    {
        *(multiply_matrix + i) = (int *)malloc(sizeof(int) *columm2);
    } //for문을 이용하여 이차원 배열 multiply_matrix 각 열 요소들에 동적할당
    int i, j, k;

    if(columm1 == row2) //행렬 A,B를 곱할경우 A의 열의 개수와 B의 행의 개수가 같아야지만 곱셈연산을 수행할 수 있으므로 그 조건을 검사하는 if문
    {
        for(i=0 ; i < row1 ; i++) 
        {
            for(j=0; j < columm2 ; j++)
            {
                int sum = 0; //행렬의 곱을 수행한 값을 임시로 저장할 변수 sum을 0으로 초기화 정수형 변수 sum의 위치는 
                             //다음 행연산으로 넘어가기전인 두번째 for문안에 위치해야함 3번째 for문안에 위치시 sum변수가 
                             //계속 0으로 초기화 되므로 쓰레기값이 저장됨

                for(k=0 ; k < columm1 ; k++) //A행렬의 행과 B행렬의 열을 곱하는 for문
                {   
                    sum += matrix1[i][k] * matrix2[k][j]; //
                }
                multiply_matrix[i][j] = sum; 
            }
        } //삼중 for문을 이용히여 연산한 행렬의 곱을 임시변수 sum을 만들어 대입하고 다시 mutiply_matrix의 각요소에 for문이 다시 돌기전에 저장
    }
    else
    {
        printf("Cannot output multiply because the number of rows and columns is different.");
    }
    print_matrix(row1, columm2, multiply_matrix);
    free_matrix(row1, multiply_matrix);
}
//각 행렬의 전치행렬을 구하는 함수
void transepose_matrix(int row1, int columm1, int** matrix1){
    //transepost_matrix 전치행렬이므로 함수의 매개변수인 행렬의 열을 전치행렬의 행의 개수로 바꿔주고 바뀐 열에 동적할당.
    int** transepose_matrix = (int**)malloc(sizeof(int *) * columm1); //전치행렬을 저장할 이차원 배열 transepose_matrix에 동적할당
    for(int i = 0; i < columm1; i++) //행렬의 행을 전치행렬의 열의 개수로 바꿔주고 바뀐 열에 동적할당.
    {
        *(transepose_matrix + i) = (int *)malloc(sizeof(int) *row1);
    }
    int i, j;
    if(row1 > 1 && columm1 > 1) //전치행렬의 경우 행과 열의 개수가 2이상이어야 함.
    {
        for(i = 0; i < columm1;i++) 
        {
            for(j=0; j < row1; j++)
            {
                transepose_matrix[i][j] = matrix1[j][i];
            }
        }// 이중 for문을 이용하여 전치행렬 연산 수행 , 행과 열의 순서만 바꿔주면 된다.
    }
    else
    {
        printf("Cannot output transepose because the number of rows and columns is different.");
    }

    print_matrix(columm1, row1, transepose_matrix);
    free_matrix(columm1, transepose_matrix);
}