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

struct S
{
    ll a;
    ll delta;
    int ind;
};

int comp(S a, S b)
{
    if (a.delta < 0 && b.delta < 0)
        return a.a > b.a;
    else
        return a.delta >= b.delta;

}
void solve()
{
    // let's go kid
    int n;
    cin >> n;
    vector<S> vec = {};
    ll max_height;
    int mx_ind = 0;
    ll mx = INT_MIN;
    ll mx_del = -1;
    for(int i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        ll delta = a - b;
        vec.push_back({a, delta, i});
        
    }
    int last_zero = 0;
    sort(vec.begin(), vec.end(), comp);
    //-------
    ll sum = 0;
    int neg_ind = n;
    int neotr_ind = 0;
    for(int i = 0; i < n; i++)
    {
        if(vec[i].delta < 0)
        {
            neg_ind = i;
            break;
        }
        else
        {
            sum += vec[i].delta;
            neotr_ind = i;
        }
    }
    ll sum_max = INT_MIN;
    int GOOD_ind = 0;
    //нет отрицательных
    for(int i = 0; i <= neotr_ind; i++)
    {
        if(neg_ind == 0)
            break;
        if(sum + vec[i].a - vec[i].delta > sum_max)
        {
            sum_max = sum + vec[i].a - vec[i].delta;
            GOOD_ind = i;
        }
    }
    if(GOOD_ind != neotr_ind && neg_ind != 0)
    {
        swap(vec[neotr_ind], vec[GOOD_ind]);
    }
    if(neg_ind != n)
    {
        if(sum + vec[neg_ind].a > sum_max)
            sum_max = sum + vec[neg_ind].a;
    }
    cout << sum_max << '\n';
    for(int i = 0; i < n; i++)
    {
        cout << vec[i].ind + 1 << ' ';
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