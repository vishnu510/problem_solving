#include<bits/stdc++.h>
using namespace std;

 int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
     int total_gas = 0,total_cost =0,len = gas.size();
     for(int i=0;i<len;i++){
         total_cost+= cost[i];
         total_gas+= gas[i];
     }
     if(total_cost>total_gas){
         return -1;
     }
     int curr_gas = 0,start=0;
     for(int i=0;i<len;i++){
         if(curr_gas<0){
             curr_gas =0;
             start =i;
         }
         curr_gas+= (gas[i]-cost[i]);
     }
     return start;
    }
int main(){
    vector<int> gas{1,2,3,4,5};
    vector<int> cost{3,4,5,1,2};
    int ans = canCompleteCircuit(gas,cost);
    cout<<ans;
    return 0;
}