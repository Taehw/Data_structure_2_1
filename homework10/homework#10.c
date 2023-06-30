/*
 * Binary Search Tree #2
 *
 * Data Structures
 *
 * School of Computer Science
 * at Chungbuk National University
 *
 */

#include <stdio.h>
#include <stdlib.h>



typedef struct node {
    int key;              // 현재 노드의 키 값
    struct node *left;    // 왼쪽 서브트리를 가리키는 포인터
    struct node *right;   // 오른쪽 서브트리를 가리키는 포인터
} Node;


/* for stack */
#define MAX_STACK_SIZE		20
Node* stack[MAX_STACK_SIZE];
int top = -1;

Node* pop();
void push(Node* aNode);

/* for queue */
#define MAX_QUEUE_SIZE		20
Node* queue[MAX_QUEUE_SIZE];
int front = -1;
int rear = -1;



int initializeBST(Node** h);
void recursiveInorder(Node* ptr);	  /* recursive inorder traversal */
int insert(Node* head, int key);      /* insert a node to the tree */
int freeBST(Node* head); /* free all memories allocated to the tree */

/* functions that you have to implement */
void iterativeInorder(Node* ptr);     /* iterative inorder traversal */
void levelOrder(Node* ptr);	          /* level order traversal */
int deleteNode(Node* head, int key);  /* delete the node for the key */
Node* pop();
void push(Node* aNode);
Node* deQueue();
void enQueue(Node* aNode);

/* you may add your own defined functions if necessary */


void printStack();



int main()
{
    char command;            // 사용자로부터 입력 받을 명령어 변수
    int key;                 // 사용자로부터 입력 받을 키 값 변수
    Node* head = NULL;       // 이진 탐색 트리의 헤드(루트) 노드를 가리키는 포인터

    do {
        printf("[----- [Taehwa kim] [2020039079] -----]\n");
        printf("\n\n");
        printf("----------------------------------------------------------------\n");
        printf("                   Binary Search Tree #2                        \n");
        printf("----------------------------------------------------------------\n");
        printf(" Initialize BST       = z                                       \n");
        printf(" Insert Node          = i      Delete Node                  = d \n");
        printf(" Recursive Inorder    = r      Iterative Inorder (Stack)    = t \n");
        printf(" Level Order (Queue)  = l      Quit                         = q \n");
        printf("----------------------------------------------------------------\n");

        printf("Command = ");
        scanf(" %c", &command);     // 사용자로부터 명령어 입력 받기

        switch (command) {
            case 'z': case 'Z':
                initializeBST(&head);      // BST 초기화
                break;
            case 'q': case 'Q':
                freeBST(head);             // BST 해제
                break;
            case 'i': case 'I':
                printf("Your Key = ");
                scanf("%d", &key);         // 삽입할 키 값 입력 받기
                insert(head, key);         // 키 값을 가진 노드 삽입
                break;
            case 'd': case 'D':
                printf("Your Key = ");
                scanf("%d", &key);         // 삭제할 키 값 입력 받기
                deleteNode(head, key);     // 키 값을 가진 노드 삭제
                break;
            case 'r': case 'R':
                recursiveInorder(head->left);   // 재귀적으로 중위 순회
                break;
            case 't': case 'T':
                iterativeInorder(head->left);   // 반복적으로 중위 순회 (스택 이용)
                break;
            case 'l': case 'L':
                levelOrder(head->left);         // 레벨 순서로 순회 (큐 이용)
                break;
            case 'p': case 'P':
                printStack();                   // 스택 출력
                break;
            default:
                printf("\n       >>>>>   Concentration!!   <<<<<     \n");   // 잘못된 명령어 처리
                break;
        }
    } while (command != 'q' && command != 'Q');   // 'q'나 'Q'가 입력될 때까지 반복

    return 1;
}


