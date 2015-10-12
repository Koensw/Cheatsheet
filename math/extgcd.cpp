//determines a and b satisfiying s*a+t*b == gcd(a, b)
std::pair<int, int> extgcd(int a, int b){
    int s = 0, old_s = 1;
    int t = 1, old_t = 0;
    int r = b, old_r = a;
    while(r){
        int q = old_r/r;
        int sv;
        sv = r;
        r = old_r - q*r; old_r = sv;
        sv = s;
        s = old_s - q*s; old_s = sv;
        sv = t;
        t = old_t - q*t; old_t = sv;
    }
    return std::make_pair(old_s, old_t);
    //return s, t if you want with result = zero
}