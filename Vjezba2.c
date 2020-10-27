#include<stdio.h>
#include<string.h>

typedef struct osoba *pos;
typedef struct osoba {
	char ime[20];
	char prezime[30];
	int god;
	pos next;
}os;

int unosP(int x,char imeU[],char prezimeU[], pos P) {
	pos q;
	q = (pos)malloc(sizeof(os));
	
	q->god = x;
	strcpy_s(q->ime,sizeof(q->ime), imeU);
	strcpy_s(q->prezime, sizeof(q->prezime), prezimeU);

	q->next = P->next;
	P->next = q;

	return 0;
}

int unosK(int x, char imeU[], char prezimeU[], pos P) {
	pos q;
	q = (pos)malloc(sizeof(os));

	q->god = x;
	strcpy_s(q->ime, sizeof(q->ime), imeU);
	strcpy_s(q->prezime, sizeof(q->prezime), prezimeU);

	while (P->next != NULL) {
		P = P->next;
	}

	P->next = q;
	q->next = NULL;

	return 0;
}

int ispis(pos P) {

	while (P != NULL) {
		printf("%s ", P->ime);
		printf("%s ", P->prezime);
		printf("%d\n", P->god);
	
		P = P->next;
	}
	return 0;
}

int trazi(char prezimeU[], pos P) {
	
	while (strcmp(prezimeU,P->prezime)!=0) {
		P = P->next;
	}
	printf("\n\n\nTRAZENA OSOBA JE:\n");
	printf("%s ", P->ime);
	printf("%s ", P->prezime);
	printf("%d\n\n\n", P->god);

	return 0;
}

int brisi(char prezimeU[], pos P) {
	pos q;
	q = (pos)malloc(sizeof(os));

	while (strcmp(prezimeU, P->prezime) != 0) {
		q = P;
		P = P->next;
		}

	q->next = P->next;
	free(P);


	return 0;
}



int main() {

	os head;
	head.next = NULL;
	char A[5];
	int br=0;
	int i = 0;
	int god_main=0;
	char ime_main[20];
	char prezime_main[30];

	//pocetna lista prije dodavanja
	unosP(1450, "Marko", "Marulic", &head);
	unosK(1891, "Tin", "Ujevic", &head);
	unosP(1487, "Petar", "Hektorovic", &head);
	unosK(1930, "Ivan", "Slamnig", &head);
	


	printf("Koliko osoba zelite dodati na pocetak?: ");
	scanf("%d", &br);

	for (i = 0; i < br; i++) {
		printf("Godina rodjenja: ");
		scanf("%d", &god_main);
		printf("Ime i prezime: ");
		scanf(" %s", ime_main);
		scanf(" %s", prezime_main);
		unosP(god_main, ime_main, prezime_main, &head);
		}

	printf("Koliko osoba zelite dodati na kraj?: ");
	scanf("%d", &br);

	for (i = 0; i < br; i++) {
		printf("Godina rodjenja: ");
		scanf("%d", &god_main);
		printf("Ime i prezime: ");
		scanf(" %s", ime_main);
		scanf(" %s", prezime_main);
		unosK(god_main, ime_main, prezime_main, &head);
	}

			
		//nisam napravio opcije za pokretanje ovih funkcija u konzoli jer
		//nije pisalo u zadatku, ali sve funckije rade pa je ovdje primjer brisanja
		//i trazenja po prezimenu
	ispis(head.next);
	trazi("Ujevic", &head);
	brisi("Ujevic", &head);
	printf("Ispis nakon izbrisane osobe\n\n");
	ispis(head.next);



	return 0;
}