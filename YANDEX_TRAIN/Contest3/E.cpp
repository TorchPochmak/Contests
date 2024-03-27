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

void input_set(set<int>& st)
{
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        st.insert(num);
    }
}

void solve()
{
    // let's go kid
    set<int> st1 = {}, st2 = {}, st3 = {};
    input_set(st1);
    input_set(st2);
    input_set(st3);
    map<int, int> mp = {};
    for(auto el : st1)
    {
        mp[el]++;
    }
    for(auto el : st2)
    {
        mp[el]++;
    }
    for(auto el : st3)
    {
        mp[el]++;
    }
    for(auto el : mp)
    {
        if (el.second >= 2)
            cout << el.first << ' ';
    }
}
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    fastboi

    // SPEEDTEST_START
    solve();
    // SPEEDTEST_STOP
}