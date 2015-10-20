int ldp[MAXN]; //lis dp array
int lin[MAXN]; //lin[inp.size()-1] contains last index
int frm[MAXN]; //contains index number came from
int lis(std::vector<int> inp){ //non-decreasing lis
    for(int i=0; i<MAXN; ++i) ldp[i] = INT_MAX;

    for(size_t i=0; i<inp.size(); ++i){
        int k = std::upper_bound(ldp, ldp+MAXN, inp[i])-ldp;
        ldp[k] = inp[i];
        lin[k] = i;
        if(k == 0) frm[i] = -1;
        else frm[i] = lin[k-1];
    }
    
    return std::upper_bound(ldp, ldp+MAXN, INT_MAX-1)-ldp;
}