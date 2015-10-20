int tarjan_ind = 0;
std::vector<std::vector<int> > tarjan(int r){
    for(int i=0; i<MAXN; ++i) eit[i] = nd[i].ed.begin();
    std::vector<std::vector<int> > res; //result components
    
    std::stack<int> st; //stack
    std::stack<int> cp; //current component
    st.push(r);
    dpt[r] = ++tarjan_ind;
    while(!st.empty()){
        int c = st.top();
        st.pop();
        
        //init
        if(low[c] == INT_MAX){
            cp.push(c);
            low[c] = dpt[c];
        }
        
        //add to result
        if(eit[c] == nd[c].ed.end()){
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
        
        //loop through children (non-recursive so we should come back to this node)
        st.push(c);
        auto iter = eit[c];
        for(; iter!=nd[c].ed.end(); ++iter){
            int n = (*iter)->t;
            if(dpt[n] != -1){
                if(dpt[n] < dpt[c]) low[c] = std::min(low[c], dpt[n]); // back edge
                else if(dpt[n] > dpt[c]) low[c] = std::min(low[c], low[n]); // forward edge
            }else{
                dpt[n] = ++tarjan_ind;
                st.push(n);
                break;
            }
        }
        eit[c] = iter;
    }
    return res;
}