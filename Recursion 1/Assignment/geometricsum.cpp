#include <cmath>
double geometricSum(int k) {

    if(k==0)
    	return 1.00;
    double as=geometricSum(k-1);
    double ss=as+pow(0.5,k);
    return ss;

}


