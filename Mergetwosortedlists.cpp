#include <iostream>
using namespace std;

/*Leetcode-21:
Problem statement:- Merge Two Sorted Lists
You are give the heads of two sorted linked list list1 and list2. 

Merge the two lists into one shorted list. The list should be made by splicing together the node of the first two lists.

returns the head of the merged linked list.
e.g: 
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

*/

typedef struct Node{
    int data;
    struct Node *next;
}Node;

void solve(Node* first, Node* second){
    Node* curr1 = first;
    Node* next1 = curr1->next;
    Node* curr2 = second;
    Node* next2 = curr2->next;

    while(next1 != NULL && curr2 != NULL){
        if((curr2->data >= curr1->data) && (curr2->data <= next1->data)){
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next =next1;

            curr1 = curr2;
            curr2 = next2;
        } else {
            //moving curr1 and next1 forward
            curr1=next1;
            next1 = next1->next;

            if(next1 == NULL){
                curr1->next = curr2;
                return;
            }
        }
    }
    if(curr2 != NULL){
        curr2->next = curr2;
    }
}
struct Node* sortTwoList(Node* first, Node* second){
    if(first == NULL){
        return second;
    }
    if(second == NULL){
        return first;
    }

    if(first->data <= second->data){
        solve(first, second);
        return first;
    } else {
        solve(second, first);
        return second;
    }
}



int main() {
    cout << "Hello, World!";
    return 0;
}