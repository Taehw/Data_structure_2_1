/*
 *  doubly circular linked list
 *
 *  Data Structures
 *
 *  School of Computer Science
 *  at Chungbuk National University
 *
 */


#include<stdio.h>
#include<stdlib.h>
/* 필요한 헤더파일 추가 */

typedef struct Node {
	int key; 
	struct Node* llink; 
	struct Node* rlink;
} listNode; 

/* 함수 리스트 */
int initialize(listNode** h); 
int freeList(listNode* h);
int insertLast(listNode* h, int key); 
int deleteLast(listNode* h); 
int insertFirst(listNode* h, int key); 
int deleteFirst(listNode* h);
int invertList(listNode* h); 

int insertNode(listNode* h, int key); 
int deleteNode(listNode* h, int key); 

void printList(listNode* h);




int main()
{
	char command; //문자형 변수 command 
	int key;//정수형변수 key
	listNode* headnode=NULL;

	do{ //Q 또는 q를 입력받기 전까지 do while 안의 구문들을 반복
		printf("[----- [Taehwa kim] [2020039079] -----]");
		printf("----------------------------------------------------------------\n");
		printf("                  Doubly Circular Linked List                   \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize    = z           Print         = p \n");
		printf(" Insert Node   = i           Delete Node   = d \n");
		printf(" Insert Last   = n           Delete Last   = e\n");
		printf(" Insert First  = f           Delete First  = t\n");
		printf(" Invert List   = r           Quit          = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command); //원하는 명령을 실행하기 위한 command 입력

		switch(command) {
		case 'z': case 'Z': //z를 입력한 경우 initialze 함수 실행
			initialize(&headnode); 
			break;
		case 'p': case 'P': //z를 입력한 경우 printlist 함수 실행
			printList(headnode); 
			break;
		case 'i': case 'I': //i를 입력받았을 경우 key를 입력받고 insertNode 함수 실행 
			printf("Your Key = ");
			scanf("%d", &key); 
			insertNode(headnode, key);
			break;
		case 'd': case 'D': //d를 입력받았을 경우 key를 입력받고 deleteNode 함수 실행
			printf("Your Key = ");
			scanf("%d", &key);
			deleteNode(headnode, key);
			break;
		case 'n': case 'N': //n를 입력받았을 경우 key를 입력받고 insertLast함수 실행
			printf("Your Key = ");
			scanf("%d", &key);
			insertLast(headnode, key); 
			break;
		case 'e': case 'E'://e를 입력받았을 경우 delete 함수 실행 
			deleteLast(headnode);
			break;
		case 'f': case 'F': //f를 입력받았을 경우 insertFirst 함수 실행
			printf("Your Key = ");
			scanf("%d", &key); //key 입력
			insertFirst(headnode, key);
			break;
		case 't': case 'T': //t를 입력받았을 경우 deleteFirst 함수 실행
			deleteFirst(headnode); 
			break;
		case 'r': case 'R': //r를 입력받았을 경우 invertList 함수 실행
			invertList(headnode); 
			break;
		case 'q': case 'Q': //q를 입력받았을 경우 freeList 함수 실행
			freeList(headnode); 
		
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break; 
		}

	}while(command != 'q' && command != 'Q');

	return 1;
}


int initialize(listNode** h) { //이중 연결리스트를 생성하여 초기화하는 함수, 이중포인터를 매개변수로 받음. 함수가 리스트의 헤드 포인터를 수정할 수 있도록

	if(*h != NULL) 
		freeList(*h); //freeList 함수를 호출하여 기존 노드들이 차지하고 있는 메모리를 해제

	*h = (listNode*)malloc(sizeof(listNode)); //기존 리스트를 해제한 후 malloc을 사용하여 새로운 헤드 노드를 위한 메모리를 할당
	(*h)->rlink = *h; //새로 생성된 노드를 헤드 노드로 할당하기 우해 rlink 포인터를 자기 자신을 가리키도록 설정
	(*h)->llink = *h; //위와 동일한 이유로 ㄹllink 포인터를 자기 자신을 가리키도록 설정
	(*h)->key = -9999;  //헤드 노드는 data 값을 가지지 않으므로 쓰레기값을 넣어 실제 data가 아님을 명시해줌
	
	return 1; 
}

int freeList(listNode* h){  //이중 연결 리스트를 해제하는 함수 

	if(h->rlink == h) //h->rlink가 h를 가리키는지 확인
	{
		free(h); //h 해제
		return 1;
	}

	listNode* p = h->rlink; //리스트의 첫 번째 실제 노드를 가리키는 포인터

	listNode* prev = NULL; //이전 노드를 추적하기 위한 prev 변수 선언
	while(p != NULL && p != h) { //리스트의 마지막 노드까지 반복하여 해제함
		prev = p; 
		p = p->rlink; 
		free(prev); 
	}
	free(h); 
	return 0; //0을 반환하여 해제가 성공적으로 이루어졌음을 나타냄
}



void printList(listNode* h) { 
	int i = 0; 
	listNode* p; 

	printf("\n---PRINT\n");

	if(h == NULL) { 
		printf("Nothing to print....\n");
		return;
	}

	p = h->rlink;

	while(p != NULL && p != h) { 
		printf("[ [%d]=%d ] ", i, p->key); 
		p = p->rlink; 
		i++; 
	}
	printf("  items = %d\n", i);


	printf("\n---checking addresses of links\n");
	printf("-------------------------------\n");
	printf("head node: [llink]=%p, [head]=%p, [rlink]=%p\n", h->llink, h, h->rlink);

	i = 0; 
	p = h->rlink; 
	while(p != NULL && p != h) { 
		printf("[ [%d]=%d ] [llink]=%p, [node]=%p, [rlink]=%p\n", i, p->key, p->llink, p, p->rlink); 
		
		p = p->rlink;
		i++; 
	}

}




int insertLast(listNode* h, int key) {

	if (h == NULL) 
	return -1;

	listNode* node = (listNode*)malloc(sizeof(listNode)); 
	node->key = key; 
	node->rlink = NULL; 
	node->llink = NULL;

	if (h->rlink == h) 
	
	{
		h->rlink = node; 
		h->llink = node; 
		node->rlink = h; 
		node->llink = h; 
	} else {
		h->llink->rlink = node; 
		node->llink = h->llink; 
		h->llink = node; 
		node->rlink = h; 
	}

	return 1;
}



int deleteLast(listNode* h) {

	if (h->llink == h || h == NULL) 
	{
		printf("nothing to delete.\n");
		return 1;
	}

	listNode* nodetoremove = h->llink; 

	
	nodetoremove->llink->rlink = h; 
	h->llink = nodetoremove->llink; 

	free(nodetoremove); 

	return 1;
}



int insertFirst(listNode* h, int key) {

	listNode* node = (listNode*)malloc(sizeof(listNode)); 
	
	node->key = key; 
	node->rlink = NULL; 
	node->llink = NULL;


	node->rlink = h->rlink; 
	h->rlink->llink = node; 
	node->llink = h; 
	h->rlink = node;


	return 1;
}


int deleteFirst(listNode* h) {

	if (h == NULL || h->rlink == h) 
	{
		printf("nothing to delete.\n");
		return 0;
	}

	listNode* nodetoremove = h->rlink; 

	
	nodetoremove->rlink->llink = h; 
	h->rlink = nodetoremove->rlink; 

	free(nodetoremove); 

	return 1;

}


int invertList(listNode* h) {


	if(h->rlink == h || h == NULL) { 
		printf("nothing to invert...\n");
		return 0;
	}
	listNode *n = h->rlink; 
	listNode *trail = h; 
	listNode *middle = h; 

	
	h->llink = h->rlink;

	while(n != NULL && n != h){
		trail = middle; 
		middle = n;
		n = n->rlink;
		middle->rlink = trail; 
		middle->llink = n; 
	}

	h->rlink = middle; 

	return 0;
}




int insertNode(listNode* h, int key) {

	if(h == NULL) return -1; 

	listNode* node = (listNode*)malloc(sizeof(listNode)); 
	node->key = key; 
	node->llink = node->rlink = NULL; 

	if (h->rlink == h)  
	{
		insertFirst(h, key); 
		return 1;
	}

	listNode* n = h->rlink; 

	
	while(n != NULL && n != h) { 
		if(n->key >= key) { 
			
			if(n == h->rlink) { 
				insertFirst(h, key); 
			} else { 
				node->rlink = n; 
				node->llink = n->llink; 
				n->llink->rlink = node; 
				n->llink = node; 
			}
			return 0;
		}

		n = n->rlink; 
	}

	
	insertLast(h, key); 
	return 0;
}



int deleteNode(listNode* h, int key) {

	if (h->rlink == h || h == NULL)  
	{
		printf("nothing to delete.\n");
		return 0;
	}

	listNode* n = h->rlink;

	while(n != NULL && n != h) { 
		if(n->key == key) { 
			if(n == h->rlink) { 
				deleteFirst(h); 
			} else if (n->rlink == h){ 
				deleteLast(h); 
			} else { 
				n->llink->rlink = n->rlink; 
				n->rlink->llink = n->llink; 
				free(n); 
			}
			return 0;
		}

		n = n->rlink;
	}

	
	printf("cannot find the node for key = %d\n", key);
	return 0;
}

