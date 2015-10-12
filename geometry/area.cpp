double area(const std::vector<Vec> &v){ //ADD FIRST POINT AGAIN!
    double res = 0.0;
    for(int i=0; i<v.size()-1; ++i){
        res += v[i].x*v[i+1].y-v[i+1].x*v[i].y;
    }
    return fabs(res)/2.0;
}