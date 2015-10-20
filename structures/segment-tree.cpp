// inclusion segment tree (a node includes both it endpoints!)
struct Node{
Node(): li(0), ri(0), l(0), r(0) {}
    int li;
    int ri;
    Node *l;
    Node *r;
    
    int val;

    bool hupd;
    int upd;
};

Node *r;

Node *build(int li, int ri) {
    Node *n = new Node;
    n->li = li;
    n->ri = ri;
    n->upd = 0;
    if(li == ri){
        n->val = 0; //init
    }else{
        int mi = (li+ri)/2;
        n->r = build(li, mi);
        n->l = build(mi+1, ri);
        
        n->val = std::min(n->r->val, n->l->val); // merge
    }
    return n;
}

void pushd(Node *n){
    if(!n->hupd) return;
    n->l->val = n->upd; //update
    n->r->val = n->upd; //update
    n->l->upd = n->upd; //split (move old updates)
    n->r->upd = n->upd; //split (move old updates)
    n->l->hupd = true;
    n->r->hupd = true;
    n->hupd = false;
    n->upd = 0;
}

int query(Node *n, int li, int ri){
    if(ri < n->li || n->ri < li){
        //outside
        return INT_MAX;
    }else if(li <= n->li && n->ri <= ri){
        //inside
        return n->val;
    }
    pushd(n);
    
    int la = query(n->l, li, ri);
    int ra = query(n->r, li, ri);
    return std::min(la, ra); // merge
}

void update(Node *n, int li, int ri, int v){
    if(ri < n->li || n->ri < li){
        //outside
        return;
    }else if(li <= n->li && n->ri <= ri){
        //inside
        if(n->ri != n->li){
            pushd(n);
            n->upd = v; //split
            n->hupd = true;
        }
        n->val = v; //update
        return;
    }
    pushd(n);
    
    update(n->l, li, ri, v);
    update(n->r, li, ri, v);
    n->val = std::min(n->r->val, n->l->val); // merge
}