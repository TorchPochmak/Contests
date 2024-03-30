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

bool check(ull n, ull k)
{
    ull z = (k) * (k + 1) * (k + 2) / 6 + k * (k + 1) / 2 - 1;
    //bool bigger = z > 1e18;
    return z <= n;
}
//11111111111100000000000000
void solve()
{
    // let's go kid
    ull n;
    cin >> n;
    if(n == 0) cout << 0;
	else if (n == 1) cout << 1;
	else 
    {
		ull l = 1;
		ull r = 1e7;
		ull m = r;
		while (r - l > 1) {
			m = (l + r) / 2;
			if (check(n, m)) {
				l = m;
			}
			else {
				r = m;
			}
		}
		cout << l;
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