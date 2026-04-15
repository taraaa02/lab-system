#include "header.h"

void bacaAkun(Akun akun[], int *jumlah) {
    FILE *fp = fopen("data/akun.txt", "r");
    *jumlah = 0;

    if (!fp) return;

    while (fscanf(fp, "%49s %49s %9s",
        akun[*jumlah].username,
        akun[*jumlah].password,
        akun[*jumlah].role) == 3) {
        (*jumlah)++;
    }

    fclose(fp);
}

void bacaAlat(Alat alat[], int *jumlah) {
    FILE *fp = fopen("data/alat.txt", "r");
    *jumlah = 0;

    if (!fp) return;

    while (fscanf(fp, "%d %49s %49s %49s %d %d",
        &alat[*jumlah].id,
        alat[*jumlah].nama,
        alat[*jumlah].merek,
        alat[*jumlah].model,
        &alat[*jumlah].tahun,
        &alat[*jumlah].stok) == 6) {
        (*jumlah)++;
    }

    fclose(fp);
}

void bacaPinjam(Pinjam pinjam[], int *jumlah) {
    FILE *fp = fopen("data/pinjam.txt", "r");
    *jumlah = 0;

    if (!fp) return;

    while (fscanf(fp, "%49s %d %49s %19s %d",
        pinjam[*jumlah].username,
        &pinjam[*jumlah].id_alat,
        pinjam[*jumlah].nama_alat,
        pinjam[*jumlah].tanggal,
        &pinjam[*jumlah].dikembalikan) == 5) {
        (*jumlah)++;
    }

    fclose(fp);
}

void tulisAlat(Alat alat[], int jumlah) {
    FILE *fp = fopen("data/alat.txt", "w");
    if (!fp) return;

    for (int i = 0; i < jumlah; i++) {
        fprintf(fp, "%d %s %s %s %d %d\n",
            alat[i].id,
            alat[i].nama,
            alat[i].merek,
            alat[i].model,
            alat[i].tahun,
            alat[i].stok);
    }

    fclose(fp);
}

void tulisPinjam(Pinjam pinjam[], int jumlah) {
    FILE *fp = fopen("data/pinjam.txt", "w");
    if (!fp) return;

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

void tambahUser() {
    FILE *fp = fopen("data/akun.txt", "a");
    if (!fp) return;

    Akun baru;

    printf("Username: ");
    scanf("%49s", baru.username);

    printf("Password: ");
    scanf("%49s", baru.password);

    strcpy(baru.role, "user");

    fprintf(fp, "%s %s %s\n",
        baru.username,
        baru.password,
        baru.role);

    fclose(fp);

    printf("User berhasil ditambahkan!\n");
}