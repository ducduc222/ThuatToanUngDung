#include <bits/stdc++.h>
#define MAX 10000
using namespace std;

stack<int> st;
string S[MAX];
int n;
map<char, int> C;

void input()
{
    C['{'] = 1;
    C['}'] = -1;
    C['['] = 2;
    C[']'] = -2;
    C['('] = 3;
    C[')'] = -3;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> S[i];
    }
}

int solve(int j)
{
    for (int i = 0; i < S[j].size(); i++)
    {

        int d = C[S[j][i]];
        if (!st.empty() && st.top() == -d)
            st.pop();
        else
            st.push(d);
    }
    if (!st.empty()){
        return 0;
    }
    return 1;
}

int main()
{

    input();

    for (int i = 0; i < n; i++)
    {
        if (solve(i)) cout << 1 << "\n";
        else cout << 0 << "\n";
    }
    
    return 0;
}