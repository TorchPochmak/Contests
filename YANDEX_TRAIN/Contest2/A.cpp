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
    int min_x = INT_MAX, min_y = INT_MAX, 
    max_x = INT_MIN, max_y = INT_MIN;

    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        int x,y;
        cin >> x >> y;
        min_x = min(x, min_x);
        min_y = min(y, min_y);
        max_x = max(max_x, x);
        max_y = max(max_y, y);
    }
    cout << min_x << " " <<  min_y << " " << max_x << " " << max_y; 
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