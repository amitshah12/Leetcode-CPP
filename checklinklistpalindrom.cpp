#include <iostream>
#include <vector>
using namespace std;

/***** Leetcode: 234. Palindrome linked list */
//Q. Check if Linked List is Palindrom or not

//Problem statement: Given a singly Linked list of size N of integer. The task is to check if the given linked list is palindrom or not.

typedef struct Node{
    int data;
    struct Node *next;
}Node;

// method-1
// class Solution{
//     private:
//         bool checkPalindrome(vector<int> arr){
//             int n = arr.size();
//             int s = 0;
//             int e = n-1;

//             while(s<=e){
//                 if(arr[s] != arr[e]){
//                     return 0;
//                 }
//                 s++;
//                 e--;
//             }
//             return 1;
//         }

//     public:
//     bool isPalindrome(Node *head){
//         vector<int> arr;

//         Node* temp = head;
//         while (temp != NULL)
//         {
//             arr.push_back(temp->data);
//             temp = temp->next;
//         }
//         return checkPalindrome(arr);
        
//     }
// }

//method-2
class Solution{
    private:
    Node* getMid(Node* head){
        Node* slow = head;
        Node* fast = head -> next;

        while(fast != NULL && fast->next != NULL){
            fast = fast -> next ->next;
            slow = slow -> next;
        }
        return slow;
    }
    Node* reverse(Node* head){
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;

        while(curr != NULL){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    public:
    bool isPalindrome(Node *head){
        if(head == NULL || head -> next == NULL){
            return true;
        }

        //step 1 -> find Middle
        Node* middle = getMid(head);

        //step 2 -> reverse List after Middle
        Node* temp = middle -> next;
        middle -> next = reverse(temp);

        //step3 -> compare both halves
        Node* head1 = head;
        Node* head2 = middle->next;

        while(head2 != NULL){
            if(head1 -> data != head2 -> data){
                return false;
            }
            head1 = head1 -> next;
            head1 = head2 -> next;
        }

        //step4 -> repeat step 2
        temp = middle -> next;
        middle ->next = reverse(temp);


        return true;
    }
};

int main() {
    


    return 0;
}