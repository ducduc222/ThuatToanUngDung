#include <bits/stdc++.h>
#define MAX 10000
using namespace std;

int m;            // số teachers
int n;            // số môn học
int T[MAX];       // số khóa học mà giáo viên i có thể dạy
list<int> C[MAX]; // Danh sách khóa học mà giáo viên i dạy
int l[MAX];       // số môn học đang được phân công cho giáo viên i
int p;            // số cặp môn không thể dạy cùng 1 cô
int D[MAX][MAX];  // các cặp môn trùng nhau
int s = 0;        // số môn đã được phân công
int l_min = MAX;  // lưu giá trị load nhỏ nhất
list<int> H;      // các môn học được giảng dạy
list<int> Z[MAX]; // lưu các môn học mà giáo viên Z[i] đã được phân công

void input()
{
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        cin >> T[i];
        for (int j = 1; j <= T[i]; j++)
        {
            int t;
            cin >> t;
            C[i].push_back(t);
        }
    }

    cin >> p;
    int u, v;
    for (int i = 1; i <= p; i++)
    {
        cin >> u >> v;
        D[u][v] = 1;
        D[v][u] = 1;
    }
}

int check(int k, int i)
{
    // check số môn còn lại < n
    if (s + 1 > n)
        return 0;
    // số môn còn lại của k < T[k]
    if (Z[k].size() + 1 > T[k])
        return 0;
    // môn i có trong C chưa (có thể dạy)
    list<int>::iterator it = find(C[k].begin(), C[k].end(), i);
    if (it == C[k].end())
        return 0;
    // môn i đã có trong Z chưa (môn đã phân công)

    list<int>::iterator it1 = find(Z[k].begin(), Z[k].end(), i);
    if (it1 != Z[k].end())
        return 0;

    // môn i có bị trùng trong D không
    for (list<int>::iterator t = Z[k].begin(); t != Z[k].end(); t++)
    {
        if (D[i][*t] == 1 || D[*t][i] == 1)
            return 0;
    }

    return 1;
}

int solution()
{
    int max = 0;
    for (int i = 1; i <= m; i++)
    {
        if (l[i] > max)
            max = l[i];
    }

    return max;
}

void TRY(int k)
{
    for (list<int>::iterator it = C[k].begin(); it != C[k].end(); it++)
    {
        int v = *it;
        list<int>::iterator itN = it++;
        if (check(k, v))
        {
            s += 1;
            C[k].erase(it);
            Z[k].push_back(v);
            l[k]++;

            if (k == m)
            {
                if (l_min > solution())
                    l_min = solution();
            }
            else
            {
                if (l[k] > l_min)
                    TRY(k + 1);
            }

            it = itN;
            s -= 1;
            C[k].push_front(v);
            Z[k].pop_back();
            l[k]--;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    input();
    TRY(1);
    cout << l_min << "\n";
}