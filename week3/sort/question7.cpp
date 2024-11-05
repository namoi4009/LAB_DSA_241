#include <iostream>
#include <algorithm>

using namespace std;

struct Item {
    int val;
    int fre;
};

bool compareByFre(const Item& a, const Item& b) {
    return a.fre > b.fre;
}

bool containsValue(Item* items, int n, int value) {
    if (n == 0) return false;

    for (int i = 0; i < n; i++) 
        if (items[i].val == value) return true;
    return false;
}

void sortByFrequency(int arr[], int n){
    Item* items = new Item[n];
    int index = 0;
    for (int i = 0; i < n; i++) {
        if (!index || !containsValue(items, index, arr[i])) {
            items[index].val = arr[i];
            items[index++].fre = count(arr, arr + n, arr[i]);
        }
    }
    sort(items, items + index, compareByFre);
    int i = 0, j = 0;
    while (i < n) {
        while (items[j].fre > 0) {
            arr[i++] = items[j].val;
            items[j].fre--;
        }
        j++;
    }
    delete []items;
}

int main() {
    int arr[] = {-4,1,2,2,-4,9,1,-1};
    sortByFrequency(arr, 8);
    return 0;
}