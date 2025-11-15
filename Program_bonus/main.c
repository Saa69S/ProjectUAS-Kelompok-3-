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
        fclose(fin); fclose(fout); return 1;
    }

    // array kata unik
    char **words = NULL;
    int wcount = 0;

    while(fgets(line, sizeof(line), fin)){
        // proses baris: ekstrak token kata
        int len = strlen(line);
        char buf[MAX_WORD] = "";
        int bi=0;
        for(int i=0;i<=len;i++){
            char c = line[i];
            if(is_word_char(c)){
                // huruf jadi lowercase
                buf[bi++] = (char)tolower((unsigned char)c);
                if(bi >= MAX_WORD-1){ bi = MAX_WORD-2; }
            } else {
                if(bi>0){
                    buf[bi]=0;