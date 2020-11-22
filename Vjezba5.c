#include <stdio.h>

typedef struct lista *poz;
typedef struct lista{
	int x;
	poz next;
}ls;

int unosSort(poz p, int x) {
	poz q;
	q = (poz)malloc(sizeof(ls));
	q->x = x;

	
	while (1) {
		if (p->next == NULL) {
			q->next = NULL;
			p->next = q;
			return 0;
			}

		if((p->next->x)>=q->x){
			q->next = p->next;
			p->next = q;	
			return 0;
		}
		else {
			p = p->next;
		}
	}
	return 0;
}

poz presjek(poz p, poz q) {
	ls rez;
	rez.next = NULL;
	

	while ((p->next!=NULL)&&(q->next!=NULL)) {
		if ((p->next->x) == (q->next->x)) {
			
			upisK(&rez, p->next->x);

			p = p->next;
			q = q->next;
		}
		else if ((p->next->x) > (q->next->x)) {
			q = q->next;
		}
		else {
			p = p->next;
		}
	}
	return &rez;
}

poz unija(poz p, poz q) {
	ls rez;
	rez.next = NULL;

	while ((p->next != NULL) && (q->next != NULL)) {
		if ((p->next->x) == (q->next->x)) {
			upisK(&rez, p->next->x);

			p = p->next;
			q = q->next;
		}
		else if ((p->next->x) > (q->next->x)) {
			upisK(&rez, q->next->x);

			q = q->next;
		}
		else {
			upisK(&rez, p->next->x);

			p = p->next;
		}
	
	}
	if (p->next == NULL) {
		while (q->next != NULL) {
			upisK(&rez, q->next->x);
			q = q->next;
		}
	}
	else {
		while (p->next != NULL) {
			upisK(&rez, p->next->x);
			p = p->next;
		}
	}

	return &rez;
}

int ispis(poz P) {

	while (P != NULL) {
		printf("%d\n", P->x);

		P = P->next;
	}
	return 0;
}

int upisK(poz p,int x) {
	poz q;
	q = (poz)malloc(sizeof(ls));
	q->x = x;

	while (p->next != NULL)
		p = p->next;
	
	q->next = p->next;
	p->next = q;

	return 0;
}

int main() {

	ls head1;
	ls head2;

	head1.next = NULL;
	head2.next = NULL;

	unosSort(&head1, 7);
	unosSort(&head1, 4);
	unosSort(&head1, 10);
	unosSort(&head1, 4);
	unosSort(&head1, 1);
	unosSort(&head1, 8);
	unosSort(&head1, 2);
	unosSort(&head1, 25);
	unosSort(&head1, 290);
	unosSort(&head1, 289);
		
	unosSort(&head2, 5);
	unosSort(&head2, 1);	
	unosSort(&head2, 6);
	unosSort(&head2, 4);	
	unosSort(&head2, 3);
	unosSort(&head2, 11);
	unosSort(&head2, 7);

	ispis(head1.next);
	printf("\n\n");
	ispis(head2.next);
	printf("\n\n");
	ispis(presjek(&head1,&head2)->next);
	printf("\n\n");
	ispis(unija(&head1, &head2)->next);

	return 0;
}