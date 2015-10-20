//bfs is safer (unless path length is limited and integer)
//for min-cost replace by Bellman-Ford or Dijkstra with potentials
int dfs(int a, int b){
    if(a == b) return INT_MAX;
    if(vis[a]) return 0;
    vis[a] = true;
    
    for(size_t i=0; i<nd[a].ed.size(); ++i){
        Edge *e = nd[a].ed[i];
        
        int cap = (e->cap-e->flw)+e->rev->flw;
        if(cap == 0) continue;
        else{
            int k = dfs(e->t, b);
            if(k == 0) continue;
            frm[e->t] = e;
            return std::min(cap, k);
        }
    }
    return 0;
}

int max_flow(int a, int b){
    int mf = 0;
    
    frm[a] = 0;
    while(true){
        for(int i=0; i<2000; ++i) vis[i] = false;
        int f = dfs(a, b);
        if(f == 0) break;
        mf += f;
        
        int lst = b;
        while(frm[lst]){
            Edge *nr = frm[lst];
            
            int rf = std::min(nr->cap-nr->flw, f);
            nr->flw += rf;
            nr->rev->flw -= f-rf;
            
            lst = frm[lst]->f;
        }
    }
    return mf;
}
