/* Bagian: Fungsi file handling */
int load_tools(struct Tool alat[]) {
    FILE *f = fopen("tools.txt", "r");                        // Membuka file "tools.txt" untuk dibaca
    if (!f) return 0;                                         
    int n = 0;                                                // Inisialisasi penghitung data
    while (fscanf(f, "%u %s %s %s %u %u",                    // Membaca 6 data dari file untuk setiap alat
        &alat[n].id, alat[n].nama, alat[n].merek,             // Membaca ID, nama, dan merek alat
        alat[n].model, &alat[n].tahun, &alat[n].stok) == 6) { // Membaca model, tahun, dan stok alat
        n++;                                                  
    }
                                                              

