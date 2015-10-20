int LCP[MAXN]; //longest common prefix for suffix at position i

int PLCP[MAXN];
int PHI[MAXN];
void constructLCP(std::string T){
    T += '$';
    int N = T.size();
    
    PHI[SA[0]] = -1;
    for(int i=1; i<N; ++i) PHI[SA[i]] = SA[i-1];
    
    int L = 0;
    for(int i=0; i<N; ++i){
        if(PHI[i] == -1) {
            PLCP[i] = 0;
            continue;
        }
        while(T[i+L] == T[PHI[i] + L]) L++;
        PLCP[i] = L;
        L = std::max(L-1, 0);
    }
    for(int i=0; i<N; ++i) LCP[i] = PLCP[SA[i]];
}