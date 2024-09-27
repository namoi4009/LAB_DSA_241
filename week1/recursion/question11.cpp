#include <iostream>
#include <string>

using namespace std;

bool containSpace(string s) {
    if (s == "") return false;
    if (s[s.size() - 1] == ' ') return true;
    return true && containSpace(s.substr(0, s.size() - 1));
}

string lastWord(string s) {
    int n = s.size();
    if (s[n - 1] == ' ' || s == "") return "";
    return lastWord(s.substr(0, n - 1)) + s[n - 1];
}

string reverseSentence(string s) {
    // STUDENT ANSWER
    string word = lastWord(s);
    if (!containSpace(s)) return s;
    return word + ' ' + reverseSentence(s.substr(0, s.size() - word.size() - 1));
}

int main() {
    cout << reverseSentence("data structure and algorithm is scary");
    return 0;
}