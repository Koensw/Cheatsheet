bool can(double f){ 
    //add implementation here 
    return true; 
}

int binsearch(int lo, int hi){
    while(lo < hi){
        int mid = (lo+hi)/2;
        
        if(can(mid)) lo = mid+1;
        else hi = mid;
    }
    return lo;
}