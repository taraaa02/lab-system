#include "header.h"

int login(char *username, char *role, int argc, char *argv[]) {
    Akun akun[100];
    int jumlah = 0;
    char inputUser[50], inputPass[50];

    bacaAkun(akun, &jumlah);

    printf("\n=== LOGIN ===\n");
    printf("Username: ");
    scanf("%49s", inputUser);
    printf("Password: ");
    scanf("%49s", inputPass);

    for (int i = 0; i < jumlah; i++) {
        if (strcmp(akun[i].username, inputUser) == 0 &&
            strcmp(akun[i].password, inputPass) == 0) {

            strcpy(username, akun[i].username);
            strcpy(role, akun[i].role);

            printf("Login berhasil sebagai %s\n", role);
            return 1;
        }
    }

    printf("Login gagal\n");
    return 0;
}