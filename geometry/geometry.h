#define PI (2*std::acos(0.0))
#define EPS 1e-9

struct Vec{
    Vec(): x(0), y(0), z(0) {}
    Vec(Vec p1, Vec p2): x(p2.x-p1.x), y(p2.y-p1.y), z(p2.z-p1.z) {}
    Vec(double i, double j, double k = 0): x(i), y(j), z(k) {}
    double x;
    double y;
    double z;
    
    bool operator<(const Vec &o){
        if(fabs(x - o.x) > EPS) return x < o.x;
        else if(fabs(y - o.y) > EPS) return y < o.y;
        else return z < o.z;
    }
    bool operator==(const Vec &o){
        return (fabs(x-o.x) < EPS) && (fabs(y-o.y) < EPS) && (fabs(z-o.z) < EPS);
    }
};
Vec operator+(const Vec &a, const Vec &b){
    return Vec(a.x+b.x, a.y+b.y, a.z+b.z);
}
Vec operator*(const double d, Vec b){
    return Vec(d*b.x, d*b.y, d*b.z);
}

struct Line{
    Line(Vec i, Vec j): b(i), d(j) {}
    Vec b; //base
    Vec d; //direction
};
Line fromPoints(Vec i, Vec j){
    return Line(i, Vec(i, j));
}

double dot(Vec a, Vec b){ //dot product
    return a.x*b.x+a.y*b.y+a.z*b.z;
}
double cross(Vec a, Vec b){ //cross product (2D)
    return a.x*b.y-a.y*b.x;
}
Vec cross_vec(Vec a, Vec b){
    return Vec(a.y*b.z-b.y*a.z, a.z*b.x-b.z*a.x, a.x*b.y-a.y*b.x);
}
double len_sq(Vec a){ //give the squared length of a vector
    return dot(a, a);
}
double len(Vec a){ //squares the squared length
    return std::sqrt(len_sq(a));
}

double angle(Vec p, Line l){ //return the angle between the line and the point
    Vec c(l.b, p);
    return acos(dot(c, l.d)/std::sqrt(len_sq(c)*len_sq(l.d)));
}
bool colineair(Vec p, Line l){ //returns if a point is on a line
    return fabs(cross(Vec(l.b, p), l.d)) < EPS;
}
double ccw(Vec p, Line l){ //return true if p is left of l
    return cross(Vec(l.b, p), l.d) < 0;
}