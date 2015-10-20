#include <bits/stdc++.h>
#define MAXN 20

#include "../geometry/geometry.h"

#include "binary-search-integer.cpp"
#include "binary-search-float.cpp"

#include "counting-sort.cpp"

#include "gen-permutations.cpp"
#include "gen-combinations.cpp"

#include "lis.cpp"

void test_counting_sort(){
    std::vector<int> arr = {23, 21, 22, 55, 22};
    counting_sort(arr);
    
    for(int i=0; i<5; ++i) std::cout << arr[i] << std::endl;
}

void test_combinations(){
    std::vector<int> vec = {1, 2, 3, 4};
    
    std::list< std::vector<int> > lst = gen_combinations(vec, 1);
    for(auto iter=lst.begin(); iter!=lst.end(); ++iter){
        for(size_t j=0; j<iter->size(); ++j){
            std::cout << (*iter)[j];
        }
        std::cout << std::endl;
    }
    
}

int main(){
    std::vector<int> v = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    //std::vector<int> v = {-7, 10, 9, 2, 3, 8, 8, 1};
    
    std::cout << lis(v) << std::endl;
    int lst = lin[lis(v)-1];
    while(lst != -1){
        std::cout << v[lst] << " ";
        lst = frm[lst];
    }
    std::cout << std::endl;
}