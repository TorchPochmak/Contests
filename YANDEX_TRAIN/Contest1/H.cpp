#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;

const double EPS = 1e-10;
const ll INF = 1e18;
const int INF_int = 1e9;
const ll MOD = 1e9 + 7;
const double PI = acos(-1.0);

double __speedstart__;
#define SPEEDTEST_START __speedstart__ = clock();
#define SPEEDTEST_STOP cout << "Process finished in: " << (double)(clock() - __speedstart__)/CLOCKS_PER_SEC << " seconds";
#define fastboi ios::sync_with_stdio(false); cin.tie(0);

bool check(int k, double mult, double plus) {
    double res = plus + (double)k * mult;
	return !(res > 0 || abs(res) < EPS);//some formula
}

//00000000000000001111111111111111
//               lr
// 

double get_time(double mult, double plus)
{
    if(plus > 0)
        return plus;
    bool OK = true;
    if(mult < 0)
        OK = false;
    int l = -1e9;
    int r = 1e9;
    int m = r;
    while (r - l > 1) {
        m = (l + r) / 2;
        bool target = true;
        if(OK)
            target = check(m, mult, plus);
        else
            target = !check(m, mult, plus);
        if (target) {
            l = m;
        }
        else {
            r = m;
        }
    }
    if(OK)
        return plus + (double)r * mult;
    else
        return plus + (double)l * mult;
}

void solve()
{
    cout << fixed << setprecision(10);
    // let's go kid
    double L, x1, v1, x2, v2;
    cin >> L >> x1 >> v1 >> x2 >> v2;

    if(x1 == x2 || L - x1 == x2 || L - x2 == x1)
    {
        cout << "YES\n" << 0;
        return;
    }
    double t1 = v2 + v1 != 0 ? get_time(L/(v2+v1), (L-x1-x2)/(v2+v1)) : 1e12;
    double t2 = v2 != v1 ? get_time(L/(v2-v1), (x1-x2)/(v2-v1)) : 1e12;
    double mn = min(t1, t2);
    if(abs(mn - 1e12) < EPS)
    {
        cout << "NO";
    }
    else
    {
        cout << "YES\n";
        cout << mn;
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
