int firstIndex(int input[], int size, int x) {
  
    for(int i=0;i<size;i++){
        if(input[i]==x){
            return i;
        }
    }return -1;
}
