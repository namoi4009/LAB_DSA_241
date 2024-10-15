#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *left;
    ListNode *right;
    ListNode(int x = 0, ListNode *l = nullptr, ListNode* r = nullptr) : val(x), left(l), right(r) {}
};

ListNode* add(ListNode* head, int val) {
    ListNode* temp = head;
    while (temp->right)
        temp = temp->right;
    
    ListNode* newNode = new ListNode(val, temp, nullptr);
    temp->right = newNode;
    return head;
}

void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp) {
        cout << temp->val << " ";
        temp = temp->right;
    }
    cout << endl;
}

void clear(ListNode* head) {
    ListNode* temp = head;
    while (temp) {
        ListNode* delNode = temp;
        temp = temp->right;
        delete delNode;
    }
    head = nullptr;
}

ListNode* reverse(ListNode* head, int a, int b) {
    //To Do
    ListNode* curr = head;
    ListNode* prev = nullptr;
    ListNode* next = nullptr;
    ListNode* bef = nullptr;
    ListNode* aft = nullptr;

    for (int i = 1; i < a; i++)
        curr = curr->right;

    if (curr != head) bef = curr->left;
    for (int i = a; i < b; i++) {

    }

    return head;
}

int main() {
    ListNode* head = new ListNode(0);
    for (int i = 1; i < 10; i++)
        head = add(head, i);
    printList(head);
    clear(head);
    return 0;
}