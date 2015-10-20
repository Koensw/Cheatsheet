//set MAXK to the log2 of MAXN
int par[MAXN][MAXK]; //example of sparse table idea
void construct(int k, int p = -1){
    if(dpt[k] != -1) return;
    
    if(p == -1) dpt[k] = 0;
    else dpt[k] = dpt[p]+1;
    
    //compute parents
    par[k][0] = p;
    for(int i=1; i<MAXK; ++i){
        if(par[k][i-1] == -1) break;
        par[k][i] = par[par[k][i-1]][i-1];
    }
    
    //dfs children
    for(size_t i=0; i<nd[k].ed.size(); ++i){
        int t = nd[k].ed[i]->t;
        
        construct(t, k);
    }
}

int query(int a, int b){
    if(dpt[a] < dpt[b]) std::swap(a, b);
    
    //level out
    int k = 0;
    for(; k<MAXK; ++k){
        if(par[a][k] == -1 || dpt[par[a][k]] < dpt[b]) break;
    }
    --k;
    while(dpt[a] != dpt[b]){        
        a = par[a][k];
        while(k>=0 && (par[a][k] == -1 || dpt[par[a][k]] < dpt[b])) --k;
    }
        
    //go up
    for(k=0; k<MAXK; ++k){
        if(par[a][k] == par[b][k]) break;
    }
    --k;
    while(k >= 0){
        a = par[a][k];
        b = par[b][k];
        while(k >= 0 && par[a][k] == par[b][k]) --k;
    }
    //do last jump if necessary
    if(a != b){
        k++;
        
        a = par[a][k];
        b = par[b][k];
    }
    
    return a; 
}