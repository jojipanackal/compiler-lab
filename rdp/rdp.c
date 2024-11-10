#include <ctype.h>
#include <stdio.h>
#include <string.h>

char input[10];
int i = 0, error = 0;

void E();
void Eprime();
void T();
void Tprime();
void F();

int main() {
    printf("Enter arithmetic expression: ");
    scanf("%s", input);

    E();
    if (strlen(input) == i && error == 0)
        printf("String accepted\n");
    else
        printf("String Rejected\n");

    return 0;
}

void E() {
    T();
    Eprime();
}

void Eprime() {
    if (input[i] == '+') {
        i++;
        E();
    }
}

void T() {
    F();
    Tprime();
}

void Tprime() {
    if (input[i] == '*') {
        i++;
        T();
    }
}

void F() {
    if (isalnum(input[i]))
        i++;
    else if (input[i] == '(') {
        i++;
        E();
        if (input[i] == ')')
            i++;
        else
            error = 1;
    } else
        error = 1;
}
