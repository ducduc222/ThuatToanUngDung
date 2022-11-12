#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
map<ii, int> m;
queue<ii> q;

int a, b, c;

int solve()

{
    int step = 0;
    while (!q.empty())
    {
        ii u = q.front();
        q.pop();
        int x = u.first;
        int y = u.second;

        if (m.find(u) == m.end())
        {
        cout << "{" << x << "," << y << "}\n";
            if (x != 0)
            {
                q.push(make_pair(0, y));
            }

            if (x < a)
            {
                q.push(make_pair(a, y));
            }

            if (x != 0 && y < b)
            {
                if (x + y >= b)
                {
                    int d = b - y;
                    q.push(make_pair(x - d, y + d));

                    if (x - d == c || y + d == c)
                        return c;
                }
                else
                {

                    q.push(make_pair(0, y + x));

                    if (y + x == c)
                        return c;
                }
            }

            if (y != 0)
            {
                q.push(make_pair(x, 0));
            }

            if (y < b)
            {
                q.push(make_pair(x, b));
            }

            if (y != 0 && x < a)
            {
                if (x + y >= a)
                {
                    int d = a - x;
                    q.push(make_pair(x + d, y - d));

                    if (x + d == c || y - d == c)
                        return c;
                }
                else
                {

                    q.push(make_pair(x + y, 0));

                    if (y + x == c)
                        return c;
                }
            }
        }

        m.insert({make_pair(x, y), 1});
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b >> c;
    if (a > b)
    {
        int tmp = b;
        a = b;
        b = tmp;
    }
    q.push(make_pair(0, 0));

    int t = solve();
    cout << "\n"
         << t << "\n";

    return 0;
}