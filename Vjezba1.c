

#include <stdio.h>
#include <string.h>

typedef struct student {
	char ime[20];
	char prezime[30];
	int bod;
}stud;


int main() {

	stud *osoba;
	FILE* f;
	char a;
	
	int br=1;	//zato sta EOF zavrsava nakon zadnjeg broja a ne u novom redu tako da zadnji red nema \n na kraju
	float rel;
	int i;
	int pom;
	
	f = fopen("tekst.txt", "r");

	

	while ((a=fgetc(f)) != EOF) {
		if (a == '\n')
			br++;
		}

	rewind(f); //vracanje na pocetak Filea


	osoba = (stud*)malloc(br * sizeof(stud));
	for (i = 0; i < 5; i++) {
		fscanf(f, " %s %s %d", osoba[i].ime, osoba[i].prezime, &(osoba[i].bod));
		}
		
	for (i = 0; i < 5; i++) {
		printf("%s ", osoba[i].ime);
		printf("%s ", osoba[i].prezime);
		printf("[Aps. broj bodova: %d]  ", osoba[i].bod);
		
		rel = (float)osoba[i].bod/120 *100;
		printf("[Rel. broj bodova: %.2f]\n", rel);
	}

	fclose(f);

	return 0;
}

