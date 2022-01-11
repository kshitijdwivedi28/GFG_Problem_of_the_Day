// Clone a stack without usinig extra space 
// Medium Accuracy: 87.88% Submissions: 3637 Points: 4
// Given elements of a stack, clone the stack without using extra space.


// Example 1:

// Input:
// N = 10
// st[] = {1, 1, 2, 2, 3, 4, 5, 5, 6, 7}
// Output:
// 1 

// Your Task:  
// You don't need to read input or print anything. Your task is to complete the function clonestack() which takes the input stack st[], an empty stack cloned[], you have to clone the stack st into stack cloned.
// The driver code itself prints 1 in the output if the stack st is cloned properly and prints 0 otherwise.


// Expected Time Complexity: O(N*N)
// Expected Auxiliary Space: O(1)
 

// Constraints:
// 1 <= N <= 1000
// 1<= st[i] <= 105

// View Bookmarked Problems
// Company Tags
//  Flipkart
// Topic Tags
//  Stack

// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    
    // void insert_at_bottom(stack<int>& st, int value)
    // {
    //     if (st.empty())
    //     {
    //         st.push(value);
    //         return;
    //     }
            
    //     else
    //     {
    //         int x = st.top();
    //         st.pop();
            
    //         insert_at_bottom(st, value);
            
    //         st.push(x);
            
            
    //     }
    // }
    // void recursion(stack<int>& st)
    // {
    //     if(st.size() == 0)
    //         return;
    //     else
    //     {
    //         int value = st.top();
    //         st.pop();
            
    //         recursion(st);
            
    //         insert_at_bottom(st,value);
    //     }
    // }
    
    void clonestack(stack<int> st, stack<int>& cloned)
    {
        //code here
        // Approach
        // Reverse the input stack
        // Push the reversed input stack to cloned stack
        
        // recursion(st);
        
        // while(!st.empty())
        // {
        //     int value = st.top();
        //     st.pop();
        //     cloned.push(value);
        // }
        
        
        // Optimised 
        // doesn't need other helper functions 
        // self recursion on given function
        
        if (st.empty())
            return;
            
        int value = st.top();
        st.pop();
        
        clonestack(st, cloned);
        
        cloned.push(value);
        
        
        
    //     PS : Just one liner 
    //     cloned = st;
    // }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int arr[N];
        stack<int> st;
        vector<int> copy;
        for(int i = 0; i < N; i++){
            cin >> arr[i];
            st.push(arr[i]);
            copy.push_back(arr[i]);
        }
        
        reverse(copy.begin(), copy.end());
        
        Solution ob;
        stack<int> cloned;
        ob.clonestack(st,cloned);
        vector<int> check;
        while(cloned.size())
        {
            check.push_back(cloned.top());
            cloned.pop();
        }
        
        int flag = 0;
        if(check!=copy)
            flag = 1;
        
        cout<<1-flag<<endl;
    }
    return 0; 
} 
  // } Driver Code Ends
