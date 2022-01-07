1's Complement 
Basic Accuracy: 82.65% Submissions: 3805 Points: 1
Given an N bit binary number, find the 1's complement of the number. The ones' complement of a binary number is defined as the value obtained by inverting all the bits in the binary representation of the number (swapping 0s for 1s and vice versa).
 

Example 1:

Input:
N = 3
S = 101
Output:
010
Explanation:
We get the output by converting 1's in S
to 0 and 0s to 1
Example 2:

Input:
N = 2
S = 10
Output:
01
Explanation:
We get the output by converting 1's in S
to 0 and 0s to 1

Your Task:  
You don't need to read input or print anything. Your task is to complete the function onesComplement() which takes the binary string S, its size N as input parameters and returns 1's complement of S of size N.
 

Expected Time Complexity: O(N)
Expected Space Complexity: O(N)
 

Constraints:
1<=N<=100

View Bookmarked Problems
Topic Tags
 Bit Magic
 
// { Driver Code Starts
 
#include<bits/stdc++.h>
using namespace std; 

 // } Driver Code Ends
  
class Solution{ 
public:
    string onesComplement(string S,int N){
        //code here
        string ans = "";
        for(auto value : S)
        {
            if (value == '0')
                ans += '1';
            else
                ans += '0';
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.onesComplement(s,n)<<"\n";
    }
}  // } Driver Code Ends
