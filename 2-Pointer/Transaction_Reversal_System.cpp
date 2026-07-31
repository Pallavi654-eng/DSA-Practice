/*      Linked List
You are interviewing at a fintech firm that maintains financial audit logs using a singly-linked list. Each node in the linked list represents 
a ledger transaction with an integer value.Due to a compliance update, the system needs to re-order every transaction block. Specifically, given 
a linked list representing transactions L_0 -> L_1 -> .... -> L_{n-1} -> L_n, you must reorder it in-place 
to follow this specific interleaved pattern:
        L0 → L_n → L_1 → L_{n-1} → L_2 → L_{n-2} → …
You cannot alter the values inside the nodes—only the pointers themselves may be changed. You must solve this in O(N) time and O(1) extra space.

Example:
Input:  1 -> 2 -> 3 -> 4 -> 5
Output: 1 -> 5 -> 2 -> 4 -> 3

Explanation:
- L0 = 1, L1 = 2, L2 = 3, L3 = 4, L4 = 5
- Interleaved sequence: L0 -> L4 -> L1 -> L3 -> L2
- Resulting list: 1 -> 5 -> 2 -> 4 -> 3

Expected Time Complexity: O(N)
Expected Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=NULL;
    }
};
void orderList(Node* head){
    //Edge case
    if(head==NULL || head->next==NULL){
        return;
    }
    Node* slow=head;
    Node* fast=head;
    //finding mid of LL
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    //reverse second half of LL
    Node* curr=slow->next;
    slow->next=NULL;    //break list

    Node* prev=NULL;
    while(curr!=NULL){
        Node* nextNode=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextNode;
    }
    //merge two halves
    Node* second = prev;
    Node* first = head;
    while(second!=NULL){
        Node* temp1=first->next;
        Node* temp2=second->next;
        first->next=second;
        second->next=temp1;
        first=temp1;
        second=temp2;
    }
}

void printList(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    Node* head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);
    head->next->next->next->next=new Node(5);

    cout<<"Original List: ";
    printList(head);

    orderList(head);

    cout<<"Reordered List: ";
    printList(head);

    return 0;
}

/*
If the same happens with array:
arr= [1, 2, 3, 4, 5]

output: [1, 5, 2, 4, 3]
left =0, right=4

in LL we need to first go to the last node
So basically -> find the middle of the linked list, reverse the second half, and then merge the two halves together.
1->5->2->4->3
*/