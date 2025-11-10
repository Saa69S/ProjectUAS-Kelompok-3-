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
void hapus_enter(char *s) {  /* fungsi untuk menghapus newline */
    int n = strlen(s);  /* menghitung panjangnya string */
    if (n > 0 && s[n-1] == '\n') {  /* jika string tidak kosong dan last char yaitu '\n' */
        s[n-1] = '\0';  /* mengganti '\n' dengan '\0' untuk mempersingkat string */
    }
}
int login (char *user, char *pass, char *role) {
    FILE *file = fopen ("akun.txt", "r");
    if (!file) {  /* jika file tidak berhasil dibuka*/
        printf("File akun tidak ada\n");
        return 0;
    }
    struct Akun login;  /*mengaliaskan struct Akun menjadi login*/
    while(fscanf(file, "%s %s %s", login.username, login.pass, login.role) == 3) {  /*mengecek jika username dan pass cocok dengan inputan*/
        if (strcmp(login.username, user) == 0 && strcmp(login.pass, pass) == 0)  /*jika kondisi awal terpenuhi, maka atur ke role*/
            strcpy(role, login.role);  /*menyalin peran dari login*/
            fclose(file);  /*tutup file*/
            return 1;
    }
    fclose(file);
    return 0;
}