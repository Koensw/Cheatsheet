int cmb[MAXN][MAXN];
int comb(int i, int j){
    if(i < 0) return 0;
    else if(j == 0) return 1;
    else if(cmb[i][j] != -1) return cmb[i][j];
    else return cmb[i][j] = comb(i-1,j-1)+comb(i-1,j);
}