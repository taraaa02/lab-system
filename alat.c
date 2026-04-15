#include "header.h"

void tampilAlat() {
    Alat alat[100];
    int jumlah;

    bacaAlat(alat, &jumlah);

    printf("\n=== DAFTAR ALAT ===\n");
    for (int i = 0; i < jumlah; i++) {
        printf("%d. %s (%d)\n", i+1, alat[i].nama, alat[i].stok);
    }
}

void tambahAlat() {
    FILE *fp = fopen("data/alat.txt", "a");
    char nama[50];
    int stok;

    printf("Nama alat: ");
    scanf("%s", nama);
    printf("Stok: ");
    scanf("%d", &stok);

    fprintf(fp, "%s %d\n", nama, stok);
    fclose(fp);

    printf("Alat ditambahkan\n");
}

void hapusAlat() {
    printf("Fitur hapus (bisa dikembangkan)\n");
}