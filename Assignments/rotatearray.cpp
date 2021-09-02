void rotate(int *input, int d, int n)
{
    //Write your code here
    int brr[d];
    int i=0,j=0,k=0;
    for(j;j<d;j++){
        brr[j]=input[j];
    }for(i=0;i<n-d;i++){
        input[i]=input[i+d];
    }for(j=n-d;j<n;j++){
        input[j]=brr[k];
        k++;
    }
}