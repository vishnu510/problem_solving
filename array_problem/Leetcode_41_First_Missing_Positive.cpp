#include<bits/stdc++.h>
using namespace std;


int FirstMissing(int nums[],int n){
    int size = n;
		vector<int> sequence(size, -1); 
		for (int i = 0; i < size; i++) {
			if (nums[i] > 0 && nums[i] <= size)
				sequence[nums[i] - 1] = 1; 
		}

		for (int i = 0; i < size; i++) { 
			if (sequence[i] == -1)
				return i + 1;
		}

		return size + 1;
}

int main(){
   
     // this approach will take O(nlogn) time 
    int nums[] = {1,2,3,1,3,6,6};
    int n = sizeof(nums)/sizeof(int);
cout<<FirstMissing(nums,n);

    return 0;
}