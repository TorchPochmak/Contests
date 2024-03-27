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
    cin >> n;
    map<string, int> mp = {};
    for(int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        for(int j = 0; j < k; j++)
        {
            string s;
            cin >> s;
            if(mp.contains(s))
                mp[s]++;
            else
                mp[s] = 1;
        }
    }
    int nums = 0;
    for(auto el : mp)
    {
        if(el.second == n)
        {
            nums++;
        }
    }
    cout << nums << '\n';
    for(auto el : mp)
    {
        if(el.second == n)
        {
            cout << el.first << ' ';
        }
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