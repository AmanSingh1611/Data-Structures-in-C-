int sumOfDigits(int n) {
    // Write your code here
    if(n==0){
        return 0;
    }else{
        int ans=(n%10)+sumOfDigits(n/10);
        return ans;
    }
}


