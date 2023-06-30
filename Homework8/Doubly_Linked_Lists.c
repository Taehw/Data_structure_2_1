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

void printList(listNode* h) { //원형 이중 연결 리스트의 내용을 출력하는 함수.
	int i = 0; //i는 노드의 인덱스를 나타내는 변수
	listNode* p; //현재 노드를 가리키는 포인터 변수 p 선언

	printf("\n---PRINT\n");

	if(h == NULL) {  //리스트가 비어있는 경우 해당 메시지를 출력하고 함수 종료
		printf("Nothing to print....\n");
		return;
	}

	p = h->rlink; //리스트의 첫 번째 실제 노드를 가리키는 포인터

	while(p != NULL && p != h) { //리스트의 첫 번째 노드부터 마지막 노드까지 반복하여 각 노드의 'key'값을 출력
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
	} //리스트의 각 노도와 해당 노드의 링크들의 주소를 확인하기 위한 반복문

}




int insertLast(listNode* h, int key) { //이중 연결 리스트의 마지막에 새로운 노드를 삽입하는 함숭

	if (h == NULL) 
	return -1;

	listNode* node = (listNode*)malloc(sizeof(listNode)); //listNode의 크기만큼 node 포인터 변수에 동적할당
	node->key = key;  //node의 key값에 key를 할당
	node->rlink = NULL; //node의 rlink을 null값으로 초기화
	node->llink = NULL; //node의 llink을 null값으로 초기화

	if (h->rlink == h) //실제 노드를 삽입하는 부분 h->rlink == h로 리스트가 비어있는지 확인
	
	{
		h->rlink = node; 
		h->llink = node; 
		node->rlink = h; 
		node->llink = h; //조건이 참일시 비어있는 리스트에 node를 첫 번째 노드로 삽입
	} else {
		h->llink->rlink = node; 
		node->llink = h->llink; 
		h->llink = node; 
		node->rlink = h; 
	} //리스트가 비어 있지 않다면 node를 리스트의 마지막에 삽입

	return 1;
}



int deleteLast(listNode* h) { //이중 연결 리스트의 마지막 노드를 삭제하는 함수

	if (h->llink == h || h == NULL) 
	{
		printf("nothing to delete.\n");
		return 1;
	} //매개변수 h가 NULL값이거나 h의 llink가 h 자제를 가리키는지 확인, 삭제할 노드가 없으면 해당메시지를 출력후 함수 종료

	listNode* nodetoremove = h->llink; //삭제할 마지막 노드를 가리키는 nodetoremove 포인터 변수 생성하고 h의 llink로 초기화 

	
	nodetoremove->llink->rlink = h; //nodetoremove의 rlink의 llink에 h 저장
	h->llink = nodetoremove->llink; //h의 rlink에 nodetoremove의 rlink 저장

	free(nodetoremove);  //nodetoremove에 할당된 메모리 해젬

	return 1;
}



int insertFirst(listNode* h, int key) { //이중 연결 리스트의 첫번째에 새로운 노드를 삽입하는 함수

	listNode* node = (listNode*)malloc(sizeof(listNode)); //node를 listNode의 크기만큼 동적으로 할당하고 초기화
	
	node->key = key; //key값을 node의 key 멤버에 저장
	node->rlink = NULL; 
	node->llink = NULL; //node의 링크인 rlink와 llink를 NULL로 초기화


	node->rlink = h->rlink; //node의 오른족 링크를 리스트의 첫 번째 노드로 설정
	h->rlink->llink = node; 
	node->llink = h;  //node의 llink를 h로 설정
	h->rlink = node;


	return 1;
}


int deleteFirst(listNode* h) { //이중 연결 리스트에서 첫 번째 노드를 삭제하는 함수

	if (h == NULL || h->rlink == h) 
	{
		printf("nothing to delete.\n");
		return 0;
	} //함수는 h가 NULL이거나 리스트에 노드가 하나만 있는 경우 해당메시지를 출력하고 함수 종료

	listNode* nodetoremove = h->rlink; //h의 rlink를 nodetoremove 포인터 변수에 할당    

	
	nodetoremove->rlink->llink = h; //nodetoremove의 rlink의 llink에 h 저장
	h->rlink = nodetoremove->rlink; //h의 다음 노드를 nodetoremove의 다음 노드로 설정

	free(nodetoremove); //nodetoremove에 할당된 메모리 해제

	return 1; //삭제가 성공했으면 1을 반환

}


