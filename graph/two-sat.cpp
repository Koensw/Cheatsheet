//needs tarjan (MAXN = 2x the amount of variables)
int asgn[MAXN]; //start from 2 all even indexes contain normal var

//give terms with negative as negotiation (make sure no zero used!)
int comp[MAXN];
int casg[MAXN];
bool two_sat(std::vector<std::pair<int, int> > terms){
    for(int i=0; i<MAXN; ++i) comp[i] = casg[i] = -1;
    
    //build graph
    for(size_t i=0; i<terms.size(); ++i){
        std::pair<int, int> p = terms[i];
        Edge *e = new Edge();
        if(p.first < 0) e->f = -2*p.first;
        else e->f = 2*p.first+1;
        if(p.second < 0) e->t = -2*p.second+1;
        else e->t = 2*p.second;
        nd[e->f].ed.push_back(e);
        e = new Edge();
        if(p.second < 0) e->f = -2*p.second;
        else e->f = 2*p.second+1;
        if(p.first < 0) e->t = -2*p.first+1;
        else e->t = 2*p.first;
        nd[e->f].ed.push_back(e);
    }
    
    //apply tarjan
    std::vector<std::vector<int> > all;
    for(int k=0; k<MAXN; ++k){
        if(dpt[k] != -1) continue;
        std::vector<std::vector<int> > vec = tarjan(k);
        for(size_t i=0; i<vec.size(); ++i) for(size_t j=0; j<vec[i].size(); ++j) comp[vec[i][j]] = i+all.size();        
        all.insert(all.end(), vec.begin(), vec.end());
    }
    
    //reverse topological traverse
    for(size_t i=0; i<all.size(); ++i){
        if(casg[i] == -1) casg[i] = true;
        
        for(size_t j=0; j<all[i].size(); ++j){
            int chk = comp[all[i][j]]/2;
            if(comp[chk*2] == comp[chk*2+1]) return false;
            
            if(all[i][j] % 2) casg[comp[all[i][j]-1]] = !casg[i];
            else casg[comp[all[i][j]+1]] = !casg[i];
        }
    }
    
    //set assignment (2 contains assignment var 1, 4 assignment var 2 etc...)
    for(size_t i=0; i<all.size(); ++i) for(size_t j=0; j<all[i].size(); ++j) asgn[all[i][j]/2] = casg[i];
    return true;
}