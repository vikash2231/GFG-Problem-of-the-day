/*
Given a string str, find the minimum characters to be added at front of the string to make it a palindrome.


Example 1:

Input:
str = ABCD
Output: 3
Explanation: The resultant string 
after adding 3 characters is DCBABCD.
The minimum possible answer is 3.
Example 2:

Input:
str = ABA
Output: 0
Explanation: The given string
is already a palindrome.

Your Task:  
You don't need to read input or print anything. Your task is to complete the function addMinChar() which takes the string str as input parameters and returns the minimum number of characters to be added to make it a palindrome.


Expected Time Complexity: O(|str|)
Expected Auxiliary Space: O(|str|)

*/


class Solution{   
public:
    int addMinChar(string str){    
        //code here
        int n=str.size(),ans=0;
        int i=0,j=n-1;
        while(i<=j){
            if(str[i]==str[j]){
                i++;j--;
            }else{
                ans++;
                i=0;j=n-1-ans;
            }
        }
        return ans;
        
    }
};
