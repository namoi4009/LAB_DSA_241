#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxNumberOfPeople(vector<int>& rooms, vector<int>& people, int k) {
    std::sort(rooms.begin(), rooms.end());
    std::sort(people.begin(), people.end());

    int i = 0;
    int j = 0;
    int count = 0;  // Result

    int n = people.size();
    int m = rooms.size();

    while (i < n && j < m) {
        // Check if the current room is acceptable for the current person
        if (rooms[j] < people[i] - k) {
            // Room is too small, move to the next room
            j++;
        } else if (rooms[j] > people[i] + k) {
            // Room is too big, move to the next person
            i++;
        } else {
            // Room is acceptable, assign it to the person
            count++;
            i++;
            j++;
        }
    }

    return count;
}

int main() {
    int peopleCount, roomCount, k;
    cin >> peopleCount >> roomCount >> k;
    
    vector<int> people(peopleCount);
    vector<int> rooms(roomCount);

    for(int i = 0; i < peopleCount; i++)
        cin >> people[i];
    for(int i = 0; i < roomCount; i++)
        cin >> rooms[i];
    cout << maxNumberOfPeople(rooms, people, k) << '\n';

    return 0;
}