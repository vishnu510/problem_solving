#include<bits/stdc++.h>
using namespace std;
# define N 8
bool MATRIX[N][N] = {{0, 0, 1, 0},
                    {0, 0, 1, 0},
                    {0, 0, 0, 0},
                    {0, 0, 1, 0}};
bool knows(int a,int b){
    return MATRIX[a][b];
}                    

// this is brute force approach 
int findCelebs(int n){
    int indegree[n]={0},outdegree[n]={0};
     
    //query for all edges
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            int x = knows(i,j);
             
            //set the degrees
            outdegree[i]+=x;
            indegree[j]+=x;
        }
    }
     

    for(int i=0; i<n; i++)
    if(indegree[i] == n-1 && outdegree[i] == 0)
        return i;
     
    return -1;
}
// this approach will take O(n) time
int findPotentialCelebrity(int n)
{
    // base case - when n reaches 0 , returns -1
    // since n represents the number of people,
    // 0 people implies no celebrity(= -1)
    if (n == 0)
        return -1;
 
    // find the celebrity with n-1
    // persons
    int id = findPotentialCelebrity(n - 1);
 
    // if there are no celebrities
    if (id == -1)
        return n - 1;
 
    // if the id knows the nth person
    // then the id cannot be a celebrity, but nth person
    // could be one
    else if (knows(id, n - 1)) {
        return n - 1;
    }
    // if the nth person knows the id,
    // then the nth person cannot be a celebrity and the id
    // could be one
    else if (knows(n - 1, id)) {
        return id;
    }
 
    // if there is no celebrity
    return -1;
}
 
// Returns -1 if celebrity
// is not present. If present,
// returns id (value from 0 to n-1).
// a wrapper over findCelebrity
int Celebrity(int n)
{
    // find the celebrity
    int id = findPotentialCelebrity(n);
 
    // check if the celebrity found
    // is really the celebrity
    if (id == -1)
        return id;
    else {
        int c1 = 0, c2 = 0;
 
        // check the id is really the
        // celebrity
        for (int i = 0; i < n; i++)
            if (i != id) {
                c1 += knows(id, i);
                c2 += knows(i, id);
            }
 
        // if the person is known to
        // everyone.
        if (c1 == 0 && c2 == n - 1)
            return id;
 
        return -1;
    }
}
int main(){
           int n =4;
           int id = findCelebs(n); 
           id == -1?cout<<"There is no Celebrity":cout<<"Celebrity is "<<id;     
           cout<<endl;
           id = Celebrity(n);
           id == -1 ? cout << "No celebrity"
             : cout << "Celebrity ID " << id;
           cout<<endl;
           int celeb = 0;
           for(int i=0;i<n;i++){
               if(knows(celeb,i)==1){
                   celeb =i;
               }
           }  
           for(int i=0;i<n;i++){
               if(i!=celeb and knows(celeb,i)==1 and knows(i,celeb)!=1){
                   cout<<"-1";
               }
           }  
           cout<<"Celebrity ID is:"<<celeb;
    return 0;
}