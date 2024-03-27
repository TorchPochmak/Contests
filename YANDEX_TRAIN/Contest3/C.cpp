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
    ll n;
    cin >> n;
    vector<ll> vec = vector<ll>(10e5 + 1, 0);
    for(int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        vec[num]++;
    }
    if(n <= 2)
    {
        cout << 0;
        return;
    }
    ll ind = 0;
    ll mx = INT_MIN;
    for(int i = 0; i < 10e5 + 1; i++)
    {
        if(vec[i] + vec[i + 1] > mx)
        {
            mx = vec[i] + vec[i + 1];
            ind = i;
        }
    }
    ll sm = 0;
    for(int i = 0; i < 10e5 + 1; i++)
    {
        if(i < ind || i > ind + 1)
        {
            sm += vec[i];
        }
    }
    cout << sm;
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