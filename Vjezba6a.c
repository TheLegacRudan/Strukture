#include<stdio.h>
#include<time.h>

typedef struct stog *poz;
typedef struct stog {
	int x;
	poz next;
}st;

int push(int x,poz head){
	poz q;
	q = (poz)malloc(sizeof(st));
	q->x=x;
	
	q->next = head->next;
	head->next = q;
}
int pop(poz head) {
	poz q;
	q = head->next;

	head->next = q->next;
	free(q);
}
int random(){
	int gg = 100;
	int dg = 10;
	int num;
	num = (rand() %	(gg - dg + 1)) + dg;
	return num;
}


int main() {
	st pr1;
	pr1.next = NULL;
	srand(time(0));
	random();

	push(random(), &pr1);

	return 0;
}
