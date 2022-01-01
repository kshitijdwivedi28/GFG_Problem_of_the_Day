// Integer to Words 
// Medium Accuracy: 30.64% Submissions: 3062 Points: 4
// Write a function to convert a given number into words.

// Example 1:

// Input:
// N = 438237764
// Output: forty three crore eighty two lakh 
// thirty seven thousand seven hundred and 
// sixty four
 

// Example 2:

// Input:
// N = 1000
// Output: one thousand

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function convertToWords() which takes the integer n as input parameters and returns a string containing n in words.


// Expected Time Complexity: O(1)
// Expected Auxiliary Space: O(1)


// Constraints:
// 1 ≤ N ≤ 109 - 1

 

// View Bookmarked Problems
// Company Tags
//  Amazon Microsoft Oracle Zoho
// Topic Tags
//  Arrays

// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:

    string nums_to_string(long n, string s)
    {
        vector<string> ones {"", "one ", "two ", "three ", "four ", "five ", "six ",
        "seven ", "eight ", "nine ", "ten ", "eleven ", "twelve ", "thirteen ", "fourteen ",
        "fifteen ", "sixteen ", "seventeen ", "eighteen ", "nineteen " };
        
        vector<string> tens {"", "", "twenty ", "thirty ", "forty ", "fifty ", "sixty ",
        "seventy ", "eighty ", "ninety "};
        
        string res = "";
        
        if (n > 19)
            res += tens[n/10] + ones[n%10];
        else
            res += ones[n];
            
        if(n)
            res += s;
            
        return res;
    }
    
    string convertToWords(long n) {
        // code here
        // APPROACH : max range till crore
        // make string vectors to store values
        
        string ans = "";
        
        // helper function numtostring
        ans += nums_to_string((n/10000000), "crore ");
        ans += nums_to_string((n/100000)%100, "lakh ");
        ans += nums_to_string((n/1000)%100, "thousand ");
        ans += nums_to_string((n/100)%10, "hundred ");
        
        // If value greater than hundred and has remainder values 
        if (n > 100 && n%100)  
            ans += "and ";
            
        ans += nums_to_string((n%100), "");
        
        return ans;
    }
    
    
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long n;
        cin >> n;
        Solution ob;
        auto ans = ob.convertToWords(n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
