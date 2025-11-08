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
    }
}