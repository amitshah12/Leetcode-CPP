#include <iostream>
#include <vector>
using namespace std;

/* GFG - Merge two sorted linked lists
Given the head of two sorted linked lists consisting of nodes respectively. Merge both lists and return the head of the sorted merged list.

Input:
head1 : 5->10->15->40->NULL
head2 : 2->3->20->NULL
  
Output: 2 -> 3 -> 5 -> 10 -> 15 -> 20 -> 40
*/

class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


class Solution {
  public:
  
    Node* solve(Node* head1, Node* head2){

        //If only one element is present in first list
        if(head1 -> next == NULL){
            head1 -> next = head2;
            return head1;
        }


        Node* curr1 = head1;
        Node* next1 = curr1 -> next;
        
        Node* curr2 = head2;
        Node* next2 = curr2 -> next;
        
        while(next1 != NULL && curr2 != NULL){
            if((curr2 -> data >= curr1 -> data) && (curr2 -> data <= next1 -> data)){
                
                //add node in betweeen the first list
                curr1 -> next = curr2; 
                next2 = curr2 -> next;
                curr2 -> next = next1;
                //updating pointers
                curr1 = curr2;
                curr2 = next2;
            } else {
                //moving curr1 and next1 
                curr1 = next1;
                next1 = next1 -> next;
                
                if(next1 == NULL){
                    curr1 -> next = curr2;
                    return head1;
                }
                
            }
        }
        return head1;
    }
  
  
    Node* sortedMerge(Node* head1, Node* head2) {
        // code here
        if(head1 == NULL){
            return head2;
        }
        
        if(head2 == NULL){
            return head1;
        }
        
        if(head1 -> data <= head2 -> data){
            solve(head1, head2);
        } else {
            solve(head1, head2);
        }
    }
};

int main() {

    return 0;
}