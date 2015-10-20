//MAXN should be 2x normal
int SA[MAXN];

int RA[MAXN];
int tempRA[MAXN];
int SK;
bool cmp(int a, int b){
    if(RA[a] == RA[b]) return RA[a+SK] < RA[b+SK];
    else return RA[a] < RA[b];
}

void constructSA(std::string T){
    T += '$';
    int N = T.size();
    for(int i=0; i<2*N; ++i) {
        if(i < N) RA[i] = T[i]; 
        else RA[i] = 0;
        SA[i] = i;
    }
    int r = 0;
    for(SK=1; SK<N; SK<<=1){
        std::sort(SA, SA+N, cmp); //can also use 2x counting sort
        
        tempRA[SA[0]] = r = 0;
        for(int i=0; i<N; ++i){
            if(RA[SA[i]] != RA[SA[i-1]] || RA[SA[i]+SK] != RA[SA[i-1]+SK]) ++r;
            tempRA[SA[i]] = r;
        }
        
        for(int i=0; i<N; ++i) RA[i] = tempRA[i];
        if(RA[SA[N-1]] == N-1) break;
    }
}
