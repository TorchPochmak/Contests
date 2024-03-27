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
    ll n, k, d;
    cin >> n >> k >> d;
    string res = to_string(n);
    //Да, можно вычислить остаток, но мне слишком лень
    ll new_n = 0;
    bool worked = false;
    for(int i = 0; i <= 9; i++)
    {
        new_n = n * 10 + i;
        if(new_n % k == 0)
        {
            worked = true;
            break;
        }
    }
    if(!worked)
    {
        cout << -1;
        return;
    }
    cout << new_n;
    for(int i = 0; i < d - 1; i++)
    {
        cout << 0;
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