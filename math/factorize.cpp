//returns list of factors and how many times they occur
std::vector<std::pair<int, int> > factors(long long n){
    std::vector<std::pair<int, int> > v;
    for(long long i=0; i<prms.size(); ++i){
        long long k = 0;
        while((n % prms[i]) == 0){
                ++k;
                n/=prms[i];
        }
        if(k) v.push_back(std::make_pair(prms[i], k));
    }
    if(n!=1) v.push_back(std::make_pair(n, 1));
    return v;
}