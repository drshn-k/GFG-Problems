//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};



// } Driver Code Ends
/* Following is the Linked list node structure */

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
class Solution{ 
public:
    void reorderList(Node* head) {
        int l=0;
        Node* temp=head;
        while(temp!=NULL){
            l++;
            temp=temp->next;
        }
        int times=(l+1)/2;
        times--;
        temp=head;
        while(times--){
            temp=temp->next;
        }
        Node* head1=temp->next;
        temp->next=NULL;
        int l1=l/2;
        temp=head1;
        Node* temp1=temp;
        Node* ch=NULL;
        while(temp!=NULL){
            if(temp->next==NULL){head1=temp;}
            temp1=temp->next;
            temp->next=ch;
            ch=temp;
            temp=temp1;
        }
        temp=head;
        temp1=head1;
        ch=head1;
        Node* ch1=head;
         l1=l/2;
        while(temp1!=NULL){
            ch=temp1->next;
            ch1=temp->next;
            temp1->next=temp->next;
            temp->next=temp1;
            temp=ch1;
            temp1=ch;
        }
    }
};

//{ Driver Code Starts.



/* Function to create a new Node with given data */
struct Node* newNode(int data) {
    struct Node* new_Node = new Node(data);
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}

void printList(struct Node* Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {

        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {
    int t, n, m, i, x;

    cin >> t;
    while (t--) {
        struct Node* temp, *head;
        cin >> n;
        cin >> x;
        head = new Node(x);
        temp = head;
        for (i = 0; i < n - 1; i++) {
            cin >> x;
            temp->next = new Node(x);
            temp = temp->next;
        }
        
        Solution ob;
        
        ob.reorderList(head);
        printList(head);
        freeList(head);
    }
    return 0;
}

// } Driver Code Ends