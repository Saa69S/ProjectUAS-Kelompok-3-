  return 0;
}

int main(){
    FILE *fin = fopen(INFILE, "r");
    if(!fin){
        printf("Gak nemu %s, tolong taruh file lirik.txt di folder yg sama.\n", INFILE);
        return 1;
    }
    FILE *fout = fopen(OUTFILE, "w");
    if(!fout){ fclose(fin); printf("Gagal tulis %s\n", OUTFILE); return 1; }

    char line[MAX_LINE];
    char title[MAX_LINE] = "";
    if(fgets(line, sizeof(line), fin)){
        // simpan title persis seperti di input (ikut soal)
        strncpy(title, line, sizeof(title)-1);
        // tulis title ke outfile
        fprintf(fout, "%s", title);
    } else {
        printf("File lirik kosong.\n");