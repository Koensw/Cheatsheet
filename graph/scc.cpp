int tarjan_ind = 0;
std::vector<std::vector<int> > tarjan(int r){
    std::vector<std::vector<int> > res;
    
    std::stack<int> s;
    std::stack<int> cp;
    s.push(r);
    dpt[r] = ++tarjan_ind;
    while(!s.empty()){
        int c = s.top();
        s.pop();
        
        //init
        if(low[c] == INT_MAX){
            cp.push(c);
            low[c] = dpt[c];
        }
        
        //add to result
        if(lit[c] == nd[c].ed.end()){
            if(low[c] == dpt[c]){
                res.push_back(std::vector<int>());
                while(true){
                    int n = cp.top();
                    dpt[n] = INT_MAX; low[n] = INT_MAX;
                    res.back().push_back(n);
                    cp.pop();
                    if(n == c) break;
                }
            }
            continue;
        }
        
        //compute scc
        s.push(c);
        auto iter = lit[c];
        for(; iter!=nd[c].ed.end(); ++iter){
            int n = (*iter)->t;
            if(dpt[n] != -1){
                if(dpt[n] < dpt[c]) low[c] = std::min(low[c], dpt[n]); // back edge
                else if(dpt[n] > dpt[c]) low[c] = std::min(low[c], low[n]); // forward edge
            }else{
                dpt[n] = ++tarjan_ind;
                s.push(n);
                break;
            }
        }
        lit[c] = iter;
    }
    return res;
}