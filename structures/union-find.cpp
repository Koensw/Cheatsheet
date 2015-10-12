int pr[MAXN];
int sz[MAXN];

int find(int k){
    if(pr[k] == k) return k;
    else return pr[k] = find(pr[k]);
}
void merge(int a, int b){
    a = find(a); b = find(b);
    if(a == b) return;
    if(sz[a] > sz[b]) std::swap(a, b);
    
    pr[a] = b;
    sz[b] += sz[a];
    sz[a] = 0;
}