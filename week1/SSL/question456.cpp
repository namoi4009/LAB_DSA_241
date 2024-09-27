#include <bits/stdc++.h>

using namespace std;

class LLNode {
public:
    int val;
    LLNode* next;
    LLNode(): val(0), next(nullptr) {};
    LLNode(int val, LLNode* next): val(val), next(next) {};

    static LLNode* createWithIterators(const int* arr, const int* end) {
        LLNode* head = nullptr;
        int len = end - arr;
        if (len == 0) return head;
        for (int i = 0; i < len; i++) {
            LLNode* newNode = new LLNode(arr[i], nullptr);
            if (!head) {
                head = newNode;
            } else {
                LLNode* curr = head;
                while(curr->next) {
                    curr = curr->next;
                }
                curr->next = newNode;
            }
            
        }
        return head;
    }

    static void printList(LLNode *head) {
        cout << "[" << head->val;
        LLNode* temp = head->next;
        while (temp) {
            cout << ", " << temp->val;
            temp = temp->next;
        }
        cout << "]" << endl;
    }
};

// Cau4
LLNode* reverseLinkedList(LLNode* head) {
    // STUDENT ANSWER
    LLNode* curr = head;
    LLNode* n = nullptr;
    LLNode* prev = nullptr;
    while (curr) {
        n = curr->next;
        curr->next = prev;
        
        prev = curr;
        curr = n;
    }
    return prev;
}

// Cau 5
LLNode* addLinkedList(LLNode* l0, LLNode* l1) {
    // STUDENT ANSWER
    LLNode* head = nullptr;
    LLNode* curr = head;
    LLNode* temp0 = l0;
    LLNode* temp1 = l1;
    int remainder = 0, value0 = 0, value1 = 0;
    while (temp1 || temp0 || remainder) {
        if (temp0) {
            value0 = temp0->val;
            temp0 = temp0->next;
        } else value0 = 0;
        
        if (temp1) {
            value1 = temp1->val;
            temp1 = temp1->next;
        } else value1 = 0;

        int sum = value0 + value1;
        if (remainder) {
            sum++;
            remainder = 0;
        }
        if (sum >= 10) {
            remainder = sum / 10;
            sum %= 10;
        }
        LLNode* newNode = new LLNode(sum, nullptr);

        if (!head) {
            head = newNode;
            curr = head;
        }
        else {
            curr->next = newNode;
            curr = newNode;
        }
    }
    return head;
}

// Cau 6
int len(LLNode* head) {
    int length = 0;
    LLNode* temp = head;
    while(temp) {
        temp = temp->next;
        length++;
    }
    return length;
}

LLNode* rotateLinkedList(LLNode* head, int k) {
    // STUDENT ANSWER
    if (!head || k == 0) return head;
    int size = len(head);
    if (size < 1 || k % size == 0) return head;
    
    k %= size;

    // Make the list circular
    LLNode* oldTail = head;
    for (int i = 0; i < size - 1; i++) {
        oldTail = oldTail->next;
    }
    oldTail->next = head;

    // Find new tail: (size - k)th element
    LLNode* newTail = head;
    for (int i = 0; i < size - k - 1; i++) {
        newTail = newTail->next;
    }
    
    head = newTail->next;
    newTail->next = nullptr;

    return head;
}

int main() {
    int arr[] = {2, 4, 6, 6, 3};
    int k = 3;
    LLNode* head = LLNode::createWithIterators(arr, arr + sizeof(arr) / sizeof(int));
    LLNode::printList(head);
    cout << "\n";
    LLNode* newhead = rotateLinkedList(head, k);
    LLNode::printList(newhead);
    return 0;
}