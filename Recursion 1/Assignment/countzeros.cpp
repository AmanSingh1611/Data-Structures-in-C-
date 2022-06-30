
int countZeros(int n) {
    // Write your code here
    if(n<10){
        if(n==0){
            return 1;
        }return 0;
    }
    int ans=countZeros(n/10);
	return (n%10==0)?1+ans:ans;
}


