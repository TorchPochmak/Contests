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
    int k;
    cin >> k;
    vector<int> vec = vector<int>(n, 0);
    for(int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    set<int> st = {};
    if(k >= n - 1)
    {
        for(int i = 0; i < n; i++)
        {
            if(st.contains(vec[i]))
            {
                cout << "YES";
                return;
            }
            else
                st.insert(vec[i]);
        }
        cout << "NO";
        return;
    }
    else
    {
        for(int i = 0; i < k; i++)
        {
            if(st.contains(vec[i]))
            {
                cout << "YES";
                return;
            }
            else
                st.insert(vec[i]);
        }
        for(int j = k; j < n; j++)
        {   
            if(st.contains(vec[j]))
            {
                cout << "YES";
                return;
            }
            else
                st.insert(vec[j]);
            st.erase(vec[j - k]);
        }
        cout << "NO";
        return;
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
