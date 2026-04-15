#include "header.h"
#include <time.h>

static void getTanggal(char *buffer) {
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    strftime(buffer, 20, "%d-%m-%Y", tm_info);
}

void pinjamAlat(char *username) {
    Alat alat[100];
    Pinjam pinjam[200];
    int jmlAlat = 0, jmlPinjam = 0;

    bacaAlat(alat, &jmlAlat);
    bacaPinjam(pinjam, &jmlPinjam);

    int idPilih;
    printf("ID alat: ");
    scanf("%d", &idPilih);

    for (int i = 0; i < jmlAlat; i++) {
        if (alat[i].id == idPilih && alat[i].stok > 0) {

            Pinjam baru;
            strncpy(baru.username, username, 49);
            baru.username[49] = '\0';

            baru.id_alat = alat[i].id;

            strncpy(baru.nama_alat, alat[i].nama, 49);
            baru.nama_alat[49] = '\0';

            getTanggal(baru.tanggal);
            baru.dikembalikan = 0;

            pinjam[jmlPinjam++] = baru;
            alat[i].stok--;

            tulisAlat(alat, jmlAlat);
            tulisPinjam(pinjam, jmlPinjam);

            printf("Berhasil pinjam!\n");
            return;
        }
    }

    printf("Gagal pinjam\n");
}

void lihatPinjaman(char *username) {
    Pinjam pinjam[200];
    int jumlah = 0;

    bacaPinjam(pinjam, &jumlah);

    for (int i = 0; i < jumlah; i++) {
        if (strcmp(pinjam[i].username, username) == 0) {
            printf("%d | %s | %s | %d\n",
                pinjam[i].id_alat,
                pinjam[i].nama_alat,
                pinjam[i].tanggal,
                pinjam[i].dikembalikan);
        }
    }
}

void kembalikanAlat(char *username) {
    Alat alat[100];
    Pinjam pinjam[200];
    int jmlAlat = 0, jmlPinjam = 0;

    bacaAlat(alat, &jmlAlat);
    bacaPinjam(pinjam, &jmlPinjam);

    int id;
    printf("ID kembali: ");
    scanf("%d", &id);

    for (int i = 0; i < jmlPinjam; i++) {
        if (pinjam[i].id_alat == id &&
            strcmp(pinjam[i].username, username) == 0 &&
            pinjam[i].dikembalikan == 0) {

            pinjam[i].dikembalikan = 1;

            for (int j = 0; j < jmlAlat; j++) {
                if (alat[j].id == id) {
                    alat[j].stok++;
                }
            }

            tulisAlat(alat, jmlAlat);
            tulisPinjam(pinjam, jmlPinjam);

            printf("Berhasil kembali\n");
            return;
        }
    }

    printf("Gagal kembali\n");
}