//Bagian Menu admin (lihat alat, tambah alat, edit alat, dan hapus alat)
int cari_alat(struct Tool alat[], int n, unsigned int id) { //int cari_alat(struct Tool alat[], int n, unsigned int id) 
    for (int i = 0; i < n; i++) {
        if (alat[i].id == id) return i;                     //Ketika id alat yang dicari sama dengan id alat yang ditemukan maka fungsinya selesai

    }
    return -1;                                              //Angka tidak ditemukan, berarti id alat gak sama dengan id yang temukan maka pencarian gagal
}

void menu_(char *user) {                           //Prototype fungsi menu dan tidak mengembalikan nilai void
    struct Tool alat[MAX];                         //Membuat array struct tool bernama alat berukuran MAX, berfungsi untuk menyimpan data alat
    int n = load_tools(alat);                      //Memanggil fungsi load_tools() untuk memuat data alat dari file ke dalam array alat lalu nilai dikembalikan ke n 
    int pilih;                                     //Untuk menentukan pilihan menu admin dibawah

    do{                                             //Menggunakan loop do..while agar menu dapat ditampilkan berulang kali sampai admin memilih logout
        printf("\n== MENU ADMIN (%s) ===\n", user); //Fungsi %s adalah untuk menampilkan dengan nama admin(user)
        printf("1. Lihat alat\n");
        printf("2. Tambah alat\n");
        printf("3. Edit alat\n");
        printf("4. Hapus alat\n");
        printf("5. Logout\n");
        printf("Pilih: ");
        scanf("%d", &pilih);
        getchar();                                  //Untuk menghapus \n yang terbaca di buffer setelah scanf() agar tidak mengganggu inputnya

        if (pilih == 1) {                           //Menampilkan semua alat yang tersimpan di array alat
            printf("\n%-5s %-15s %-15s %-15s %-8s %-6s\n", //Rata kiri sebesar 15 karakter agar kolomnya sejajar
            "ID", "Nama", "Merek", "Model", "Tahun", "Jumlah");
            printf("------------------------------------------------------\n");
            for (int i = 0; i < n; i++) {                  //n adalah jumlah alat yang dimuat dari file (load_tools())
                printf("%-5u %-15s %-15s %-15s %-8u %-6u\n",
                alat[i].id, alat [i].nama, alat[i].merek, alat[i].model, alat[i].tahun, alat[i].stok);
            }
        } else if (pilih == 2) {                     //Untuk memasukkan data alat baru ke dalam daftar (datanya ada di simpan di file)
            struct Tool t;                           // t menggunakan tipe data sturct untuk mencari id alat
            printf("ID: "); scanf("%u", &t.id);
        }
    }
}