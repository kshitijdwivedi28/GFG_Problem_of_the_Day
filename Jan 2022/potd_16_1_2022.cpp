// Steps by Knight 
// Medium Accuracy: 50.11% Submissions: 36902 Points: 4
// Given a square chessboard, the initial position of Knight and position of a target. Find out the minimum steps a Knight will take to reach the target position.

// Note:
// The initial and the target position co-ordinates of Knight have been given accoring to 1-base indexing.

 

// Example 1:

// Input:
// N=6
// knightPos[ ] = {4, 5}
// targetPos[ ] = {1, 1}
// Output:
// 3
// Explanation:

// Knight takes 3 step to reach from 
// (4, 5) to (1, 1):
// (4, 5) -> (5, 3) -> (3, 2) -> (1, 1).
 

 

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function minStepToReachTarget() which takes the inital position of Knight (KnightPos), the target position of Knight (TargetPos) and the size of the chess board (N) as an input parameters and returns the minimum number of steps required by the knight to reach from its current position to the given target position.

 

// Expected Time Complexity: O(N2).
// Expected Auxiliary Space: O(N2).

 

// Constraints:
// 1 <= N <= 1000
// 1 <= Knight_pos(X, Y), Targer_pos(X, Y) <= N

// View Bookmarked Problems
// Company Tags
//  Amazon Goldman Sachs Intuit Linkedin MakeMyTrip OYO Rooms Microsoft Flipkart
// Topic Tags
//  BFS Graph Queue

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    
	    // Calculating 8 possible movements of knight
	    int pos[8][2] = {
	                        {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, 
	                        {2, -1}, {2, 1}, {-1, -2}, {1, -2}
                        };
        
        // Array to mark positions visited or not
        bool vis[N+1][N+1];
        
        // Initializing values to 0
        memset(vis, 0, sizeof(vis));
        
        // Current position of knight marked 1
        vis[KnightPos[0]][KnightPos[1]] = 1;
        
        // Queue to hold movement (all positions) of knight
        queue<pair<int, int>> q;
        
        // Inserting current position in queue
        q.push({KnightPos[0], KnightPos[1]});
        
        // Final Ans steps, initially set to zero
        int steps = 0;
        
        // While movment of knight is possible in the board 
        // similar to search in a graph
        while(!q.empty()) 
        {
           // Total moments till now 
           int sz = q.size();
           
           // Initally for the base coordinates movement 
           // and further forming the path
            while(sz--) 
            {
                // Taking current position of knight in a pair
                pair<int, int> p = q.front();
                q.pop();
                
                // initialising x and y coordinates
                int x = p.first, y = p.second;
                
                // Case when we have reached the target location 
                if(x == TargetPos[0] && y == TargetPos[1])
                    return steps;
                    
                // Exploring all other possible positions of knight
                for(int k=0; k<8; k++) 
                {
                    // New coordinates a, b after adding movement from pos array
                    int a = x + pos[k][0], b = y + pos[k][1];
                    
                    // Checking if final position is in the range of board and node visited or not
                    if(a>0 && a<=N && b>0 && b<=N && !vis[a][b]) 
                    {
                        // If coordinate possible add it into queue
                        q.push({a, b});
                        // Mark visited coordinate
                        vis[a][b] = 1;
                    }
                }
            }
            
            // Adding step upon successful movement
            steps++;
        }
        
        // if no input 
        return -1;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
