#include <iostream>
#include <vector>
#include <set>

#define newline "\n"
#define whitespace " "
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define ORANGE 3
#define RED 4

class Graph
{
private:
    
    uint v_1;
    uint v_2;
    uint n; 
    uint m;
    int start;
    std::vector<char> color;
    std::vector<int> color_2;
    std::vector<int> indegree;
    std::vector<std::vector<int>> adjacency_list;
    std::vector<std::vector<int>> transpose;
    std::set<int,std::less<int>> res;
    
public:
                                                                                        // && an r-value reference
    Graph(uint vert_1, uint vert_2, uint total_vertices, uint total_edges,std::vector<std::vector<int>> &&adj,std::vector<std::vector<int>> &&transp):
        v_1(vert_1),
        v_2(vert_2),
        n(total_vertices),
        m(total_edges),
        adjacency_list(std::move(adj)),
        transpose(std::move(transp))
        {};
        
    uint getNumVertices() { return n; };
    uint getNumberEdges() { return m; };
    uint getVerticeOne()  { return v_1; };
    uint getVerticeTwo()  { return v_2; };
    
    uint getStart() { return start; };
    void setStart(int v) { start = v; };
    
    void printAdjacencyList() {

        for(std::vector<std::vector<int>>::iterator row = adjacency_list.begin(); row != adjacency_list.end(); ++row ) {
            std::cout << (row- adjacency_list.begin() + 1)<< "--> " ;
            for(std::vector<int>::iterator col = row->begin();col != row->end(); ++col ){   
                std::cout << " " << *col  ; 
            }
            std::cout << newline;
        }
    };

    void printTransposeList() {

        for(std::vector<std::vector<int>>::iterator row = transpose.begin(); row != transpose.end(); ++row ) {
            std::cout << (row- transpose.begin() + 1)<< "--> " ;
            for(std::vector<int>::iterator col = row->begin();col != row->end(); ++col ){   
                std::cout << " " << *col  ; 
            }
            std::cout << newline;
        }
    };

    bool dfsMarker(uint v) {

        color[v] = GRAY;
        for(uint u: adjacency_list[v]) {
            u--;
            if (color[u] == WHITE) {
                if (dfsMarker(u))
                    return true;
            } else if (color[u] == GRAY) {
                setStart(u);
                return true;
            } else if((v+1) == (u+1)) {
                setStart(2);
                return true;
            }
        }
        color[v] = BLACK;
        return false;

    };

    bool dfsAcyclic() {
        
        color.assign(n,WHITE); 
        setStart(-1);
        for (uint i = 0; i < n ; i++) {
            if (color[i] == WHITE && dfsMarker(i)) {
                break;
            }
        }
        if (start == -1) {
            return true; 
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
  
    void printIndegrees() {

        for(uint i = 0; i < n ; i++) {
            std::cout << indegree[i] << newline;
        }
    };

    void checkAndRemoveAncestorRelationship() {

        std::set<int>::iterator it;
        std::set<int>::iterator tmp;
        std::vector<int> adj;
    
        it = res.begin();

        for(;it != res.end();) {
            adj = adjacency_list[(*it-1)];
            if(adj.empty()) {
                ++it;         
            } else {
             
                for(uint el: adj) {
                    if(res.count(el) == 1) {
                        tmp = it;
                        ++tmp; 
                        res.erase(it);
                        it = tmp;
                        break;
                    } 
                }
                ++it;                
            }
        }   
    }
    
    void dfsV2(uint v) {

        if(color_2[v] == WHITE) {
            color_2[v] = GRAY;
            for(uint u: transpose[v]) {
                u--;
                if(color_2[u] == WHITE) 
                    dfsV2(u);
                else if(color_2[u] == BLACK) {
                    
                    color_2[u] = ORANGE;
                    u++;
                    res.insert(u);
                }
            }
            color_2[v] = RED;
        }
       

    };

    void dfsV1(uint v) {
        color_2[v] = GRAY;

        for(uint u: transpose[v]) {
            u--;
            if(color_2[u] == WHITE) {
                dfsV1(u);
            } 
        }
        color_2[v] = BLACK; 
    };

    void allCommonAncestor() {

       
        color_2.assign(n,WHITE);
        uint v1 = getVerticeOne() - 1;
        uint v2 = getVerticeTwo() - 1;
    
        dfsV1(v1);

        if(color_2[v2] == BLACK)  {
            std::cout << getVerticeTwo() << whitespace << newline;
        } 
        else {
            dfsV2(v2);
    
            if(res.empty()){
                std::cout << "-" << newline; 
            } else {
                checkAndRemoveAncestorRelationship();

                for(std::set<int>::iterator i = res.begin(); i != res.end(); i++)
                    std::cout << *i << whitespace; 
                std::cout << newline;   
            }
        }

    };

    void invalidGenealogyTree() { std::cout << "0" << newline; }; 
   
};


Graph process_input() {
    
    uint v1, v2;
    uint n, m;   

    std::cin >> v1 >> v2;
    std::cin >> n >> m;

    std::vector<std::vector<int>> adj_list(n);
    std::vector<std::vector<int>> transpose(n);
    
    for(uint i = 0; i < m; i++) { 
        uint x, y; 
        std::cin >> x >> y;
        x--;
        adj_list[x].push_back(y);
        x++,y--;
        transpose[y].push_back(x);
    }
 
    Graph g(v1,v2,n,m,std::move(adj_list),std::move(transpose));

    return g;

}


int main() {

    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    Graph g = process_input();

    if(!g.dfsAcyclic() || !g.validIndegree()) {
        g.invalidGenealogyTree();
    } else {
        g.allCommonAncestor();
    }

    return 0;
}