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

struct image
{
    int type;
    //0 - embedded
    //1 - surrounded
    //2 - floating
    int width;
    int height;
    int dx;
    int dy;
    int left_pos;
    int up_pos;
}


//for example: width=1
void parse(string &a, string &b, image& im)
{
    if(b[b.size() - 1] == ')')
        b.erase(b.begin() + b.size() - 1, b.end());
    if(a == "width")
    {
        im.width = stoi(b);
    }
    else if(a == "height")
    {
        im.height = stoi(b);
    }
    else if(a == "layout")
    {
        if(b == "embedded")
        {
            im.type = 0;
        }
        else if(b == "surrounded")
        {
            im.type = 1;
        }
        else
        {
            im.type = 2;
        }
    }
    else if(a == "dx")
    {
        im.type = stoi(b);
    }
    else if(a == "dy")
    {
        im.type = stoi(b);
    }
}

void calculate_block(int cursor_x, int w, 
                    vector<image>& surrounded, int &x_end,
                    int &x_new_begin)
{
    if(surrounded.size() == 0)
    {
        x_end = w;
        x_new_begin = 0;
    }
    else
    {
        x_end = surrounded[0];
        x_new_begin = surrounded[0].left_pos + surrounded[0].width;
    }
}
void solve()
{

    int x_end, y_end;
    int x_new_begin, y_new_begin;
    // let's go kid
    int w, h, c;
    cin >> w >> h >> c;

    x_end = w;
    y_end = 0;
    x_new_begin = 0;
    y_new_begin = 0;
    int cnt = 0;
    int cursor_x = 0;
    int cursor_y = 0;
    bool new_frag = true; 
    vector<image> images = {};
    string s;
    while(getline(cin, s))
    {
        stringstream stream(s);
        if(s == "\n")
        {
            cursor_y += h;
            cursor_x = 0;
        }
        string read;
        while(getline(stream, read, ' '))
        {
            if(read[0] == '(')
            {
                //TODO parse an image
                image im;
                string type;
                int width, height, dx, dy;
                //type
                string a, b;
                getline(stream, read, ' ');                
                getline(stream, a, '=');
                getline(stream, b, '=');
                parse(a, b, im);
                if(im.type == 2)
                {
                    //4 раза
                    for(int i = 0; i < 4; i++)
                    {
                        getline(stream, read, ' ');                
                        getline(stream, a, '=');
                        getline(stream, b, '=');
                        parse(a, b, im);
                    }
                }
                else
                {
                    //2 раза
                    for(int i = 0; i < 2; i++)
                    {
                        getline(stream, read, ' ');                
                        getline(stream, a, '=');
                        getline(stream, b, '=');
                        parse(a, b, im);
                    }
                }
            }
            else
            {
                //try to insert word into next fragment
                //dont forget about space
                //and in the beginning you dont need one
                
                calculate_block(cursor_x, w, 
                    images, &x_end,
                    &x_new_begin);
                int word_size = read.size() * c; 
                if(!new_frag)
                {
                    word_size += c;
                }
                while(cursor_x + word_size > x_end - cursor_x)
                {
                    //w or risunok
                    cursor_x = ;
                    
                }

            }
        }
        
    }
    cout << cnt;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    //fastboi

    SPEEDTEST_START
    solve();
    SPEEDTEST_STOP
}