int fib(int n){
    int a = 0, b = 1;
    for(int i=0; i<n; ++i){
        int t = b;
        b = a+b;
        a = t;
    }
    return a;
}