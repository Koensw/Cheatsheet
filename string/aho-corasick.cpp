#define MAXA 26

long long S; // number of nodes
std::vector<std::string> words; // fill with the words
long long nxt[MAXN][MAXA]; // trie
long long fail[MAXN]; // failure function
std::vector<long long> mtch[MAXN]; // matches for word i

void init_aho_corasick() {
    // Reset
    S = 1;
    for(long long i=0; i<MAXN; ++i) {
        for(long long j=0; j<26; ++j) {
            nxt[i][j] = -1;
        }
        fail[i] = 0;
        mtch[i].clear();
    }
    // Build trie
    long long s;
    for(long long i=0; i<words.size(); ++i) {
        s = 0;
        for(long long j=0; j<words[i].size(); ++j) {
            long long c = words[i][j]-'a';
            if(nxt[s][c] == -1) nxt[s][c] = S++;
            s = nxt[s][c]; 
        }
        mtch[s].push_back(i);
    }
    // Initialize queue
    std::queue<long long> q;
    for(long long i=0; i<MAXA; ++i) {
        if(nxt[0][i] != -1) {
            fail[nxt[0][i]] = 0;
            q.push(nxt[0][i]);
        } else nxt[0][i] = 0;
    }
    // Create failure function
    while(!q.empty()) {
        auto s = q.front();
        q.pop();
        for(long long i=0; i<MAXA; ++i) {
            if(nxt[s][i] == -1) continue;
            auto f = fail[s];
            while(nxt[f][i] == -1) f = fail[f];
            f = nxt[f][i];
            fail[nxt[s][i]] = f;
            for(auto& m : mtch[f]) mtch[nxt[s][i]].push_back(m);
            q.push(nxt[s][i]);
        }
    }
}
