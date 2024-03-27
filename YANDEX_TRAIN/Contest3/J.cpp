#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;

const ll INF = 1e18;
const int INF_int = 1e9;
const int MOD = 998244353;
const double PI = acos(-1.0);

double __speedstart__;
#define SPEEDTEST_START __speedstart__ = clock();
#define SPEEDTEST_STOP cout << "Process finished in: " << (double)(clock() - __speedstart__)/CLOCKS_PER_SEC << " st2s";
#define fastboi ios::sync_with_stdio(false); cin.tie(0);
#define pb push_back
class DeviceManager {

public:
    DeviceManager(size_t k, size_t n) : updates(k, false), possible(n, 0), requests(), cnt_updates(), flag(-1), iterators(), ind_device(devices.size()), my_request(false), id_request_device(-1) {
        devices.pb(this);
    }

    void choose_part_of_update() {
        
        ll min_cnt_updates = std::numeric_limits<ll>::max();

        flag = -1;

        for (size_t i = 0; i < updates.size(); i++) {
            if (updates[i] == false and both_updates[i] < min_cnt_updates) {

                min_cnt_updates = both_updates[i];

                flag = i;

            }
        }
        if (flag != -1) iterators++;
    }

    void choose_device_who_have_part_of_update() {
        if (flag == -1) return;

        ll min_updates = std::numeric_limits<ll>::max();
        DeviceManager* request_from_device;

        request_from_device = nullptr;

        for (size_t i = 0; i < devices.size(); i++) {
            DeviceManager* my_device = devices[i];

            if (my_device->updates[flag] == true) {

                if (my_device->cnt_updates < min_updates) {

                    request_from_device = my_device;

                    min_updates = my_device->cnt_updates;

                }

            }
        }
        if (request_from_device) {
            request_from_device->requests.pb(this);
        }
    }
    size_t choose_request() {
        ll min_cnt_update_2 = std::numeric_limits<ll>::max(), max_val = -1;
        size_t device_check = std::numeric_limits<size_t>::max();

        for (size_t i = 0; i < this->requests.size(); i++) {

            DeviceManager* my_device = requests[i];

            if (possible[my_device->ind_device] > max_val) {

                device_check = my_device->ind_device;

                min_cnt_update_2 = my_device->cnt_updates;

                max_val = possible[my_device->ind_device];
            }
            else if (possible[my_device->ind_device] == max_val) {

                if (min_cnt_update_2 > my_device->cnt_updates) {

                    device_check = my_device->ind_device;

                    min_cnt_update_2 = my_device->cnt_updates;
                }
            }
        }
        this->requests.clear();
        if (device_check != std::numeric_limits<size_t>::max()) {

            DeviceManager* my_device = devices[device_check];

            my_device->my_request = true;

            my_device->id_request_device = this->ind_device;

            return device_check;

        }
        return std::numeric_limits<size_t>::max();

    }

    void good_request() {
        if (!my_request) return;

        cnt_updates++;

        updates[flag] = true;

        both_updates[flag]++;

        possible[id_request_device]++;

        my_request = false;
    }

    vector<bool> updates;

    vector<ll> possible;

    vector<DeviceManager*> requests;

    static vector<DeviceManager*> devices;


    static vector<ll> both_updates;

    bool my_request;

    ll cnt_updates, flag, iterators, ind_device;

    int id_request_device;
};

vector<DeviceManager*> DeviceManager::devices;

vector<ll> DeviceManager::both_updates;


vector<ll> decide(ll n, ll k) {
    DeviceManager::devices = vector<DeviceManager*>();
    DeviceManager::both_updates = vector<ll>(k, 1);

    for (ll i = 0; i < n; i++) {
        DeviceManager* my_device = new DeviceManager(k, n);
    }

    DeviceManager::devices[0]->cnt_updates = k;
    DeviceManager::devices[0]->updates = vector<bool>(k, true);

    while (1) {
        ll is_end = 0;
        for (DeviceManager* my_device : DeviceManager::devices) {
            if (my_device->cnt_updates == k) {
                is_end += 1;
                continue;
            }
            my_device->choose_part_of_update();
        }
        if (is_end == n) {
            break;
        }

        for (DeviceManager* my_device : DeviceManager::devices) {
            if (my_device->cnt_updates == k)
                continue;
            my_device->choose_device_who_have_part_of_update();
        }
        for (DeviceManager* my_device : DeviceManager::devices) {
            if (my_device->requests.size() == 0)
                continue;
            my_device->choose_request();
        }
        for (DeviceManager* my_device : DeviceManager::devices) {
            if (my_device->my_request == false) {
                continue;
            }
            my_device->good_request();
        }
    }

    vector<ll> ans;
    for (DeviceManager* my_device : DeviceManager::devices) {
        ans.pb(my_device->iterators);
    }

    for (DeviceManager* my_device : DeviceManager::devices) {
        delete my_device;
    }

    return ans;
}

void solve() {
    ll n, k;
    cin >> n >> k;

    vector <ll> vec = decide(n, k);

    for (size_t i = 1; i < vec.size() - 1; i++) {
        cout << vec[i] << ' ';
    }
    cout << vec[vec.size() - 1];
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