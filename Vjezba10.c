#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//proot - Position ROOT
typedef struct stablo* proot;
//pol - POsition Lista
typedef struct lista* pol;

//lista rootova
typedef struct lista {
	//pokazivac rootova
	proot root;
	//obican next
	pol next;
}ls;

typedef struct stablo{
	char a;
	proot lt;
	proot rt;
}st;

//pushamo rootove na stog/listu
int push(proot rootU, pol p){
	//memorija za novi el
	pol q;
	q = (pol)malloc(sizeof(ls));
	//klasicno umetanje
	q->next = p->next;
	p->next = q;
	//root je root
	q->root = rootU;
	return 0;
}
//prima head
proot pop(pol p) {
	pol q;
	proot ret;
	q = p->next;
	//da sacuvamo root vrijednost
	ret = q->root;
	p->next = q->next;
	free(q);
	//vracamo root vrijednost
	return ret;
}

//prima string i parsira ga, tvori stablo
proot fun(char stringU[]) {
	//deklariramo listu head za push i pop
	pol head;
	head = (pol)malloc(sizeof(ls));
	head->next = NULL;
	head->root = NULL;

	char* token;
	//prvi char u stringu
	token = strtok(stringU, " ");
	//do zadnjeg chara
	while (token != NULL) {
		if (isdigit(*token)) {
			//stavit ovo u f-ju poslin
			//stablo s praznim lt i rt
			proot root;
			root = (proot)malloc(sizeof(st));
			root->lt = NULL;
			root->rt = NULL;			
			root->a = *token;
			
			push(root, head);
		}
		else {
			//pop drugi pa prvi iz liste
			//onda znak (+-*/) postaje root, livo dite =prvi pop
			//pushamo novi root na stog
			proot root1;
			root1 = (proot)malloc(sizeof(st));
			root1->lt = pop(head);
			root1->rt = pop(head);
			root1->a = *token;
			push(root1, head);
		}
		//mijenja char na slijedeci
		token = strtok(NULL, " ");
	}
	//provjera
	if (head->next == NULL) {
		return NULL;
	}
	return head->next->root;	
}
int print(proot cur,FILE*fp2) {
	if (NULL == cur)
		return -1;
	if (cur->lt != NULL && cur->rt != NULL)
		fprintf(fp2,"(");
	
	print(cur->rt,fp2);
	fprintf(fp2,"%c ", cur->a);
	print(cur->lt,fp2);
	
	if (cur->lt != NULL && cur->rt != NULL)
		fprintf(fp2,"(");

	return 0;
}

int main() {
	char string[100];
	//citanje (iz txt filea za 7. zdk)
	FILE* fp;
	fp = fopen("zazad7.txt", "r");
	//ispis
	FILE* fp2;
	fp2 = fopen("ispis.txt", "w");

	//unos cijelog stringa u memoriju
	fscanf(fp,"%[^EOF]", string);
	print(fun(string),fp2);

	fclose(fp);
	fclose(fp2);

	return 0;
}
