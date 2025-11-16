#ifndef FILE_H
#define FILE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct Tool {
    unsigned int id;
    char nama[50];
    char merek[50];
    char model[50];
    unsigned int tahun;
    unsigned int stok;
};

struct Akun {
    char username[50];
    char pass[50];
    char role[10];
};

struct Loan {
    char username[50];
    unsigned int id;
    unsigned int jumlah;
};

/* Function Declaration */
void hapus_enter(chars);
int login(char user, char pass, char role);

int load_tools(struct Tool alat[]);
void save_tools(struct Tool alat[], int n);

int load_loans(struct Loan pinjam[]);
void save_loans(struct Loan pinjam[], int n);

int cari_alat(struct Tool alat[], int n, unsigned int id);

void menu_admin(charuser);
void menu_user(char *user);

#endif
