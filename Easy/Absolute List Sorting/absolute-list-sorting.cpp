//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Linked List Node
struct Node
{
	Node* next;
	int data;
};

// Utility function to insert a node at the
// beginning
void push(Node** head, int data)
{
	Node* newNode = new Node;
	newNode->next = (*head);
	newNode->data = data;
	(*head) = newNode;
}

// Utility function to print a linked list
void printList(Node* head)
{
	while (head != NULL)
	{
		cout << head->data;
		if (head->next != NULL)
			cout << " ";
		head = head->next;
	}
	cout << endl;
}


// } Driver Code Ends
/* The structure of the Linked list Node is as follows:
struct Node
{
    Node* next;
    int data;
}; */

/*Your method shouldn't print anything
 it should transform the passed linked list */
class Solution{
    
public:
   Node* sortList(Node* head)
    {
        // Dummy head for positive numbers list
        Node* posHead=new Node;
        Node* posTemp=posHead;
        posTemp->next=NULL;
        
        // Dummy head for negative numbers list
        Node* negHead=new Node;
        Node* negTemp=negHead;
        negTemp->next=NULL;
        
        Node* temp=head;
        while(temp){
            if(temp->data>=0){
                posTemp->next=temp; 
                temp=temp->next;
                posTemp=posTemp->next;
                posTemp->next=NULL;
            }else{
                negTemp->next=temp; 
                temp=temp->next;
                negTemp=negTemp->next;
                negTemp->next=NULL;
            }
            
        }
        
        //reverse the negative list and attche its end to the positive list
        Node* prev=posHead->next;
        Node* curr=negHead->next;
        while(curr){
            Node* nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
};


//{ Driver Code Starts.

// Driver code
int main()
{

	int t = 0;
	int n = 0;
	cin >> t;
	while (t--)
	{
		Node* head = NULL;
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			// push(&head, a);
		}
		for (int i = n - 1; i >= 0; i--)
		{
			push(&head, arr[i]);
		}
		// printList(head);
		
		Solution ob;
		head=ob.sortList(head);

		printList(head);

	}
	return 0;
}

// } Driver Code Ends