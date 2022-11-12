#include <iostream>

#include <vector>
#include <list>
using namespace std;
// std::vector<int> sapxepVecto(std::vector<int> v)
// {
//     for (int i = 0; i < v.size(); i++)
//     {
//         for (int j = 0; j < v.size(); j++)
//         {
//             if (v[i] > v[j])
//             {
//                 int tmp = v[i];
//                 v[i] = v[j];
//                 v[j] = tmp;
//             }
//         }
//     }

//     return v;
// }

int main()
{
    // Vector
    // vector<int> a;

    // a.push_back(1);
    // a.push_back(2);
    // a.push_back(3);

    // vector<int>::iterator p;

    // for (p = a.begin(); p != a.end(); p++)
    // {
    //     if (*p == -4)
    //     {
    //         *p = 1;
    //     }

    // }
    // for (p = a.begin(); p != a.end(); p++)
    // {
    //     cout << *p << "\n";
    // }

    // a.resize(1);
    // a.resize(5, 6);

    // for (auto x : a)
    // {
    //     cout << x << " ";
    // }
    // a = sapxepVecto(a);
    // // }
    // for (auto x : a)
    // {
    //     cout << x << "\n";
    // }

    //************

    // List : danh sach noi kep

    list<int> a;
    for (int i = 1; i <= 20; i++)
    {
        a.push_back(i);
    }
    

    // for (list<int>::iterator it = a.begin(); it != a.end(); it++)
    // {
    //     cout << *it << " ";
    // }
    // cout << "\n";

    // vector<int> re(a.begin(), a.end());

    // for (auto x : re)
    // {
    //     cout << x << "\n";
    // }

    // cout << "\n";


    list<int>::iterator it = a.begin();

    cout << *it;
    advance(it, 3);
    cout << *it;

}