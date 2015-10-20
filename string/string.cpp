#include <bits/stdc++.h>
#define MAXN 1000

#include "edit-distance.cpp"
#include "kmp.cpp"
#include "suffix-array.cpp"
#include "lcp.cpp"

int main(){
    std::string s = "GATATACA";
    constructSA(s);
    constructLCP(s);
    for(size_t i=0; i<=s.size(); ++i){
        std::cout << SA[i] << " " << LCP[i] << " " << s.substr(SA[i]) << std::endl;
    }
}