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

template<typename T>
void _hash_combine (size_t& seed, const T& val)
{
    seed ^= std::hash<T>()(val) + 0x9e3779b9 + (seed<<6) + (seed>>2);
}

template<typename... Types>
size_t hash_combine (const Types&... args)
{
    size_t seed = 0;
    (_hash_combine(seed,args) , ... );
    return seed;
}

struct Spichka
{
    int x, y;
    int x1, y1;
    //вызвать при создании
    //исключить совпадения
    void orient_right()
    {
        bool change = false;
        //пусть будет вверх
        if(this->x == this->x1 && this->y > this->y1)
        {
            change = true;
        }
        else if(this->x > this->x1)
        {
            change = true;
        }
        if(change)
        {
            swap(this->x, this->x1);
            swap(this->y, this->y1);
        }
    }
    bool egual_length(Spichka& s1)
    {
        return this->x-this->x1 == s1.x-s1.x1 && 
                this->y-this->y1 == s1.y-s1.y1;
    }    
};


struct VecGo
{
    int x,y;
    bool operator ==(const VecGo& rl) const
    {
        return this->x == rl.x && this->y == rl.y;
    }
};
struct VecGoHash
{
    std::size_t operator() (const VecGo& p) const
    {
        return hash_combine(p.x, p.y);
    }
};


void solve()
{
    // let's go kid
    int n;
    cin >> n;
    vector<Spichka> sp1 = vector<Spichka>(n);
    vector<Spichka> sp2 = vector<Spichka>(n);
    for(int i = 0; i < n; i++)
    {
        int x,y,x1,y1;
        cin >> x >> y >> x1 >> y1;
        sp1[i] = {x,y,x1,y1};
        sp1[i].orient_right();
    }
    for(int i = 0; i < n; i++)
    {
        int x,y,x1,y1;
        cin >> x >> y >> x1 >> y1;
        sp2[i] = {x,y,x1,y1};
        sp2[i].orient_right();
    }
    unordered_map<VecGo, int, VecGoHash> attempts = {};
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(sp1[i].egual_length(sp2[j]))
            {
                VecGo v = {sp1[i].x - sp2[j].x, sp1[i].y - sp2[j].y};
                if(attempts.contains(v))
                    attempts[v]++;
                else
                    attempts[v] = 1;
            }
        }
    }
    int mn = n;
    for(auto x : attempts)
    {
        mn = min(mn, n - x.second);
    }
    cout << mn;
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