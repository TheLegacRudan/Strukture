#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct dat *poz;
typedef struct dat {
	char ime[20];
	poz child;
	poz sibling;
	//za cd..
	poz father;
}dat;

//trazi zadnjeg siblinga za "makedir"
poz last(poz p) {
	while (p->sibling != NULL)
		p = p->sibling;
	
	return p;
}

//radi
int makedir (poz cur, char imeU[]){
	poz pom;
	poz novi;
	novi = (poz)malloc(sizeof(dat));
	
	strcpy(novi->ime, imeU);
	novi->sibling = NULL;
	novi->child = NULL;
	novi->father = cur;
	//samo ako direktorij nema prosle djece
	if (cur->child == NULL) {
		//prvi child currenta
		cur->child = novi;		
	}
	//ako current vec ima dicu
	else {
		//prvi child, spustamo se u dir currenta
		pom = cur->child;
		//zadnji child-tj zadnji sibling prvog childa
		pom = last(pom);
		//desno od zadnjega stavljamo novog
		pom->sibling = novi;			
	}
	return 0;
}
//poz jer vraca current
poz changedir(poz cur,char imeU[] ){
	poz pom;
	//ako nema childova onda ne moze ni prebacit dir
	//vraca current jer se dir nije mijenjao
	if (cur->child == NULL) {
		printf("Error 404\n");
		return cur;
	}
	//spustamo se u prvi child
	pom = cur->child;

	while (strcmp(imeU, pom->ime) != 0) {
		pom = pom->sibling;
		if (pom == NULL) {
			printf("Error 404\n");
			return cur;
		}
	}
	return pom;
}

int listdir(poz cur) {
	poz pom;
	if (cur->child == NULL) {
		printf("\n\t(empty)\n\n");
		return 0;
	}
	pom = cur->child;
	printf("\n");
	while (pom != NULL) {
		printf("\t%s\n",pom->ime);
		pom = pom->sibling;
	}
	printf("\n");
	return 0;
}

poz changetolast(poz cur) {
	if (cur->father==NULL)
		return cur;
	
	return cur->father;
}


int main() {
	dat C;
	poz current;	

	char imeM[20];
	char naredba[10];

	//default dir
	strcpy(C.ime, "C");
	C.child = NULL;
	C.sibling = NULL;
	C.father = NULL;
	//na pocetku
	current = &C;
			
	printf("\nIzaberite naredbu:\n\tmd - make directory\n\tcd - change directory\n\tcd.. - previous directory\n\tdir - list directory\n\tex - exit\n\n");
	
	while (1) {
		printf("%s:> ", current->ime);
		scanf("%s", naredba);
		if(!strcmp(naredba,"md")){						
			scanf("%s", imeM);
			makedir(current, imeM);
		}
		if (!strcmp(naredba, "cd")) {
			scanf("%s", imeM);
			//vracamo current u koji ulazimo nakon changea
			current = changedir(current, imeM);
		}
		if (!strcmp(naredba, "cd..")) {
			current=changetolast(current);
		}
		if (!strcmp(naredba, "dir")) {
			listdir(current);
		}
		if (!strcmp(naredba, "ex"))
			break;		
	}
	return 0;
}