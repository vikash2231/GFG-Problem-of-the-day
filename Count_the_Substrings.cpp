/*Given a string S. The task is to count the number of substrings which contains equal number of lowercase and uppercase letters. 

Example 1:

Input:
S = "gEEk"
Output: 3
Explanation: There are 3 substrings of
the given string which satisfy the
condition. They are "gE", "gEEk" and "Ek".
Example 2:

Input:
S = "WomensDAY"
Output: 4
Explanation: There are 4 substrings of 
the given string which satisfy the
condition. They are "Wo", "ensDAY", 
"nsDA" and "sD"
Your Task:
The task is to complete the function countSubstring() which takes the string S as input parameter and returns the number of substrings which contains equal number of uppercase and lowercase letters.

Expected Time Complexity: O(N*N)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ |S| ≤ 103
*/


//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countSubstring(string S)
    {
        // code here
        int count=0;
        for(int i=0;i<S.size()-1;i++){
            int sc=0,cc=0,f=0;
            if(islower(S[i]))
                sc++;
            else if(isupper(S[i]))
                cc++;
            for(int j=i+1;j<S.size();j++){
                if(isupper(S[j]))
                        cc++;
                else if(islower(S[j]))
                    sc++;
                if(sc==cc){
                    count++;
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
        cout<<obj.countSubstring(S)<<endl;
    }
}  
// } Driver Code Ends
