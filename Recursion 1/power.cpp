int power(int x, int n) {
    
    if(n==0){
        return 1;
    }else{
        int recursive_task=power(x,n/2);
        if(n%2==0){
            return recursive_task*recursive_task;

        }else{
            return x*recursive_task*recursive_task;
        }
    }

}
