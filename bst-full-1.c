/*
 * Binary Search Tree #1
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
	int key;
	struct node *left;
	struct node *right;
} Node;

int initializeBST(Node** h);

/* 구현해야 하는 함수들 */
void inorderTraversal(Node* ptr);        /* 재귀적으로 중위 순회를 수행합니다. */
void preorderTraversal(Node* ptr);       /* 재귀적으로 전위 순회를 수행합니다. */
void postorderTraversal(Node* ptr);      /* 재귀적으로 후위 순회를 수행합니다. */
int insert(Node* head, int key);         /* 노드를 트리에 삽입합니다. */
int deleteLeafNode(Node* head, int key); /* 지정된 키의 잎 노드를 삭제합니다. */
Node* searchRecursive(Node* ptr, int key);  /* 특정 키에 해당하는 노드를 재귀적으로 검색합니다. */
Node* searchIterative(Node* head, int key);  /* 특정 키에 해당하는 노드를 반복적으로 검색합니다. */
int freeBST(Node* head);                 /* 트리에 할당된 모든 메모리를 해제합니다. */

/* 필요에 따라 직접 정의한 함수를 추가할 수 있습니다. */



int main()
{
	char command;
	int key;
	Node* head = NULL;
	Node* ptr = NULL;	/* temp */

	do{
		printf("\n\n");
		printf("-----------[----- [Taehwa kim] [2020039079] -----]--------------\n");
		printf("----------------------------------------------------------------\n");
		printf("                   Binary Search Tree #1                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize BST       = z                                       \n");
		printf(" Insert Node          = n      Delete Leaf Node             = d \n");
		printf(" Inorder Traversal    = i      Search Node Recursively      = s \n");
		printf(" Preorder Traversal   = p      Search Node Iteratively      = f\n");
		printf(" Postorder Traversal  = t      Quit                         = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'z': case 'Z':
			initializeBST(&head);
			break;
		case 'q': case 'Q':
			freeBST(head);
			break;
		case 'n': case 'N':
			printf("Your Key = ");
			scanf("%d", &key);
			insert(head, key);
			break;
		case 'd': case 'D':
			printf("Your Key = ");
			scanf("%d", &key);
			deleteLeafNode(head, key);
			break;
		case 'f': case 'F':
			printf("Your Key = ");
			scanf("%d", &key);
			ptr = searchIterative(head, key);
			if(ptr != NULL)
				printf("\n node [%d] found at %p\n", ptr->key, ptr);
			else
				printf("\n Cannot find the node [%d]\n", key);
			break;
		case 's': case 'S':
			printf("Your Key = ");
			scanf("%d", &key);
			ptr = searchRecursive(head->left, key);
			if(ptr != NULL)
				printf("\n node [%d] found at %p\n", ptr->key, ptr);
			else
				printf("\n Cannot find the node [%d]\n", key);
			break;

		case 'i': case 'I':
			inorderTraversal(head->left);
			break;
		case 'p': case 'P':
			preorderTraversal(head->left);
			break;
		case 't': case 'T':
			postorderTraversal(head->left);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 1;
}

int initializeBST(Node** h) {

	/* 트리가 비어 있지 않은 경우, 트리에서 할당된 모든 노드를 제거합니다 */
	if (*h != NULL)
		freeBST(*h);

	/* 헤드 노드를 생성합니다 */
	*h = (Node*)malloc(sizeof(Node));
	(*h)->left = NULL;	/* 루트 노드 */
	(*h)->right = *h;	/* 오른쪽 자식을 자기 자신으로 설정합니다 */
	(*h)->key = -9999;	/* 임의의 키 값으로 설정합니다 */
	return 1;
}




void inorderTraversal(Node* ptr)
{
	if (ptr) {
		inorderTraversal(ptr->left);    // 왼쪽 서브트리를 중위 순회합니다.
		printf(" [%d] ", ptr->key);     // 현재 노드를 출력합니다.
		inorderTraversal(ptr->right);   // 오른쪽 서브트리를 중위 순회합니다.
	}
}

void preorderTraversal(Node* ptr)
{
	if (ptr) {
		printf(" [%d] ", ptr->key);     // 현재 노드를 출력합니다.
		preorderTraversal(ptr->left);   // 왼쪽 서브트리를 전위 순회합니다.
		preorderTraversal(ptr->right);  // 오른쪽 서브트리를 전위 순회합니다.
	}
}


void postorderTraversal(Node* ptr)
{
	if (ptr) {
		postorderTraversal(ptr->left);     // 왼쪽 서브트리를 후위 순회합니다.
		postorderTraversal(ptr->right);    // 오른쪽 서브트리를 후위 순회합니다.
		printf(" [%d] ", ptr->key);        // 현재 노드를 출력합니다.
	}
}

int insert(Node* head, int key)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->key = key;        // 새로운 노드의 키 값을 할당합니다.
	newNode->left = NULL;      // 새로운 노드의 왼쪽 자식을 NULL로 초기화합니다.
	newNode->right = NULL;     // 새로운 노드의 오른쪽 자식을 NULL로 초기화합니다.

	if (head->left == NULL) {
		head->left = newNode;               // 헤드 노드의 왼쪽 자식으로 새로운 노드를 연결합니다.
		return 1;
	}


	/* head->left is the root */
	Node* ptr = head->left;

	Node* parentNode = NULL;
	while(ptr != NULL) {

		/* if there is a node for the key, then just return */
		if(ptr->key == key) return 1;

		/* we have to move onto children nodes,
		 * keep tracking the parent using parentNode */
		parentNode = ptr;

		/* key comparison, if current node's key is greater than input key
		 * then the new node has to be inserted into the right subtree;
		 * otherwise the left subtree.
		 */
		if(ptr->key < key)
			ptr = ptr->right;
		else
			ptr = ptr->left;
	}

	/* linking the new node to the parent */
	if(parentNode->key > key)
		parentNode->left = newNode;
	else
		parentNode->right = newNode;
	return 1;
}

int deleteLeafNode(Node* head, int key)
{
	// head가 NULL인 경우, 아무것도 삭제할 노드가 없음
	if (head == NULL) {
		printf("\n 삭제할 노드가 없습니다!!\n");
		return -1;
	}

	// head->left가 NULL인 경우, 아무것도 삭제할 노드가 없음
	if (head->left == NULL) {
		printf("\n 삭제할 노드가 없습니다!!\n");
		return -1;
	}

	// head->left는 루트 노드를 가리킴
	Node* ptr = head->left;

	// 자식 노드로 이동하며 부모 노드를 추적하기 위한 parentNode 변수
	Node* parentNode = head;

	while(ptr != NULL) {

		// 현재 노드의 키와 입력된 키가 일치하는 경우
		if(ptr->key == key) {
			// 현재 노드가 잎 노드인 경우 (자식 노드가 없는 경우)
			if(ptr->left == NULL && ptr->right == NULL) {

				// 루트 노드인 경우
				if(parentNode == head)
					head->left = NULL;

				// 왼쪽 노드인 경우 또는 오른쪽 노드인 경우
				if(parentNode->left == ptr)
					parentNode->left = NULL;
				else
					parentNode->right = NULL;

				free(ptr);
			}
			else {
				printf("노드 [%d]는 잎 노드가 아닙니다.\n", ptr->key);
			}
			return 1;
		}

		// 부모 노드를 저장
		parentNode = ptr;

		// 키 비교, 현재 노드의 키가 입력된 키보다 작으면 오른쪽 서브트리로 이동
		// 그렇지 않으면 왼쪽 서브트리로 이동
		if(ptr->key < key)
			ptr = ptr->right;
		else
			ptr = ptr->left;


	}



	printf("Cannot find the node for key [%d]\n ", key);

	return 1;
}

Node* searchRecursive(Node* ptr, int key)
{
	// 현재 노드가 NULL인 경우, 키를 찾지 못한 것이므로 NULL 반환
	if(ptr == NULL)
		return NULL;

	// 현재 노드의 키가 입력된 키보다 작은 경우, 오른쪽 서브트리에서 재귀적으로 탐색
	if(ptr->key < key)
		ptr = searchRecursive(ptr->right, key);
	// 현재 노드의 키가 입력된 키보다 큰 경우, 왼쪽 서브트리에서 재귀적으로 탐색
	else if(ptr->key > key)
		ptr = searchRecursive(ptr->left, key);

	// ptr->key == key인 경우, 찾은 노드 반환
	return ptr;
}

Node* searchIterative(Node* head, int key)
{
	// 루트 노드
	Node* ptr = head->left;

	while(ptr != NULL)
	{
		// 현재 노드의 키가 입력된 키와 일치하는 경우, 해당 노드 반환
		if(ptr->key == key)
			return ptr;

		// 현재 노드의 키가 입력된 키보다 작은 경우, 오른쪽으로 이동
		if(ptr->key < key)
			ptr = ptr->right;
		// 현재 노드의 키가 입력된 키보다 큰 경우, 왼쪽으로 이동
		else
			ptr = ptr->left;
	}

	// 키를 찾지 못한 경우, NULL 반환
	return NULL;
}


void freeNode(Node* ptr)
{
	if(ptr) {
		// 왼쪽 서브트리 재귀적으로 해제
		freeNode(ptr->left);
		// 오른쪽 서브트리 재귀적으로 해제
		freeNode(ptr->right);
		// 현재 노드 해제
		free(ptr);
	}
}

int freeBST(Node* head)
{
	// 트리가 비어있는 경우, head 자체를 해제하고 1 반환
	if(head->left == head)
	{
		free(head);
		return 1;
	}

	// 루트 노드
	Node* p = head->left;

	// 모든 노드 해제
	freeNode(p);

	// head 해제
	free(head);
	return 1;
}






