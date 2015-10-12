int N; //amount of rows (columns = rows + 1)
double aug[MAXN][MAXN];
double ans[MAXN];
void gaussian_elimination() {
    // the forward elimination phase
    for (int i = 0; i < N - 1; i++) {
        int l = i;
        
        for (int j = i + 1; j < N; j++)
            // which row has largest column value
            if (fabs(aug[j][i]) > fabs(aug[l][i])) l = j;

        // swap this pivot row, reason: minimize floating point error
        for (int k = i; k <= N; k++){
                double t = aug[i][k];
                aug[i][k] = aug[l][k];
                aug[l][k] = t;
        }
        
        // the actual forward elimination phase
        for (int j = i + 1; j < N; j++)
            for (int k = N; k >= i; k--) aug[j][k] -= aug[i][k] * aug[j][i] / aug[i][i];
                            
    }

    // the back substitution phase
    for (int j = N - 1; j >= 0; j--) {
        double t = 0.0;
        for (int k = j + 1; k < N; k++)
                t += aug[j][k] * ans[k];
        
        ans[j] = (aug[j][N] - t) / aug[j][j];
    }
}