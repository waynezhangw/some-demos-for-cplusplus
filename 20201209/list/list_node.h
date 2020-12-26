#pragma once

#include <iostream>

using namespace std;

struct ListNode {
public:
	ListNode(char c) : ch(c), next(nullptr) {}
	char ch;
	ListNode* next;
};

ListNode* Reverse(ListNode** head);
ListNode* ReverseByStack(ListNode** head);
void run(ListNode** head);
void printList(ListNode* head);
