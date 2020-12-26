#include "list_node.h"
#include <stack>          // std::stack

ListNode* Reverse(ListNode** head) {
    ListNode* p_prev = nullptr;
    ListNode* p_current = *head;
    ListNode* p_newHead = nullptr;
    while (p_current != nullptr) {
        ListNode* p_next = p_current->next;
        if (p_next == nullptr) p_newHead = p_current;
        p_current->next = p_prev;
        p_prev = p_current;
        p_current = p_next;
    }
    return p_newHead;
}

ListNode* ReverseByStack(ListNode** head) {
    ListNode* p_current = *head;
    std::stack<ListNode*> sta;
    while (p_current != nullptr) {
        sta.push(p_current);
        p_current = p_current->next;
    }
    ListNode* p_newHead = sta.top();
    while (!sta.empty()) {
        p_current = sta.top();
        sta.pop();
        p_current->next = sta.empty() ? nullptr : sta.top();
    }
    return p_newHead;
}

void run(ListNode** head, int method) {
    cout<<"original:";
    printList(*head);
    cout<<"reverse done ";
    if (method == 1) {
        cout<<"by method Reverse:";
        printList(Reverse(head));
    }
    else {
        cout<<"by method ReverseByStack:";
        printList(ReverseByStack(head));
    }
}

void printList(ListNode* head) {
    while (head != nullptr) {
        cout<<head->ch<<",";
        head = head->next;
    }
    cout<<endl;
}

int main () {
    ListNode* p1 = new ListNode('1');
    ListNode* p2 = new ListNode('2');
    ListNode* p3 = new ListNode('3');
    ListNode* p4 = new ListNode('9');
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    ListNode** head = &p1;
    run(head, 1);
    delete p1;
    delete p2;
    delete p3;
    delete p4;
    return 0;
}
