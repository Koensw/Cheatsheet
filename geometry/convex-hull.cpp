Vec pivot(0, 0); //will contain the point that is used as pivot

bool angle_cmp(Vec p1, Vec p2){
    Line l = Line(pivot, Vec(pivot, p2));
    if(colinear(l, p1)) return dist(pivot, p1) < dist(pivot, p2);
    return !ccw(p1, l);
}

std::vector<Vec> convex_hull(std::vector<Vec> v){ //DONT ADD FIRST POINT AGAIN
    std::vector<Vec> ans;
    if(v.size() <= 3) return v;
    
    int s = 0;
    for(size_t i=1; i<v.size(); ++i){
        if(v[i].y+EPS < v[s].y || (fabs(v[i].y - v[s].y) < EPS && v[i].x < v[s].x)) s = i;
    }
    
    std::swap(v[0], v[s]);
    pivot = v[0];
    sort(++v.begin(), v.end(), angle_cmp);
    
    ans.push_back(v.back()); ans.push_back(v[0]); ans.push_back(v[1]);
    size_t i = 2;
    while(i < v.size()){
        size_t j = ans.size()-1;
        if(ccw(ans[j-1], Line(ans[j], v[i]))) ans.push_back(v[i++]);
        else ans.pop_back();
    }
    return ans;
}
