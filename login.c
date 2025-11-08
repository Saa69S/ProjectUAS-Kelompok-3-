#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Akun {  /* Struktur untuk data akun */
    char username[100];
    char pass[100];
    char role[10];
};
struct Tool {  /* Struktur untuk data alat lab */
    unsigned int id;
    char nama[50];
    char merek[50];
    char model[50];
    unsigned int tahun;
    unsigned int stok;
};
struct Loan {  /* Struktur untuk alat yg ingin dipinjam */
    char username[50];
    unsigned int id;
    unsigned int jumlah;
};
int login (char *user, char *pass, char *role) {
    FILE *file = fopen ("akun.txt", "r");
}