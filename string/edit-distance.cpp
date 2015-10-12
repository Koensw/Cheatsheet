//CLEANUP

int edit_distance(char *A, char *B) {
    int n = (int)strlen(A), m = (int)strlen(B);
    int i, j, table[20][20];
    
    memset(table, 0, sizeof table);
    // insert/delete = -1 point
    for (i = 1; i <= n; i++)
        table[i][0] = i * -1;
    for (j = 1; j <= m; j++)
        table[0][j] = j * -1;
    
    for (i = 1; i <= n; i++){
        for (j = 1; j <= m; j++) {
            // match = 2 points, mismatch = -1 point
            table[i][j] = table[i - 1][j - 1] + (A[i - 1] == B[j - 1] ? 2 : -1); // cost for match or mismatches
            // insert/delete = -1 point
            table[i][j] = std::max(table[i][j], table[i - 1][j] - 1); // delete
            table[i][j] = std::max(table[i][j], table[i][j - 1] - 1); // insert
        }
    }
    
    return 0;
}