

/*int RA[MAXN];
int SA[MAXN];
int tempRA[MAXN];
int Phi[MAXN];

int LCP[MAXN];
int PLCP[MAXN];
void constructSA() {         // this version can go up to 100000 characters
    int i, k, r;
    for (i = 0; i < n; i++) RA[i] = T[i];                 // initial rankings
    for (i = 0; i < n; i++) SA[i] = i;     // initial SA: {0, 1, 2, ..., n-1}
    for (k = 1; k < n; k <<= 1) {       // repeat sorting process log n times
        //countingSort(k);  // actually radix sort: sort based on the second item
        //countingSort(0);          // then (stable) sort based on the first item
        tempRA[SA[0]] = r = 0;             // re-ranking; start from rank r = 0
        for (i = 1; i < n; i++)                    // compare adjacent suffixes
            tempRA[SA[i]] = // if same pair => same rank r; otherwise, increase r
            (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;
        for (i = 0; i < n; i++)                     // update the rank array RA
            RA[i] = tempRA[i];
        if (RA[SA[n-1]] == n-1) break;               // nice optimization trick
    } 
}
    
void computeLCP() {
    int i, L;
    Phi[SA[0]] = -1;                                         // default value
    for (i = 1; i < n; i++)                            // compute Phi in O(n)
        Phi[SA[i]] = SA[i-1];    // remember which suffix is behind this suffix
        for (i = L = 0; i < n; i++) {             // compute Permuted LCP in O(n)
            if (Phi[i] == -1) { PLCP[i] = 0; continue; }            // special case
            while (T[i + L] == T[Phi[i] + L]) L++;       // L increased max n times
            PLCP[i] = L;
            L = std::max(L-1, 0);                             // L decreased max n times
        }
        for (i = 0; i < n; i++)                            // compute LCP in O(n)
            LCP[i] = PLCP[SA[i]];   // put the permuted LCP to the correct position
}*/
