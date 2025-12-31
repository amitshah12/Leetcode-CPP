#include <iostream>
#include <vector>
using namespace std;

/*******Leetcode:206 Reverse linked list */
/* Problem statement :
You are given two non-empty linked list representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807

*/


/**Add two numbers represented by Linked lists
 * GFG:
Given two numbers represented by two linked lists of size N and M. The task is to return a sum list
    ->The sum list is a linked list representation of the addition of two input numbers from the last.
**/

typedef struct Node{
    int data;
    struct Node *next;
}Node;

struct Node* reverseLinkedList(Node* head){
    Node* prev, *curr, *forward;

    if(head == NULL || head->next == NULL){
        return head;
    }
    prev = NULL;
    curr = head;
    forward = NULL;
    while(curr != NULL){
        forward = curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    return prev;
}

void insertAtTail(struct Node* &head,struct Node* &tail, int val){
    struct Node* temp = new Node(val);
    if(head == NULL){
        head = temp;
        tail = temp;
        return;
    } else {
        tail->next = temp;
        tail = temp;
    }
}

/**Method -1: */
// struct Node* add(struct Node* first,struct Node *second){
//     int carry = 0;

//     Node * ansHead = NULL;
//     Node* ansTail = NULL;

//     while(first != NULL && second != NULL){
//         int sum = carry + first -> data + second -> data;
//         int digit = sum % 10;

//         //Create node and add in answer linked list
//         insertAtTail(ansHead, ansTail, digit);

//         carry = sum/10;
//         first = first->next;
//         second = second->next;
//     }

//     while(first != NULL){
//         int sum = carry + first->data;
//         int digit = sum % 10;

//         //Create node and add in answer linked list
//         insertAtTail(ansHead, ansTail, digit);

//         carry = sum/10;
//         first= first->next;
//     }

//     while(second != NULL){
//         int sum = carry + second->data;
//         int digit = sum % 10;

//         //Create node and add in answer linked list
//         insertAtTail(ansHead, ansTail, digit);

//         carry = sum/10;
//         first = second->next;
//     }

//     while(carry != 0){
//         int sum = carry;
//         int digit = sum % 10;

//         //Create node and add in answer linked list
//         insertAtTail(ansHead, ansTail, digit);

//         carry = sum/10;
//     }
    
//     return ansHead;
// }

/**Method - 2: */
struct Node* add(struct Node* first,struct Node *second){
    int carry = 0;

    Node * ansHead = NULL;
    Node* ansTail = NULL;

    while(first != NULL || second != NULL || carry != 0){

        int val1 = 0;
        if(first != NULL){
            val1 = first ->data;
        }
        int val2 = 0;
        if(second != NULL){
            val2 = second ->data;
        }

        int sum = carry + val1 + val2;
        int digit = sum % 10;

        //Create node and add in answer linked list
        insertAtTail(ansHead, ansTail, digit);

        carry = sum/10;
        if(first != NULL){
            first = first->next;
        }
        if(second != NULL){
            second = second->next;
        }
        
    }
    return ansHead;
}

Node* addTwoList(Node* first, Node *second){
    //step 1 - reverse input LL
    first = reverseLinkedList(first);
    second = reverseLinkedList(second);

    //step 2 - add 2 LL
    Node* ans = add(first, second);
    
    //step 3 - reverse output of the addion
    Node * ans1 = reverseLinkedList(ans);

    return ans1;
}

int main() {
    
    cout<<"hello world!";

    return 0;
}