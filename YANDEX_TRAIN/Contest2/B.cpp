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

void solve()
{
    // let's go kid
    int n;
    int k;
    cin >> n >> k;
    int mn = INT_MAX, mx = INT_MIN;
    vector<int> vec = vector<int>(n,0);
    for(int i = 0; i < n; ++i)
    {
        cin >> vec[i];
    }
    //предподсчет
    {
        int max_delta = INT_MIN;
        for(int param = 0; param <= k; param++)
        {
            int del = INT_MIN;
            for(int i = 0; i + param < n; i++)
            {
                del = max(del, vec[param + i] - vec[i]);
            }
            max_delta = max(del, max_delta);
        }
        cout << max(0, max_delta);
    }
}
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    fastboi

    //SPEEDTEST_START
    solve();
    //SPEEDTEST_STOP
}