#include <iostream>



// A simplified structure that implements an element of a singly linked list.
struct ListNode {
	int val;
	ListNode* next;
};



// A function that flips a singly linked list.
ListNode* ReverseFList(ListNode* head)
{
	ListNode* cur;
	ListNode* next;;
	ListNode* prev;

	cur = head;
	next = cur->next;

	// Working with the first element separately.
	cur->next = nullptr;
	cur = next;
	prev = head;

	// The main cycle.
	while (cur->next != nullptr) {
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}

	// Working with the last element separately.
	cur->next = prev;
	prev = cur;
	head = cur;

	// Return the pointer to the new beginning of the list.
	return(head);
}



int main() {

	ListNode LN[5];
	ListNode* head = &LN[0];

	// Initialize a singly linked list.
	for (int i = 0; i != 4; ++i) {
		LN[i].val = i * i;
		LN[i].next = &LN[i + 1];
	}
	LN[4].val = 4 * 4;
	LN[4].next = nullptr;

	// Output the values of its val fields in the order specified during initialization.
	for (ListNode* cur = head; cur != nullptr; cur = cur->next) {
		std::cout << cur->val << " ";
	}
	std::cout << std::endl;

	// Start the "flip" function.
	head = ReverseFList(head);

	// We output the values of its val fields in the order after the "reversal".
	for (ListNode* cur = head; cur != nullptr; cur = cur->next) {
		std::cout << cur->val << " ";
	}
	std::cout << std::endl;

	return(0);
}