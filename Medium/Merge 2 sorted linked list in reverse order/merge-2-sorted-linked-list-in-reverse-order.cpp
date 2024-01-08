//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}


Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}


// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
};

*/
class Solution
{
    public:
    
    Node* reverseNode(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node* restReversed = reverseNode(head->next);
    head->next->next = head;
    head->next = nullptr;

    return restReversed;
}
    
    struct Node * mergeResult(Node *node1,Node *node2)
    {
        if(!node1 && !node2) return nullptr;
        if(!node1) return reverseNode(node2);
        if(!node2) return reverseNode(node1);
        
       Node*curr, *ans;
       
       if(node1->data < node2->data){
           curr=node1;
           ans =node1;
           node1=node1->next;
       }else{
           curr=node2;
           ans =node2;
           node2=node2->next;
       }
       
       
       while(node1 && node2){
           if(node1->data < node2->data){
               curr->next=node1;
               curr=curr->next;
               node1=node1->next;
           }else{
               curr->next=node2;
               curr=curr->next;
               node2=node2->next;
           }
       }
       
       if(node1){
           curr->next=node1;
       }
       if(node2){
           curr->next=node2;
       }
       
       ans = reverseNode(ans);
       
       return ans;
    }  
};


//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;

        struct Node* headA=NULL;
        struct Node* tempA = headA;

        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);

            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }

        struct Node* headB=NULL;
        struct Node* tempB = headB;


        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);

            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }
        
        Solution ob;
        struct Node* result = ob.mergeResult(headA,headB);

        print(result);
        cout<<endl;


    }
}

// } Driver Code Ends