bool checkNumber(int input[], int size, int x) {
    if(size==0){
        return false;
    }
    if(x==input[0]){
        return true;
    }
    else{
        checkNumber(input+1,size-1,x);
    }
}
