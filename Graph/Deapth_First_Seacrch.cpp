#include<stdio.h>
#include<stdlib.h>

int visited[8] = {0,0,0,0,0,0,0,0};
    int a [8][8] = {
        {0,0,0,0,0,0,0,0},
        {0,0,1,0,1,1,0,0},
        {0,1,0,1,0,0,1,1},
        {0,0,1,0,0,0,0,0},
        {0,1,0,0,0,0,0,0},
        {0,1,0,0,0,0,0,0},
        {0,0,1,0,0,0,0,0},
        {0,0,1,0,0,0,0,0},
    };

void DFS(int i)
{
    int j;
    printf("%d ", i);
    visited[i] = 1;
    for(int j=0;j<8;j++)
    {
        if(a[i][j]==1 && visited[j]==0)
        {
            DFS(j);
        }
    }
} 
int main()
{
    // DFS Implementation 
    DFS(1);
    return 0;
}