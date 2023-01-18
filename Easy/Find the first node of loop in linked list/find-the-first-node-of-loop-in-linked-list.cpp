//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}


// } Driver Code Ends
//User function Template for C++

/*struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/
class Solution
{
    public:
    //Optimal Approach Using Floydd Cycle Detection
    int findFirstNode(Node* head){
        Node *slow = head;
        Node *fast = head;
        
        //Floydd Cycle Detection
        bool isCycle = false;
        
        while(fast and slow){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast){
                isCycle = true;
                break;
            }
        }
        
        //if cycle present return -1
        if(!isCycle){
            return -1;
        }
        
        //Finding First Loop Node
        slow = head;
        while(slow!=fast){
            slow = slow->next;
            fast = fast->next;
        }
        
        //final answer
        return slow->data;
    }
    
    // Function to find first node if the linked list has a loop.
    // Approach 2 BruteForce Using Set
    // int findFirstNode(Node* head)
    // {
    //     set<Node*>s;
    //     Node* itr = head;
    //     s.insert(itr);
    //     while(itr->next!=NULL){
    //         if(s.find(itr->next)==s.end()){
    //             s.insert(itr->next);
    //         }
    //         else{
    //             return itr->next->data;
    //         }
    //         itr = itr->next;
    //     }
    //     return -1;
    // }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        Solution ob;
        int ans = ob.findFirstNode(head);
        cout<<ans<<"\n";
    }
	return 0;
}
// } Driver Code Ends