#include "header.h"

void tampilAlat() {

    Alat alat[100];
    int jumlah = 0;
    FILE *fp = fopen("data/alat.txt", "r");
if (!fp) {
    printf("FILE TIDAK DITEMUKAN!\n");
    return;
}
fclose(fp);

    bacaAlat(alat, &jumlah);

    printf("\n=== DATA ALAT ===\n");
    for (int i = 0; i < jumlah; i++) {
        printf("%d | %s | %s | %s | %d | %d\n",
            alat[i].id,
            alat[i].nama,
            alat[i].merek,
            alat[i].model,
            alat[i].tahun,
            alat[i].stok);
    }
}

void tambahAlat() {
    Alat alat[100];
    int jumlah = 0;

    // 👉 BACA DULU FILE (MODE READ)
    FILE *fp = fopen("data/alat.txt", "r");
    if (fp != NULL) {
        while (fscanf(fp, "%d %49s %49s %49s %d %d",
            &alat[jumlah].id,
            alat[jumlah].nama,
            alat[jumlah].merek,
            alat[jumlah].model,
            &alat[jumlah].tahun,
            &alat[jumlah].stok) == 6) {
            jumlah++;
        }
        fclose(fp);
    }

    Alat baru;

    printf("Nama: ");
    scanf("%49s", baru.nama);

    printf("Merek: ");
    scanf("%49s", baru.merek);

    printf("Model: ");
    scanf("%49s", baru.model);

    printf("Tahun: ");
    scanf("%d", &baru.tahun);

    printf("Stok: ");
    scanf("%d", &baru.stok);

    baru.id = (jumlah == 0) ? 1 : alat[jumlah-1].id + 1;

    // 👉 TULIS FILE (MODE APPEND)
    fp = fopen("data/alat.txt", "a");
    if (!fp) {
        printf("Gagal buka file!\n");
        return;
    }

    fprintf(fp, "%d %s %s %s %d %d\n",
        baru.id, baru.nama, baru.merek,
        baru.model, baru.tahun, baru.stok);

    fclose(fp);

    printf("Berhasil tambah alat!\n");
}
void hapusAlat() {
    Alat alat[100];
    int jumlah = 0;

    bacaAlat(alat, &jumlah);

    int id;
    printf("Masukkan ID yang mau dihapus: ");
    scanf("%d", &id);

    int found = 0;
    for (int i = 0; i < jumlah; i++) {
        if (alat[i].id == id) {
            found = 1;
            for (int j = i; j < jumlah - 1; j++) {
                alat[j] = alat[j+1];
            }
            jumlah--;
            break;
        }
    }

    if (found) {
        tulisAlat(alat, jumlah);
        printf("Berhasil hapus alat\n");
    } else {
        printf("ID tidak ditemukan\n");
    }
}