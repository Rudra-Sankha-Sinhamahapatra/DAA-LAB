#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 100

int minKey(int key[], bool mstSet[], int n) {
    int min = INT_MAX, minIndex;

    for (int v = 0; v < n; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void printMST(int parent[], int graph[MAX][MAX], int n) {
    printf("Minimum Spanning Tree (MST) Cost Adjacency Matrix:\n");
    int mstCost = 0;
    int mstMatrix[MAX][MAX] = {0}; 

    for (int i = 1; i < n; i++) {
        mstMatrix[i][parent[i]] = mstMatrix[parent[i]][i] = graph[i][parent[i]];
        mstCost += graph[i][parent[i]];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", mstMatrix[i][j]);
        }
        printf("\n");
    }
    
    printf("Total Weight of the Spanning Tree: %d\n", mstCost);
}

void primMST(int graph[MAX][MAX], int n) {
    int parent[MAX];   
    int key[MAX];     
    bool mstSet[MAX];  

    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;  

    for (int count = 0; count < n - 1; count++) {
        int u = minKey(key, mstSet, n);
        mstSet[u] = true;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph, n);
}

int main() {
    int n, start;
    int graph[MAX][MAX];

    FILE *file = fopen("inUnAdjMat.dat", "r");
    if (!file) {
        printf("Unable to open file.\n");
        return 1;
    }

    printf("Enter the Number of Vertices: ");
    scanf("%d", &n);
    printf("Enter the Starting Vertex: ");
    scanf("%d", &start);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(file, "%d", &graph[i][j]);
        }
    }
    fclose(file);
    primMST(graph, n);

    return 0;
}
