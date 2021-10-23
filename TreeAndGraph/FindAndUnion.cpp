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

Graph* createGraph(int V, int E)
{
    return new Graph(V, E);
}

int find(int* parent, int vertex)
{
    if (parent[vertex] == -1)
    {
        return vertex;
    }
    return find(parent, parent[vertex]);
}

void Union(int* parent, int x, int y)
{
    parent[x] = y;
}

bool IsCyclic(Graph* g)
{
    int *parent = new int[g->V];
    std::memset(parent, -1, g->V * sizeof(int));
    
    for (int i = 0; i < g->E; i++)
    {
        int x = find(parent, g->edges[i].src);
        int y = find(parent, g->edges[i].dst);
        
        if (x == y)
        {
            return true;
        }
        
        Union(parent, x, y);
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
