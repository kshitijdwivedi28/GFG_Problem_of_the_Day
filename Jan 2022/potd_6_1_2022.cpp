// Longest Common Prefix in an Array 
// Easy Accuracy: 49.76% Submissions: 26614 Points: 2
// Given a array of N strings, find the longest common prefix among all strings present in the array.


// Example 1:

// Input:
// N = 4
// arr[] = {geeksforgeeks, geeks, geek,
//          geezer}
// Output: gee
// Explanation: "gee" is the longest common
// prefix in all the given strings.
// Example 2:

// Input: 
// N = 2
// arr[] = {hello, world}
// Output: -1
// Explanation: There's no common prefix
// in the given strings.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function longestCommonPrefix() which takes the string array arr[] and its size N as inputs and returns the longest common prefix common in all the strings in the array. If there's no prefix common in all the strings, return "-1".


// Expected Time Complexity: O(N*max(|arri|)).
// Expected Auxiliary Space: O(max(|arri|)) for result.


// Constraints:
// 1 ≤ N ≤ 103
// 1 ≤ |arri| ≤ 103

// View Bookmarked Problems
// Company Tags
//  VMWare Microsoft Google
// Topic Tags
//  Strings Arrays
 
 // { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        // your code here
        int min_string_length = INT_MAX;
        
        for(int i = 0; i < N; i++ )
        {
            int curr_len = arr[i].size();
            min_string_length = min(min_string_length, curr_len);
        }
           
        if (min_string_length == 0)
            return "";
            
        bool flag = true;
        int counter = 0;
        string ans = "";
        
        
        while(counter < min_string_length)
        {
            for(int i = 1; i < N; i++)
                if (arr[i][counter] != arr[i-1][counter])
                    flag = false;
                    
            if (flag)
                ans += arr[0][counter];
                
            counter++;
        }
        
        if(ans == "")
            return "-1";
        else
            return ans;
        
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends
