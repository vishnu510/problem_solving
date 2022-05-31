//263. Ugly Number
#include<bits/stdc++.h>
using namespace std;

bool isUgly(int n) {
   vector<int> primes = {2,3,5};
   if(n<1) return false;
   for(auto i:primes) while(n%i==0) n/=i;
   return n==1;
        
    }

int main(){
    int n =8;
    cout<<isUgly(n);
    return 0;
}