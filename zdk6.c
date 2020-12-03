#include<stdio.h>
#include<time.h>

typedef struct red *poz;
typedef struct red {
	int x;
	poz next;
}rd;

int push(int x,poz head){
	poz q;
	q = (poz)malloc(sizeof(rd));

	q->next = head->next;
	head->next = q;

	return 0;
}

int pop(poz q) {
	poz pr;

	while (q->next != NULL) {
		pr = q;
		q = q->next;
	}
	
	pr->next = NULL;
	free(q);

	return 0;
}
int random(){
	int gg = 100;
	int dg = 10;
	int num;
	num = (rand() %	(gg - dg + 1)) + dg;
	return num;
}


int main() {
	rd pr1;
	pr1.next = NULL;
	srand(time(0));
	random();

	push(random(), &pr1);

	return 0;
}