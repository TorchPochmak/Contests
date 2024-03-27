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
    set<tuple<int, int, int, int>> st = {};
    for(int i = 0; i < n; i++)
    {
        int x;
        int y;
        cin >> x >> y;
        tuple<int, int, int, int> t1 = {x-1, y-1, x-1, y};
        tuple<int, int, int, int> t2 = {x-1, y-1, x, y-1};
        tuple<int, int, int, int> t3 = {x, y-1, x, y};
        tuple<int, int, int, int> t4 = {x-1, y, x, y};

        if(st.contains(t1))
            st.erase(t1);
        else
            st.insert(t1);
        if(st.contains(t2))
            st.erase(t2);
        else
            st.insert(t2);
        if(st.contains(t3))
            st.erase(t3);
        else
            st.insert(t3);
        if(st.contains(t4))
            st.erase(t4);
        else
            st.insert(t4);
    }
    cout << st.size();

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