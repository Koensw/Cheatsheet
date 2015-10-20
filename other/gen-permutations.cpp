std::list<std::vector<int> > gen_permutation(std::vector<int> &opts, int sz){
    std::list<std::vector<int> > all;
    if(sz == 0){
        for(size_t i=0; i<opts.size(); ++i) all.push_back({opts[i]});
        return all;
    }
    for(size_t i=0; i<opts.size(); ++i){
        std::list<std::vector<int> > lst = gen_permutation(opts, sz-1);
        for(auto iter = lst.begin(); iter != lst.end(); ++iter) iter->push_back(opts[i]);
        all.insert(all.end(), lst.begin(), lst.end());
    }
    return all;
}