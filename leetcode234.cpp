#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* leetcode-234. Palindrome Linked List
Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

Example 1:
Input: head = [1,2,2,1]
Output: true
*/
class ListNode {
 public:
    int data;
    ListNode *next;

    ListNode(int x) {
        data = x;
        next = NULL;
    }
};


//Method-1
class Solution {
    private:
        bool checkPalindrome(vector<int> arr){
            int n = arr.size();

            int s = 0;
            int e = n-1;
            while(s<=e){
                if(arr[s] == arr[e]){
                    return 1;
                }
                s++;
                e--;
            }
            return 1;
        }
    
    public:
    bool isPalindrome(ListNode* head) {
       vector<int> arr;

       ListNode* temp = head;
       while(temp != NULL){
        arr.push_back(temp->data);
        temp = temp->next;
       }
       return checkPalindrome(arr);
    }
};

//Method-2
class Solution{
    private:
        ListNode* getMid(ListNode* head){
            ListNode* slow = head;
            ListNode* fast = head->next;

            while(fast != NULL && fast ->next != NULL){
                fast = fast -> next ->next;
                slow = slow ->next;
            }
            return slow;
        }

        //function to reverse ll
        ListNode* reverse(ListNode* head){

            ListNode* curr = head;
            ListNode* prev = NULL;
            ListNode* next = NULL;

            while(curr != NULL){
                next = curr -> next;
                curr -> next = prev;
                prev = curr;
                curr = next;
            }
            return prev;
        }
    public:
        bool isPalindrome(ListNode* head){
            if(head == NULL || head ->next == NULL){
                return true;
            }

            //step 1: find Middle
            ListNode* middle = getMid(head);

            //step 2: reverse List after Middle
            ListNode* temp = middle -> next;
            middle -> next = reverse(temp);

            //step 3: Compare both halves
            ListNode* head1 = head;
            ListNode* head2 = middle->next;

            while(head2 != NULL){
                if(head1 -> data != head2 -> data){
                    return false;
                }
                head1 = head1 -> next;
                head2 = head2 -> next;
            }

            //step4- repeat step 2
            temp = middle ->next;
            middle -> next = reverse(temp);

            return true;
        }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
