bool can(double f){ return true; //add implementation here }

double binsearch(double lo = 0.0, double hi = 1e9){
    double mid, ans;
    while(std::fabs(hi-lo) > EPS){ //hi < lo for integers
        mid = (lo+hi)/2.0;
        if(can(mid)) {
            hi = mid;
            ans = mid;
        }else lo = mid; //+1 for integers
    }
    return ans;
}