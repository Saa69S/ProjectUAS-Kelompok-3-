 else if (pilih == 3) {
            unsigned int id;
            printf("Masukkan ID alat yang mau diedit: ");
            scanf("%u", &id);
            int idx = cari_alat(alat, n, id);
            if (idx == -1) {
                printf("ID tidak ditemukan.\n");
            }