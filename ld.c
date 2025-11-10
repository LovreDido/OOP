#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define RANDOM (rand() * rand())
int* generate(int n) {
	int* niz = (int*)malloc(n * sizeof(int));
	niz[0] = 1 + rand() % 5;
	for (int i = 1; i < n; i++) {
		niz[i] = niz[i - 1] + 1 + rand() % 5;
	}
	return niz;
}
void shuffle(int* niz, int n) {
	for (int i = 0; i < n; i++) {
		int j = RANDOM % n;
		int tmp = niz[i];
		niz[i] = niz[j];
		niz[j] = tmp;
	}
}
int presjek(int* skupA, int nA, int* skupB, int nB) {
    int count = 0;
    for (int i = 0; i < nA; i++) {
        for (int j = 0; j < nB; j++) {
            if (skupA[i] == skupB[j]) {
                count++;
                break; 
            }
        }
    }
    return count;
}
int cmpfunc(const void* a, const void* b) {
    int x = *(const int*)a;
    int y = *(const int*)b;
    return (x > y) - (x < y);
}

// 🔹 presjek_jedan_sortiran – koristi bsearch za traženje u sortiranom skupu B
int presjek_jedan_sortiran(int* skupA, int nA, int* skupB, int nB) {
    int count = 0;
    for (int i = 0; i < nA; i++) {
        if (bsearch(&skupA[i], skupB, nB, sizeof(int), cmpfunc) != NULL) {
            count++;
        }
    }
    return count;
}
int presjek_oba_sortirana(int* skupA, int nA, int* skupB, int nB) {
    int i = 0, j = 0, count = 0;
    while (i < nA && j < nB) {
        if (skupA[i] == skupB[j]) {
            count++;
            i++;
            j++;
        } else if (skupA[i] < skupB[j]) {
            i++;
        } else {
            j++;
        }
    }
    return count;
}
int presjek_po_indeksima(int* skupA, int nA, int* skupB, int nB) {
    // pronađi najveći broj iz oba skupa
    int maxA = skupA[0], maxB = skupB[0];
    for (int i = 1; i < nA; i++) if (skupA[i] > maxA) maxA = skupA[i];
    for (int i = 1; i < nB; i++) if (skupB[i] > maxB) maxB = skupB[i];
    int max = (maxA > maxB) ? maxA : maxB;

    // alociraj i postavi na 0
    int* indexA = (int*)calloc(max + 1, sizeof(int));
    int* indexB = (int*)calloc(max + 1, sizeof(int));
    if (!indexA || !indexB) {
        printf("Greska pri alokaciji!\n");
        exit(1);
    }

    // popuni maske
    for (int i = 0; i < nA; i++)
        indexA[skupA[i]] = 1;
    for (int i = 0; i < nB; i++)
        indexB[skupB[i]] = 1;

    // prebroji zajedničke
    int count = 0;
    for (int i = 0; i <= max; i++)
        if (indexA[i] && indexB[i])
            count++;

    free(indexA);
    free(indexB);
    return count;
}
void ispis(int* niz, int n, const char* name) {
    printf("%s: ", name);
    for (int i = 0; i < n; i++) {
        printf("%d ", niz[i]);
    }
    printf("\n");
}
int main() {
    
    srand((unsigned)time(NULL));

    int nA = 10, nB = 10;

    int* skupA = generate(nA);
    int* skupB = generate(nB);

    // Kopije da demonstriramo različite verzije
    int* skupA_shuffle = (int*)malloc(nA * sizeof(int));
    int* skupB_shuffle = (int*)malloc(nB * sizeof(int));
    for (int i = 0; i < nA; i++) skupA_shuffle[i] = skupA[i];
    for (int i = 0; i < nB; i++) skupB_shuffle[i] = skupB[i];

    shuffle(skupA_shuffle, nA);
    shuffle(skupB_shuffle, nB);

    // Ispis
    ispis(skupA_shuffle, nA, "Skup A (pomijesan)");
    ispis(skupB_shuffle, nB, "Skup B (pomijesan)");
    ispis(skupA, nA, "Skup A (sortiran)");
    ispis(skupB, nB, "Skup B (sortiran)");

    // 🔸 1. Obična verzija (ne sortiranih)
    int duzina1 = presjek(skupA_shuffle, nA, skupB_shuffle, nB);
    printf("\nDuzina presjeka (obicna funkcija): %d\n", duzina1);

    // 🔸 2. Jedan sortiran (koristi bsearch)
    int duzina2 = presjek_jedan_sortiran(skupA_shuffle, nA, skupB, nB);
    printf("Duzina presjeka (jedan sortiran, bsearch): %d\n", duzina2);

    // 🔸 3. Oba sortirana (dva indeksa)
    int duzina3 = presjek_oba_sortirana(skupA, nA, skupB, nB);
    printf("Duzina presjeka (oba sortirana): %d\n", duzina3);

    free(skupA);
    free(skupB);
    free(skupA_shuffle);
    free(skupB_shuffle);

    return 0;
}