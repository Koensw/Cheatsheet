int dism[MAXN][MAXN];

void floyd_warshall(){
    for(int k=0; k<MAXN; ++k){
        for(int i=0; i<MAXN; ++i){
            for(int j=0; j<MAXN; ++j){
                //line depends on exercise (this is maximum edge on minimum path)
                dism[i][j] = std::min(dism[i][j], std::max(dism[i][k], dism[k][j]));
            }
        }
    }
}