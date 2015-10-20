double binsearch(double lo, double hi){
    double mid, ans;
    while(std::fabs(hi-lo) > EPS){
        mid = (lo+hi)/2.0;
        if(can(mid)) {
            hi = mid;
            ans = mid;
        }else lo = mid;
    }
    return ans;
}