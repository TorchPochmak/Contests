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


int mn = INT_MAX;
//две стратегии: сначала убить солдат, потом казарму
//либо сначала казарму, потом солдат
void rec(int my, int hp, int enemy, int enemy_spawn, int steps, bool my_turn)
{
    if(enemy < 0)
        enemy = 0;
    if(hp < 0)
        hp = 0;
    if(enemy <= 0 && hp <= 0)
    {
        mn = min(mn, steps);
        return;
    }
    if(my <= 0)
        return;
    if(my_turn)
    {
        //сначала казарму
        //нет смысла ее сначала бить, если есть враги
        if(hp > my && enemy == 0)
        {
            rec(my, hp - my, enemy, enemy_spawn, steps + 1, false);
            return;
        }
        else if (hp <= my)
        {
            int remain = my - hp;
            rec(my, 0, enemy - remain, enemy_spawn, steps + 1, false); 
        }

        //сначала не казарму
        if(enemy >= my && hp <= 0)
        {
            //probably dead tactic, if hp != 0
            rec(my, hp, enemy - my, enemy_spawn, steps + 1, false);
        }
        else if (enemy < my)
        {
            int remain = my - enemy;
            rec(my, hp - remain, 0, enemy_spawn, steps + 1, false);
        }
        else
            return;
    }
    else
    {
        int add = hp == 0 ? 0 : enemy_spawn;
        rec(my - enemy, hp, enemy + add, enemy_spawn, steps, true);
        
    }
}

void solve()
{
    int my, hp, enemy_spawn;
    cin >> my >> hp >> enemy_spawn;
    
    rec(my, hp, 0, enemy_spawn, 0, true);
    if(mn == INT_MAX)
        cout << "-1";
    else
        cout << mn;
}
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    fastboi
    
    solve();
}