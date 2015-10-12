int bfs(int F){
    for(int i=0; i<MAXN; ++i) dis[i] = INT_MAX;
    std::queue<int> q; //replace by stack for dfs
    dis[F] = 0;
    q.push(F);
    while(!q.empty()){
        int p = q.front();
        q.pop();
        for(auto iter = nd[p].ed.begin(); iter != nd[p].ed.end(); ++iter){
            Edge *e = *iter;
            if(dis[e->t] == INT_MAX){
                dis[e->t] = dis[p] + 1;
                q.push(e->t);
            }
        }
    }
}