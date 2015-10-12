int frm[MAXN];
int flw[MAXN];
Edge *fre[MAXN];

int bfs(int f, int t){
    for(int i=0; i<MAXN; ++i) flw[i] = INT_MAX;
    std::queue<int> q;
    q.push(f);
    while(flw[t] == INT_MAX && !q.empty()){
        int p = q.front();
        q.pop();
        for(std::list<Edge*>::iterator iter = nd[p]->e.begin(); iter != nd[p]->e.end(); ++iter){	
            Node *n;
            int fl = 0;
            if((*iter)->a == nd[p]){
                n = (*iter)->b;
                fl = (*iter)->fwd;
            }else{
                n = (*iter)->a;
                fl = -(*iter)->fwd;
            }
            
            if(flw[n->p] == INT_MAX && ((*iter)->cap - fl)){
                flw[n->p] = std::min((*iter)->cap - fl, flw[p]);
                frm[n->p] = p;
                fre[n->p] = *iter;
                q.push(n->p);
            }
        }
    }
    return flw[t];
}

int maxflow(int f, int t){
    int tot = 0;
    while(true){
        int fl = bfs(f, t);
        if(fl == INT_MAX) break;
        tot += fl;
        
        int fr = t;
        while(fr != f){
            Edge *e = fre[fr];
            if(e->a == nd[frm[fr]]){
                e->fwd += fl;
            }else{
                e->fwd -= fl;
            };
            fr = frm[fr];
        }
    }
    
    return tot;
}
