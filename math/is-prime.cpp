bool is_prime(long long n){
    for(size_t i=0; i<prms.size(); ++i){
        if(prms[i]*prms[i] > n) return true;
        if((n % prms[i]) == 0) return false;
    }
    return true;
}