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
    ll a_last, b_last;
    ll a_now, b_now;
    scanf("%lld:%lld\n", &a_last, &b_last);
    scanf("%lld:%lld\n", &a_now, &b_now);
    ll a_sum = a_last + a_now;
    ll b_sum = b_last + b_now;
    ll delta = b_sum - a_sum;
    if(delta < 0)
    {
        cout << 0;
        return;
    }
    int at_home;
    cin >> at_home;
    if(at_home == 2)
    {
        //ure at home
        ll delta_guest = a_last - b_now;
        if(delta_guest <= 0)
            delta++;
    }
    else
    {
        //a is guest now
        ll delta_guest = (a_now + delta) - b_last;
        if(delta_guest <= 0)
            delta++;
    }
    cout << delta;
}
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // fastboi

    //SPEEDTEST_START
    solve();
    //SPEEDTEST_STOP
}