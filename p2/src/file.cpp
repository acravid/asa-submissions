#include <iostream>
#include <algorithm>

#include <vector>

#define newline "\n"

class Graph
{
private:
    
    uint v_1;
    uint v_2;
    uint n;
    uint m;

    std::vector<std::vector<int>> adjacency_list;

public:
                                                                                        // && an r-value reference
    Graph(uint vert_1, uint vert_2, uint total_vertices, uint total_edges,std::vector<std::vector<int>> &&adj):
        v_1(vert_1),
        v_2(vert_2),
        n(total_vertices),
        m(total_edges),
        adjacency_list(std::move(adj))
        {};
        
    uint getNumVertices() { return n; };
    uint getNumberEdges() { return m; };
    uint getVerticeOne()  { return v_1; };
    uint getVerticeTwo()  { return v_2; };


    void printAdjacencyList() {
        for(std::vector<std::vector<int>>::iterator row = adjacency_list.begin(); row != adjacency_list.end(); ++row ) {
            std::cout << (row- adjacency_list.begin() + 1)<< "--> " ;
            for(std::vector<int>::iterator col = row->begin();col != row->end(); ++col ){
                std::cout << " " << *col  ; 
            }
            std::cout << newline;
        }
    };
    
};

Graph process_input() {
    
    uint v1, v2;
    uint n, m;   

    std::cin >> v1 >> v2;
    std::cin >> n >> m;

    std::vector<std::vector<int>> adj_list;
    

    for(uint i = 0; i < m; i++) { // process the m edges
        uint x, y; // where y is a child of x
        std::cin >> x >> y;
        x--; // a zero indexed vector
        adj_list.push_back(std::vector<int>());
        adj_list[x].push_back(y);
    }
 
    Graph g(v1,v2,n,m,std::move(adj_list));

    return g;

}


int main() {
    
    Graph g = process_input();
    return 0;
}
