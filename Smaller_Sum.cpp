/*
You are given an array arr of n integers. For each index i, you have to find the sum of all integers present in the array with a value less than arr[i].

Example 1:

Input:
n = 3
arr = {1, 2, 3}
Output:
0 1 3
Explanation:
For 1, there are no elements lesser than itself.
For 2, only 1 is lesser than 2.
And for 3, 1 and 2 are lesser than 3, so the sum is 3.
Example 2:

Input:
n = 2
arr = {4, 4}
Output:
0 0
Explanation:
For 4, there are no elements lesser than itself. 
For 4, there are no elements lesser than itself.
There are no smaller elements than 4.
Your Task:
You don't need to read input or print anything. Your task is to complete the function smallerSum() which takes an integer n and an array arr and returns an array of length n , the answer for every index.

Expected Time Complexity:O(n log n)
Expected Space Complexity:O(n)

Constraints:
1 <= n <= 105
0 <= arr[i] <= 109
*/

class Solution{
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
        // Code here
        long long sum=0;
        vector<long long>arr1(n);
        unordered_map<long long,long long>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]=0;
            sum+=arr[i];
        }
      
        for(int i=0;i<n;arr1[i]=arr[i++]); //inserting elements of arr to arr1
      
        sort(arr1.begin(),arr1.end()); // sorting the elements of arr1
      
        for(int i=n-1;i>=0;i--){
            sum-=arr1[i]; // Subracting each element from last
            mp[arr1[i]]=sum; // inserting the sum in unordered map
        }
      
        for(int i=0;i<n;arr1[i]=mp[arr[i++]]); // inserting the values of unordered map to arr1
      
        return arr1;
    }
};
