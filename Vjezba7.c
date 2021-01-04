#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct stog* poz;
typedef struct stog {
	int a;
	poz next;
}st;

int unosP(int x, poz p) {
	poz q;
	q = (poz)malloc(sizeof(st));
	q->a = x;
	q->next = p->next;
	p->next = q;

	return 0;
}

//brise el s pocetka liste i vraca njegovu vrijednost
int pop(poz head) {
	poz q;
	int val;
	q = head->next;

	val = q->a;

	head->next = q->next;
	free(q);

	return val;
}

int funkc(char a[],poz adrhd) {
	
	int pom;
	int br = 0;
	char *token=strtok(a, " ");

	while (token != NULL) {
		
		if (isdigit(*token)) {
			pom = atoi(token);
			unosP(pom, adrhd);
		}
		else {
			switch (*token) {
			case '+':
				//u f-ju unos saljem zbroj prvog i drugog pop-a i adresu heada
				unosP(pop(adrhd) + pop(adrhd),adrhd);
				break;
			case '-':
				//oduzeto pomnozio s -1 jer se treba oduzimati sa stoga drugi minus prvi
				//umjesto da koristim pomocnu var. sam to invertirato na ovaj nacin
				unosP((pop(adrhd) - pop(adrhd))*(-1), adrhd);
				break;
			case '*':
				unosP(pop(adrhd) * pop(adrhd), adrhd);
				break;
			case '/':
				unosP(pop(adrhd) / pop(adrhd), adrhd);
				break;
			}
		}
		token = strtok(NULL, " ");		
	}	
	return 0;
};



int main() {
	char string[100];
	st head1;
	head1.next = NULL;
	
	FILE *fp;
	fp = fopen("zazad7.txt", "r");
	if (fp == NULL)
		printf("nije se open");
	
	//string ima sve rijeci iz filea
	fscanf(fp,"%[^\n]",string);	
	funkc(string, &head1);
	printf("%d", head1.next->a);
	
	return 0;
}