#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;

const ll INF = 1e18;
const int INF_int = 1e9;
const ll MOD = 1e9 + 7;
const float PI = acos(-1.0);

float __speedstart__;
#define SPEEDTEST_START __speedstart__ = clock();
#define SPEEDTEST_STOP cout << "Process finished in: " << (float)(clock() - __speedstart__)/CLOCKS_PER_SEC << " seconds";
#define fastboi ios::sync_with_stdio(false); cin.tie(0);

struct PlayerData
{
    float goals = 0;
    float matches = 0;
    float first_goal = 0;
    vector<int> goal_minutes = {};
};

struct TeamData
{
    float goals = 0;
    float matches = 0;
    float first_goal = 0;
    set<string> players = {};
};


void solve()
{
    unordered_map<string, PlayerData> player_data = {};
    map<string, TeamData> team_data = {};
    string input;
    string name_first;
    int minute_first;
    string his_team;
    //для первого гола выше

    string team1, team2;
    int score1, score2;

    int counter1, counter2;

    int type = -1;
    stringstream ss;
    while (getline(cin, input))
    {
        ss.clear();
        ss.str(input);
        string s;
        string s2;
        getline(ss, s, ' ');
        getline(ss, s2, ' ');
        if(s == "Total" && s2 == "goals")
        {
            getline(ss, s, ' ');
            if(s == "for")
            {
                //Total goals for <Название команды>
                getline(ss, s, ' '); //название
                if(team_data.contains(s))
                    cout << team_data[s].goals << '\n';
                else cout << 0 << '\n';
            }
            else if (s == "by")
            {
                //Total goals by <Имя игрока>
                getline(ss, s, ' '); //название
                if(player_data.contains(s))
                    cout << player_data[s].goals << '\n';
                else cout << 0 << '\n';
            }
        }
        else if(s == "Mean" && s2 == "goals")
        {
            getline(ss, s, ' '); //per
            getline(ss, s, ' '); //game
            getline(ss, s, ' '); //for by
            if(s == "for")
            {
                //Mean goals per game for <Название команды>
                getline(ss, s, ' '); //название
                if(team_data.contains(s))
                    cout << team_data[s].goals / team_data[s].matches << '\n';
                else cout << 0 << '\n';
            }
            else if (s == "by")
            {
                //Mean goals per game by <Имя игрока>
                getline(ss, s, ' '); //название
                if(player_data.contains(s))
                    cout << player_data[s].goals / player_data[s].matches << '\n';
                else cout << 0 << '\n';
            }
        }
        else if(s == "Goals" && s2 == "on")
        {
            getline(ss, s, ' ');
            if(s == "minute")
            {
                //Goals on minute <Минута> by <Имя игрока>
                getline(ss, s, ' ');
                int minute = stoi(s);
                getline(ss, s, ' '); //by
                getline(ss, s, ' ');//name
                int cnt = 0;
                int mn = minute;
                int mx = minute;
                if(player_data.contains(s))
                {
                    for(auto elem : player_data[s].goal_minutes)
                        if(mn <= elem && elem <= mx)
                            cnt++;
                    cout << cnt << '\n';
                }
                else cout << 0 << '\n';
            }
            else if (s == "first")
            {
                //Goals on first <T> minutes by <Имя игрока>
                getline(ss, s, ' ');
                int minute = stoi(s);
                getline(ss, s, ' '); //minutes
                getline(ss, s, ' '); //by
                getline(ss, s, ' ');//name
                int cnt = 0;
                int mn = 1;
                int mx = minute;
                if(player_data.contains(s))
                {
                    for(auto elem : player_data[s].goal_minutes)
                        if(mn <= elem && elem <= mx)
                            cnt++;
                    cout << cnt << '\n';
                }
                else cout << 0 << '\n';
            }
            else if (s == "last")
            {
                //Goals on last <T> minutes by <Имя игрока>
                getline(ss, s, ' ');
                int minute = stoi(s);
                getline(ss, s, ' '); //minutes
                getline(ss, s, ' '); //by
                getline(ss, s, ' ');//name
                int cnt = 0;
                int mn = 91 - minute;
                int mx = 90;
                if(player_data.contains(s))
                {
                    for(auto elem : player_data[s].goal_minutes)
                        if(mn <= elem && elem <= mx)
                            cnt++;
                    cout << cnt << '\n';
                }
                else cout << 0 << '\n';
            }
        }
        else if(s == "Score" && s2 == "opens")
        {
            getline(ss, s, ' '); //by
            getline(ss, s, ' '); //TEAM / PLAYER
            if(team_data.contains(s))
            {
                cout << team_data[s].first_goal << '\n';
            }
            else if (player_data.contains(s))
            {
                cout << player_data[s].first_goal << '\n';
            }
            else cout << 0 << '\n';
        }
        else if(s[0] == '\"' && s2 == "-")
        {
            name_first = "";
            minute_first = 91;
            his_team = "";

            ss.clear();
            ss.str(input);
            string score;
            getline(ss, team1, ' ');
            getline(ss, team2, ' ');
            getline(ss, team2, ' ');
            getline(ss, score, ' ');

            int colonPos = score.find(":");
            score1 = stoi(score.substr(0, colonPos));
            score2 = stoi(score.substr(colonPos + 1));
            counter1 = score1;
            counter2 = score2;

            if(!team_data.contains(team1))
            {
                TeamData td1;
                team_data[team1] = td1;
            }
            if(!team_data.contains(team2))
            {
                TeamData td1;
                team_data[team2] = td1;
            }

            for(auto player : team_data[team1].players)
            {
                player_data[player].matches++;
            }
            for(auto player : team_data[team2].players)
            {
                player_data[player].matches++;
            }
            team_data[team1].matches++;
            team_data[team2].matches++;
            team_data[team1].goals += score1;
            team_data[team2].goals += score2;

        }
        else
        {
            ss.clear();
            ss.str(input);
            string name = "";
            string str;
            do
            {
                getline(ss, str, ' ');
                if(str[2] != '\'')
                {
                    name += str;
                    name += " ";
                }
            } while (str[2] != '\'');
            name = name.substr(0, name.size() - 1);
            int minutes = stoi(str.substr(0, str.size() - 1));
            //если об игроке ничего не известно
            if(!player_data.contains(name))
            {
                PlayerData pd;
                player_data[name] = pd;
                if(counter1 != 0)
                    team_data[team1].players.insert(name);
                else
                    team_data[team2].players.insert(name);
            }

        //     string name_first;
        // int minute_first;
        // string his_team;
            if(counter1 != 0)
            {
                counter1--;
                //первая тима
                player_data[name].matches = 1;
                player_data[name].goals = 1;
                player_data[name].goal_minutes.push_back(minutes);
                if(minutes < minute_first)
                {
                    minute_first = minutes;
                    his_team = team1;
                    name_first = name;
                }
            }
            else
            {
                counter2--;
                //вторая тима
                player_data[name].matches = 1;
                player_data[name].goals = 1;
                player_data[name].goal_minutes.push_back(minutes);
                if(minutes < minute_first)
                {
                    minute_first = minutes;
                    his_team = team2;
                    name_first = name;
                }
            }

            if(counter1 == 0 && counter2 == 0)
            {
                player_data[name_first].first_goal++;
                team_data[his_team].first_goal++;
            }
        }
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