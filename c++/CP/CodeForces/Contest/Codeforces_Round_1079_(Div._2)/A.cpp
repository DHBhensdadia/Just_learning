#include <bits/stdc++.h>
using namespace std;

void solution(void);

int digits_sum(int n);
int CheckState(int ori, int &equilator);
int nextTen(int ori);


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int nt;
    cin >> nt;
    while (nt--){
        solution();
    }
}

// solves each test case
void solution(void)
{
    int ori;
    cin >> ori;

    int state = -1;
    int eqilator = nextTen(ori);

    // state traker
    // Keep trying until state changes from -1
    do
    {
        state = CheckState(ori, eqilator);
    } while (state == -1);

    // output according to state of number
    if (state == 0){
        cout << 10 << endl;
    }else{
        cout << 0 << endl;
    }
}


// state checker
// Returns:
//  -1 : need to increase equilator and retry
//   0 : matched condition (over - digitsSum == original)
//   1 : exceeded original
int CheckState(int ori, int &equilator)
{
    int overori = equilator + ori;
    int res = overori - (digits_sum(overori));

    if (res < ori)
    {
        int diff = ori - res;
        equilator += (diff < 10 ? 10 : diff / 10);
        return -1;
    }
    else if (res == ori)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

// sum of all digits in a number
int digits_sum(int n)
{
    int result = 0;
    while (n != 0)
    {
        result += n % 10;
        n /= 10;
    }
    return result;
}

// returns next cloasest multiple of 10
int nextTen(int ori)
{
    int temp = ori / 10;
    return (temp * 10 + 10) - ori;
}