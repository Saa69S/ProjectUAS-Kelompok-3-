#include "file.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Bagian Menu admin (lihat alat, tambah alat, edit alat, dan hapus alat)
int cari_alat(struct Tool alat[], int n, unsigned int id) {
    for (int i = 0; i < n; i++) {
        if (alat[i].id == id) return i;
    }
    return -1;
}

void menu_admin(char *user) {
    struct Tool alat[MAX];
    int n = load_tools(alat);
    int pilih;

    do {
        printf("\n=== MENU ADMIN (%s) ===\n", user);
        printf("1. Lihat alat\n");
        printf("2. Tambah alat\n");
        printf("3. Edit alat\n");
        printf("4. Hapus alat\n");
        printf("5. Logout\n");
        printf("Pilih: ");
        scanf("%d", &pilih);
        getchar();

        if (pilih == 1) {
            printf("\n%-5s %-15s %-15s %-15s %-8s %-6s\n",
                   "ID", "Nama", "Merek", "Model", "Tahun", "Jumlah");
            printf("-------------------------------------------------------------\n");
            for (int i = 0; i < n; i++) {
                printf("%-5u %-15s %-15s %-15s %-8u %-6u\n",
                    alat[i].id, alat[i].nama, alat[i].merek,
                    alat[i].model, alat[i].tahun, alat[i].stok);
            }
        } else if (pilih == 2) {
            struct Tool t;
            printf("ID: "); scanf("%u", &t.id);
            printf("Nama: "); scanf("%s", t.nama);
            printf("Merek: "); scanf("%s", t.merek);
            printf("Model: "); scanf("%s", t.model);
            printf("Tahun: "); scanf("%u", &t.tahun);
            printf("Jumlah: "); scanf(" %u", &t.stok);
            alat[n++] = t;
            save_tools(alat, n);
            printf("Alat berhasil ditambah!\n");
        }

/* Bagian: Lanjutan menu admin & awal menu user */
        else if (pilih == 3) {
            unsigned int id;
            printf("Masukkan ID alat yang mau diedit: ");
            scanf("%u", &id);
            int idx = cari_alat(alat, n, id);
            if (idx == -1) {
                printf("ID tidak ditemukan.\n");
            } else {
                printf("Nama baru: "); scanf("%s", alat[idx].nama);
                printf("Merek baru: "); scanf("%s", alat[idx].merek);
                printf("Model baru: "); scanf("%s", alat[idx].model);
                printf("Tahun baru: "); scanf("%u", &alat[idx].tahun);
                printf("Jumlah baru: "); scanf("%u", &alat[idx].stok);
                save_tools(alat, n);
                printf("Data alat berhasil diupdate!\n");
            }
        } else if (pilih == 4) {
            unsigned int id;
            printf("Masukkan ID alat yang mau dihapus: ");
            scanf("%u", &id);
            int idx = cari_alat(alat, n, id);
            if (idx == -1) {
                printf("ID tidak ditemukan.\n");
            } else {
                for (int i = idx; i < n - 1; i++) alat[i] = alat[i + 1];
                n--;
                save_tools(alat, n);
                printf("Alat berhasil dihapus!\n");
            }
        } else if (pilih == 5) {
            printf("Logout berhasil!\n");
        } else {
            printf("Pilihan salah!\n");
        }
    } while (pilih != 5);
}
