
int allIndexes(int input[], int size, int x, int output[]) {
     if(size == 0)
        return 0;
     int smallCount= allIndexes(input, size -1, x, output);
     if(input[size -1] == x)
     {
         output[smallCount] = size -1;
         return smallCount +1;
     }else {
     	   return smallCount;
     }
}
