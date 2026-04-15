#include "header.h"

void bacaAkun(Akun akun[], int *jumlah) {
    FILE *fp = fopen("data/akun.txt", "r");
    *jumlah = 0;

    if (fp == NULL) return;

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

    if (fp == NULL) return;

    while (fscanf(fp, "%d %s %d",
        &alat[*jumlah].id,
        alat[*jumlah].nama,
        &alat[*jumlah].stok) != EOF) {
        (*jumlah)++;
    }

    fclose(fp);
}

void bacaPinjam(Pinjam pinjam[], int *jumlah) {
    FILE *fp = fopen("data/pinjam.txt", "r");
    *jumlah = 0;

    if (fp == NULL) return;

    while (fscanf(fp, "%s %d %s %s %d",
        pinjam[*jumlah].username,
        &pinjam[*jumlah].id_alat,
        pinjam[*jumlah].nama_alat,
        pinjam[*jumlah].tanggal,
        &pinjam[*jumlah].dikembalikan) != EOF) {
        (*jumlah)++;
    }

    fclose(fp);
}

void tulisAlat(Alat alat[], int jumlah) {
    FILE *fp = fopen("data/alat.txt", "w");

    for (int i = 0; i < jumlah; i++) {
        fprintf(fp, "%d %s %d\n",
            alat[i].id,
            alat[i].nama,
            alat[i].stok);
    }

    fclose(fp);
}

void tulisPinjam(Pinjam pinjam[], int jumlah) {
    FILE *fp = fopen("data/pinjam.txt", "w");

    for (int i = 0; i < jumlah; i++) {
        fprintf(fp, "%s %d %s %s %d\n",
            pinjam[i].username,
            pinjam[i].id_alat,
            pinjam[i].nama_alat,
            pinjam[i].tanggal,
            pinjam[i].dikembalikan);
    }

    fclose(fp);
}