 else if (pilih == 3) {
            unsigned int id;
            printf("Masukkan ID alat yang mau diedit: ");
            scanf("%u", &id);
            int idx = cari_alat(alat, n, id);
            if (idx == -1) {
                printf("ID tidak ditemukan.\n");
            }else {
                printf("Nama baru: "); scanf("%s", alat[idx].nama);
                printf("Merek baru: "); scanf("%s", alat[idx].merek);
                printf("Model baru: "); scanf("%s", alat[idx].model);
                printf("Tahun baru: "); scanf("%u", &alat[idx].tahun);
                printf("Jumlah baru: "); scanf("%u", &alat[idx].stok);
                save_tools(alat, n);
                printf("Data alat berhasil diupdate!\n");
            }