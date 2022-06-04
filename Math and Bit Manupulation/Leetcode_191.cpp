//191. Number of 1 Bits
#include<bits/stdc++.h>
using namespace std;

int hammingWeight(uint32_t n) {
    int count=0;
    while (n>0)
    {
        if(n&1){
            count++;
        }
        n=n>>1;
    }
    return count;
}
// Second Approach
int hammingWeights(uint32_t n){
    int count=0;
    while (n>0)
    {
        n = n&n-1;
        count++;
    }
    return count;
}

int main(){
    uint32_t n = 00000000000000000000000000001011;
    cout<<hammingWeight(n)<<endl;
    cout<<hammingWeights(n);
    return 0;
}