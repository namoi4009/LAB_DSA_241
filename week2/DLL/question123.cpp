#include <bits/stdc++.h>

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

int main()
{
    DLinkedList<int> list;
    int size = 10;
    int value[] = {2,5,6,3,67,332,43,1,0,9};

    for(int idx=0; idx < size; idx++){
        list.add(0, value[idx]);
    }
    list.removeAt(10);
    cout << list.toString();

    return 0;
}