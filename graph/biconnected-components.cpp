std::vector<int> biconnected(int r){
    for(int i=0; i<MAXN; ++i) eit[i] = nd[i].ed.begin();
    std::vector<int> res; //result nodes
    
    std::stack<int> st; //stack
    st.push(r);
    dpt[r] = 0;
    while(!st.empty()){
        int c = st.top();
        st.pop();
        
        //add to result
        if(eit[c] == nd[c].ed.end()){
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
        
        //init
        if(low[c] == INT_MAX) low[c] = dpt[c];
        
        //loop through children (non-recursive so we should come back to this node)
        st.push(c);
        auto iter = eit[c];
        for(; iter!=nd[c].ed.end(); ++iter){
            int n = (*iter)->t;
            if(dpt[n] != -1){
                if(dpt[n] < dpt[c]-1) low[c] = std::min(low[c], dpt[n]); // back edge
                else if(dpt[n] > dpt[c]) low[c] = std::min(low[c], low[n]); // forward edge
            }else{
                dpt[n] = dpt[c]+1;
                st.push(n);
                break;
            }
        }
        eit[c] = iter;
    }
    return res;
}