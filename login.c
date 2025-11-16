#include "file.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

void hapus_enter(char *s) {  /* fungsi untuk menghapus newline */
    int n = strlen(s);  /* menghitung panjangnya string */
    if (n > 0 && s[n-1] == '\n') {  /* jika string tidak kosong dan last char yaitu '\n' */
        s[n-1] = '\0';  /* mengganti '\n' dengan '\0' untuk mempersingkat string */
    }
}
int login (const char *user, const char *pass, char *role) {
    FILE *f = fopen ("akun.txt", "r");
    if (!f) {  /* jika file tidak berhasil dibuka*/
        printf("File akun tidak ada\n");
        return 0;
    }
    struct Akun login;  /*mengaliaskan struct Akun menjadi login*/
    while(fscanf(f, "%s %s %s", login.username, login.pass, login.role) == 3) {  /*mengecek jika username dan pass cocok dengan inputan*/
        if (strcmp(login.username, user) == 0 && strcmp(login.pass, pass) == 0) {  /*jika kondisi awal terpenuhi, maka atur ke role*/
            strcpy(role, login.role);  /*menyalin peran dari login*/
            fclose(f);  /*tutup file*/
            return 1;
    }
}
    fclose(f);
    return 0;
}