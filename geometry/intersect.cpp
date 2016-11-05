std::pair<int, Vec> intersect(Line l1, Line l2){ //0 = non intersecting, 1 = intersecting, 2 = overlapping
    //check if single point on line
    if(l1.d == Vec(0, 0)) return std::make_pair(in_segment(l2, l1.b) && colinear(l2, l1.b), l1.b);
    if(l2.d == Vec(0, 0)) return std::make_pair(in_segment(l1, l2.b) && colinear(l1, l2.b), l2.b);
    
    Vec v = Vec(l1.b, l2.b);
    double c = cross(l1.d, l2.d);
    if(fabs(c) < EPS){
        if (fabs(cross(v, l1.d)) > EPS) return std::make_pair(0, Vec()); //parallel
        else{
            if(in_segment(l2, l1.b)) return std::make_pair(2, l1.b); //colinear and overlapping
            if(in_segment(l2, l1.b+l1.d)) return std::make_pair(2, l1.b+l1.d); //colinear and overlapping
            if(in_segment(l1, l2.b)) return std::make_pair(2, l2.b); //colinear and overlapping
            if(in_segment(l1, l2.b+l2.d)) return std::make_pair(2, l2.b+l2.d); //colinear and overlapping
            return std::make_pair(0, Vec()); //colinear but not overlapping 
        }
    }else{
        double t = cross(v, l1.d)/c;
        double u = cross(v, l2.d)/c;
        if(-EPS <= t && t <= 1+EPS && -EPS <= u && u <= 1+EPS) return std::make_pair(1, l1.b+u*l1.d); //intersects
        else return std::make_pair(0, Vec()); //not intersecting
    }
}
