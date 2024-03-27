#include <iostream>
#include <vector>
#include <algorithm>

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;

const ll INF = 1e18;
const int INF_int = 1e9;
const ll MOD = 1e9 + 7;
const double PI = acos(-1.0);

double __speedstart__;
#define SPEEDTEST_START __speedstart__ = clock();
#define SPEEDTEST_STOP cout << "Process finished in: " << (double)(clock() - __speedstart__)/CLOCKS_PER_SEC << " seconds";
#define fastboi ios::sync_with_stdio(false); cin.tie(0);

struct S
{
    ll a;
    ll delta;
    int ind;
};

int comp(S a, S b)
{
    return a.delta > b.delta;
}
void solve()
{
    // let's go kid
    int n;
    cin >> n;
    vector<S> pluses = {};
    vector<S> minuses = {};
    S max_a_min;
    S max_a_plus;
    max_a_min.a = max_a_plus.a = LLONG_MIN;
    max_a_min.delta = max_a_plus.delta = LLONG_MIN;
    ll delta_sum = 0;
    S tmp;
    for(int i = 0; i < n; ++i)
    {
        cin >> tmp.a >> tmp.delta;
        tmp.delta = tmp.a - tmp.delta;
        tmp.ind = i;
        cout << max_a_plus.delta << 'l'<<'\n';
        if (tmp.delta > 0)
        {
            
            cout << max_a_plus.delta << 'l'<<'\n';
            delta_sum += tmp.delta;
            if (tmp.a > max_a_plus.a) 
            {
                if (max_a_plus.delta != LLONG_MIN) pluses.push_back(max_a_plus);
                max_a_plus = tmp;
            }
            else pluses.push_back(tmp);
        }
        else
        {
            if (tmp.a > max_a_min.a) 
            {
                if (max_a_min.delta != LLONG_MIN) minuses.push_back(max_a_min);
                max_a_min = tmp;
            }
            else minuses.push_back(tmp);
        }
    }
    cout << max_a_plus.delta << 'l'<<'\n';
    pluses.push_back(max_a_plus);
    ll best = max_a_min.a, index = max_a_min.ind;
    S* to_remove;
    for (int i = 0; i < pluses.size(); ++i)
    {
        if (delta_sum - pluses[i].delta > best)
        {
            best = delta_sum - pluses[i].delta;
            index = pluses[i].ind;
            to_remove = &pluses[i];
        }
    }
    tmp = *to_remove;
    *to_remove = pluses[pluses.size()-1];
    pluses[pluses.size()-1] = tmp;

    for(int i = 0; i < pluses.size(); ++i)
    {
        cout << pluses[i].ind << ' ';
    }
    cout << index << ' ';
    for(int i = 0; i < minuses.size(); ++i)
    {
        cout << minuses[i].ind << ' ';
    }
    cout << endl;
    return;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    fastboi

    //SPEEDTEST_START
    solve();
    //SPEEDTEST_STOP
}