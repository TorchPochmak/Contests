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
    vector<vector<int>> matr = vector<vector<int>>(n, vector<int>(n, 0));
    for(int q = 0; q < n; q++)
    {
        int i, j;
        cin >> i >> j;
        matr[i - 1][j - 1] = 1;
    }
    int mn = INT_MAX;
    //первое, что в голову пришло. Ну да, за куб...
    for(int q = 0; q < n; q++)
    {
        int sm = 0;
        //q - j
        int counter = 0;//i
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(matr[i][j] == 1)
                {
                    sm += abs(i - counter) + abs(q - j);
                    counter++;
                }
            }
        }
        mn = min(sm, mn);
    }
    cout << mn;
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