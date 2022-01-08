// N Digit numbers with digits in increasing order 
// Medium Accuracy: 78.69% Submissions: 2064 Points: 4
// Given an integer N, print all the N digit numbers in increasing order, such that their digits are in strictly increasing order(from left to right).

// Example 1:

// Input:
// N = 1
// Output:
// 0 1 2 3 4 5 6 7 8 9
// Explanation:
// Single digit numbers are considered to be 
// strictly increasing order.
// Example 2:

// Input:
// N = 2
// Output:
// 12 13 14 15 16 17 18 19 23....79 89
// Explanation:
// For N = 2, the correct sequence is
// 12 13 14 15 16 17 18 19 23 and so on 
// up to 89.
// Your Task:  
// You don't need to read input or print anything. Your task is to complete the function increasingNumbers() which takes an integer N as an input parameter and return the list of numbers such that their digits are in strictly increasing order.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 <= N <= 9

// View Bookmarked Problems
// Company Tags
//  ABCO
// Topic Tags
//  Recursion
 
 
 // { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++
class Solution
{

public:

    void solver(int n, int delimiter, vector<int>& ans)
    {
        if (n == 0)
        {
           // cout << delimiter << endl;
            ans.push_back(delimiter);
            return;
        }
    
        int digit = delimiter%10;
        
        for(int i = digit+1; i <= 9; i++)
            solver(n-1, delimiter*10 + i , ans);
        
    }
    
    vector<int> increasingNumbers(int N)
    {
        // Write Your Code here
        vector<int> ans;
            
        if (N == 1)
            ans.push_back(0);
            
        solver(N, 0, ans);
        
        return ans;
    }
    
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        vector<int> ans = ob.increasingNumbers(N);
        for(auto num : ans){
            cout<< num <<" ";
        }
        cout<<endl;
        
    }
    return 0;
}  // } Driver Code Ends
