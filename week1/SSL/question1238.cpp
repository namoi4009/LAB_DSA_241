#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

template <class T>
class SLinkedList {
public:
    class Node; // Forward declaration
protected:
    Node* head;
    Node* tail;
    int count;
public:
    SLinkedList() {
        head = nullptr;
        tail = nullptr;
        count = 0;
    }
    ~SLinkedList() { }

    void    add(const T& e);
    void    add(int index, const T& e);
    int     size();
    string  toString();

    bool    empty();
    T       get(int index);
    void    set(int index, const T& e);
    int     indexOf(const T& item);
    bool    contains(const T& item);

    T       removeAt(int index);
    bool    removeItem(const T& item);
    void    clear();

    class Iterator {
    private:
        Node* current; // Pointer to the current node in the list
    public:
        Iterator(Node* start = nullptr) : current(start) {}

        // Dereference operator
        T& operator*() {
            return current->data;
        }

        // Arrow operator
        T* operator->() {
            return &(current->data);
        }

        // Pre-increment operator
        Iterator& operator++() {
            if (current) {
                current = current->next;
            }
            return *this;
        }

        // Post-increment operator
        Iterator operator++(int) {
            Iterator temp = *this;
            ++(*this); // Use pre-increment
            return temp;
        }

        // Equality comparison operator
        bool operator==(const Iterator& other) const {
            return current == other.current;
        }

        // Inequality comparison operator
        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }
    };

    // Returns an iterator pointing to the first node
    Iterator begin() {
        return Iterator(head);
    }

    // Returns an iterator pointing to the end (nullptr) of the list
    Iterator end() {
        return Iterator(nullptr);
    }

public:
    class Node {
    private:
        T data;
        Node* next;
        friend class SLinkedList<T>;
    public:
        Node() {
            next = 0;
        }
        Node(Node* next) {
            this->next = next;
        }
        Node(T data, Node* next) {
            this->data = data;
            this->next = next;
        }
    };
};

