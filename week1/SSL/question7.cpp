#include <bits/stdc++.h>

using namespace std;

class LinkedList {
public: 
    class Node;
private:
    Node* head;
    Node* tail;
    int size;
public: 
    class Node {
        private: 
            int value;
            Node* next;
            friend class LinkedList;
        public:
            Node() {
                this->next = nullptr;
            }
            Node(Node* node) {
                this->value = node->value;
                this->next = node->next;
            }
            Node(int value, Node* next = nullptr) {
                this->value = value;
                this->next = next;
            }
    };
    LinkedList(): head(nullptr), tail(nullptr), size(0) {};
    void add(int value) {
        Node* newNode = new Node(value, nullptr);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    string toString() {
        if (!head) return "";

        Node* temp = head;
        string res = "[" + to_string(temp->value);
        for (int i = 1; i < size; i++) {
            temp = temp->next;
            res = res + ", " + to_string(temp->value);
        }
        res += "]"; 
        return res;
    }
    void partition(int k);
};

void LinkedList::partition(int k) {
    Node* newHead = nullptr; // new List
    Node* curr = nullptr; // cursor of the new List
    Node* temp = head;
    
    // Find the first group (value < k)
    while (temp) {
        if (temp->value < k) {
            Node* newNode = new Node(temp->value, nullptr);
            if (!newHead) {
                newHead = newNode;
                curr = newNode;
            } else {
                curr->next = newNode;
                curr = newNode;
            }
        }
        temp = temp->next;
    }
    
    // Find the second group (value = k)
    temp = head;
    while (temp) {
        if (temp->value == k) {
            Node* newNode = new Node(temp->value, nullptr);
            if (!newHead) {
                newHead = newNode;
                curr = newNode;
            } else {
                curr->next = newNode;
                curr = newNode;
            }
        }
        temp = temp->next;
    }
    
    // Find the third group (value > k)
    temp = head;
    while (temp) {
        if (temp->value > k) {
            Node* newNode = new Node(temp->value, nullptr);
            if (!newHead) {
                newHead = newNode;
                curr = newNode;
            } else {
                curr->next = newNode;
                curr = newNode;
            }
        }
        temp = temp->next;
    }
    
    // Change the value in the original node
    temp = head;
    curr = newHead;
    while (temp) {
        temp->value = curr->value;
        temp = temp->next;
        curr = curr->next;
    }
}

int main() {
    LinkedList* l1 = new LinkedList();
    l1->add(20); l1->add(30); l1->add(10); l1->add(60); l1->add(40); l1->add(45); l1->add(55);
    l1->partition(45);
    cout << l1->toString() << "\n";

    return 0;
}