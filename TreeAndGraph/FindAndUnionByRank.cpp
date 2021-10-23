#include <iostream>
#include <cstring>

class Edge
{
    public:
    
    int src, dst;  
};

class Graph
{
    public:
    
    int V, E;
    Edge* edges = nullptr;
    
    Graph(int v, int e) : V(v), E(e)
    {
        edges = new Edge[E * sizeof(Edge)];
    }
};

struct subset
{
    int parent;
    int rank;
};

Graph* createGraph(int V, int E)
{
    return new Graph(V, E);
}

int find(struct subset* subsets, int vertex)
{
    if (subsets[vertex].parent != vertex)
    {
        subsets[vertex].parent = find(subsets, subsets[vertex].parent);
    }
    return subsets[vertex].parent;
}

void Union(struct subset* subsets, int x, int y)
{
    if (subsets[x].rank > subsets[y].rank)
    {
        subsets[y].parent = x;
    }
    else if (subsets[x].rank < subsets[y].rank)
    {
        subsets[x].parent = y;
    }
    else
    {
        subsets[x].parent = y;
        subsets[y].rank++;
    }
}

bool IsCyclic(Graph* g)
{
    struct subset* subsets = new struct subset[g->V];
    for (int i = 0; i < g->V; i++)
    {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }
    
    for (int i = 0; i < g->E; i++)
    {
        int x = find(subsets, g->edges[i].src);
        int y = find(subsets, g->edges[i].dst);
        
        if (x == y)
        {
            return true;
        }
        
        Union(subsets, x, y);
    }
    return false;
}

int main()
{
    int V = 3, E = 3;
    Graph* g = createGraph(V, E);

    g->edges[0].src = 0;
    g->edges[0].dst = 1;
    
    g->edges[1].src = 1;
    g->edges[1].dst = 2;
        
    g->edges[2].src = 2;
    g->edges[2].dst = 0;
    
    if (IsCyclic(g))
    {
        std::cout << "Cyclic";
    }
    else
    {
        std::cout << "Not Cyclic";
    }
    return 0;
}
