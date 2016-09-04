bool in_segment(Line l, Vec p){
	Vec b = l.b;
	Vec e = l.b+l.d;
	return (std::min(b.x,e.x)-EPS <= p.x && p.x <= std::max(b.x,e.x)+EPS) &&
		   (std::min(b.y,e.y)-EPS <= p.y && p.y <= std::max(b.y,e.y)+EPS);
}
 
std::pair<bool, Vec> intersect(Line l1, Line l2){
    Vec v = Vec(l1.b, l2.b);
    double c = cross(l1.d, l2.d);
    if(fabs(c) < EPS){
    	if (fabs(cross(v, l1.d)) > EPS) return std::make_pair(false, Vec()); //parallel
        else{
        	if(in_segment(l2, l1.b)) return std::make_pair(true, l1.b); //colinear and touching
        	if(in_segment(l2, l1.b+l1.d)) return std::make_pair(true, l1.b+l1.d); //colinear and touching
        	if(in_segment(l1, l2.b)) return std::make_pair(true, l2.b); //colinear and touching
        	if(in_segment(l1, l2.b+l2.d)) return std::make_pair(true, l2.b+l2.d); //colinear and touching
       		return std::make_pair(false, Vec()); //colineair but not touching 
        }
    }else{
        double t = cross(v, l1.d)/c;
        double u = cross(v, l2.d)/c;
        if(-EPS <= t && t <= 1+EPS && -EPS <= u && u <= 1+EPS) return std::make_pair(true, l1.b+u*l1.d); //intersects
        else return std::make_pair(false, Vec()); //not intersecting
    }
}