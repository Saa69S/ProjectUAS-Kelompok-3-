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
    fclose(f);                          // Menutup file yang sebelumnya dibuka
    return n;                          // Mengembalikan jumlah data (n)
}

void save_tools(struct Tool alat[], int n) {   // Fungsi untuk menyimpan data alat ke file
    FILE *f = fopen("tools.txt", "w");         // Membuka file "tools.txt" untuk ditulis (mode write)
    for (int i = 0; i < n; i++) {              // Melakukan iterasi untuk setiap data alat
        fprintf(f, "%u %s %s %s %u %u\n",      
            alat[i].id, alat[i].nama, alat[i].merek,  
            alat[i].model, alat[i].tahun, alat[i].stok); 
    }                                          

                                                             

