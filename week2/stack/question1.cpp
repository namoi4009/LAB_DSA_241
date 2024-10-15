#include <iostream>
#include <cassert>

using namespace std;

template <class T>
class DLinkedList
{
public:
    class Node; // Forward declaration
protected:
    Node *head;
    Node *tail;
    int count;

public:
    DLinkedList() : head(nullptr), tail(nullptr), count(0) {};
    ~DLinkedList()
    {
        if (head)
        {
            Node *temp = head;
            while (temp)
            {
                Node *delNode = temp;
                temp = temp->next;
                delete delNode;
            }

            head = nullptr;
            tail = nullptr;
            count = 0;
        }
    }
    void    add(const T &e);
    void    add(int index, const T &e);
    int     size();
    string  toString();
    T       get(int index);
    void    set(int index, const T &e);
    bool    empty();
    int     indexOf(const T &item);
    bool    contains(const T &item);
    T       removeAt(int index);
    bool    removeItem(const T& item);
    void    clear();

public:
    class Node
    {
    private:
        T data;
        Node *next;
        Node *previous;
        friend class DLinkedList<T>;

    public:
        Node()
        {
            this->previous = NULL;
            this->next = NULL;
        }

        Node(const T &data)
        {
            this->data = data;
            this->previous = NULL;
            this->next = NULL;
        }
    };
};

template <class T>
void DLinkedList<T>::add(const T &e)
{
    /* Insert an element into the end of the list. */
    Node *newNode = new Node(e);
    if (count == 0)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->previous = tail;
        tail = newNode;
    }
    count++;
}

template <class T>
void DLinkedList<T>::add(int index, const T &e)
{
    /* Insert an element into the list at given index. */
    if (index < 0 || index > count)
    {
        throw out_of_range("Index is out of range!");
    }

    if (index == count)
    {
        add(e);
        return;
    }

    Node *newNode = new Node(e);
    if (index == 0)
    {
        head->previous = newNode;
        newNode->next = head;
        head = newNode;
    }
    else
    {
        Node *temp = head;
        for (int i = 0; i > index - 1; i++)
        {
            temp = temp->next;
        }
        Node *curr = temp->next;
        newNode->next = curr;
        newNode->previous = temp;
        temp->next = newNode;
        curr->previous = newNode;
    }

    count++;
}

template <class T>
int DLinkedList<T>::size()
{
    /* Return the length (size) of list */
    return this->count;
}

template <class T>
string DLinkedList<T>::toString()
{
    if (!head)
        return "[]";
    Node *temp = head->next;
    string res = "[" + to_string(head->data);
    while (temp)
    {
        res = res + ", " + to_string(temp->data);
        temp = temp->next;
    }
    res += "]";
    return res;
}

template <class T>
T DLinkedList<T>::get(int index)
{
    /* Give the data of the element at given index in the list. */
    if (index < 0 || index > count)
        throw out_of_range("Index is out of range!");

    Node *temp = head;
    for (int i = 0; i < index; i++)
    {
        temp = temp->next;
    }
    return temp->data;
}

template <class T>
void DLinkedList<T>::set(int index, const T &e)
{
    /* Assign new value for element at given index in the list */
    if (index < 0 || index > count)
        throw out_of_range("Index is out of range!");

    Node *temp = head;
    for (int i = 0; i < index; i++)
    {
        temp = temp->next;
    }
    temp->data = e;
}

template <class T>
bool DLinkedList<T>::empty()
{
    /* Check if the list is empty or not. */
    return this->count == 0;
}

template <class T>
int DLinkedList<T>::indexOf(const T &item)
{
    /* Return the first index wheter item appears in list, otherwise return -1 */
    Node *temp = head;
    int pos = 0;
    while (temp)
    {
        if (temp->data == item)
        {
            return pos;
        }
        temp = temp->next;
        pos++;
    }
    return -1;
}

template <class T>
bool DLinkedList<T>::contains(const T &item)
{
    /* Check if item appears in the list */
    return indexOf(item) != -1;
}

template <class T>
T DLinkedList<T>::removeAt(int index)
{
    /* Remove element at index and return removed value */
    if (index < 0 || index >= count) throw out_of_range("Index is out of range!");

    Node* delNode;

    if (index == 0) { // remove at front
        delNode = head;
        head = head->next;
        if (!head) tail = nullptr;
        else head->previous = nullptr;
    } else if (index == count - 1) { // remove at tail
        delNode = tail;
        tail = tail->previous;
        tail->next = nullptr;
    } else {
        Node* temp = head;
        for (int i = 0; i < index - 1; i++) { // remove in the middle
            temp = temp->next;
        }
        delNode = temp->next;

        temp->next = delNode->next;
        temp->next->previous = temp;
    }

    T removedData = delNode->data;
    delete delNode;
    count--;
    return removedData;
}

template <class T>
bool DLinkedList<T>::removeItem(const T& item)
{
    /* Remove the first apperance of item in list and return true, otherwise return false */
    int pos = indexOf(item);
    if (pos != -1) {
        removeAt(pos);
        return true;
    }
    return false;
}

template<class T>
void DLinkedList<T>::clear(){
    /* Remove all elements in list */
    Node* temp = head;
    while (temp) {
        Node* delNode = temp;
        temp = temp->next;
        delete delNode;
    }
    count = 0;
    head = tail = nullptr;
}

template<class T>
class Stack {
protected:
    DLinkedList<T> list;
public:
    Stack() {}
    void push(T item) {
        // TODO: Push new element into the top of the stack
        list.add(item);
    }

    T pop() {
        // TODO: Remove an element on top of the stack
        return list.removeAt(list.size() - 1);
    }

    T top() {
        // TODO: Get value of the element on top of the stack
        return list.get(list.size() - 1);
    }

    bool empty() {
        // TODO: Determine if the stack is empty
        return list.size() == 0;
    }

    int size() {
        // TODO: Get the size of the stack
        return list.size();
    }

    void clear() {
        // TODO: Clear all elements of the stack
        list.clear();
    }
};

int main() {
    Stack<int> stack;

    int item[] = { 3, 1, 4, 5, 2, 8, 10, 12 };
    for (int idx = 0; idx < 8; idx++) stack.push(item[idx]);
        
    assert(stack.top() == 12);
        
    stack.pop();
    stack.pop();
        
    cout << stack.top();

    return 0;
}