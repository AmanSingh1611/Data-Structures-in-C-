int sum(int input[], int n) {
    if(n==0){
        return 0;
    }else{
        int ans=input[0]+sum(input+1,n-1);
        return ans;
    }
}
