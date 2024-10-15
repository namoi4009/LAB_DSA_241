#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *left;
    ListNode *right;
    ListNode(int x = 0, ListNode *l = nullptr, ListNode* r = nullptr) : val(x), left(l), right(r) {}
};

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

ListNode* add(ListNode* head, int val) {
    if (!head) {
        ListNode* newNode = new ListNode(val);
        head = newNode;
        return head;
    }

    ListNode* temp = head;
    while (temp->right)
        temp = temp->right;
    
    ListNode* newNode = new ListNode(val, temp, nullptr);
    temp->right = newNode;
    return head;
}

ListNode* reverse(ListNode* head, int a, int b) {
    //To Do
    if (a == b || !head) return head;

    ListNode* temp = head;
    ListNode* bef = nullptr;
    ListNode* prev = nullptr;
    for (int i = 1; i < b; i++)
        temp = temp->right;
    if (temp->right) prev = temp->right;
    temp = head;
    for (int i = 1; i < a; i++) 
        temp = temp->right;
    if(temp->left) bef = temp->left;

    ListNode* next = nullptr;
    for (int i = a; i <= b; i++) {
        next = temp->right;
        temp->right = prev;
        temp->left = next;
        if (i == b) {
            if (a == 1) head = temp;
            else {
                temp->left = bef;
                bef->right = temp;
            }
        } else { 
            prev = temp;
            temp = next;
        }
    }
    return head;
}

int main() {
    ListNode* head = nullptr;
    for (int i = 3; i <= 7; i++)
        head = add(head, i);
    printList(head);

    ListNode* reverseList = reverse(head, 2, 4);
    printList(reverseList);

    clear(head);
    return 0;
}