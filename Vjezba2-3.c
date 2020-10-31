#include<stdio.h>
#include<string.h>
#include<stdlib.h>

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
	strcpy(q->ime, imeU);
	strcpy(q->prezime, prezimeU);

	q->next = P->next;
	P->next = q;

	return 0;
}

int unosK(int x, char imeU[], char prezimeU[], pos P) {
	pos q;
	q = (pos)malloc(sizeof(os));

	q->god = x;
	strcpy(q->ime, imeU);
	strcpy(q->prezime, prezimeU);

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
		if(P==NULL){
		    printf("\nNema trazenog prezimena u listi - za trazenje(-1)\n\n");
		    return -1;
		    }
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
		if(P==NULL){
		    printf("\nNema trazenog prezimena u listi - za brisanje(-1)\n\n");
		    return -1;
		    }
		}

	q->next = P->next;
	free(P);

	return 0;
}
//prezime iza kojeg el zelimo dodat, sastavnice novog el (ime,god,prez), pos head
int dod_eiz(char elem[], int x, char imeU[], char prezimeU[], pos P) {

    pos q;
    q = (pos)malloc(sizeof(os));

    q->god = x;
    strcpy(q->ime, imeU);
    strcpy(q->prezime,prezimeU);
        
    while (strcmp(P->prezime, elem) != 0) {
        P = P->next;
        if(P==NULL){
            printf("\nNema trazenog prezimena u listi - za dodavanje iza(-1)\n\n");
		    return -1;
            }
    }

    q->next = P->next;
    P->next = q;
             
    return 0;
}

int dod_eis(char elem[], int x, char imeU[], char prezimeU[], pos P) {

    pos q,r;
    q = (pos)malloc(sizeof(os));
    r= (pos)malloc(sizeof(os));

    q->god = x;
    strcpy(q->ime, imeU);
    strcpy(q->prezime, prezimeU);

    while (P != NULL) {
        if (strcmp(P->next->prezime, elem) == 0)
            break;

        P = P->next;
         if(P->next==NULL){
            printf("\nNema trazenog prezimena u listi - za dodavanje ispred(-1)\n\n");
		    return -1;
            }
    }

    q->next = P->next;
    P->next = q;

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

	ispis(head.next);
	trazi("Ujevic", &head);
	brisi("Hektorovic", &head);
	printf("Ispis nakon izbrisane osobe\n\n");
	ispis(head.next);
	dod_eiz("Slamnig", 1745, "Dodan", "Iza", &head);
    printf("\n\nIspis nakon dodane osobe iza odredjenog elementa \n\n");
    ispis(head.next);
    printf("\n\nIspis nakon dodane osobe ispred odredjenog elementa \n\n");
    dod_eis("Slamnig", 1000, "Dodan", "Ispred",&head);
    ispis(head.next);

	return 0;
}
