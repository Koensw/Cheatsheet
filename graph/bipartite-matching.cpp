int mtch[MAXN]; //only the size of one side
bool aug(int n) {
    if (vis[n]) return false;
    vis[n] = true;
    
    for (size_t i = 0; i < nd[n].ed.size(); i++) {
        Edge *e = nd[n].ed[i];
        //try match with edge (if available or previous can be rematched) 
        if (mtch[i] == -1 || aug(mtch[e->t])) { 
            mtch[i] = n; 
            return true;
        }
    }
    return false;
}

void bipartite_matching() {
    for (int i = 0; i < MAXN; i++) mtch[i] = -1; 
    
    int M = 0; //contains the maximum matching
    for (int i = 0; i < MAXN; i++) { //try to start match from i
        for (int j = 0; j<MAXN; j++) vis[j] = false;
        if (aug(i)) M++; 
    }
}