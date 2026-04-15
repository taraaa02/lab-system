#include "header.h"

int main(int argc, char *argv[]) {
    char username[50];
    char role[10];
    int pilih;

    if (!login(username, role, argc, argv)) {
        return 0;
    }

    do {
        printf("\n=== MENU ===\n");

        if (strcmp(role, "admin") == 0) {
            printf("1. Tampil Alat\n");
            printf("2. Tambah Alat\n");
            printf("3. Hapus Alat\n");
        } else {
            printf("1. Tampil Alat\n");
            printf("2. Pinjam Alat\n");
            printf("3. Lihat Pinjaman\n");
            printf("4. Kembalikan Alat\n");
        }

        printf("0. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilih);

        if (strcmp(role, "admin") == 0) {
            if (pilih == 1) tampilAlat();
            else if (pilih == 2) tambahAlat();
            else if (pilih == 3) hapusAlat();
        } else {
            if (pilih == 1) tampilAlat();
            else if (pilih == 2) pinjamAlat(username);
            else if (pilih == 3) lihatPinjaman(username);
            else if (pilih == 4) kembalikanAlat(username);
        }

    } while (pilih != 0);

    return 0;
}