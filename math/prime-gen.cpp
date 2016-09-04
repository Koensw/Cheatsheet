std::vector<long long> prms;
long long is_prm[MAXN];

//generate primes needed for functions below
void init_prms(){
    for(long long i=0; i<MAXN; ++i) is_prm[i] = true;
    for(long long i=2; i<MAXN; ++i){
        if(!is_prm[i]) continue;
        prms.push_back(i);
        for(long long j=i*i; j<MAXN; j+=i) is_prm[j] = false;
    }
}
