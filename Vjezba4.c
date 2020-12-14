#include <stdio.h>
#include <stdlib.h>

typedef struct polinomi* poz;
typedef struct polinomi{
    int exp;
    int koef;
    poz next;
} pol;

//svaki polinom je zapisan u novom retku
int br(char* name){ 
    FILE* fp = NULL;
    fp = fopen(name, "r");

    int n = 0;
    char buffer[256];

    if (fp == NULL) {
        printf("Error\n");
        return -1;
    }

    while (fgets(buffer, 256, fp) != NULL) {
        ++n;
    }

    fclose(fp);
    return n;
}

int sort(poz temp, int a, int b) {
    poz p = (poz)malloc(sizeof(pol));

    p->koef = a;
    p->exp = b;

    while (temp->next != NULL && temp->next->exp < p->exp) {
        temp = temp->next;
    }
    p->next = temp->next;
    temp->next = p;

    return 0;
}

int upis(char* dat, poz temp) {
    FILE* fp = NULL;
    fp = fopen(dat, "r");

    if (fp == NULL) {
        printf("Error\n");
        return -1;
    }

    for (int i = 0; i < br(dat); i++) {
        fscanf(fp, "%d %d", &temp->koef, &temp->exp);
        sort(temp, temp->koef, temp->exp);
    }

    fclose(fp);
    return 0;
}
int zbroji(poz temp1, poz temp2, poz rez) {
    poz p = temp1->next;
    poz q = temp2->next;

    if (p == NULL && q == NULL) {
        printf("Prazne liste\n");
        return -1;
    }

    while (p != NULL && q != NULL) {
        if (p->exp == q->exp) {
            sort(rez, p->koef + q->koef, p->exp);

            p = p->next;
            q = q->next;
        }

        else if (p->exp < q->exp) {
            sort(rez, p->koef, p->exp);
            p = p->next;
        }

        else {
            sort(rez, q->koef, q->exp);
            q = q->next;
        }
    }

    while (p != NULL) {
        sort(rez, p->koef, p->exp);
        p = p->next;
    }

    while (q != NULL) {
        sort(rez, q->koef, q->exp);
        q = q->next;
    }
    return 0;
}

int mnozi(poz temp1, poz temp2, poz r) {
    poz p = NULL;
    poz q = NULL;

    for (p = temp1->next; p != NULL; p = p->next) {
        for (q = temp2->next; q != NULL; q = q->next) {
            sort(r, p->koef * q->koef, p->exp + q->exp);
        }
    }
    return 0;
}

int ispis(poz p) {

    while (p != NULL) {
        printf("%d  %d\n", p->koef, p->exp);
        p = p->next;
    }
    return 0;
}


int main(){
    poz l1, l2, r1, r2;

    l1 = (poz)malloc(sizeof(pol));
    l1->next = NULL;
    l2 = (poz)malloc(sizeof(pol));
    l2->next = NULL;
    r1 = (poz)malloc(sizeof(pol));
    r1->next = NULL;
    r2 = (poz)malloc(sizeof(pol));
    r2->next = NULL;

    upis("pol1.txt", l1);
    upis("pol2.txt", l2);
    
    printf("Zbroj :\n");
    zbroji(l1, l2, r1);
    ispis(r1->next);
    printf("\n\n\n");
    printf("Umnozak :\n");
    mnozi(l1, l2, r2);
    ispis(r2->next);
    printf("\n\n\n"); 

    return 0;
}

