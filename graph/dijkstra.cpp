void dijkstra(int F){
    for(int i=0; i<MAXN; ++i) dis[i] = INT_MAX;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int > >, std::greater<std::pair<int, int > > > pq;
    dis[F] = 0;
    pq.push(std::make_pair(0, F));
    while(!pq.empty()){
        std::pair<int, int> p = pq.top();
        pq.pop();
        if(dis[p.second] != p.first) continue;
        for(auto iter = nd[p.second].ed.begin(); iter != nd[p.second].ed.end(); ++iter){
            Edge *e = *iter;
            if(p.first + e->d < dis[e->t]){
                dis[e->t] = p.first + e->d;
                pq.push(std::make_pair(dis[e->t], e->t));
            }
        }
    }
}