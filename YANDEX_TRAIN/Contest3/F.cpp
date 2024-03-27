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

struct trie {
	using dict = map<char, int>;
	trie() {
		create_node();
	}
	struct node {
		dict go;
		int end = -1;
	};
	vector<node> data;
	int create_node() {
		data.push_back(node());
		return data.size() - 1;
	}
	bool can_go(int u, char c) {
		return data[u].go[c];
	}
	int go(int u, char c) {
		return data[u].go[c];
	}
	void insert(const string& s) {
		int u = 0;
		for (char c : s) {
			if (!can_go(u, c)) {
				data[u].go[c] = create_node();
			}
			u = go(u, c);
		}
		data[u].end++;
	}
	int counter(const string& s) {
		int u = 0;
		for (int i = 0; i < s.size(); i++) {
			if(data[u].end != -1)
            {
                return i;
            }
            if (!can_go(u, s[i])) {
				return -1;
			}
			u = go(u, s[i]);
		}
        if(data[u].end != -1)
		    return s.size();
        return -1;
	}
	void erase(const string& s) {
		int u = 0;
		for (char c : s) {
			u = go(u, c);
		}
		data[u].end--;
	}
};

void solve()
{
    // let's go kid
    trie t;
    // t.insert("aba");
    // t.insert("abara");
    // t.insert("abgi");
    // cout << t.counter("ab");
    // cout << t.counter("aba");
    // cout << t.counter("abarag");
    // cout << t.counter("abara");
    // cout << t.counter("abg");
    // cout << t.counter("abhj");
    // cout << t.counter("abgihj");
    string inp1;
    getline(cin, inp1);
    stringstream ss(inp1);
    string tok;
    while (getline(ss, tok, ' '))
    {
        t.insert(tok);
    }
    while(cin >> tok)
    {
        int ind = t.counter(tok);
        if(ind != -1)
        {
            cout << tok.substr(0, ind) << ' ';
        }
        else
            cout << tok << ' ';
    }
    
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