#include <stdio.h>
#include <string.h>

#define N 10

int a=0, b=0, p, n;
char input[N], stack[N];

char table[4][4] = {
    '>', '<', '<', '>',
    '>', '>', '<', '>',
    '>', '>', '=', '>',
    '<', '<', '<', '=',
}; 

int idx(char c) {
    switch (c) {
        case '+': return 0;    
        case '*': return 1;    
        case 'i': return 2;    
        case '$': return 3;
        default: printf("Error char\n"); return 4;     
    }
}

void printv(char *action) {
    char temp1[N], temp2[N];
    strncpy(temp1, stack, b+1);
    temp1[b + 1] = '\0';
    strncpy(temp2, input+a, n);
    temp2[n] = '\0';
    
    printf("%s\t\t%s\t\t%s\n", temp1, temp2, action);
}

int main() {
    printf("Enter input string size: ");
    scanf("%d", &n);
    printf("Enter input string: ");
    scanf("%s", input);
    stack[b] = '$';
    printf("%s\n", input);
    printf("Stack\t\tInput\t\tAction\n");
    while (a < n+1) {
        if (input[a] == '$' && stack[b] == '$') {
            printv("String Accepted");
            break;
        }
        if (table[idx(stack[b])][idx(input[a])] == '<' || table[idx(stack[b])][idx(input[a])] == '=') {
            printv("Shift");
            stack[++b] = input[a++];
        }
        else {
            while(1) {
                printv("Reduce");
                p = stack[b--];
                if (table[idx(stack[b])][idx(p)] == '<') {
                    break;
                }
            }
        }

    }
    if (stack[b] != '$') printv("String Rejected;");
    return 0;
}