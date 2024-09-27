#include <iostream>
#include <string>

using namespace std;

int containNum(const char* s, int pos) {
    if (*s == '\0') return -1; // STOP
    if (isdigit(*s)) return pos; // Found
    return containNum(s + 1, pos + 1);
}

// Return position of the n - 1 relative close bracket
int closeBracket(const char* s, int pos, int balance) {
   
    if (*s == '\0') return -1; // Stop if we reach the end - default to avoid error
    if (*s != '(' && *s != ')') return closeBracket(s + 1, pos + 1, balance);
    if (*s == '(') balance++;
    if (*s == ')') balance--;
    if (balance == 0) return pos;
    return closeBracket(s + 1, pos + 1, balance);
}

// Repeat string n times
string repeatStr(int time, string s) {
    if (time == 0) return "";
    if (time == 1) return s;
    return s + repeatStr(time - 1, s);
}

// main inplementation 1 term
string singleTerm(string s) {
    int numPos = containNum(&s[2], 2);

    if (numPos == -1) { // not found number --> return repeated string
        return repeatStr(s[0] - '0', s.substr(2, s.size() - 3));
    } else {
        int close = closeBracket(&s[2], 2, 0);
        string sub = s.substr(numPos, close + 1 - numPos);
        return repeatStr(s[0]- '0', s.substr(2, numPos - 2) + singleTerm(sub) + s.substr(close + 1, s.size() - close - 2));
    }
}

// handle muliple terms
string multipleTerms(string s) {
    if (s.empty()) return s;
    if (!s.empty() && isalpha(s[0])) { // Khi có char đơn lẻ (ví dụ như x hoặc y), thì ta in ra và đi tiếp, nếu không có thì ví dụ như x3(b) chỉ in 3b, bỏ qua x
        return s[0] + multipleTerms(s.substr(1));
    }
    int end = closeBracket(&s[0], 0, 0) + 1;
    if (end <= 0 || end > (int) s.size()) return s; // tương tự, đảm bảo dù end không có ')' vẫn in phần phía sau nó
    return singleTerm(s.substr(0, end)) + multipleTerms(s.substr(end));
}

string expand(string s) {
    if (isdigit(s[0])) return multipleTerms(s);
    return s[0] + expand(s.substr(1));
}

int main() {
    // // Sample testcase 1
    // cout << expand("2(ab3(cde)x)") << "\n";

    // // Sample testcase 2
    // cout << expand("2(x0(y))3(z)") << "\n";
    return 0;
}