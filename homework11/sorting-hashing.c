
/*

sorting-hashing.c
Sorting & Hashing
충북대학교 소프트웨어학부
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ARRAY_SIZE 13 /* 소수(prime number) */
#define MAX_HASH_TABLE_SIZE MAX_ARRAY_SIZE

/* 필요에 따라 함수 추가 가능 */
int initialize(int **a);
int freeArray(int *a);
void printArray(int *a);

int selectionSort(int *a);
int insertionSort(int *a);
int bubbleSort(int *a);
int shellSort(int a);
/* 재귀 함수로 구현 */
int quickSort(int *a, int n);

/* 해시 코드 생성기, key % MAX_HASH_TABLE_SIZE */
int hashCode(int key);

/* 배열 a에 대한 해시 테이블을 생성한다. */
int hashing(int *a, int **ht);

/* 해시 테이블에서 key를 찾아 해시 테이블의 인덱스를 반환한다. */
int search(int *ht, int key);


int main()
{
	char command;
	int *array = NULL;
	int *hashtable = NULL;
	int key = -1;
	int index = -1;

	printf("        [----- [Taehwa kim] [2020039079] -----]       \n");
	
	srand(time(NULL));

	do{
		printf("----------------------------------------------------------------\n");
		printf("                        Sorting & Hashing                       \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize       = z           Quit             = q\n");
		printf(" Selection Sort   = s           Insertion Sort   = i\n");
		printf(" Bubble Sort      = b           Shell Sort       = l\n");
		printf(" Quick Sort       = k           Print Array      = p\n");
		printf(" Hashing          = h           Search(for Hash) = e\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'z': case 'Z':
			initialize(&array);
			break;
		case 'q': case 'Q':
			freeArray(array);
			break;
		case 's': case 'S':
			selectionSort(array);
			break;
		case 'i': case 'I':
			insertionSort(array);
			break;
		case 'b': case 'B':
			bubbleSort(array);
			break;
		case 'l': case 'L':
			shellSort(array);
			break;
		case 'k': case 'K':
			printf("Quick Sort: \n");
			printf("----------------------------------------------------------------\n");
			printArray(array);
			quickSort(array, MAX_ARRAY_SIZE);
			printf("----------------------------------------------------------------\n");
			printArray(array);

			break;

		case 'h': case 'H':
			printf("Hashing: \n");
			printf("----------------------------------------------------------------\n");
			printArray(array);
			hashing(array, &hashtable);
			printArray(hashtable);
			break;

		case 'e': case 'E':
			printf("Your Key = ");
			scanf("%d", &key);
			printArray(hashtable);
			index = search(hashtable, key);
			printf("key = %d, index = %d,  hashtable[%d] = %d\n", key, index, index, hashtable[index]);
			break;

		case 'p': case 'P':
			printArray(array);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 1;
}

int initialize(int** a)
{
int *temp = NULL;

/* 배열이 NULL인 경우 메모리 할당 */
if(*a == NULL) {
	temp = (int*)malloc(sizeof(int) * MAX_ARRAY_SIZE);
	*a = temp;  /* 할당된 메모리의 주소를 복사하여 main에서 배열을 제어할 수 있도록 함 */
} else
	temp = *a;

/* 랜덤값을 배열의 값으로 저장 */
for(int i = 0; i < MAX_ARRAY_SIZE; i++)
	temp[i] = rand() % MAX_ARRAY_SIZE;

return 0;
}

/*

배열을 초기화하는 함수입니다.
배열이 NULL인 경우에만 메모리를 할당하고, 랜덤값을 배열의 각 요소에 저장합니다.
a: 배열의 이중 포인터
리턴값: 성공 시 0, 실패 시 -1
*/

// 배열을 해제하는 함수
int freeArray(int *a)
{
if(a != NULL)
free(a); // 동적 할당된 메모리를 해제합니다.
return 0;
}

// 배열을 출력하는 함수
void printArray(int *a)
{
if (a == NULL) 
{
	printf("nothing to print.\n"); // 배열이 비어있을 경우 아무것도 출력하지 않고 함수를 종료합니다.
	return;
}
for(int i = 0; i < MAX_ARRAY_SIZE; i++)
	printf("a[%02d] ", i); // 배열의 인덱스를 출력합니다.
	printf("\n");
for(int i = 0; i < MAX_ARRAY_SIZE; i++)
	printf("%5d ", a[i]); // 배열의 요소를 출력합니다.
	printf("\n");
}


int selectionSort(int *a)
{
	int min;
	int minindex;
	int i, j;

printf("Selection Sort: \n");  // 선택 정렬을 수행한다는 메시지를 출력합니다.
printf("----------------------------------------------------------------\n");

printArray(a);  // 정렬 전 배열을 출력합니다.

for (i = 0; i < MAX_ARRAY_SIZE; i++)
{
	minindex = i;  // 최솟값의 인덱스를 i로 초기화합니다.
	min = a[i];  // 최솟값을 a[i]로 초기화합니다.
	for(j = i+1; j < MAX_ARRAY_SIZE; j++)
	{
		if (min > a[j])
		{
			min = a[j];  // 더 작은 값이 발견되면 최솟값을 갱신합니다.
			minindex = j;  // 최솟값의 인덱스를 갱신합니다.
		}
	}
	a[minindex] = a[i];  // 최솟값을 현재 위치로 이동시킵니다.
	a[i] = min;  // 현재 위치에 최솟값을 저장합니다.
}

printf("----------------------------------------------------------------\n");
printArray(a);  // 정렬 후 배열을 출력합니다.
return 0;

}

int insertionSort(int *a)
{
	int i, j, t;

printf("Insertion Sort: \n");  // 삽입 정렬을 수행한다는 메시지를 출력합니다.
printf("----------------------------------------------------------------\n");

printArray(a);  // 정렬 전 배열을 출력합니다.

for(i = 1; i < MAX_ARRAY_SIZE; i++)
{
	t = a[i];
	j = i;
	while (a[j-1] > t && j > 0)
	{
		a[j] = a[j-1];  // 현재 요소보다 큰 값을 오른쪽으로 한 칸씩 이동합니다.
		j--;
	}
	a[j] = t;  // 현재 요소를 정렬된 위치에 삽입합니다.
}

printf("----------------------------------------------------------------\n");
printArray(a);  // 정렬 후 배열을 출력합니다.

return 0;

}

int bubbleSort(int *a)
{
	int i, j, t;

	printf("Bubble Sort: \n");  // 버블 정렬을 수행한다는 메시지를 출력합니다.
printf("----------------------------------------------------------------\n");

printArray(a);  // 정렬 전 배열을 출력합니다.

for(i = 0; i < MAX_ARRAY_SIZE; i++)
{
	for (j = 0; j < MAX_ARRAY_SIZE; j++)
	{
		if (a[j-1] > a[j])  // 인접한 요소를 비교하여 순서가 잘못되어 있다면 교환합니다.
		{
			t = a[j-1];
			a[j-1] = a[j];
			a[j] = t;
		}
	}
}

printf("----------------------------------------------------------------\n");
printArray(a);  // 정렬 후 배열을 출력합니다.

return 0;
}

int shellSort(int *a)
{
	int i, j, k, h, v;

printf("Shell Sort: \n");  // 쉘 정렬을 수행한다는 메시지를 출력합니다.
printf("----------------------------------------------------------------\n");

printArray(a);  // 정렬 전 배열을 출력합니다.

for (h = MAX_ARRAY_SIZE/2; h > 0; h /= 2)
{
	for (i = 0; i < h; i++)
	{
		for(j = i + h; j < MAX_ARRAY_SIZE; j += h)
		{
			v = a[j];
			k = j;
			while (k > h-1 && a[k-h] > v)
			{
				a[k] = a[k-h];  // h 간격만큼 떨어진 요소들을 비교하여 정렬합니다.
				k -= h;
			}
			a[k] = v;  // 현재 요소를 정렬된 위치에 삽입합니다.
		}
	}
}
printf("----------------------------------------------------------------\n");
printArray(a);  // 정렬 후 배열을 출력합니다.

return 0;

}

int quickSort(int *a, int n)
{
	int v, t;
	int i, j;

if (n > 1)
{
	v = a[n-1];
	i = -1;
	j = n - 1;

	while(1)
	{
		while(a[++i] < v);  // 피벗보다 작은 값을 찾습니다.
		while(a[--j] > v);  // 피벗보다 큰 값을 찾습니다.

		if (i >= j) break;
		t = a[i];
		a[i] = a[j];
		a[j] = t;
	}
	t = a[i];
	a[i] = a[n-1];
	a[n-1] = t;

	quickSort(a, i);  // 피벗을 기준으로 좌측 부분 배열을 재귀적으로 정렬합니다.
	quickSort(a+i+1, n-i-1);  // 피벗을 기준으로 우측 부분 배열을 재귀적으로 정렬합니다.
}


return 0;

}

// 해시 함수: 키를 해시 테이블의 인덱스로 변환하는 함수
int hashCode(int key) {
return key % MAX_HASH_TABLE_SIZE; // 키를 해시 테이블의 크기로 나눈 나머지를 반환합니다.
}

// 해싱 함수: 주어진 배열을 해시 테이블에 저장하는 함수
int hashing(int *a, int **ht)
{
int *hashtable = NULL;

/* hash table이 NULL인 경우 메모리 할당 */
if(*ht == NULL) {
	hashtable = (int*)malloc(sizeof(int) * MAX_ARRAY_SIZE);
	*ht = hashtable;  /* 할당된 메모리의 주소를 복사 --> main에서 배열을 control 할 수 있도록 함*/
} else {
	hashtable = *ht;	/* hash table이 NULL이 아닌 경우, table 재활용, reset to -1 */
}

for(int i = 0; i < MAX_HASH_TABLE_SIZE; i++)
	hashtable[i] = -1;  // 해시 테이블의 모든 요소를 -1로 초기화합니다.

int key = -1;
int hashcode = -1;
int index = -1;
for (int i = 0; i < MAX_ARRAY_SIZE; i++)
{
	key = a[i];
	hashcode = hashCode(key);  // 키의 해시 코드를 계산합니다.

	if (hashtable[hashcode] == -1)
	{
		hashtable[hashcode] = key;  // 해당 해시 코드의 위치에 키를 저장합니다.
	} else 	{

		index = hashcode;

		while(hashtable[index] != -1)
		{
			index = (++index) % MAX_HASH_TABLE_SIZE;  // 선형 탐색을 통해 다음 빈 슬롯을 찾습니다.
		}
		hashtable[index] = key;  // 빈 슬롯에 키를 저장합니다.
	}
}

return 0;
}

// 해시 테이블에서 키를 검색하는 함수
int search(int *ht, int key)
{
int index = hashCode(key); // 키의 해시 코드를 계산합니다.

if(ht[index] == key)
	return index;  // 해당 인덱스에 저장된 값이 키와 일치하면 인덱스를 반환합니다.

while(ht[++index] != key)
{
	index = index % MAX_HASH_TABLE_SIZE;  // 다음 인덱스로 이동하며 순환합니다.
}
return index;  // 키를 찾은 인덱스를 반환합니다.
}
//complete



