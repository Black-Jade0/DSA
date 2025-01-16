#include <stdio.h>
#include <stdlib.h>

// Structure to represent the graph
typedef struct Graph
{
    int numVertices;
    int **adjMatrix;
} Graph;

// Function to create a new graph
Graph *createGraph(int numVertices)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = numVertices;

    // Create the adjacency matrix
    graph->adjMatrix = (int **)malloc(numVertices * sizeof(int *));
    for (int i = 0; i < numVertices; i++)
    {
        graph->adjMatrix[i] = (int *)calloc(numVertices, sizeof(int));
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph *graph, int source, int destination)
{
    // Add an edge from source to destination
    graph->adjMatrix[source][destination] = 1;

    // For undirected graph, add an edge from destination to source
    graph->adjMatrix[destination][source] = 1;
}

// Function to print the adjacency matrix
void printGraph(Graph *graph)
{
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->numVertices; i++)
    {
        for (int j = 0; j < graph->numVertices; j++)
        {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    Graph *graph = createGraph(5);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printGraph(graph);

    return 0;
}