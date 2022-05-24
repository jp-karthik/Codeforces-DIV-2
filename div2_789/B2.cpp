#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<long, long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int,int>> vpi;
typedef vector<pair<long long, long long>> vpll;

#define PB push_back
#define rep(i, a, b) for(int i=a; i<=b; i++)
#define sort(v) sort(v.begin(), v.end())
#define endl "\n"

bool dec(int x, int y) {
    return x>y;
}
bool inc(int x, int y) {
    return x<y;
}

void solve(int arg) {
    int n;
    string s;
    cin >> n >> s;
    ll res = 0;
    ll unique = 1;
    char prev = -1;
    for (int i = 0; i < n; i += 2) {
        if (s[i] != s[i + 1]) {
            res++;
        } else {
            if (prev == -1) {
                prev = s[i];
                continue;
            }
            if (prev != s[i]) {
                prev = s[i];
                unique++;
            }
        }
    }
    cout << res << " " << unique << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    int arg = 1;
    cin>>t;
    while(t > 0) {
        solve(arg);
        t--;
        arg++;
    };
    return 0;
}