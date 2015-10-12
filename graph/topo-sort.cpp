int ecnt[MAXN];

std::vector<int> toposort(){
    std::vector<int> res;
    std::queue<int> q;
    for(int i=0; i<MAXN; ++i){
        if(incnt[i] == 0) q.push(i);
    }
    
    while(!q.empty()){
        int c = q.front();
        q.pop();
        res.push_back(c);
        for(auto iter = nd[c].ed.begin(); iter != nd[c].ed.end(); ++iter){			
            Edge *e = (*iter);
            --incnt[e->t];
            if(incnt[e->t] == 0) q.push(e->t);
        }
    }
    return res;
}