bool bellman_ford(int F){
    //compute shortest path
    for(int i=0; i<MAXN; ++i) dis[i] = INT_MAX;
    dis[F] = 0;
    for(int k=0; k<MAXN-1; ++k){
        for(int i=0; i<MAXN; ++i){
            for(auto iter = nd[i].ed.begin(); iter != nd[i].ed.end(); ++iter){	
                Edge *e = *iter;
                if(dis[i] + e->d < dis[e->t]){
                    dis[e->t] = dis[i] + e->d;
                }
            }
        }
    }
    
    //check for negative weight path
    for(int i=0; i<MAXN; ++i){
        for(auto iter = nd[i].ed.begin(); iter != nd[i].ed.end(); ++iter){		
            Edge *e = *iter;
            if(dis[i] + e->d < dis[e->t]) return false;
        }
    }
    return true;
}