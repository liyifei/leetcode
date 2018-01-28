#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *head = new ListNode(0);
    ListNode *tail = head;
    
    int carry = 0;
    while(l1 || l2 || carry){
        int n = (l1?l1->val:0) + (l2?l2->val:0) + carry;
        tail -> next = new ListNode(n % 10);
        carry = n / 10;
        tail = tail -> next;
        l1 = l1?l1 -> next:NULL;
        l2 = l2?l2 -> next:NULL;
    }
    return head -> next;
}



int main(){

	ListNode a1(2);
	ListNode a2(4);
	ListNode a3(3);
	a1.next = &a2;
	a2.next = &a3;

	ListNode b1(5);
	ListNode b2(6);
	ListNode b3(4);
	//ListNode b4(4);
	b1.next = &b2;
	b2.next = &b3;
	//b3.next = &b4;

	ListNode *first_node = addTwoNumbers(&a1,&b1);
  while( first_node != NULL){
    cout << (*first_node).val << "" ;
		delete first_node;
    first_node = first_node->next;
  } 

	return 0;
}

//Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//Output: 7 -> 0 -> 8
//Explanation: 342 + 465 = 807.
