#include <iostream>
#include <vector>
using namespace std;
 
// Data structure to store a graph edge
struct Edge {
    int src, dest;
};
 
// A class to represent a graph object
class Graph
{
public:
    // a vector of vectors to represent an adjacency list in C++
    vector<vector<int>> adjList;
 
    // Graph Constructor
    Graph(vector<Edge> const &edges, int N)
    {
        // resize the vector to hold `N` elements of type `vector<int>`
        adjList.resize(N);
 
        // add edges to the directed graph
        for (auto &edge: edges) {
            adjList[edge.src].push_back(edge.dest);
        }
    }
};
 
// Function to perform DFS traversal in a directed graph to find the
// complete path between source and destination vertices
bool isConnected(Graph const &graph, int src, int dest,
        vector<bool> &discovered, vector<int> &path)
{
    // mark the current node as discovered
    discovered[src] = true;
 
    // include the current node in the path
    path.push_back(src);
 
    // if destination vertex is found
    if (src == dest) {
        return true;
    }
 
    // do for every edge `src —> i`
    for (int i: graph.adjList[src])
    {
        // if `u` is not yet discovered
        if (!discovered[i])
        {
            // return true if the destination is found
            if (isConnected(graph, i, dest, discovered, path)) {
                return true;
            }
        }
    }
 
    // backtrack: remove the current node from the path
    path.pop_back();
 
    // return false if destination vertex is not reachable from src
    return false;
}
 
// Utility function to print a path
void printPath(vector<int> const &path)
{
    for (int i: path) {
        cout << i << ' ';
    }
    cout << endl;
}
 
int main()
{
    // vector of graph edges as per the above diagram
    vector<Edge> edges = {
        {0, 3}, {1, 0}, {1, 2}, {1, 4}, {2, 7}, {3, 4},
        {3, 5}, {4, 3}, {4, 6}, {5, 6}, {6, 7}
    };
 
    // total number of nodes in the graph (labeled from 0 to `N-1`)
    int N = 8;
 
    // build a graph from the given edges
    Graph graph(edges, N);
 
    // to keep track of whether a vertex is discovered or not
    vector<bool> discovered(N);
 
    // source and destination vertex
    int src = 0, dest = 7;
 
    // vector to store the complete path between source and destination
    vector<int> path;
 
    // perform DFS traversal from the source vertex to check the connectivity
    // and store path from the source vertex to the destination vertex
    if (isConnected(graph, src, dest, discovered, path))
    {
        cout << "A path exists from vertex " << src << " to vertex " << dest;
        cout << "\nThe complete path is "; printPath(path);
    }
    else {
        cout << "No path exists between vertices " << src << " and " << dest;
    }
 
    return 0;
}
