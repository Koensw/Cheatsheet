#include <bits/stdc++.h>
#define MAXN 18
#define MAXK 5

#include "../structures/union-find.cpp"
#include "graph.h"

#include "bfs.cpp"
#include "dijkstra.cpp"
#include "floyd-warshall.cpp"
#include "bellman-ford.cpp"
#include "kruskal.cpp"

#include "biconnected-components.cpp"
#include "scc.cpp"
#include "two-sat.cpp"

#include "max-flow.cpp"
#include "bipartite-matching.cpp"

#include "euler-tour.cpp"
#include "topo-sort.cpp"

#include "lca.cpp"

void test_euler_tour(){
    std::vector<std::pair<int, int> > lst;
    
    lst.emplace_back(2, 3);
    lst.emplace_back(0, 3);
    lst.emplace_back(2, 5);
    lst.emplace_back(0, 1);
    lst.emplace_back(1, 4);
    lst.emplace_back(2, 4);
    lst.emplace_back(1, 2);
    lst.emplace_back(1, 5);
    
    for(size_t i=0; i<lst.size(); ++i){
        Edge *e = new Edge;
        e->t = lst[i].second;
        e->use = false;
        nd[lst[i].first].ed.push_back(e);
        
        Edge *er = new Edge;
        er->t = lst[i].first;
        er->use = false;
        nd[lst[i].second].ed.push_back(er);
        e->rev = er;
        er->rev = e;
    }
    
    std::list<int> ans = euler_tour(0);
    for(auto iter = ans.begin(); iter != ans.end(); ++iter){
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
}

int main(){
    //add graph tests...comp[all[i][j]-1] << " " << 
    init();
    
    std::vector<std::pair<int, int> > v;
    v.emplace_back(1, 4);
    v.emplace_back(-2, 5);
    v.emplace_back(3, 7);
    v.emplace_back(2, -5);
    v.emplace_back(-8, -2);
    v.emplace_back(3, -1);
    v.emplace_back(4, -3);
    v.emplace_back(5, -4);
    v.emplace_back(-3, -7);
    v.emplace_back(6, 7);
    v.emplace_back(1, 7);
    v.emplace_back(-7, -1);
    
    std::cout << two_sat(v) << std::endl;
}