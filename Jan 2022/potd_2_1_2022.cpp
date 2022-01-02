// Kth Smallest Factor 
// Medium Accuracy: 51.14% Submissions: 6574 Points: 4
// GIven two positive integers N and K. You have to find the Kth smallest factor of N. A factor of N is a positive integer which divides N. Output the Kth smallest factor of N if it exists otherwise print -1.


// Example 1:

// Input : N = 4 , K = 2
// Output: 2
// Explanation:
// All factors of 4 are 1,2 and 4. Out of
// these 2 is the 2nd smallest.
// Example 2:

// Input : N = 4 , K = 3
// Output: 4
// Explanation:
// All factors of 4 are 1,2 and 4. Out of
// these 4 is the 3rd smallest.
 

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function kThSmallestFactor() which takes 2 Integers N and K as input and returns the answer.

 

// Expected Time Complexity: O(sqrt(N))
// Expected Auxiliary Space: O(1)

 

// Constraints:
// 1 <= N <= 106
// 1 <= K <= 106


// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int kThSmallestFactor(int N , int K) {
        // code here
        // int count = 0;
        // for(int i = 1; i <= N; i++)
        // {
        //     if (N%i == 0)
        //         count++;
        //     if (K == count)
        //         return i;
        // }
        
        // return -1;
        
        // Trying in sqrt(N) time
        
        int count = 0;
        for(int i = 1; i <= sqrt(N); i++)
        {
            if (N%i == 0)
                count++;
            if (count == K)
                return i;
        }
        
        for(int i = floor(sqrt(N))+1; i <= N; i++)
        {
            if (N%i == 0)
                count++;
            if (count == K)
                return i;
        }
        
        return -1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        
        cin>>N>>K;

        Solution ob;
        cout << ob.kThSmallestFactor(N,K) << endl;
    }
    return 0;
}  // } Driver Code Ends