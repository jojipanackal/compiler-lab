#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define N 10

char inp[N][N];
char symtab[N][5];

int i, j, error = 0, l = 0;

int isconstant();
void insertsymbol();
void E();
void T();
void Eprime();
void O();
void C();
void L();
void R();

int main() {
    int n;
    printf("Enter no. of variables: ");
    scanf("%d", &n);

    printf("Enter pseudo:\n");
    for (int k = 0; k < n; k++)
        scanf("%s", inp[k]);

    for (i = 0; i < n; i++) {
        j = 0;
        if (isconstant())
            insertsymbol();
        else {
            E();
            if (error == 1) return 1;
        }
    }
    for (int g = 0; g < l; g++)
        printf("%s\n", symtab[g]);

    return 0;
}

int isconstant() {
    C();
    if (error == 1) {
        error = 0;
        return 0;
    }
    return 1;
}

void E() {
    T();
    Eprime();
}

void T() {
    printf("T");
    printf("j%d", j);
    printf("ch%c", inp[i][j]);
    if (isalpha(inp[i][j])) {
        for (int g = 0; g < l; g++)
            if (inp[i][j] == symtab[g][0]) inp[i][j] = symtab[g][1];
        j++;
    } else if (isdigit(inp[i][j]))
        return;
    else
        error = 1;
}

void Eprime() {
    O();
    E();
}

void O() {
    if (inp[i][j] == '+' || inp[i][j] == '-' || inp[i][j] == '*')
        j++;
    else
        error = 1;
}

void C() {
    printf("C");
    L();
    if (inp[i][j++] == '=') {
        R();
        printf("error t %d\n", error);
        return;
    }
    error = 1;
}

void L() {
    if (!isalpha(inp[i][j++])) error = 1;
}

void R() {
    for (int g = j; g < strlen(inp[i]); g++)
        if (!isdigit(inp[i][g])) error = 1;
}

void insertsymbol() {
    printf("Hai\n");
    symtab[l][0] = inp[i][0];
    for (int k = 2; k < strlen(inp[i]); k++) {
        symtab[l][k - 1] = inp[i][k];
    }
    l++;
}