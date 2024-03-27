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

bool valid(int i, int j)
{
    return i >= 0 && i < 8 && j >= 0 && j < 8;
}

void make_bishop(vector<vector<char>>& board, int i_ind, int j_ind)
{
    //NE
    for(int step = 1; step <= 8; step++)
    {
        int i = i_ind - step;
        int j = j_ind + step;
        if(valid(i, j) && board[i][j] != 'R' && board[i][j] != 'B')
        {
            board[i][j] = 'X';
        }
        else
            break;
    }
    //NW
    for(int step = 1; step <= 8; step++)
    {
        int i = i_ind - step;
        int j = j_ind - step;
        if(valid(i, j) && board[i][j] != 'R' && board[i][j] != 'B')
        {
            board[i][j] = 'X';
        }
        else
            break;
    }
    //SE
    for(int step = 1; step <= 8; step++)
    {
        int i = i_ind + step;
        int j = j_ind + step;
        if(valid(i, j) && board[i][j] != 'R' && board[i][j] != 'B')
        {
            board[i][j] = 'X';
        }
        else
            break;
    }
    //SW
    for(int step = 1; step <= 8; step++)
    {
        int i = i_ind + step;
        int j = j_ind - step;
        if(valid(i, j) && board[i][j] != 'R' && board[i][j] != 'B')
        {
            board[i][j] = 'X';
        }
        else
            break;
    }
}

void make_rook(vector<vector<char>>& board, int i_ind, int j_ind)
{
    //N
    for(int step = 1; step <= 8; step++)
    {
        int i = i_ind - step;
        int j = j_ind;
        if(valid(i, j) && board[i][j] != 'R' && board[i][j] != 'B')
        {
            board[i][j] = 'X';
        }
        else
            break;
    }
    //W
    for(int step = 1; step <= 8; step++)
    {
        int i = i_ind;
        int j = j_ind - step;
        if(valid(i, j) && board[i][j] != 'R' && board[i][j] != 'B')
        {
            board[i][j] = 'X';
        }
        else
            break;
    }
    //S
    for(int step = 1; step <= 8; step++)
    {
        int i = i_ind + step;
        int j = j_ind;
        if(valid(i, j) && board[i][j] != 'R' && board[i][j] != 'B')
        {
            board[i][j] = 'X';
        }
        else
            break;
    }
    //E
    for(int step = 1; step <= 8; step++)
    {
        int i = i_ind;
        int j = j_ind + step;
        if(valid(i, j) && board[i][j] != 'R' && board[i][j] != 'B')
        {
            board[i][j] = 'X';
        }
        else
            break;
    }
}


void solve()
{
    // let's go kid
    vector<vector<char>> board = vector<vector<char>>(8, vector<char>(8, ' '));
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            cin >> board[i][j];
        }
    }
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(board[i][j] == 'B')
                make_bishop(board, i, j);
            else if(board[i][j] == 'R')
                make_rook(board, i, j);
        }
    }
    int counter = 0;
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(board[i][j] == '*')
                counter++;
        }
    }
    cout << counter;
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