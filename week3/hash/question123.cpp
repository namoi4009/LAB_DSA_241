int hashFunction(int key, int capacity)
{
    return key % capacity;
}

template <class K, class V>
class XHashMap
{
public:
    class Entry
    {
    public:
        K key;
        V value;
        Entry *next;

        Entry(K key, V value, Entry *next = 0)
        {
            this->key = key;
            this->value = value;
            this->next = next;
        }
    };

private:
    Entry **table; // hash table
    int capacity;  // size for the hash table
    int count;

public:
    // Constructor
    XHashMap()
    {
        this->capacity = 10;
        this->count = 0;
        table = new Entry *[capacity];
        // reset table to 0
        for (int i = 0; i < capacity; i++)
        {
            table[i] = 0;
        }
    }

    ~XHashMap()
    { // Destructor
        // Remove all entries in the current map
        for (int idx = 0; idx < this->capacity; idx++)
        {
            Entry *entry = this->table[idx];
            while (entry != 0)
            {
                Entry *next = entry->next;
                delete entry;
                entry = next;
            }
        }
        // Remove table
        delete[] table;
    }

    // Question 1
    void put(int key, int value) {
        int index = hashFunction(key, capacity);
        for (int i = 0; i < capacity; i++) {
            Entry* entry = table[i];
            while (entry != 0) {
                if (entry->key == key) {
                    entry->value = value;
                    return;
                }
                entry = entry->next;
            }
        }
        Entry* newEntry = new Entry(key, value, table[index]);
        table[index] = newEntry;
        count++;
        ensureLoadFactor(count);
    }

    void ensureLoadFactor(int current_size) {
        int maxSize = (int)(capacity * 0.75);
        if (count >= maxSize) {
            int newCapacity = (int)(1.5 * capacity);
            rehash(newCapacity);
        }
    }

    void rehash(int newCapacity) {
        Entry** oldTable = this->table;
        int oldCap = this->capacity;
        
        this->table = new Entry*[newCapacity];
        this->capacity = newCapacity;

        for (int i = 0; i < capacity; i++) {
            table[i] = nullptr;
        }
        
        for (int i = 0; i < oldCap; i++) {
            Entry* entry = oldTable[i];
            while (entry != nullptr) {
                Entry* nextEntry = entry->next;
                int newIndex = hashFunction(entry->key, capacity);
                entry->next = table[newIndex];
                table[newIndex] = entry;
                entry = nextEntry;
            }
        }

        delete []oldTable;
    }

    // Question 2
    V& get(K key) {
        // Calculate the index using the hash function.
        int index = hashFunction(key, capacity);
        
        // Access and traverse the linked list at that index.
        Entry* entry = table[index];
        while (entry) {
            if (entry->key == key)
                return entry->value;
            entry = entry->next;
        }
        
        throw std::out_of_range("Key not found");
    }

    // Question 3
    V remove(int key) {
    /*
            An index need to find by using the hash function,
            then find the Entry of this index
                
            Check if the key already exists. If yes, remove the key from the table
            
            If the key doesn't exist, throw out_of_range("Key not found");
        
        */
        int index = hashFunction(key, capacity);
        Entry* entry = table[index];
        Entry* prev = nullptr;
        while (entry) {
            if (entry->key == key) {
                Entry* delNode = entry;
                if (prev) prev->next = delNode->next;
                V rev = delNode->value;
                delete delNode;
                return rev;
            }
            prev = entry;
            entry = entry->next;
        }
        throw out_of_range("Key not found");
    }

    // print table method (for testing)
    void printTable() const
    {

        cout << "------------The hash table is shown below------------\n";
        for (int i = 0; i < capacity; i++)
        {
            Entry *entry = table[i];
            cout << "Index " << i << ": ";
            while (entry != 0)
            {
                cout << "(" << entry->key << ", " << entry->value << ") ";
                entry = entry->next;
            }
            cout << endl;
        }
        cout << "-----------------------------------------------------\n";
    }
};