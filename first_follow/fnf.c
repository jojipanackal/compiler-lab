#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, m = 0, f = 0;  // f is a flag

char p[10][10], s[10];

void first(char c);
void follow(char c);
void insert(char c);

int main() {
    int i, z;
    char c, ch;

    printf("Enter the no of productions:\n");
    scanf("%d", &n);

    printf("Enter the prods (Use # for epsilon)\n");
    for (int i = 0; i < n; i++)
        scanf("%s%c", p[i], &ch);

    do {
        m = 0;
        printf("Enter the elements whose first and follow needed: ");
        scanf("%c", &c);

        first(c);

        printf("First(%c)={", c);
        for (int i = 0; i < m; i++)
            printf("%c, ", s[i]);
        printf("}\n");
        strcpy(s, "");
        m = 0;

        f = 1;
        follow(c);
        f = 0;

        printf("Follow(%c)={", c);
        for (int i = 0; i < m; i++)
            printf("%c, ", s[i]);
        printf("}\n");
        strcpy(s, "");

        printf("Continue? 0 or 1: ");
        scanf("%d%c", &z, &ch);

    } while (z == 1);

    return 0;
}

void first(char c) {
    if (!isupper(c)) {
        insert(c);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (p[i][0] == c) {
            if (p[i][2] == '#') {
                if (f == 0)
                    insert('#');
                else
                    follow(p[i][0]);
            } else if (!isupper(p[i][2]))
                insert(p[i][2]);
            else
                first(p[i][2]);
        }
    }
}

void follow(char c) {
    if (c == p[0][0]) insert('$');
    for (int i = 0; i < n; i++) {
        for (int j = 2; j < strlen(p[i]); j++) {
            if (p[i][j] == c) {
                if (p[i][j + 1] != '\0') first(p[i][j + 1]);
                if (p[i][j + 1] == '\0' && c != p[i][0]) follow(p[i][0]);
            }
        }
    }
}

void insert(char c) {
    for (int i=0; i<m; i++) {
        if (c == s[i]) return;
    }

    s[m++] = c;
}