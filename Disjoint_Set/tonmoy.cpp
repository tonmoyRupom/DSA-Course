#include<bits/stdc++.h>
#define ll long long
using namespace std;

class DisjointSet
{
    int *rank,*parent,n;

public:

    DisjointSet(int n)
    {
        rank=new int[n];
        parent=new int[n];
        this->n=n;
        makeset();
    }

    void makeset()
    {
        for(ll i=0;i<n;i++)
        {
            parent[i]=i;
        }
    }

    //Finds Parent of given item x
    int find(int x)
    {
        // Finds the representative of the set 
        // that x is an element of 
        if(parent[x]!=x)
        {
            // if x is not the parent of itself 
            // Then x is not the representative of 
            // his set,
            parent[x]=find(parent[x]);
            // so we recursively call Find on its parent 
        }
        return parent[x];
    }

    // Do union of two sets by rank represented 
    // by x and y. 

    void Union(int x,int y)
    {
        // Find current sets of x and y 
        int xRoot = find(x); 
        int yRoot = find(y);

        // If they are already in same set 
        if (xRoot == yRoot)
        { 
            return;
        }

        //Jar rank beshi seta parent hobe
        if(rank[xRoot]<rank[yRoot])
        {
            parent[xRoot]=yRoot;
        }

        else if(rank[xRoot]>rank[yRoot])
        {
            parent[yRoot]=xRoot;
        }

        //rank soman hole ekta korlei holo
        else
        {
            parent[yRoot]=xRoot;
            rank[xRoot]++;
        } 
    }
};

int main()
{

    DisjointSet obj(5);
    obj.Union(0, 2); 
    obj.Union(4, 2); 
    obj.Union(3, 1); 
    
    if (obj.find(4) == obj.find(0)) 
        cout << "Yes\n"; 
    else
        cout << "No\n"; 
    if (obj.find(1) == obj.find(0)) 
        cout << "Yes\n"; 
    else
        cout << "No\n";
    return 0;
}