template <class T>
void SLinkedList<T>::add(const T& e) {
    /* Insert an element into the end of the list. */
    Node* newNode = new Node(e, nullptr);
    count++;
    if (!head) {
        head = newNode;
        tail = newNode;
    } else if (!head->next) {
        head->next = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

template<class T>
void SLinkedList<T>::add(int index, const T& e) {
    /* Insert an element into the list at given index. */ 
    
    if (index > count || index < 0) {
        throw out_of_range("Index is out of range");
    } else {
        Node* newNode = new Node(e, nullptr);

        if (index == 0) {
            newNode->next = head;
            head = newNode;
            if (count == 0) {
                tail = newNode;
            }
        } else {
            Node* temp = head;
            for (int i = 0; i < index - 1; i++) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;

            if (newNode->next == nullptr) {
                tail = newNode;
            }
        }
        count++;
    }
}

template<class T>
int SLinkedList<T>::size() {
    /* Return the length (size) of list */ 
    return this->count;
}

template<class T>
string SLinkedList<T>::toString() {
    if (!head) return "[]";
    Node* temp = head->next;
    string res = "[" + to_string(head->data);
    while (temp) {
        res = res + ", " + to_string(temp->data);
        temp = temp->next;
    }
    res += "]";
    return res;
}

template<class T>
T SLinkedList<T>::get(int index) {
    /* Give the data of the element at given index in the list. */
    if (index < 0 || index > count) throw out_of_range("index is out of range");
    if (index == 0) return head->data;
    if (index == count - 1) return tail->data;
    Node* temp = head;
    for (int i = 0; i < index; i++) temp = temp->next;
    return temp->data;
}

template <class T>
void SLinkedList<T>::set(int index, const T& e) {
    /* Assign new value for element at given index in the list */
    if (index < 0 || index > count) throw out_of_range("index is out of range");
    if (index == 0) head->data = e;
    if (index == count - 1) tail->data = e;
    Node* temp = head;
    for (int i = 0; i < index; i++) temp = temp->next;
    temp->data = e;
}

template<class T>
bool SLinkedList<T>::empty() {
    /* Check if the list is empty or not. */
    return (head == nullptr);
}

template<class T>
int SLinkedList<T>::indexOf(const T& item) {
    /* Return the first index wheter item appears in list, otherwise return -1 */
    int index = 0;
    Node* temp = head;
    while (temp) {
        if (temp->data == item) return index;
        temp = temp->next;
        index++;
    }
    return -1;
}

template<class T>
bool SLinkedList<T>::contains(const T& item) {
    /* Check if item appears in the list */
    Node* temp = head;
    while (temp) {
        if (temp->data == item) return true;
        temp = temp->next;
    }
    return false;
}

template <class T>
T SLinkedList<T>::removeAt(int index) {
    if (index < 0 || index >= count) {
        throw std::out_of_range("index is out of range");
    }

    T removedData;

    if (index == 0) { // Delete the head
        Node* delNode = head;
        removedData = delNode->data;
        head = head->next;
        delete delNode;
        
        if (head == nullptr) {
            tail = nullptr;
        }
    } else {
        Node* curr = head;
        for (int i = 0; i < index - 1; i++) {
            curr = curr->next;
        }
        Node* delNode = curr->next;
        removedData = delNode->data;
        curr->next = delNode->next;
        delete delNode;
        
        if (curr->next == nullptr) {
            tail = curr;
        }
    }

    count--;
    return removedData;
}

template <class T>
bool SLinkedList<T>::removeItem(const T& item) {
    if (!head) return false;

    if (head->data == item) {
        Node* delNode = head;
        head = head->next;
        delete delNode;

        if (head == nullptr) {
            tail = nullptr;
        }

        count--;
        return true;
    } else {
        Node* curr = head;
        while (curr->next) {
            if (curr->next->data == item) {
                Node* delNode = curr->next;
                curr->next = curr->next->next;
                delete delNode;

                if (curr->next == nullptr) {
                    tail = curr;
                }

                count--;
                return true;
            } else {
                curr = curr->next;
            }
        }
    }

    return false;
}

template<class T>
void SLinkedList<T>::clear() {
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }

    head = nullptr;
    tail = nullptr;
    count = 0;
}

class Polynomial;
class Term {
private:
    double coeff;   
    int exp;
    friend class Polynomial;
public:
    Term(double coeff = 0.0, int exp = 0) {
        this->coeff = coeff;
        this->exp = exp;
    }
    bool operator==(const Term& rhs) const {
        return this->coeff == rhs.coeff && this->exp == rhs.exp;
    }
    friend ostream & operator<<(ostream &os, const Term& term) {
        cout << endl;
        cout << "Term: " << "(" << term.coeff << " " << term.exp << ")";
        return os;
    }
};
class Polynomial {
private:
    SLinkedList<Term>* terms;
public:
    Polynomial() {
        this->terms = new SLinkedList<Term>();
    }
    ~Polynomial() {
        this->terms->clear();
    }
    void insertTerm(const Term& term);
    void insertTerm(double coeff, int exp);
    void print() {
        SLinkedList<Term>::Iterator it;
        cout << "[";
        for (it = this->terms->begin(); it != this->terms->end(); it++) {
            cout << (*it);
        }
        cout << endl << "]";
    }
};

void Polynomial::insertTerm(const Term& term) {
    // STUDENT ANSWER
    if (this->terms->empty()) {
        this->terms->add(term);
        return;
    }

    SLinkedList<Term>::Iterator it;
    int pos = 0;
    for (it = this->terms->begin(); it != this->terms->end(); ++it) {
        if ((*it).exp == term.exp) {
            (*it).coeff += term.coeff;

            // remove 0 coeff term
            if ((*it).coeff == 0.0) {
                this->terms->removeAt(pos);
            }
            return;
        }

        if ((*it).exp < term.exp) {
            this->terms->add(pos, term);
            return;
        }

        pos++;
    }
    this->terms->add(term);
}

void Polynomial::insertTerm(double coeff, int exp) {
    // STUDENT ANSWER
    if (coeff != 0.0) {
        Term newTerm(coeff, exp);
        insertTerm(newTerm);
    }
}

int main() {    
    Polynomial *poly = new Polynomial();
    poly->insertTerm(6.0, 2);
    poly->insertTerm(4.0, 5);
    poly->insertTerm(4.0, 3);
    poly->insertTerm(6.0, 5);
    poly->insertTerm(-1.0, 0);
    poly->insertTerm(-6.0, 6);
    poly->insertTerm(6.0, 6);
    poly->print();

    return 0;
}