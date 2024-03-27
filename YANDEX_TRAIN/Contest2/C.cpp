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
    ll sum = 0;
    ll n;
    cin >> n;
    vector<ll> vec = vector<ll>(n);
    ll mx = -INF;
    int ind = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> vec[i];
        if(vec[i] > mx)
        {
            mx = vec[i];
            ind = i;
        }
        sum += vec[i];
    }
    ll sum2 = 0;
    for(int i = 0; i < n; i++)
    {
        if(i != ind)
            sum2 += vec[i];
    }
    ll delta = mx - sum2;
    if(delta > 0)
        cout << mx - sum2;
    else
        cout << sum;


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