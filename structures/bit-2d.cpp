//online O(N (log(N)^2) is also possible using std::map<int, int>
std::pair<int, int> rs[MAXN]; //list of points (y,x)
std::vector<int> lst2[MAXN];
std::vector<int> order[MAXN];

int sum(int b, int c){
    int sum = 0; b+=1; c+=1;
    for(; b; b-=(b&(-b))){
        int h = upper_bound(order[b].begin(), order[b].end(), c) - order[b].begin();
        for(int d = h; d; d-=(d&(-d))){
            sum += lst2[b][d];
        }
    }
    return sum;
}

void update(int b, int c, int v){
    b+=1; c+=1;
    int unt = 0;
    for(; b<MAXN; b+=(b&(-b))){
        int h = upper_bound(order[b].begin(), order[b].end(), c) - order[b].begin();
        for(int d = h; d<lst2[b].size(); d+=(d&(-d))){
            lst2[b][d] += v;
        }
    }
}

void init(){
    std::sort(rs, rs+MAXN);
    for(int i=0; i<MAXN; ++i){
        for(int j=rs[i].second+1; j<MAXN; j+=(j&(-j))){
            order[j].push_back(rs[i].first+1);
            lst2[j].push_back(0);
        }
    }
    for(int i=0; i<MAXN; ++i) lst2[i].push_back(0);
}