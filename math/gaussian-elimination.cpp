long long R; //number of rows
long long C; //number of columns excluding result (which is thus aug[i][C])
double aug[MAXN][MAXN];
double ans[MAXN];
void gaussian_elimination() {
    // incomplete system
    if(R < C) return false;
    
    // the forward elimination phase
    for (int i = 0; i < C; i++) {
        int l = i;
        
        // which row has larest column value
        for (int j = i + 1; j < R; j++) if (std::fabs(aug[j][i]) > std::fabs(aug[l][i])) l = j;
        // swap this pivot row, reason: minimize floating point error
        for (int k = i; k <= C; k++) std::swap(aug[i][k], aug[l][k]);
        // the actual forward elimination phase
        for (int j = i + 1; j < R; j++)
            if(std::fabs(aug[i][i]) < EPS) return false;
            for (int k = C; k >= i; k--) aug[j][k] -= aug[i][k] * aug[j][i] / aug[i][i];
                            
    }
    
    // check valid result
    for(long long j = R-1; j>=C; j--) {
        if(std::fabs(aug[j][C]) > EPS) return false;
        ans[j] = 0;
    }

    // the back substitution phase
    for (int j = C - 1; j >= 0; j--) {
        for (int k = j + 1; k < C; k++) aug[j][C] -= aug[j][k] * aug[k][C] / aug[k][k];
        ans[j] = aug[j][C] / aug[j][j];
    }
}
