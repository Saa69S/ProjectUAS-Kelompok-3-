#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Akun {
    char username[100];
    char pass[100];
    char role[10];
};
int login (char *user, char *pass, char *role) {
    FILE *file = fopen ("akun.txt", "r");
}