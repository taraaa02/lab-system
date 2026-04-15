// pinjam.c - Dibuat oleh: LUTHFI
// Fungsi: Pinjam alat, lihat pinjaman, kembalikan alat (khusus User)

#include "header.h"
#include <time.h>

// ===================== AMBIL TANGGAL HARI INI =====================

static void getTanggal(char *buffer) {
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    strftime(buffer, 20, "%d-%m-%Y", tm_info);
}

// ===================== PINJAM ALAT =====================

void pinjamAlat(char *username) {
    Alat alat[100];
    Pinjam pinjam[200];
    int jmlAlat = 0, jmlPinjam = 0;

    bacaAlat(alat, &jmlAlat);
    bacaPinjam(pinjam, &jmlPinjam);

    if (jmlAlat == 0) {
        printf("Belum ada alat yang tersedia!\n");
        return;
    }

    // Tampilkan alat yang stoknya > 0
    printf("\n--- ALAT TERSEDIA ---\n");
    printf("╔════╦══════════════════════════╦══════╗\n");
    printf("║ ID ║ Nama Alat                ║ Stok ║\n");
    printf("╠════╬══════════════════════════╬══════╣\n");
    int adaStok = 0;
    for (int i = 0; i < jmlAlat; i++) {
        if (alat[i].stok > 0) {
            printf("║ %-2d ║ %-24s ║  %-3d ║\n", alat[i].id, alat[i].nama, alat[i].stok);
            adaStok = 1;
        }
    }
    printf("╚════╩══════════════════════════╩══════╝\n");

    if (!adaStok) {
        printf("Semua alat sedang habis dipinjam!\n");
        return;
    }

    int idPilih;
    printf("\nMasukkan ID alat yang ingin dipinjam (0 batal): ");
    scanf("%d", &idPilih);
    if (idPilih == 0) return;

    // Cari alat
    for (int i = 0; i < jmlAlat; i++) {
        if (alat[i].id == idPilih) {
            if (alat[i].stok <= 0) {
                printf("✗ Stok alat habis!\n");
                return;
            }

            // Cek apakah user sudah meminjam alat yang sama
            for (int j = 0; j < jmlPinjam; j++) {
                if (strcmp(pinjam[j].username, username) == 0 &&
                    pinjam[j].id_alat == idPilih &&
                    pinjam[j].dikembalikan == 0) {
                    printf("✗ Kamu sudah meminjam alat ini!\n");
                    return;
                }
            }

            // Catat pinjaman baru
            Pinjam baru;
            strncpy(baru.username, username, 49);
            baru.id_alat = alat[i].id;
            strncpy(baru.nama_alat, alat[i].nama, 99);
            getTanggal(baru.tanggal);
            baru.dikembalikan = 0;

            pinjam[jmlPinjam] = baru;
            jmlPinjam++;

            // Kurangi stok
            alat[i].stok--;

            tulisAlat(alat, jmlAlat);
            tulisPinjam(pinjam, jmlPinjam);

            printf("✓ Berhasil meminjam '%s' pada %s\n", alat[i].nama, baru.tanggal);
            return;
        }
    }
    printf("✗ ID alat tidak ditemukan!\n");
}

// ===================== LIHAT PINJAMAN USER =====================

void lihatPinjaman(char *username) {
    Pinjam pinjam[200];
    int jumlah = 0;
    bacaPinjam(pinjam, &jumlah);

    printf("\n--- RIWAYAT PINJAMAN: %s ---\n", username);
    printf("╔════╦══════════════════════════╦════════════╦════════════╗\n");
    printf("║ ID ║ Nama Alat                ║ Tanggal    ║ Status     ║\n");
    printf("╠════╬══════════════════════════╬════════════╬════════════╣\n");

    int ada = 0;
    for (int i = 0; i < jumlah; i++) {
        if (strcmp(pinjam[i].username, username) == 0) {
            char *status = (pinjam[i].dikembalikan == 1) ? "Dikembalikan" : "Dipinjam";
            printf("║ %-2d ║ %-24s ║ %-10s ║ %-10s ║\n",
                   pinjam[i].id_alat, pinjam[i].nama_alat,
                   pinjam[i].tanggal, status);
            ada = 1;
        }
    }

    if (!ada) {
        printf("║        Belum ada riwayat pinjaman                        ║\n");
    }
    printf("╚════╩══════════════════════════╩════════════╩════════════╝\n");
}

// ===================== KEMBALIKAN ALAT =====================

void kembalikanAlat(char *username) {
    Alat alat[100];
    Pinjam pinjam[200];
    int jmlAlat = 0, jmlPinjam = 0;

    bacaAlat(alat, &jmlAlat);
    bacaPinjam(pinjam, &jmlPinjam);

    printf("\n--- ALAT YANG SEDANG DIPINJAM ---\n");
    printf("╔════╦══════════════════════════╦════════════╗\n");
    printf("║ ID ║ Nama Alat                ║ Tanggal    ║\n");
    printf("╠════╬══════════════════════════╬════════════╣\n");

    int ada = 0;
    for (int i = 0; i < jmlPinjam; i++) {
        if (strcmp(pinjam[i].username, username) == 0 && pinjam[i].dikembalikan == 0) {
            printf("║ %-2d ║ %-24s ║ %-10s ║\n",
                   pinjam[i].id_alat, pinjam[i].nama_alat, pinjam[i].tanggal);
            ada = 1;
        }
    }
    printf("╚════╩══════════════════════════╩════════════╝\n");

    if (!ada) {
        printf("Tidak ada alat yang sedang dipinjam.\n");
        return;
    }

    int idKembali;
    printf("\nMasukkan ID alat yang dikembalikan (0 batal): ");
    scanf("%d", &idKembali);
    if (idKembali == 0) return;

    for (int i = 0; i < jmlPinjam; i++) {
        if (strcmp(pinjam[i].username, username) == 0 &&
            pinjam[i].id_alat == idKembali &&
            pinjam[i].dikembalikan == 0) {

            pinjam[i].dikembalikan = 1;

            // Tambah stok kembali
            for (int j = 0; j < jmlAlat; j++) {
                if (alat[j].id == idKembali) {
                    alat[j].stok++;
                    break;
                }
            }

            tulisAlat(alat, jmlAlat);
            tulisPinjam(pinjam, jmlPinjam);
            printf("✓ Alat '%s' berhasil dikembalikan!\n", pinjam[i].nama_alat);
            return;
        }
    }
    printf("✗ Data pinjaman tidak ditemukan!\n");
}

// ===================== MENU PINJAM =====================

void menuPinjam(char *username) {
    int pilihan;
    do {
        printf("\n╔══════════════════════════════╗\n");
        printf("║      MENU PEMINJAMAN ALAT    ║\n");
        printf("╠══════════════════════════════╣\n");
        printf("║  1. Pinjam Alat              ║\n");
        printf("║  2. Lihat Pinjaman Saya      ║\n");
        printf("║  3. Kembalikan Alat          ║\n");
        printf("║  0. Kembali                  ║\n");
        printf("╚══════════════════════════════╝\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1: pinjamAlat(username); break;
            case 2: lihatPinjaman(username); break;
            case 3: kembalikanAlat(username); break;
            case 0: printf("Kembali ke menu utama...\n"); break;
            default: printf("✗ Pilihan tidak valid!\n");
        }
    } while (pilihan != 0);
}
