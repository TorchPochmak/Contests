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

struct Point
{
    int x, y;

    bool operator<(const Point& rl) const
    {
        if(this->x == rl.x)
            return this->y < rl.y;
        return this->x < rl.x;
    }
    bool operator ==(const Point& rl) const
    {
        return this->x == rl.x && this->y == rl.y;
    }
};
struct PointHash
{
    std::size_t operator() (const Point& p) const
    {
        return hash_combine(p.x, p.y);
    }
};



void solve()
{
    // let's go kid
    int n;
    cin >> n;
    vector<Point> vec = vector<Point>(n, {0,0});
    unordered_set<Point, PointHash> st = {};
    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        Point point{x,y};
        vec[i] = point;
        st.insert(point);
    }
    if(n == 1)
    {
        cout << 3 << '\n';
        cout << vec[0].x + 1 << ' ' << vec[0].y << '\n';
        cout << vec[0].x + 1 << ' ' << vec[0].y + 1 << '\n';
        cout << vec[0].x << ' ' << vec[0].y + 1 << '\n';
        return;
    }
    //4
    int mx_points = 0;
    Point rem1{0,0};
    Point rem2{0,0};
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            //if sosedi
            int delta_y = abs(vec[i].y - vec[j].y);
            int delta_x = abs(vec[i].x - vec[j].x);
            Point main_v{vec[j].x - vec[i].x, vec[j].y - vec[i].y};
            Point main90{main_v.y, -main_v.x};

            Point new_1 {vec[i].x + main90.x, vec[i].y + main90.y};
            Point new_2 {new_1.x + main_v.x, new_1.y + main_v.y};

            Point main90_2 = {-main_v.y, main_v.x};
            Point new_11 {vec[i].x + main90_2.x, vec[i].y + main90_2.y};
            Point new_22 {new_11.x + main_v.x, new_11.y + main_v.y};
            //if not sosedi
            Point main_v2 {0,(main_v.x + main_v.y)/2};
            main_v2.x = main_v2.y - main_v.y;
            
            Point new_3 {vec[i].x + main_v2.x, vec[i].y + main_v2.y};
            Point new_4 {vec[j].x - main_v2.x, vec[j].y - main_v2.y};
            bool able_to_diag = (main_v.x + main_v.y) % 2 == 0 ? true : false; 
            if(st.contains(new_1) && st.contains(new_2))
            {
                cout << 0;
                return;
            }
            if(st.contains(new_11) && st.contains(new_22))
            {
                cout << 0;
                return;
            }
            if(able_to_diag && st.contains(new_3) && st.contains(new_4))
            {
                cout << 0;
                return;
            }
            //
            if(st.contains(new_1) && mx_points < 3)
            {
                mx_points = 3;
                rem1.x = new_2.x;
                rem1.y = new_2.y;
            }
            if(st.contains(new_2) && mx_points < 3)
            {
                mx_points = 3;
                rem1.x = new_1.x;
                rem1.y = new_1.y;
            }
            if(st.contains(new_11) && mx_points < 3)
            {
                mx_points = 3;
                rem1.x = new_22.x;
                rem1.y = new_22.y;
            }
            if(st.contains(new_22) && mx_points < 3)
            {
                mx_points = 3;
                rem1.x = new_11.x;
                rem1.y = new_11.y;
            }
            if(able_to_diag && st.contains(new_3) && mx_points < 3)
            {
                mx_points = 3;
                rem1.x = new_4.x;
                rem1.y = new_4.y;
            }
            if(able_to_diag && st.contains(new_4) && mx_points < 3)
            {
                mx_points = 3;
                rem1.x = new_3.x;
                rem1.y = new_3.y;
            }
            //
            if(mx_points < 2)
            {
                mx_points = 2;
                rem1.x = new_1.x;
                rem1.y = new_1.y;

                rem2.x = new_2.x;
                rem2.y = new_2.y;
            }
        }
    }

    if(mx_points == 2)
    {
        cout << 2 << '\n';
        cout << rem1.x << ' ' << rem1.y << '\n';
        cout << rem2.x << ' ' << rem2.y << '\n';
    }
    else if(mx_points == 3)
    {
        cout << 1 << '\n';
        cout << rem1.x << ' ' << rem1.y;
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