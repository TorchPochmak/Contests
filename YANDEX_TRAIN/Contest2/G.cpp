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
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> vec = vector<int>(n,0);
        vector<int> ans = {};
        int counter = 0;
        int mn = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            cin >> vec[i];
        }
        for(int i = 0; i < n; i++)
        {
            int pot_mn = min(mn, vec[i]);
            if(pot_mn > counter)
            {
                counter++;
                mn = pot_mn;
            }
            else
            {
                if(counter != 0)
                    ans.push_back(counter);
                counter = 1;
                mn = vec[i]; 
            }
        }
        if(counter != 0)
            ans.push_back(counter);
        cout << ans.size() << '\n';
        for(int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << ' ';
        }
        cout << '\n';
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