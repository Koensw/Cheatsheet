//needs union-find
bool cmp(Edge *e1, Edge *e2) { return e1->d < e2->d; }

std::vector<Edge*> kruskal(std::vector<Edge*> &edg){
    std::vector<Edge*> vec;
    
    std::sort(edg.begin(), edg.end(), cmp);
    for(size_t i=0; i<edg.size(); ++i){
        int a = find(edg[i]->f);
        int b = find(edg[i]->t);
        if(a != b){
            vec.push_back(edg[i]);
            merge(a, b);
        }
    }
    
    return vec;
}