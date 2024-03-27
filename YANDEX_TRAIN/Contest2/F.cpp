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

int get_max(vector<int>& vec, int min_i, int max_i)
{
    int mx = INT_MIN;
    for(int i = min_i; i % vec.size() != max_i; i++)
        mx = max(mx, vec[i % vec.size()]);
    mx = max(mx, vec[max_i]);
    return mx;
}
void solve()
{
    // let's go kid
    ll n;
    cin >> n;
    vector<int> vec = vector<int>(n,0);
    vector<int> rev = vector<int>(n, 0);
    for(int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    rev = vec;
    if(rev.size() != 1)
        reverse_copy(vec.begin() + 1, vec.end(), rev.begin() + 1);
    ll a, b, k;
    cin >> a >> b >> k;
    if((b - a) > (n - 1) * k)
    {
        cout << get_max(vec, 0, vec.size() - 1);
    }
    else
    {

        int ind_min = (a % (n*k));
        int ind_max = (b % (n*k));
        if (ind_min == 0) ind_min = n-1;
        else if (ind_min % k) ind_min = ind_min / k;
        else ind_min = ind_min / k - 1;
        if (ind_max == 0) ind_max = n-1;
        else if (ind_max % k) ind_max = ind_max / k;
        else ind_max = ind_max / k - 1;
        cout << max(get_max(vec, ind_min, ind_max), get_max(rev, ind_min, ind_max));
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