#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

#define newline "\n"

class Graph
{
private:
    // v1 nd v2, vertices we want to calculate the closest common ancestor
    int v_1;
    int v_2;
    int n; // number of vertices
    int m; // number of edges

    // adjacency list 
    std::vector<std::vector<int> > adj;
public:
    Graph(int vert_1, int vert_2, int total_vertices, int total_edges, std::vector<std::vector<int> > &adjacency):
        v_1(vert_1),
        v_2(vert_2),
        n(total_vertices),
        m(total_edges),
        adj(total_vertices)
        {};
        
    // default constructor
    Graph(): n(0), m(0) {};

    int getNumVertices() const { return n; };
    int getNumberEdges() const { return m; };
    int getVerticeOne() const { return v_1; };
    int getVerticeTwo() const { return v_2; };
    
    // gets the adjacency list
    const std::vector<std::vector<int>> getAdjacencyList() { return adj; };

    void printAdjacencyList() {};


    void addVertice() {

    };
    void addEdge(int a, int b) {

    };



};

Graph process_input(Graph g) {
    
    uint v1, v2;
    uint n, m;   

    // process the first two lines
    std::cin >> v1 >> v2;
    std::cin >> n >> m;


    // n total vertices, hence the adjacency list will have n placeholders for the n vertices
    std::vector<std::vector<int> > adj(n, std::vector<int>());

    // we now have to process m lines (the total number of edges)
    
    for(uint i = 0; i < m; i++) {
        uint x, y;
        std::cin >> x >> y;
        //adj[x-1]
    }

    return g;
}


int main() {
    
    Graph g;
    g = process_input(g);




}

