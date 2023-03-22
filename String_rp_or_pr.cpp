/*Given a string S. In one operation, you can remove the substring "pr" from the string S and get amount X or you can remove the substring "rp" and get the amount Y. 
Find the maximum amount you can get if you perform zero or more such operations optimally. 

Note : 

Substring of a string S is defined as a continuous sequence of characters in S.
After removing pr or rp, the order of remaining letters should remain the same.

Example 1:

Input:
X = 5, Y = 4
S = "abppprrr"
Output: 15
Explanation: 
Here, S = "abppprrr" 
X= 5, Y=4.
Remove "pr", new string S = "abpprr".
Remove "pr", new string S = "abpr".
Remove "pr", new string S = "ab".
In total, we removed "pr" 3 times, 
so total score is 3*X + 0*Y = 3*5 =15.
 

 

Example 2:

Input:
X = 7, Y = 7
S = "prpptppr"
Output: 14
Explanation: 
Here, S = "prpptppr" 
X= 7, Y=7.
As both have the same amount we can first 
remove either pr or rp. Here we start with pr
Remove "pr", new string S = "pptppr".
Remove "pr", new string S = "pptp".
In total, we removed "pr" 2 times, 
so total score is 2*X + 0*Y = 2*7 =14.

Your Task: 
You don't need to read input or print anything. Your task is to complete the function solve() which takes the X ,Y and string S as input parameters and returns the maximum amount you can get after performing the above operations.


Expected Time Complexity: O(|S|)
Expected Auxiliary Space: O(|S|)


Constraints:
1 ≤ |S| ≤ 105
1 ≤ X,Y ≤ 105
S contains lowercase English letters only.*/

//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    long long solve(int X,int Y,string S){
      //code here
      long long int x=0,y=0;
      string s1="pr",s2="rp";
      if(X<Y){
          swap(X,Y);
          swap(s1,s2);
      }
      stack<char>arr;
      for(int i=S.size()-1;i>=0;i--){
          if(arr.size()!=0 && S[i]==s1[0] && arr.top()==s1[1]){
            arr.pop();
            x++;  
          }
          else
            arr.push(S[i]);
      }
      S="";
      while(arr.size()){
          S.push_back(arr.top());
          arr.pop();
      }
      for(int i=S.size()-1;i>=0;i--){
          if(arr.size()!=0 && S[i]==s2[0] && arr.top()==s2[1]){
              arr.pop();
              y++;
          }
          else
            arr.push(S[i]);
      }
        return x*X+y*Y;
    }
};

//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int X,Y;
      cin>>X>>Y;
      string S;
      cin>>S;
      Solution obj;
      long long answer=obj.solve(X,Y,S);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends
