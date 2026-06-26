#include <bits/stdc++.h>
using namespace std;


int evaluate(string s);
bool isOperator (char c);

int main () {
    vector<string> test_cases = {
        "234*+",    // 2 + (3 * 4) = 14
        "82/",      // 8 / 2 = 4
        "523^*",    // 5 * (2 ^ 3) = 40
        "93-",      // 9 - 3 = 6
        "53+82-*"   // (5 + 3) * (8 - 2) = 8 * 6 = 48
    };

    cout << "--- Postfix Evaluation Test Cases ---" << endl;
    for (const string& test : test_cases) {
        cout << "Postfix string : " << test << endl;
        int result = evaluate(test);
        cout << "Evaluated Result: " << result << endl;
        cout << "-----------------------------------" << endl;
    }

    return 0;
}


int evaluate(string s) {
    stack<int> st;

    for(int i = 0; i < s.size(); i++) {
        if (isOperator(s[i])) {
            int a = st.top();   st.pop();
            int b = st.top();   st.pop();
            switch (s[i]) {
                case '+' :
                    st.push(a + b);
                    break;
                case '-' :
                    st.push(b - a);
                    break;
                case '*' :
                    st.push(a * b);
                    break;
                case '/' :
                    st.push(b / a);
                    break;
                case '^' :
                    st.push(pow(b, a));
                    break;
                case '%' :
                    st.push(b % a);
                    break;
            }
        } else {
            st.push(s[i] - '0');
        }
    }

    return st.top();

}

bool isOperator (char c) {
    string op = "+-*^%=/[]{}()";
    return op.find(c) != std::string::npos;
}
