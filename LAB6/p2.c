#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int u, v, weight;
};

int find(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return find(parent, parent[i]);
}

void unionSets(int parent[], int rank[], int u, int v) {
    int rootU = find(parent, u);
    int rootV = find(parent, v);

    if (rank[rootU] < rank[rootV])
        parent[rootU] = rootV;
    else if (rank[rootU] > rank[rootV])
        parent[rootV] = rootU;
    else {
        parent[rootV] = rootU;
        rank[rootU]++;
    }
}

int compareEdges(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

void kruskal(struct Edge edges[], int n, int m) {
    int parent[n+1], rank[n+1], total_weight = 0;

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    qsort(edges, m, sizeof(struct Edge), compareEdges);

    printf("Edge    Cost\n");

    int count = 0;
    for (int i = 0; i < m && count < n - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;

        int setU = find(parent, u);
        int setV = find(parent, v);

        if (setU != setV) {
            printf("%d -- %d  %d\n", u, v, edges[i].weight);
            total_weight += edges[i].weight;
            unionSets(parent, rank, setU, setV);
            count++;
        }
    }

    printf("Total Weight of the Spanning Tree: %d\n", total_weight);
}

int main() {
    int n, m;
    printf("Enter number of nodes and edges:\n");
    scanf("%d %d", &n, &m);

    struct Edge edges[m];

    printf("Enter edges (u v weight):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    kruskal(edges, n, m);

    return 0;
}
