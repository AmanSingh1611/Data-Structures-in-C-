int count(int n){
    if(n==0){
        return 1;
    }
    int ans=0;
    while(n){
        ans++;
        n=n/10;
    }return ans;
}