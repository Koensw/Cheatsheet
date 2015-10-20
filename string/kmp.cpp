int bt[MAXN]; //back table created preprocessing pattern
void kmpPreprocess(std::string P) {
    size_t i = 0, j = -1; bt[0] = -1;
    while (i < P.size()) { 
        while (j >= 0 && P[i] != P[j]) j = bt[j]; 
        i++; j++; 
        bt[i] = j;
    }
}

void kmpSearch(std::string T, std::string P) {
    kmpPreprocess(P); //preprocess first
    
    size_t i = 0, j = 0; 
    while (i < T.size()) {
        while (j >= 0 && T[i] != P[j]) j = bt[j]; 
        i++; j++; 
        if (j == P.size()) { 
            //pattern is found in text at index i-j -- DO STUFF HERE
            j = bt[j];
        }
    } 
}