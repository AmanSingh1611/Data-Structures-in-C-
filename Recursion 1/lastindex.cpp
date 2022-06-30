int lastIndex(int input[], int size, int x) {
    for(int i=size-1;i>=0;i--){
        if(input[i]==x){
            return i;
        }
    }return -1;
}