int initializeBST(Node** h) {
    /* 이진 탐색 트리가 비어있지 않은 경우, 트리에서 할당된 모든 노드를 제거합니다. */
    if (*h != NULL)
        freeBST(*h);

    /* 헤드(루트) 노드를 생성합니다. */
    *h = (Node*)malloc(sizeof(Node));
    (*h)->left = NULL;    // 루트 노드의 왼쪽 서브트리는 비어있음을 나타냅니다.
    (*h)->right = *h;     // 루트 노드의 오른쪽 서브트리는 자기 자신을 가리킵니다.
    (*h)->key = -9999;    // 임의의 특정한 값을 헤드 노드의 키로 설정합니다.

    top = -1;             // 스택의 초기 상태를 설정합니다.

    front = rear = -1;    // 큐의 초기 상태를 설정합니다.

    return 1;
}




void recursiveInorder(Node* ptr) {
    if (ptr) {
        recursiveInorder(ptr->left);       // 왼쪽 서브트리를 재귀적으로 중위 순회합니다.
        printf(" [%d] ", ptr->key);        // 현재 노드의 키 값을 출력합니다.
        recursiveInorder(ptr->right);      // 오른쪽 서브트리를 재귀적으로 중위 순회합니다.
    }
}

void iterativeInorder(Node* node) {
    for (;;) {
        for (; node; node = node->left)
            push(node);                   // 현재 노드를 스택에 추가하고, 왼쪽 자식으로 이동합니다.
        node = pop();                      // 스택에서 노드를 팝하여 방문합니다.

        if (!node)
            break;                         // 노드가 NULL인 경우 반복문을 종료합니다.
        printf(" [%d] ", node->key);        // 현재 노드의 키 값을 출력합니다.

        node = node->right;                 // 오른쪽 자식으로 이동합니다.
    }
}



void levelOrder(Node* ptr) {
    if (!ptr)
        return;   // 트리가 비어있는 경우, 함수를 종료합니다.

    enQueue(ptr);   // 루트 노드를 큐에 넣습니다.

    for (;;) {
        ptr = deQueue();   // 큐에서 노드를 꺼냅니다.

        if (ptr) {
            printf(" [%d] ", ptr->key);   // 현재 노드의 키 값을 출력합니다.

            if (ptr->left)
                enQueue(ptr->left);       // 왼쪽 자식을 큐에 넣습니다.
            if (ptr->right)
                enQueue(ptr->right);      // 오른쪽 자식을 큐에 넣습니다.
        } else
            break;   // 노드가 NULL인 경우 반복문을 종료합니다.
    }
}

int insert(Node* head, int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;

    if (head->left == NULL) {
        head->left = newNode;   // 트리가 비어있는 경우, 새로운 노드를 루트로 설정합니다.
        return 1;
    }

    Node* ptr = head->left;   // 현재 노드를 루트로 설정합니다.
    Node* parentNode = NULL;  // 부모 노드를 추적하기 위한 변수입니다.

    while (ptr != NULL) {
        if (ptr->key == key)
            return 1;   // 이미 키 값이 존재하는 경우, 함수를 종료하고 중복 삽입을 허용하지 않습니다.

        parentNode = ptr;   // 부모 노드를 현재 노드로 설정합니다.

        if (ptr->key < key)
            ptr = ptr->right;   // 현재 노드의 키 값보다 큰 경우, 오른쪽 자식으로 이동합니다.
        else
            ptr = ptr->left;    // 현재 노드의 키 값보다 작은 경우, 왼쪽 자식으로 이동합니다.
    }

    // 새로운 노드를 부모 노드와 연결합니다.
    if (parentNode->key > key)
        parentNode->left = newNode;   // 현재 노드의 키 값보다 작은 경우, 왼쪽 자식으로 연결합니다.
    else
        parentNode->right = newNode;  // 현재 노드의 키 값보다 큰 경우, 오른쪽 자식으로 연결합니다.

    return 1;
}



