#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

const ll INF = 1e18;
const int INF_int = 1e9;
const ll MOD = 1e9 + 7;
const double PI = acos(-1.0);

double __speedstart__;
#define SPEEDTEST_START __speedstart__ = clock();
#define SPEEDTEST_STOP cout << "Process finished in: " << (double)(clock() - __speedstart__)/CLOCKS_PER_SEC << " seconds";
#define fastboi ios::sync_with_stdio(false); cin.tie(0);

int draw_rect(vector<vector<char>>& matr, int ii, int jj, int height, int length, char ch)
{
    for(int i = ii; i < ii + height; i++)
    {
        for(int j = jj; j < jj + length; j++)
        {
            if(matr[i][j] == '#')
                matr[i][j] = ch;
            else
                return 1;
        }
    }
    return 0;
}
int all_clear(vector<vector<char>>& matr, int ii, int jj, int n, int m)
{
    for(int i = ii; i < n; i++)
    {
        for(int j = jj; j < m; j++)
        {
            if(matr[i][j] == '#')
                return 1;
        }
    }
    return 0;
}
int draw(vector<vector<char>>& matr, int min_i, int min_j, int n, int m, char ch)
{
    int height = 0, length = 0;
    for(int i = min_i; i < n; i++)
    {
        for(int j = min_j; j < m; j++)
        {
            if(matr[i][j] == '#')
            {
                //ЗАКРАСИТЬ
                int height = 0, length = 0;
                while(i + height < n && matr[i + height][j] == '#')
                    height++;
                while(j + length < m && matr[i][j + length] == '#')
                    length++;
                int status_code = draw_rect(matr, i, j, height, length, ch);
                if(status_code)
                    return status_code;
                return all_clear(matr, min_i, min_j, n, m);
            }   
        }
    }
    return 1;
}

int try_divide(vector<vector<char>>& matrix, int n, int m, int border, bool is_vertical)
{
    if(is_vertical)
    {
        vector<vector<char>> matr = matrix;
        //dividing m
        int errors = 0;
        errors = draw(matr, 0, 0, n, border, 'a');
        if(!errors)
        {
            errors = draw(matr, 0, border, n, m, 'b');
            if(!errors)
            {
                matrix = matr;
                return 0;
            }
        }
        return 1;

    }
    else
    {
        vector<vector<char>> matr = matrix;
        //dividing m
        int errors = 0;
        errors = draw(matr, 0, 0, border, m, 'a');
        if(!errors)
        {
            errors = draw(matr, border, 0, n, m, 'b');
            if(!errors)
            {
                matrix = matr;
                return 0;
            }
        }
        return 1;
    }
    return 0;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> matrix = vector<vector<char>>(n, vector<char>(m, 0));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }
    bool errors;
    for(int i = 1; i < n; i++)
    {
        errors = try_divide(matrix, n, m, i, false);
        if(!errors)
        {
            //GG
            cout << "YES\n";
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < m; j++)
                {
                    cout << matrix[i][j];
                }
                cout << '\n';
            }
            return;
        }
    }
    for(int j = 1; j < m; j++)
    {
        errors = try_divide(matrix, n, m, j, true);
        if(!errors)
        {
            //GG
            cout << "YES\n";
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < m; j++)
                {
                    cout << matrix[i][j];
                }
                cout << '\n';
            }
            return;
        }
    }
    cout << "NO";
}
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    fastboi

    //SPEEDTEST_START
    solve();
   // SPEEDTEST_STOP
}