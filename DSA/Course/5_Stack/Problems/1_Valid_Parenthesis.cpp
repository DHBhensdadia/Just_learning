#include <bits/stdc++.h>
using namespace std;

bool validation_check (string s) {
    int size = s.size();

    stack<char> t;
    for (int i = 0; i < size; i++) {

        switch (s[i]) {
            case '(' :
                t.push('(');
                break;
            case '[' :
                t.push('[');
                break;
            case '{' :
                t.push('{');
                break;

            case ')' :
               if (!t.empty() && t.top() == '(') {
                   t.pop();
               } else {
                   return false;
               }
               break;
            case ']' :
                if (!t.empty() && t.top() == '[') {
                    t.pop();
                } else {
                    return false;
                }
                break;
            case '}' :
                if (!t.empty() && t.top() == '{') {
                    t.pop();
                } else {
                    return false;
                }
                break;

            default :
                break;
        }
    }

    return t.empty();
}

int main () {
    vector<string> test_cases = {
        "()",             // Valid
        "()[]{}",         // Valid
        "(]",             // Invalid
        "([)]",           // Invalid
        "{[]}",           // Valid
        "((",             // Invalid
        ")(",             // Invalid
        "a(b)c[d]e{f}g"   // Valid
    };

    cout << "--- Valid Parenthesis Test Cases ---" << endl;
    for (const string& test : test_cases) {
        cout << "Test string: \"" << test << "\"" << endl;
        bool result = validation_check(test);
        cout << "Result: " << (result ? "Valid" : "Invalid") << endl;
        cout << "---------------------------------" << endl;
    }

    return 0;
}
