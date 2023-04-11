#include <stdio.h>
#include <stdlib.h>

void print_matrix(int row, int columm, int** matrix);
void free_matrix(int row, int** matrix);

int main(void)
{
    int row_A, columm_A, row_B, columm_B, i;

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
    }

    for(i = 0; i < row_B ; i++)
    {
        for(int j = 0; j < columm_B ;j++)
        {
            printf("Enter the element [%d][%d]of matrix B : ", i, j);
            scanf("%d", &B[i][j]);
        }
    }

    print_matrix(row_A, columm_A, A);
    printf("\n");
    print_matrix(row_B, columm_B, B);

    free_matrix(row_A, A);
    free_matrix(row_B, B);
}


void print_matrix(int row, int columm, int** matrix){
    int i, j;
    for(i = 0; i < row; i++)
    {
        for(j = 0; j < columm; j++)
        {
            printf("%3d", *(*(matrix+i)+j)); //*(*(matrix+i)+j)   *(*matrix+i)+j, *((*matrix+i)+j)
        }
        printf("\n");
    }
}

void free_matrix(int row, int** matrix){
    for(int i=0 ; i < row ; i++){
        free(*(matrix+i));
    }
}


