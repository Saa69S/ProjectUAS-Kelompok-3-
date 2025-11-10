void menu_user(char *user) {
    struct Tool alat[MAX];
    struct Loan pinjam[MAX];
    int n = load_tools(alat);
    int m = load_loans(pinjam);
    int pilih;

    do {
        printf("\n=== MENU USER (%s) ===\n", user);
        printf("1. Lihat alat\n");
        printf("2. Pinjam alat\n");
        printf("3. Lihat pinjaman\n");
        printf("4. Kembalikan alat\n");
        printf("5. Logout\n");
        printf("Pilih: ");
        scanf("%d", &pilih);

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
            unsigned int id, jml;
            printf("Masukkan ID alat: "); scanf("%u", &id);
            printf("Jumlah: "); scanf("%u", &jml);
            int idx = cari_alat(alat, n, id);
            if (idx == -1) printf("ID tidak ditemukan.\n");
            else if (alat[idx].stok < jml) printf("Stok tidak cukup.\n");
            else {
                alat[idx].stok -= jml;
                int found = 0;
                for (int i = 0; i < m; i++) {
                    if (strcmp(pinjam[i].username, user) == 0 && pinjam[i].id == id) {
                        pinjam[i].jumlah += jml;
                        found = 1;
                    }
                }
                if (!found) {
                    strcpy(pinjam[m].username, user);
                    pinjam[m].id = id;
                    pinjam[m].jumlah = jml;
                    m++;
                }
                save_tools(alat, n);
                save_loans(pinjam, m);
                printf("Berhasil meminjam alat!\n");