struct Edge{
    //add constructor if convenient
    int f; //from
    int t; //to
    int d; //distance

    int cap; //capacity (max flow)
    int flw; //flow (max flow)
    Edge *rev; //reverse edge (in case undirected)
    
    bool use; //edge is used (euler-tour) 
};

struct Node{
    int n; //index
    std::vector<Edge*> ed; //adjadency list
};

Node nd[MAXN]; //nodes
int dis[MAXN]; //distance to node

int dpt[MAXN]; //depth node (SCC/bridge)
int low[MAXN]; //low-link node (SCC/bridge)
//next edge of a node, used to keep track of next path in a non-recursive dfs
std::vector<Edge*>::iterator eit[MAXN]; 

Edge *frm[MAXN]; //edge used to node
bool vis[MAXN]; //visited

int incnt[MAXN]; //active indegree count (topo-sort)

void init(){
    for(int i=0; i<MAXN; ++i){
        nd[i].n = i;
        for(size_t j=0; j<nd[i].ed.size(); ++j) delete nd[i].ed[j];
        nd[i].ed.clear();
        dis[i] = INT_MAX;
        dpt[i] = -1;
        low[i] = INT_MAX;
        frm[i] = 0;
        vis[i] = false;
        incnt[i] = 0;
    }
}
