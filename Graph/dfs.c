#include<stdio.h>
#include<stdlib.h>

int vis[20];
int a[20][20];

void dfs(int v, int n) {
    vis[v] = 1;
    printf("%d ", v);

    for(int i = 1; i <= n; i++) {
        if(a[v][i] == 1 && vis[i] == 0) {
            dfs(i, n);
        }
    }
}

int main() {
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("Enter 1 if %d has a node with %d else 0: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("The adjacency matrix is\n");
    for(int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    for(int i = 1; i <= n; i++) {
        vis[i] = 0;
    } 

    int s;
    printf("Enter the source vertex: ");
    scanf("%d", &s);

    printf("The dfs traversal is:\n");
    dfs(s, n);
    return 0;
}