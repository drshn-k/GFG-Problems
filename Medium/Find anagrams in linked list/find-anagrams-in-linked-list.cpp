//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node *next;

    Node(char x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList() {
    int n; // length of link list
    scanf("%d ", &n);

    char data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i) {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends
/*

Definition for singly Link List Node
struct Node
{
    char data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
};

You can also use the following for printing the link list.
printList(Node* node);
*/
class Solution {

  public:

    Node* create_node(Node* start,Node* end)

    {

        end->next=NULL;

        return start;

    }

    vector<Node*> findAnagrams(struct Node* head, string s) {

        Node* temp=head;

        vector<Node*> res;

        map<char,int> mp;

        int i=0,n=s.length();

        while(i<n)

        {

            mp[s[i]]++;

            i++;

        }

        map<char,int> mp1;

        Node* end=head;

        int cnt=0;

        while(temp!=NULL)

        {

            mp1[temp->data]++;

            cnt++;

            if(cnt==n)

            {

               // cout<<temp->data<<endl;

                //for(auto it:mp1) cout<<it.first<<" "<<it.second;

                //cout<<endl;

                if(mp1==mp) 

                {

                    Node* dummy=temp->next;

                    res.push_back(create_node(end,temp));

                    temp=dummy;

                    mp1.clear();

                    cnt=0;

                    end=dummy;

                }

                else

                {

                    mp1[end->data]--;

                    if(mp1[end->data]==0) mp1.erase(end->data);

                    cnt--;

                    end=end->next;

                }

            }

            if(cnt!=0) temp=temp->next;

        }

        return res;

    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        struct Node *head = inputList();

        string s;
        cin >> s;

        Solution obj;
        vector<Node *> res = obj.findAnagrams(head, s);

        for (int i = 0; i < res.size(); i++) {
            printList(res[i]);
        }

        if (res.size() == 0) cout << "-1\n";
    }
}

// } Driver Code Ends