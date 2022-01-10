// Add 1 to a number represented as linked list 
// Easy Accuracy: 51.33% Submissions: 82324 Points: 2
// A number N is represented in Linked List such that each digit corresponds to a node in linked list. You need to add 1 to it.

// Example 1:

// Input:
// LinkedList: 4->5->6
// Output: 457 
// Example 2:

// Input:
// LinkedList: 1->2->3
// Output: 124 
// Your Task:
// Your task is to complete the function addOne() which takes the head of the linked list as the only argument and returns the head of the modified linked list. The driver code prints the number.
// Note: The head represents the left-most digit of the number.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 <= N <= 101000

// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
    
    // Node* curr = head;
    // Node* temp = head;
    // while(curr -> next) 
    // {
    //     if(curr->data < 9 && curr->next->data == 9)
    //         temp = curr;
            
    //     curr = curr->next;
    // }
    
    // if(curr->data == 9) 
    // {
    //     if(temp -> data == 9) 
    //     {
    //         temp = new Node(0);
    //         temp -> next = head;
    //         head = temp;
    //     }
        
    //     temp -> data = temp -> data + 1;
    //     temp = temp -> next;
        
    //     while(temp) 
    //     {
    //         temp -> data = 0;
    //         temp = temp -> next;
    //     }
    // } 
    // else 
    //     curr->data = curr->data + 1;


    // return head;
    
           
    //   1->9->1->9->9->9;
        Node* temp = head;
        auto sitting = head;
        while(temp)
        {
          if(temp->data < 9) sitting = temp;
          temp = temp->next;
        }
       
        if(sitting == head && sitting->data==9)
        {
          Node* newnode = new Node(1);
          newnode->next = head;
          head->data = 0;
          head = newnode;
        }
        else 
            sitting->data = sitting->data + 1;
       
        while(sitting->next)
        {
            sitting->next->data = 0;
            sitting = sitting->next;
        }
        
        return head;
    
    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 
  // } Driver Code Ends
