//use a std::map to save very large tables or for simple 2D (faster below)
int lst[MAXN];

int sum(int b){
    int sum = 0; b+=1;
    for(; b; b-=(b&(-b))){
        sum += lst[b];
    }
    return sum;
}

int update(int b, int v){
    b+=1;
    for(; b<MAXN; b+=(b&(-b))){
        lst[b] += v;
    }
}