#include <stdio.h>
#include <stdlib.h>

//    depth first search

//    concept of stack is builtin this code, we dont use stack externally but the code itself uses the concept of it
//    it keepes digging in keeping the cunnected nodes on hold (stack),
//    printing the node only and then returns when it finds that no connected is there that is unexplored
//    and then go back the path it came from and see if there is any path from the nodes kept on hold (stack)

int visited[7] = {0, 0, 0, 0, 0, 0, 0};
int a[7][7] = {
    {0, 1, 1, 1, 0, 0, 0},
    {1, 0, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 0},
    {1, 0, 1, 0, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0}};

void DFS(int i)
{
    printf("%d\n", i);
    int node = i;
    visited[i] = 1;
    for (int j = 0; j < 7; j++)
    {
        if (a[node][j] == 1 && visited[j] == 0)
        {
            // printf("%d\n", j);
            // node = j;
            DFS(j);
        }
    }
}

int main()
{

    // DFS Implementation
    DFS(0);
    return 0;
}
