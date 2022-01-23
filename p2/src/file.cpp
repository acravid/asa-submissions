#include <iostream>
#include <algorithm>
#include <vector>

#define newline "\n"

class Graph
{
private:
    
    uint v_1;
    uint v_2;
    uint n; // number of vertices
    uint m; // number of edges
    int start, end;
    std::vector<char> color;
    std::vector<int> parent;
    std::vector<int> indegree;
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
    
    uint getStart() { return start; };
    uint getENd() { return end; };
    void setStart(int v) { start = v; };
    void setEnd(int v) { end = v; };

    void printAdjacencyList() {

        for(std::vector<std::vector<int>>::iterator row = adjacency_list.begin(); row != adjacency_list.end(); ++row ) {
            std::cout << (row- adjacency_list.begin() + 1)<< "--> " ;
            for(std::vector<int>::iterator col = row->begin();col != row->end(); ++col ){   
                std::cout << " " << *col  ; 
            }
            std::cout << newline;
        }
    };


    bool dfsMarker(uint v) {

        color[v] = 1;
        for(uint u: adjacency_list[v]) {
            u--; // zero indexed vector
            if (color[u] == 0) {
                parent[u] = v;
                if (dfsMarker(u))
                    return true;
            } else if (color[u] == 1) {
                setStart(u);
                return true;
            }
        }
        color[v] = 2;
        return false;

    };

    bool dfsAcyclic() {

        color.assign(n,0); 
        parent.assign(n,-1);
        setStart(-1);
        for (uint i = 0; i < n ; i++) {
            if (color[i] == 0 && dfsMarker(i)) {
                break;
            }
        }
        if (start == -1) {
            return true; // acyclic
        }
        return false;
    };

    bool validIndegree() {
  
        indegree.assign(n,0);       
        for(uint i = 0; i < n ; i++) {
            for(uint u: adjacency_list[i]) {
                u--;
                indegree[u]++;
                if(indegree[u] >= 3) { 
                    return false;
                }
            }
        }
        return true;
    };

};

Graph process_input() {
    
    uint v1, v2;
    uint n, m;   

    std::cin >> v1 >> v2;
    std::cin >> n >> m;

    std::vector<std::vector<int>> adj_list(n);
    

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

void invalidGenealogyTree() { std::cout << "0" << newline; } 

int main() {

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    Graph g = process_input();

    if(!g.dfsAcyclic() || !g.validIndegree()) {
        invalidGenealogyTree();
    } else {
        std::cout << "all good" << newline;
    }

    return 0;
}
