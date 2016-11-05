/* TEST THESE */

bool inPolygon(Vec pt, const std::vector<Vec> &v){ //ADD FIRST POINT AGAIN!
    double sum = 0.0;
    for(size_t i=0; i<v.size()-1; ++i){
        if(ccw(v[i+1], fromPoints(pt, v[i]))){ //extend this to handle border
            sum += angle(v[i+1], fromPoints(pt, v[i]));
        }else sum -= angle(v[i+1], fromPoints(pt, v[i]));
    }
    return fabs(fabs(sum) - 2*PI) < EPS;
}

Vec centroid(const std::vector<Vec> &v){ //ADD FIRST POINT AGAIN!
    Vec ans;
    for(size_t i=0; i<v.size()-1; ++i){
        double spc = v[i].x*v[i+1].y-v[i+1].x*v[i].y;
        ans.x += (v[i].x+v[i+1].x)*spc;
        ans.y += (v[i].y+v[i+1].y)*spc;
    }
    ans = (1/(6.0*areaPolygon(v)))*ans;
    return ans;
}

double radiusInCircle(double ab, double bc, double ca){
    double sp = 0.5*(ab+bc+ca);
    return areaCircle(ab, bc, ca)/sp;
}

double radiusCircumCircle(double ab, double bc, double ca){
    return ab*bc*ca/(4.0*areaCircle(ab, bc, ca));
}

std::pair<int, Vec> inCircleTriangle(Vec pa, Vec pb, Vec pc){ //returns radius and center
    double r = radiusInCircle(len(Vec(pa, pb)), len(Vec(pb, pc)), len(Vec(pa, pc)));
    if(fabs(r) < EPS) return std::make_pair(r, Vec());
    
    double ratio = len(Vec(pa, pb))/len(Vec(pa, pc));
    Vec pt = pb + (ratio/(1+ratio))*Vec(pb, pc);
    Line l1 = fromPoints(pa, pt); //check this line
    
    ratio = len(Vec(pb, pa))/len(Vec(pb, pc));
    pt = pa + (ratio/(1+ratio))*Vec(pa, pc);
    Line l2 = fromPoints(pb, pt); //check this line
    
    return std::make_pair(r, intersect(l1, l2).second);
}
