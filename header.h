#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <string.h>

// ===== STRUCT =====

typedef struct {
    char username[50];
    char password[50];
    char role[10];
} Akun;

typedef struct {
    int id;
    char nama[50];
    int stok;
} Alat;

typedef struct {
    char username[50];
    int id_alat;
    char nama_alat[100];
    char tanggal[20];
    int dikembalikan;
} Pinjam;

// ===== LOGIN =====

int login(char *username, char *role, int argc, char *argv[]);

// ===== FILE =====

void bacaAkun(Akun akun[], int *jumlah);
void bacaAlat(Alat alat[], int *jumlah);
void bacaPinjam(Pinjam pinjam[], int *jumlah);

void tulisAlat(Alat alat[], int jumlah);
void tulisPinjam(Pinjam pinjam[], int jumlah);

// ===== ALAT =====

void tampilAlat();
void tambahAlat();
void hapusAlat();

// ===== PINJAM =====

void pinjamAlat(char *username);
void lihatPinjaman(char *username);
void kembalikanAlat(char *username);

#endif