//start from one of the two non-even edges (if trail)
std::list<int> euler_tour(int s){
    std::list<int> ans;
    for(int i=0; i<MAXN; ++i) eit[i] = nd[i].ed.begin();
    
    std::stack<int> st;
    st.push(s);
    while(!st.empty()){
        int c = st.top();
        st.pop();
        
        auto iter = eit[c];
        if(iter == nd[c].ed.end()){
            ans.push_front(c);
            continue;
        }
        
        st.push(c);
        for(; iter != nd[c].ed.end(); ++iter){
            Edge *e = *iter;
            if(e->use) continue;
            e->use = e->rev->use = true;
            st.push(e->t);
            break;
        }
        eit[c] = iter;
    }

    return ans;
}