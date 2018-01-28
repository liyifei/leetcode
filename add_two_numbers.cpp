#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

	ListNode *first_node;
	ListNode *ln_pre;

	int sum,remainder;
	int carry = 0;
	bool first = true;
	while(l1 != NULL && l2 != NULL){
		sum = (l1->val + l2->val) + carry;
		remainder =  sum % 10;
		carry = sum / 10;
		ListNode *ln_now = new ListNode(remainder);
		if(first){
			first_node = ln_pre = ln_now;
			first = false;
		}else{
			ln_pre->next = ln_now;
			ln_pre = ln_now;
		}
		l1 = l1->next;
		l2 = l2->next;
	}
	while(l1 != NULL){
    sum = (l1->val ) + carry;
    remainder =  sum % 10; 
    carry = sum / 10; 
		ListNode *ln = new ListNode(remainder);
		ln_pre->next = ln;
    ln_pre = ln_pre->next;
    l1 = l1->next;
	}
	while(l2 != NULL){
    sum = (l2->val ) + carry;
    remainder =  sum % 10;
    carry = sum / 10;
    ListNode *ln = new ListNode(remainder);
    ln_pre->next = ln;
    ln_pre = ln_pre->next;
    l2 = l2->next;
	}

	if(carry > 0 ){
    ListNode *ln = new ListNode(carry);
    ln_pre->next = ln; 
	}

	 return first_node; 
   
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
