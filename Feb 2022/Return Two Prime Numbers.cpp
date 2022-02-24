// Return two prime numbers 
// Hard Accuracy: 78.46% Submissions: 4547 Points: 8
// Given an even number N (greater than 2), return two prime numbers whose sum will be equal to given number. There are several combinations possible. Print only the pair whose minimum value is the smallest among all the minimum values of pairs and print the minimum element first.

// NOTE: A solution will always exist, read Goldbachs conjecture. 

// Example 1:

// Input: N = 74
// Output: 3 71
// Explaination: There are several possibilities 
// like 37 37. But the minimum value of this pair 
// is 3 which is smallest among all possible 
// minimum values of all the pairs.
// Example 2:

// Input: 4
// Output: 2 2
// Explaination: This is the only possible 
// prtitioning of 4.
// Your Task:
// You do not need to read input or print anything. Your task is to complete the function primeDivision() which takes N as input parameter and returns the partition satisfying the condition.

// Expected Time Complexity: O(N*log(logN))
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 ≤ N ≤ 104  

// View Bookmarked Problems
// Company Tags
//  Yahoo Zoho
// Topic Tags
//  Mathematical
// Related Interview Experiences
//  Zoho interview experience set 21 campus
// We are replacing the old Disqus forum with the new Discussions section given below.
// Click here to view old Disqus comments.




// -------------------------------------------------------------------------------------------------------------------------------------------------------------

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> primeDivision(int N){
        // code here
        vector<int> prime_seive(N+1, 0);

        for(int i = 2; i <= N; i++)
        {
            if(prime_seive[i] == 0)
            {
                for(int j = 2*i; j < N+1; j += i)
                    prime_seive[j] = 1;
            }
        }

        vector<int> prime;
        for(int i = 2; i < N+1; i++)
            if(prime_seive[i] == 0)
                prime.push_back(i);


        
        unordered_map<int, int> m;
        for(auto value : prime)
            m[value]++;
            
        vector<pair<int, int>> vp;
        
        for(auto value : prime)
            if (m[N-value])
                vp.push_back({value, (N-value)});

        
        sort(vp.begin(), vp.end());
        
        return {vp[0].first, vp[0].second};

    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.primeDivision(N);
        cout<<ans[0]<<" "<<ans[1]<<"\n";
    }
    return 0;
}  // } Driver Code Ends


// -----------------------------------------------------------------------------------------------------------------------------------------------------------------











// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> primeDivision(int N){
        // code here
        vector<int> prime_seive(N+1, 0);

        for(int i = 2; i <= N; i++)
            if(prime_seive[i] == 0)
                for(int j = 2*i; j < N+1; j += i)
                    prime_seive[j] = 1;

        for(int i = 2; i < N+1; i++)
            if (prime_seive[i] == 0 && prime_seive[N-i] == 0)
                return {i, (N-i)};
        
        return {};
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.primeDivision(N);
        cout<<ans[0]<<" "<<ans[1]<<"\n";
    }
    return 0;
}  // } Driver Code Ends