int deleteNode(Node* head, int key) {
    if (head == NULL || head->left == NULL) {
        printf("\n Nothing to delete!!\n");
        return -1;
    }

    Node* root = head->left;   // 루트 노드를 설정합니다.

    Node* parent = NULL;
    Node* ptr = root;

    while ((ptr != NULL) && (ptr->key != key)) {
        parent = ptr;   // 부모 노드를 저장합니다.

        if (ptr->key > key)
            ptr = ptr->left;   // 현재 노드의 키 값보다 작은 경우, 왼쪽 자식으로 이동합니다.
        else
            ptr = ptr->right;  // 현재 노드의 키 값보다 큰 경우, 오른쪽 자식으로 이동합니다.
    }

    if (ptr == NULL) {
        printf("No node for key [%d]\n ", key);
        return -1;   // 삭제할 노드가 존재하지 않는 경우, 함수를 종료합니다.
    }

    // case 1: 삭제할 노드가 단말 노드인 경우
    if (ptr->left == NULL && ptr->right == NULL) {
        if (parent != NULL) {   // 부모 노드가 존재하는 경우, 부모의 링크를 조정합니다.
            if (parent->left == ptr)
                parent->left = NULL;
            else
                parent->right = NULL;
        } else {
            head->left = NULL;   // 부모가 없는 경우, 삭제할 노드가 루트인 경우입니다.
        }

        free(ptr);
        return 1;
    }

    // case 2: 삭제할 노드가 하나의 자식을 가지고 있는 경우
    if (ptr->left == NULL || ptr->right == NULL) {
        Node* child;
        if (ptr->left != NULL)
            child = ptr->left;
        else
            child = ptr->right;

        if (parent != NULL) {
            if (parent->left == ptr)
                parent->left = child;
            else
                parent->right = child;
        } else {
            root = child;   // 삭제할 노드가 루트인 경우, 자식을 새로운 루트로 설정합니다.
        }

        free(ptr);
        return 1;
    }

    // case 3: 삭제할 노드가 두 개의 자식을 가지고 있는 경우
    Node* candidate;
    parent = ptr;

    candidate = ptr->right;   // 오른쪽 서브트리에서 가장 작은 값을 가지는 노드를 찾습니다.

    while (candidate->left != NULL) {
        parent = candidate;
        candidate = candidate->left;
    }

    if (parent->right == candidate)
        parent->right = candidate->right;   // 후보 노드의 오른쪽 자식을 연결합니다.
    else
        parent->left = candidate->right;

    ptr->key = candidate->key;   // 후보 노드의 키 값을 삭제할 노드에 복사합니다.

    free(candidate);
    return 1;
}



void freeNode(Node* ptr)
{
	if(ptr) {
		freeNode(ptr->left);   // 왼쪽 자식 노드를 재귀적으로 해제합니다.
		freeNode(ptr->right);  // 오른쪽 자식 노드를 재귀적으로 해제합니다.
		free(ptr);             // 현재 노드를 해제합니다.
	}
}

int freeBST(Node* head)
{
	if(head->left == head)   // 헤드 노드만 존재하는 경우
	{
		free(head);          // 헤드 노드를 해제합니다.
		return 1;
	}

	Node* p = head->left;    // 루트 노드를 설정합니다.

	freeNode(p);             // 트리의 모든 노드를 해제합니다.

	free(head);              // 헤드 노드를 해제합니다.
	return 1;
}

Node* pop()
{
	if (top < 0) return NULL;   // 스택이 비어있는 경우 NULL을 반환합니다.
	return stack[top--];       // 스택에서 가장 위에 있는 노드를 꺼내고, top을 감소시킵니다.
}

void push(Node* aNode)
{
	stack[++top] = aNode;       // 스택에 노드를 추가하고, top을 증가시킵니다.
}

void printStack()
{
	int i = 0;
	printf("--- stack ---\n");
	while(i <= top)
	{
		printf("stack[%d] = %d\n", i, stack[i]->key);   // 스택에 저장된 노드의 키 값을 출력합니다.
	}
}



Node* deQueue()
{
	if (front == rear) {
		// 큐가 비어있는 경우 NULL을 반환합니다.
		// printf("\n....Now Queue is empty!!\n");
		return NULL;
	}

	front = (front + 1) % MAX_QUEUE_SIZE;   // front를 다음 위치로 이동합니다.
	return queue[front];                    // front 위치의 노드를 반환합니다.
}

void enQueue(Node* aNode)
{
	rear = (rear + 1) % MAX_QUEUE_SIZE;   // rear를 다음 위치로 이동합니다.
	if (front == rear) {
		// 큐가 가득 찬 경우 함수를 종료합니다.
		// printf("\n....Now Queue is full!!\n");
		return;
	}

	queue[rear] = aNode;   // rear 위치에 노드를 추가합니다.
}





