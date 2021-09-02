void pushZeroesEnd(int *input, int size){
    int i=0;non_zero=0;
    for(i;i<size;i++){
        if(input[i]==0){
            continue;
        }else{
            int temp=input[i];
            input[i]=input[k];
            input[k]=temp;
            k++;
        }
    }
}