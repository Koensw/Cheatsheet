int dp[MAXN][MAXN]; //edit distance dp table
inline int edit_distance(std::string a, std::string b){
    dp[0][0] = 0;
    for(size_t i=1; i<=a.size(); ++i) dp[i][0] = i;
    for(size_t j=1; j<=b.size(); ++j) dp[0][j] = j;
    for(size_t i=1; i<=a.size(); ++i){
        for(size_t j=1; j<=b.size(); ++j){
            dp[i][j] = std::min(dp[i][j-1], dp[i-1][j])+1; //add character: +1
            if(a[i-1] == b[j-1]) dp[i][j] = std::min(dp[i][j], dp[i-1][j-1]); //same character: no cost
            else dp[i][j] = std::min(dp[i][j], dp[i-1][j-1]+1); //replace character +1
        }
    }
    return dp[a.size()][b.size()];
}