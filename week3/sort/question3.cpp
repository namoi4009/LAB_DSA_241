#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int _val = 0, ListNode *_next = nullptr) : val(_val), next(_next) {}
};

// Merge two sorted lists
ListNode* mergeLists(ListNode* a, ListNode* b) {
    if (!a) return b;
    if (!b) return a;

    ListNode dummy;
    ListNode* tail = &dummy;
    while (a && b) {
        if (a->val <= b->val) {
            tail->next = a;
            a = a->next;
        } else {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }

    if (a) tail->next = a;
    else tail->next = b;

    return dummy.next;
}
// Sort an unsorted list given its head pointer
ListNode* mergeSortList(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = nullptr;

    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    prev->next = nullptr;
    
    ListNode* left = mergeSortList(head);
    ListNode* right = mergeSortList(slow);

    return mergeLists(left, right);
}

int main() {

    return 0;
}