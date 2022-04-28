// leetcode Astroid collide problem
#include<bits/stdc++.h>
using namespace std;
vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> s;
        for(int i = 0; i < n; i++) {
            if(asteroids[i] > 0 || s.empty()) {
                s.push(asteroids[i]);
            }
            else {
                while(!s.empty() and s.top() > 0 and s.top() < abs(asteroids[i])) {
                    s.pop();
                }
                if(!s.empty() and s.top() == abs(asteroids[i])) {
                    s.pop();
                }
                else {
                    if(s.empty() || s.top() < 0) {
                        s.push(asteroids[i]);
                    }
                }
            }
        } 
        vector<int> res(s.size());
        for(int i = (int)s.size() - 1; i >= 0; i--) {
            res[i] = s.top();
            s.pop();
        }
        return res; 
    }
// Approach 2
    vector<int> asteroidCollision_1(vector<int>& asteroids) {
        
    }
int main(){
   vector<int> asteroids{5,10,-5};
   vector<int> ans = asteroidCollision(asteroids);
   for(auto c:ans){
       cout<<c<<" ";
   }
   vector<int> answer = asteroidCollision_1(asteroids);
   for(auto c:answer){
       cout<<c<<" ";
   }
    return 0;
}