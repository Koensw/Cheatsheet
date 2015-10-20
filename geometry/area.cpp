//returns signed area
double areaPolygon(const std::vector<Vec> &v){ //ADD FIRST POINT AGAIN!
    double res = 0.0;
    for(size_t i=0; i<v.size()-1; ++i){
        res += v[i].x*v[i+1].y-v[i+1].x*v[i].y;
    }
    return res/2.0; 
}

double areaCircle(double ab, double bc, double ca){
    double pm = ab+bc+ca;
    double sp = pm/2;
    return std::sqrt(sp*(sp-ab)*(sp-bc)*(sp-ca));
}