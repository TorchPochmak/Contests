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

ll mod(ll a, ll b) {
	return (a % b + b) % b;
}

void solve()
{
    // let's go kid
    int n;
    cin >> n;
    ll num1;
    cin >> num1;
    if(mod(num1, 2) == 0)
    {
        int cnt_sums = 1;
        //even begin
        //three or two sums: 0*0 + 1*1 or 0*0 + 1*1 + 0******
        for(int i = 0; i < n - 1; i++)
        {
            ll num;
            cin >> num;
            if(cnt_sums == 1) //even
            {
                if(mod(num, 2) == 0)
                    cout << 'x';
                else
                {
                    cout << '+';
                    cnt_sums = 2;
                }
            }
            else if(cnt_sums == 2)//odd
            {
                if(mod(num, 2) == 0)
                {
                    cout << '+';
                    cnt_sums = 3;
                }
                else
                {
                    cout << 'x';
                }
            }
            else//even
            {
                cout << 'x';
            }
        }
    }
    else
    {
        //odd begin
        //two sums: 1*1*1*1 or 1*1*1 + 0************
        int cnt_sums = 1;
        for(int i = 0; i < n - 1; i++)
        {
            ll num;
            cin >> num;
            if(cnt_sums == 1)
            {
                if(mod(num, 2) == 0)
                {
                    cout << '+';
                    cnt_sums = 2;
                }
                else
                    cout << 'x';
            }
            else if(cnt_sums == 2)
            {
                cout << 'x';
            }
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