std::list<std::vector<int> > gen_combinations(std::vector<int> &opts, int k){    
    std::vector<bool> has(opts.size());
    std::fill(has.begin() + k, has.end(), true); 

    std::list<std::vector<int> > all;
    do {
        std::vector<int> comb;
        for (size_t i = 0; i < has.size(); ++i) {
            if (!has[i]) comb.push_back(opts[i]);
        }
        all.push_back(comb);
    } while (std::next_permutation(has.begin(), has.end()));
    
    return all;
}