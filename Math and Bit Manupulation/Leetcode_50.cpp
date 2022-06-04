//50. Pow(x, n)
#include<bits/stdc++.h>
using namespace std;

double solve(double x, long long int n) {
		if(n == 0)
			return 1.0;
		if(n % 2 == 0)
			return solve(x * x, n/2);
		else
			return (x * solve(x, n-1));
	}
	double myPow(double x, int n) {
		double ans = 1.0;
		long long int temp = abs(n);
		ans = solve(x, temp);
		if(n<0)
			ans = 1/(ans);
		return ans;
}
double myPower(double x,int n){
    if(n<0){
        x = 1/x;
        n = -n;
    }
    auto result =0;
    auto currProduct = x;
    auto i = n;
    while (i)
    {
        if(i%2==1){
            result*=currProduct;
            currProduct*=currProduct;
        }
        i>>1;
    }
    return result;
}
int main(){
    
    double x = 2.00000;
    int n = 10;
    cout<<myPow(x,n)<<endl;
    cout<<myPower(x,n);
    return 0;
}