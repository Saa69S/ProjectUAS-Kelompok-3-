//Bagian Menu admin (lihat alat, tambah alat, edit alat, dan hapus alat)
int cari_alat(struct Tool alat[], int n, unsigned int id) { //int cari_alat(struct Tool alat[], int n, unsigned int id) 
    for (int i = 0; i < n; i++) {
        if (alat[i].id == id) return i;                     //Ketika id alat yang dicari sama dengan id alat yang ditemukan maka fungsinya selesai

    }
    return -1;                                              //Angka tidak ditemukan, berarti id alat gak sama dengan id yang temukan maka pencarian gagal
}