int invertList(listNode* h) { //이중 연결 리스트의 순서를 반전 시키는 함수


	if(h->rlink == h || h == NULL) { //매겨변수로 받은 이중연결리스트 h가 비어있거나 하나의 노드만 가지고 있는 경우 해당 메시지 출력하고 함수 종료
		printf("nothing to invert...\n");
		return 0;
	}
	listNode *n = h->rlink; //if의 조건문을 만족하지 않는 경우 포인터 변수 n을 선언하고 h의 rlink를 할당
	listNode *trail = h; 
	listNode *middle = h; 

	
	h->llink = h->rlink; //trail 현재 노드의 이전 노드를 middle은 현재 노드를 가리키도록 함

	while(n != NULL && n != h){
		trail = middle; 
		middle = n;
		n = n->rlink;
		middle->rlink = trail; 
		middle->llink = n; 
	} //n이 널값이 n이 h와 같지 않을 때까지 반복문 실행

	h->rlink = middle; //리스트의 첫번째 노드를 변경하여 리스트의 순서가 반전되도록 함

	return 0;
}




int insertNode(listNode* h, int key) { //이중 연결 리스트에 새로운 노드를 삽입하는 함수

	if(h == NULL) return -1; //인자로 받은 리스트가 비어있는 리스트인지 확인

	listNode* node = (listNode*)malloc(sizeof(listNode)); //리스트가 비어있지 않은 경우 새로운 노드에 동적할당
	node->key = key; //node의 key에 인자로 받은 key값을 할당
	node->llink = node->rlink = NULL; //node의 llink,rlinkd을 NULL로 초기화

	if (h->rlink == h)  //h의 rlink가 h일 경우
	{
		insertFirst(h, key); //첫번째 노드에 key값을 넣는다.
		return 1;
	}

	listNode* n = h->rlink; //if의 조건을 만족하지 않을경우 포인터 변수 n을 선언하고 h의 rlink를 가리키도록 함.

	
	while(n != NULL && n != h) { //n이 널값이 아니고 n이 h가 아닐때 해당 반복문을 수행
		if(n->key >= key) { //n의 key가 입력받은 key값보다 클경우
			
			if(n == h->rlink) { //n이 h의 rlink인 경우
				insertFirst(h, key); //key값을 첫번째 노드에 삽입
			} else { //그 밖인 경우
				node->rlink = n; //node의 rlink에 n저장
				node->llink = n->llink; //node의 llink에 n의 llink 저장
				n->llink->rlink = node; //n의 llink의 rlink에 node를 할당
				n->llink = node; //n의 llink의 node를 할당
			}
			return 0;
		}

		n = n->rlink; 
	}

	
	insertLast(h, key); //연결리스트의 마지막에 새로운 노드를 삽입
	return 0; 
}

/**
 * list에서 key에 대한 노드 삭제
 */


int deleteNode(listNode* h, int key) {

	if (h->rlink == h || h == NULL)  //리스트가 비어있거나 h가 NULL인 경우 해당 메시지 출력후 함수 종료
	{
		printf("nothing to delete.\n"); 
		return 0;
	}

	listNode* n = h->rlink; //포인터변수 n에 h의 rlink 저장

	while(n != NULL && n != h) { //n이 NULL이 아니고 h가 아니며 해당 반복분 실행
		if(n->key == key) { //인자로 받은 key값고 n의 key값이 다를 때 
			if(n == h->rlink) { //첫번째 노드인 경우
				deleteFirst(h); //첫번째 노드삭제
			} else if (n->rlink == h){  //마지막 노드인경우
				deleteLast(h); //마지막 노드삭제
			} else { //중간인경우
				n->llink->rlink = n->rlink; //n의 llink의 rlink에 n의 rlink 할당
				n->rlink->llink = n->llink; //n의 rlink의 llink에 n의 llink 할당
				free(n); //n에 할당된 메모리 해제
			}
			return 0;
		}

		n = n->rlink;
	}

	
	printf("cannot find the node for key = %d\n", key);
	return 0;
}

