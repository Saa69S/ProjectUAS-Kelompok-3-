        //============================== ORANG 4 ============================== */
// Bagian: Lanjutan menu admin & awal menu user */
        else if (pilih == 3) {
            unsigned int id; //unsigned = tidak boleh negatif, maka id pelaggan tidak boleh negatif. 
            printf("Masukkan ID alat yang mau diedit: ");
            scanf("%u", &id);
            int idx = cari_alat(alat, n, id); //memanggil fungsi cari alat dengan parameter alat, n, id
            if (idx == -1) { //jika idx = -1 maka id tidak ditemukan
                printf("ID tidak ditemukan.\n"); 
            }else { //jika idx tidak -1 maka id ditemukan
                printf("Nama baru: "); scanf("%s", alat[idx].nama);
                printf("Merek baru: "); scanf("%s", alat[idx].merek);
                printf("Model baru: "); scanf("%s", alat[idx].model);
                printf("Tahun baru: "); scanf("%u", &alat[idx].tahun);
                printf("Jumlah baru: "); scanf("%u", &alat[idx].stok);
                save_tools(alat, n); // untuk menyimpan data alat yang sudah di edit
                printf("Data alat berhasil diupdate!\n");
            }
        } else if (pilih == 4) {
            unsigned int id; //unsigned = tidak boleh negatif, maka id pelaggan tidak boleh negatif.
            printf("Masukkan ID alat yang mau dihapus: ");
            scanf("%u", &id);
            int idx = cari_alat(alat, n, id); //memanggil fungsi cari alat dengan parameter alat, n, id
            if (idx == -1) { //jika idx = -1 maka id tidak ditemukan
                printf("ID tidak ditemukan.\n");
            } else { //jika idx tidak -1 maka id ditemukan
                for (int i = idx; i < n - 1; i++) alat[i] = alat[i + 1];
                n--;
                save_tools(alat, n);
                printf("Alat berhasil dihapus!\n");
            }
        } else if (pilih == 5) { //jika pilih = 5 maka logout berhasil
            printf("Logout berhasil!\n");
        } else { //jika pilih tidak sesuai dengan pilihan yang ada
            printf("Pilihan salah!\n");
        }
    } while (pilih != 5); //jika pilih tidak sama dengan 5 maka akan mengulang kembali
}