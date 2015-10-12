double dist(Vec p1, Vec p2){
    return hypot(p1.x-p2.x, p1.y-p2.y);
}

double dist(Vec p, Line l){
    Vec c(l.b, p);
    double u = dot(c, l.d)/len_sq(l.d);
    if(u < 0.0) return dist(l.b, p);
    else if(u > 1.0) return dist(l.b+l.d, p);
    return dist(p, l.b+u*l.d);
}