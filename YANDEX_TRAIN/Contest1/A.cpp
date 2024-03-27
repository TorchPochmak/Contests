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
    ll a, a_len;
    ll b, b_len;
    // a < b
    cin >> a >> a_len >> b >> b_len;
    if(a > b)
    {
        swap(a, b);
        swap(a_len, b_len);
    }
    ll min_tree = min(a - a_len, b - b_len);
    ll max_tree = max(a + a_len, b + b_len);
    ll distance = (b - b_len) - (a + a_len);
    if(distance <= 1)
    {
        cout << max_tree - min_tree + 1;
    }  
    else
    {
        cout << max_tree - min_tree - (distance - 1) + 1;
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