struct Edge{
    //add constructor if convenient
    int f;
    int t;
    int d;

    int cap;
    int flw;
    
    Edge *rev;
};

struct Node{
    int n;
    
    std::vector<Edge*> ed;
};

Node nd[MAXN];
int dis[MAXN];

int dpt[MAXN];
int low[MAXN];
std::vector<Edge*>::iterator lit[MAXN];

Edge *frm[MAXN];
bool vis[MAXN];

int incnt[MAXN];

void init(){
    for(int i=0; i<MAXN; ++i){
        nd[i].n = i;
        for(int j=0; j<nd[i].ed.size(); ++j) delete nd[i].ed[j];
        nd[i].ed.clear();
        dis[i] = INT_MAX;
        dpt[i] = -1;
        low[i] = INT_MAX;
        frm[i] = 0;
        vis[i] = false;
        incnt[i] = 0;
    }
}
