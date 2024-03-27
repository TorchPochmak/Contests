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


const vector<string> months = {"January", "February", "March", "April", "May", 
        "June", "July", "August", "September", "October", "November", "December"};
const vector<int> days_month = {31, 28, 31, 30, 31, 
    30, 31, 31, 30, 31, 30, 31};
const vector<string> week = {"Monday", "Tuesday", "Wednesday",
    "Thursday", "Friday", "Saturday", "Sunday"};

//Начинает считать с нуля
int parse_month(string s)
{
    int res = 0;
    for(int i = 0; i < months.size(); i++)
        if(months[i] == s)
            res = i;
    return res;
}
int parse_week(string s)
{
    int res = 0;
    for(int i = 0; i < week.size(); i++)
        if(week[i] == s)
            res = i;
    return res;
}

void add_day(int num, string mon, vector<int>& days, int delta, bool leap)
{
    //1 jan == 0 + delta
    int month = parse_month(mon);
    int days_delta = 0;
    for(int i = 0; i < month; i++)
    {
        days_delta += days_month[i];
        if(i == 1 && leap)
            days_delta += 1;
    }
    days_delta += num - 1;
    days_delta += delta;

    days[days_delta % 7]++;
}

void solve()
{
    
    
    //1 january 1800 - wednesday
    // let's go kid
    int n;
    cin >> n;
    int year;
    cin >> year;
    ll days = 0;
    //Первый день недели интересующего года
    bool is_unique = false;
    vector<int> all_days = vector<int>(7,0);
    vector<int> celeb_days = vector<int>(7,0);
    if(year % 4 == 0)
    {
        if(year % 100 == 0)
        {
            if(year % 400 == 0)
            {
                is_unique = true;
            }
            else
                is_unique = false;
        }
        else
            is_unique = true;
    }
    vector<pair<int, string>> cel_days = {};
    for(int i = 0; i < n; i++)
    {
        int num;
        string month;
        cin >> num;
        cin >> month;
        cel_days.push_back(pair<int, string>(num, month));
    }
    int delta;
    string d;
    cin >> d;
    delta = parse_week(d);
    for(int i = 0; i < 365 + is_unique; i++)
    {
        all_days[(i + delta) % 7]++;
    }
    for(int i = 0; i < n; i++)
    {
        add_day(cel_days[i].first, cel_days[i].second, celeb_days, delta, is_unique);       
    }
    for(int i = 0; i < 7; i++)
    {
        all_days[i] -= celeb_days[i];
    }
    //теперь в all_days хранится число дней, которые надо отработать
    //в каждый день недели
    //min - худший выбор, max - лучший выбор
    int mn_ind = 0, mx_ind = 0;
    int mn = INT_MAX, mx = INT_MIN;
    for(int i = 0; i < 7; i++)
    {
        if(all_days[i] < mn)
        {
            mn = all_days[i];
            mn_ind = i;
        }
        if(all_days[i] > mx)
        {
            mx = all_days[i];
            mx_ind = i;
        }
    }
    cout << week[mx_ind] << ' ' << week[mn_ind];
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