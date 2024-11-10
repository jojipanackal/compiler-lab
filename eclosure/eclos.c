#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define N 10

int epsilonTransitions[N][N];
int epsilonClosure[N][N];
bool visited[N];

void computeClosure(int);
void dfs(int, int);

int main() {
    int n, transitions;

    printf("Enter no. of states: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            epsilonTransitions[i][j] = 0;
            epsilonClosure[i][j] = 0;
        }
    }

    printf("Enter no. of epsilon transitions: ");
    scanf("%d", &transitions);

    printf("Enter the epsilon transitions (from, to):\n");
    for (int i = 0; i < transitions; i++) {
        int t1, t2;
        scanf("%d %d", &t1, &t2);
        epsilonTransitions[t1][t2] = 1;
    }

    computeClosure(n);

    printf("\nEpsilon Closure:\n");
    for (int i = 0; i < n; i++) {
        printf("Epsilon Closure of state %d = {", i);
        for (int j = 0; j < n; j++) {
            if (epsilonClosure[i][j] == 1) {
                printf("%d, ", j);
            }
        }
        printf("}\n");
    }

    return 0;
}

void computeClosure(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            visited[j] == false;
        }
        dfs(i, i);
    }
}

void dfs(int start, int s) {
    if (visited[s]) return;
    visited[s] == true;

    epsilonClosure[start][s] = 1;

    for (int i = 0; i < N; i++) {
        if (epsilonTransitions[s][i] == 1) {
            dfs(start, i);
        }
    }
}
