//122. Best Time to Buy and Sell Stock II
#include<bits/stdc++.h>
using namespace std;



int maxProfit(vector<int>& prices) {
    int maxProfits = 0;
    for(int i=1;i<prices.size();i++){
        if(prices[i]>prices[i-1]){
            maxProfits+=(prices[i]-prices[i-1]);
        }
    }
    return maxProfits;
}

int main(){

    vector<int> prices = {7,1,5,3,6,4};
    cout<<maxProfit(prices);
    return 0;
}