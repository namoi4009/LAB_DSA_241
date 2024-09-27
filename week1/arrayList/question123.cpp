#include <iostream>
#include <string>

using namespace std;

template <class T>
class ArrayList {
protected:
    T* data;        // dynamic array to store the list's items
    int capacity;   // size of the dynamic array
    int count;      // number of items stored in the array
public:
    ArrayList(){capacity = 5; count = 0; data = new T[5];}
    ~ArrayList(){ delete[] data; }
    void    add(T e);
    void    add(int index, T e);
    int     size();
    void    ensureCapacity(int index);
    string  toString();

    T       removeAt(int index);
    bool    removeItem(T item);
    void    clear();

    T       get(int index);
    void    set(int index, T e);
    bool    empty();
    int     indexOf(T item);
    bool    contains(T item);
};

template<class T>
void ArrayList<T>::ensureCapacity(int cap){
    /* 
        if cap > capacity: 
            new_capacity = capacity * 1.5;
            create new array with new_capacity
        else: do nothing
    */
    if (cap > capacity) {
        this->capacity = (int)(this->capacity * 1.5);
        T* temp = new T[this->capacity];
        for (int i = 0; i < this->capacity; i++) {
            temp[i] = this->data[i];
        }
        delete[] this->data;
        this->data = temp;
    } else return;
}

template <class T>
void ArrayList<T>::add(T e) {
    /* Insert an element into the end of the array. */
    ensureCapacity(this->size() + 1);
    this->data[count++] = e;
}

template<class T>
void ArrayList<T>::add(int index, T e) {
    /* 
        Insert an element into the array at given index.
        if index is invalid:
            throw std::out_of_range("the input index is out of range!");
    */
    ensureCapacity(this->size() + 1);
    if (index > count || index < 0) {
        throw out_of_range("the input index is out of range!");
    } else {
        count++;
        for (int i = count - 1; i > index; i--) {
            this->data[i] = this->data[i - 1];  
        }
        this->data[index] = e;
    }
}

template<class T>
int ArrayList<T>::size() {
    /* Return the length (size) of the array */ 
    return this->count;
}

template<class T>
string ArrayList<T>::toString() {
    string result = "[" + to_string(this->data[0]);
    for (int i = 1; i < this->size(); i++) {
        result = result + ", " + to_string(this->data[i]);
    }
    result += "]";
    return result;
}

template<class T>
T ArrayList<T>::removeAt(int index){
    /*
    Remove element at index and return removed value 
    if index is invalid:
        throw std::out_of_range("index is out of range");
    */
    T removeValue = this->data[index];
    if (index > count || index < 0) {
        throw out_of_range("index is out of range");
    } else {
        for (int i = index; i < count - 1; i++) {
            this->data[i] = this->data[i + 1];
        }
        count--;
    }
    return removeValue;
}

template<class T>
bool ArrayList<T>::removeItem(T item){
     /* Remove the first apperance of item in array and return true, otherwise return false */
    for (int i = 0; i < count; i++) {
        if (this->data[i] == item) {
            removeAt(i);
            return true;
        }
    }
    return false;
}

template<class T>
void ArrayList<T>::clear(){
    /* 
        Delete array if array is not NULL
        Create new array with: size = 0, capacity = 5
    */
    if (this->data) {
        delete[] this->data;
        this->data = new T[5];
        this->count = 0;
        this->capacity = 5;
    }
}

template<class T>
T ArrayList<T>::get(int index) {
    if (index >= count || index < 0) {
        throw out_of_range("Index is out of range");
    }
    return this->data[index];
}

template<class T>
void ArrayList<T>::set(int index, T e) {
    if (index >= count || index < 0) {
        throw out_of_range("Index is out of range");
    }
    this->data[index] = e;
}

template<class T>
bool ArrayList<T>::empty() {
    return ( this->count == 0);
}

template<class T>
int ArrayList<T>::indexOf(T item) {
    for (int i = 0; i < count; i++) {
        if (this->data[i] == item) return i;
    }
    return -1;
}

template<class T>
bool ArrayList<T>::contains(T item) {
    for (int i = 0; i < count; i++) {
        if (this->data[i] == item) return true;
    }
    return false;
}

int main() {
    // // Testcase 1 of question 1
    // ArrayList<int> arr;
    // int size = 20;

    // for(int index = 0; index < size; index++){
    //     arr.add(0, index);
    // }

    // cout << arr.toString() << '\n';
    // cout << arr.size() << '\n';
    // arr.ensureCapacity(5);

    // // Testcase 1 question 2
    // ArrayList<int> arr;

    // for (int i = 0; i < 10; ++i) {
    //     arr.add(i);
    // }
    // arr.removeAt(0);

    // cout << arr.toString() << '\n';
    // cout << arr.size();

    // // Testcase 2 of question 2
    // ArrayList<int> arr;

    // for (int i = 0; i < 10; ++i) {
    //     arr.add(i);
    // }
    // arr.removeAt(9);

    // cout << arr.toString() << '\n';
    // cout << arr.size();

    // // Testcase 3 of question 2
    // ArrayList<int> arr;

    // for (int i = 0; i < 10; ++i) {
    //     arr.add(i);
    // }
    // arr.removeAt(5);

    // cout << arr.toString() << '\n';
    // cout << arr.size();

    // Testcase 1 of question 3
    ArrayList<int> arr;
    int size = 10;
    for(int index = 0; index < size; index++){
        arr.add(index);
    }
    try {
        arr.set(10,100);
        cout << arr.get(10) << '\n';
    }
    catch(const std::exception & e){
        cout << e.what() << endl;
    }

    return 0;
}