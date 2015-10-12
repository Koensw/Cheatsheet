//deterministic until 2^64 -- needs long long expmod probably!
bool is_prime_fast(long long n){
    long long prms[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    
    long long s = 0, d = n-1;
    while((d % 2) == 0){
        d/=2;
        s++;
    }
    for(int i=0; i<12; ++i){
        if(prms[i] >= n) break;
        if(expmod(prms[i], d, n) == 1) continue;
        long long c = 1;
        int j = 0;
        for(j=0; j<s; ++j){
            if(expmod(prms[i], c*d, n) == n-1) break;
            c *= 2;
        }
        if(j == s) return false;
    }
    return true;
}