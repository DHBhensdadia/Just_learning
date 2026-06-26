#include <bits/stdc++.h>
using namespace std;

string itp(string s);

bool isOperator (char c);
int inStackPrecedence (char c);
int outStackPrecedence (char c);



int main () {
    vector<string> test_cases = {
        "A+B*C",                    // Standard test case
        "(A+B)*C",                  // Parenthesis test
        "A*B+C*D",                  // Precedence test
        "a+b*(c^d-e)^(f+g*h)-i",    // Complex test from standard literature
        "A+B*C-D/E"                 // Mixed operators
    };

    cout << "--- Infix to Postfix Test Cases ---" << endl;
    for (const string& test : test_cases) {
        cout << "Infix   : " << test << endl;
        string result = itp(test);
        cout << "Postfix : " << result << endl;
        cout << "---------------------------------" << endl;
    }

    return 0;
}



string itp(string s) {
    string ans;
    stack<char> oh;

    for (int i = 0; i < s.size(); ) {

        if (isOperator(s[i])) {
            if (oh.empty()) {
                oh.push(s[i]);
                i++;
            } else {
                if (inStackPrecedence(oh.top()) < outStackPrecedence(s[i])) {
                    oh.push(s[i]);
                    i++;
                } else if (inStackPrecedence(oh.top()) > outStackPrecedence(s[i])) {
                    ans.push_back(oh.top());
                    oh.pop();
                } else {
                    // Match found, e.g. '(' and ')'
                    oh.pop();
                    i++;
                }
            }
        } else {
            ans.push_back(s[i]);
            i++;
        }

    }


    while (!oh.empty()) {
        ans.push_back(oh.top());
        oh.pop();
    }

    return ans;
}


bool isOperator (char c) {
    string op = "+-*^%=/[]{}()";
    return op.find(c) != std::string::npos;
}
int inStackPrecedence (char c) {
    if (c == '+' || c == '-') return 2;
    if (c == '*' || c == '/' || c == '%') return 4;
    if (c == '^') return 5;
    if (c == '(' || c == '[' || c == '{') return 0;
    return -1;
}
int outStackPrecedence (char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/' || c == '%') return 3;
    if (c == '^') return 6;
    if (c == '(' || c == '[' || c == '{') return 7;
    if (c == ')' || c == ']' || c == '}') return 0;
    return -1;
}
