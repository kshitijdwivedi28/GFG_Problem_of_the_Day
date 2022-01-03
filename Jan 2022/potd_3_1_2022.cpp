// Rotate by 90 degree 
// Medium Accuracy: 53.41% Submissions: 19304 Points: 4
// Given a square matrix[][] of size N x N. The task is to rotate it by 90 degrees in an anti-clockwise direction without using any extra space.

// Example 1:

// Input:
// N = 3
// matrix[][] = [[1 2 3],
//               [4 5 6],
//               [7 8 9]]
// Output:
// 3 6 9 
// 2 5 8 
// 1 4 7
// Your Task:
// You only need to implement the given function rotate(). Do not read input, instead use the arguments given in the function. 

// Expected Time Complexity: O(N*N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ N ≤ 50
// 1 <= matrix[][] <= 100

 

// View Bookmarked Problems
// Company Tags
//  Amazon D-E-Shaw Microsoft Morgan Stanley Paytm Samsung Snapdeal Zoho
// Topic Tags
//  Matrix

// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
void rotate (vector<vector<int> >& matrix);


 // } Driver Code Ends
//User function template for C++

/* matrix : given input matrix, you are require 
 to change it in place without using extra space */
void rotate(vector<vector<int> >& matrix)
{
    // Your code goes here

    for(int i = 0; i < matrix.size(); i++)
        for(int j = i+1; j < matrix[0].size(); j++)
            swap(matrix[i][j], matrix[j][i]);
            
    // for(int i = 0; i < matrix.size(); i++)
    //     for(int j = 0; j < matrix[0].size(); j++)
    //         cout << matrix[i][j] << " ";
            
    // cout << endl;
            
            
    reverse(matrix.begin(), matrix.end());
            
    // for(int i = 0; i < matrix.size(); i++)
    //     for(int j = 0; j < matrix[0].size(); j++)
    //         cout << matrix[i][j] << " ";
            
    // cout << endl;
    
            

    
    
}


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t; 
    while(t--)
    {
        int n;
        cin>>n; 
        vector<vector<int> > matrix(n);
        for(int i=0; i<n; i++)
        {
            matrix[i].resize(n);
            for(int j=0; j<n; j++)
                cin>>matrix[i][j]; 
        }
        rotate(matrix);
        for (int i = 0; i < n; ++i)
        {
            for(int j=0; j<n; j++)
                cout<<matrix[i][j]<<" ";
            cout<<"\n";
        }
    }
    return 0;
}

  // } Driver Code Ends