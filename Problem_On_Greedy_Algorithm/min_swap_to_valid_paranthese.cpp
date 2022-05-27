#include<bits/stdc++.h>
using namespace std;

int MinSwap(string s){
   int count_l = 0,count_r=0,swap=0,imbalance=0;
   for(int i=0;i<2*s.size()-1;i++){
      if(s[i]=='['){
          count_l++;
          if(imbalance>0){
              swap+=imbalance;
              imbalance--;
          }
      }
      if(s[i]==']'){
          count_r++;
          imbalance = count_l-count_r;
      }
   }
   return swap;
}

int main(){
    
    string str = "[[[]][";
    cout<<MinSwap(str);
    return 0;
}