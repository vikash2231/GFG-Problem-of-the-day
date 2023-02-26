/*A special compression mechanism can arbitrarily delete 0 or more characters and replace them with the deleted character count.
Given two strings, S and T where S is a normal string and T is a compressed string, determine if the compressed string  T is valid for the plaintext string S. 


Example 1:

Input:
S = "GEEKSFORGEEKS"
T = "G7G3S"
Output:
1
Explanation:
We can clearly see that T is a valid 
compressed string for S.

Example 2:

Input:
S = "DFS"
T = "D1D"
Output :
0
Explanation:
T is not a valid compressed string.

Your Task:  
You don't need to read input or print anything. Your task is to complete the function checkCompressed() which takes 2 strings S and T as input parameters and returns integer 1 if T is a valid compression of S and 0 otherwise.


Expected Time Complexity: O(|T|)
Expected Auxiliary Space: O(1)


Constraints:
1 ≤ |S| ≤ 106
1 ≤ |T| ≤ 106
All characters are either capital or numeric.*/









//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends
//User function Template for C++
#include<vector>
class Solution {
  public:
    int checkCompressed(string S, string T) {
        // code here
        vector<char>ch;
        int pc=0,a=0,f=0;
        for(int i=0;i<T.size();i++){
            if(isalpha(T[i])){
                 if(f==1){
                    while(a){
                        ch.push_back('%');
                        pc++;
                        a--;
                    }
                    f=0;
                    a=0;
                }
                ch.push_back(T[i]);
               
            }else if(isdigit(T[i])){
                 a=a*10+(T[i]-'0');
                 f=1;
            }
        }
        if(f==1){
            while(a){
                ch.push_back('%');
                pc++;
                a--;
            }
        }
        if(ch.size()!=S.size())
            return 0;
        for(int i=0;i<ch.size();i++){
            if(isalpha(ch[i])){
                if(ch[i]!=S[i])
                    return 0;
            }
        }
        return 1;
    }
};
//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        cin>>S>>T;
        Solution ob;
        cout << ob.checkCompressed(S,T) << endl;
    }
    return 0;
}
// } Driver Code Ends
