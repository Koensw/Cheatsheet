std::pair<bool, Vec> intersect(Line l1, Line l2){
    Vec v = Vec(l1.b, l2.b);
    double c = cross(l1.d, l2.d);
    if(fabs(c) < EPS){
        if((-EPS <= dot(v, l1.d) && dot(v, l1.d) <= len_sq(l1.d)+EPS) ||
            (-EPS <= dot(v, l2.d) && dot(v, l2.d) <= len_sq(l2.d)+EPS))
            return std::make_pair(true, Vec()); //colinear and touching
            else return std::make_pair(false, Vec()); //either colineair but not touching or parallel
    }else{
        double t = cross(v, l1.d)/c;
        double u = cross(v, l2.d)/c;
        if(-EPS <= t && t <= 1+EPS && -EPS <= u && u <= 1+EPS) return std::make_pair(true, l1.b+u*l1.d); //intersects
        else return std::make_pair(false, Vec()); //not intersecting
    }
}