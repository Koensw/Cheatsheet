std::vector<int> biconnected(int r){
    std::vector<int> res;
    
    std::stack<int> s;
    s.push(r);
    dpt[r] = 0;
    while(!s.empty()){
        int c = s.top();
        s.pop();
        
        if(lit[c] == nd[c].ed.end()){
            int cnt = 0;
            for(auto iter = nd[c].ed.begin(); iter != nd[c].ed.end(); ++iter){ 
                int n = (*iter)->t;
                if(dpt[c] != 0 && low[n] >= dpt[c] && dpt[n] == dpt[c]+1){ //other edges
                    res.push_back(c);
                    break;
                }else if(dpt[c] == 0 && dpt[n] == dpt[c]+1){ //root
                    dpt[n] = 0;
                    ++cnt;
                }
            }
            if(dpt[c] == 0 && cnt >= 2) res.push_back(c); //root
            continue;
        }
        if(low[c] == INT_MAX) low[c] = dpt[c];
        s.push(c);
        
        auto iter = lit[c];
        for(; iter!=nd[c].ed.end(); ++iter){
            int n = (*iter)->t;
            if(dpt[n] != -1){
                if(dpt[n] < dpt[c]-1) low[c] = std::min(low[c], dpt[n]); // back edge
                else if(dpt[n] > dpt[c]) low[c] = std::min(low[c], low[n]); // forward edge
            }else{
                dpt[n] = dpt[c]+1;
                s.push(n);
                break;
            }
        }
        lit[c] = iter;
    }
    return res;
}