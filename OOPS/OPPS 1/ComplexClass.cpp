class ComplexNumbers {
    private :
    long int r1,i1;
    public :
    ComplexNumbers(int real,int imag){
        r1=real;
        i1=imag;
    }void print(){
        cout<<r1<<" "<<"+"<<" "<<"i"<<i1;
    }void plus(ComplexNumbers c2 ){
        r1=r1+c2.r1;
        i1=i1+c2.i1;
    }void multiply(ComplexNumbers c2){
        int x=(r1*c2.r1)-(i1*c2.i1);
        int y=(c2.r1*i1)+(c2.i1*r1);
        r1=x;
        i1=y;
    }
};