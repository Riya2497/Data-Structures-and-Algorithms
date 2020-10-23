#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) 
{
    int i, flag;
    
    //Taking care of arrays with all negative numbers
    for(i=0; i<nums.size(); i++)
    {
        if(nums[i]>0)
        {
            flag = 0;
            break;
        }
        else
        flag = 1;
     }   
    
    //If array has all negative numbers, print the maximum
    if(flag==1)
    {
       int max = INT_MIN;
       for(i=0; i<nums.size(); i++)
       {
        if(nums[i]>max)
        max = nums[i];
       }
    
       return max;
    }
     
    //Taking care of arrays with both negative and positive numbers, with Kadane's algo. 
    int j = INT_MIN, k = 0; 
  
    for (i = 0; i < nums.size(); i++) 
    { 
        k = k + nums[i]; 
        if (j < k) 
            j = k; 
  
        if (k < 0) 
           k = 0;
    }    
    return j; 
}


int main() 
{
	int n;
	vector<int> nums;
	cin>>n;
	int arr[n];
	for(int i=0; i<n;i++)
	{
	    cin>>arr[i];
	    nums.push_back(arr[i]);
	}
	
	int max_sum=maxSubArray(nums);
	cout<<max_sum<< endl;
	
	return 0;
}
