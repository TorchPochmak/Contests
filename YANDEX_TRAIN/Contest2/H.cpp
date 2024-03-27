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

void get_max(vector<vector<int>>& matr, int n, int m,
    int& ind_i, int& ind_j, int& mx)
{
    mx = matr[0][0];
    ind_i = 0;
    ind_j = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(matr[i][j] > mx)
            {
                mx = matr[i][j];
                ind_i = i;
                ind_j = j;
            }
        }
    }
}
void clean(vector<vector<int>>& matr, int n, int m, int x, bool is_row)
{
    if(is_row)
    {
        for(int j = 0; j < m; j++)
            matr[x][j] = -1;
    }
    else
    {
         for(int j = 0; j < n; j++)
            matr[j][x] = -1;
    }
}

void solve()
{
    // let's go kid
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matr = vector<vector<int>>(n, vector<int>(m));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> matr[i][j];
        }
    }
    //две стратегии
    //сначала вычеркиваем строку


    int mx = INT_MIN;
    int ans_i = 0, ans_j = 0;

    int mx2 = INT_MIN;
    int ans_i2 = 0, ans_j2 = 0;

    int ind_i = 0, ind_j = 0;
    int ind_i2 = 0, ind_j2 = 0;
    vector<vector<int>> matr2 = matr;
    get_max(matr, n, m, ind_i, ind_j, mx);
    clean(matr, n, m, ind_i, true);
    get_max(matr, n, m, ind_i2, ind_j2, mx);
    clean(matr, n, m, ind_j2, false);
    ans_i = ind_i;
    ans_j = ind_j2;

    
    get_max(matr2, n, m, ind_i, ind_j, mx2);
    clean(matr2, n, m, ind_j, false);
    get_max(matr2, n, m, ind_i2, ind_j2, mx2);
    clean(matr2, n, m, ind_i2, true);
    ans_i2 = ind_i2;
    ans_j2 = ind_j;

    get_max(matr, n, m, ind_i, ind_j, mx);
    get_max(matr2, n, m, ind_i, ind_j, mx2);

    if(mx < mx2)
    {
        cout << ans_i + 1 << ' ' << ans_j + 1;
    }
    else
    {
        cout << ans_i2 + 1 << ' ' << ans_j2 + 1;
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