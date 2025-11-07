void menu_user(char *user) {
    struct Tool alat[MAX];
    struct Loan pinjam[MAX];
    int n = load_tools(alat);
    int m = load_loans(pinjam);
    int pilih;

    do {
        printf("\n=== MENU USER (%s) ===\n", user);
        printf("1. Lihat alat\n");