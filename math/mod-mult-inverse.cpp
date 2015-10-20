//needs extended euclidean
int mod_inverse(int a, int m){
    if(gcd(a, m) != 1) return -1; //inverse does not exist
    int inv = extgcd(a, m).first;
    if(inv < 0) {
        int mlt = inv/m;
        if(inv % m) mlt--;
        inv -= mlt*m;
    }
    return inv;
}