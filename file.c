#include "header.h"

void bacaAkun(Akun akun[], int *jumlah) {
    FILE *fp = fopen("data/akun.txt", "r");
    *jumlah = 0;

    while (fscanf(fp, "%s %s %s",
        akun[*jumlah].username,
        akun[*jumlah].password,
        akun[*jumlah].role) != EOF) {
        (*jumlah)++;
    }

    fclose(fp);
}

void bacaAlat(Alat alat[], int *jumlah) {
    FILE *fp = fopen("data/alat.txt", "r");
    *jumlah = 0;

    while (fscanf(fp, "%s %d",
        alat[*jumlah].nama,
        &alat[*jumlah].stok) != EOF) {
        (*jumlah)++;
    }

    fclose(fp);
}