#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

#define newline "\n"


class Graph
{
private:
    
    uint v_1;
    uint v_2;
    uint n; // number of vertices
    uint m; // number of edges

    // adjacency list 
    std::vector<int> *adjacency;

public:

    Graph(uint vert_1, uint vert_2, uint total_vertices, uint total_edges):
        v_1(vert_1),
        v_2(vert_2),
        n(total_vertices),
        m(total_edges)
        {};
        
    // default constructor
    Graph(): n(0), m(0) {};

    uint getNumVertices() { return n; };
    uint getNumberEdges() { return m; };
    uint getVerticeOne()  { return v_1; };
    uint getVerticeTwo()  { return v_2; };
    
    void setAdjacencyList(std::vector<int> a, int n) {
        
    };

    void printAdjacencyList(int k) {

        std::vector<int>::iterator it;
        for (int i = 0; i < k ; ++i) { 
            std::cout << "\n adjacency list of vertex "
             << i + 1 << "\n head ";
        }
        for (it= adjacency[k].begin();it!= adjacency[k].end(); it++) 
           std::cout << " -->" << *it; 
        std::cout << newline;
    };


};

Graph process_input() {
    
    uint v1, v2;
    uint n, m;   

    std::cin >> v1 >> v2; // reads the two vertices, we want to find all the LCA
    std::cin >> n >> m; // reads number of vertices and edges

    // array of vectors, of length N, each of which is empty initially.
    std::vector<int> adj[n];

    for(uint i = 0; i < m; i++) { // process the m edges
        uint x, y; // where y is a child of x
        std::cin >> x >> y;
        x--; // a zero indexed vector
        adj[x].push_back(y);
        
    }

    Graph g = Graph(v1,v2,n,m);
    //g.setAdjacencyList(adj,n);
    //g.printAdjacencyList(n);

    //std::cout << newline;
    //printAdjacencyListF(adj,n);


   
   
    
    return g;
}


int main() {
    
    Graph g = process_input();
    

    return 0;
}
