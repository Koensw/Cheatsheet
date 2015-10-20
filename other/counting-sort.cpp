const int MAXNUM = 100;
int ind[MAXNUM]; //contains new index after sort
int tmp[MAXN]; //temporary sort array

void counting_sort(std::vector<int> arr) { //stable counting sort
    for(int i=0; i<MAXNUM; ++i) ind[i] = 0;
    
    for(size_t i=0; i<arr.size(); ++i){
        ind[arr[i]]++;
    }
    int sum = 0;
    for(int i=0; i<MAXNUM; ++i){
        int t = ind[i];
        ind[i] = sum;
        sum += t;
    }
    for(size_t i=0; i<arr.size(); ++i){
        tmp[ind[arr[i]]++] = arr[i];
    }
    for(size_t i=0; i<arr.size(); ++i){
        arr[i] = tmp[i];
    }
}