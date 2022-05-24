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
bool search(char c, vector<char>& sp) {
    for (auto x : sp) {
        if (c == x) {
            return true;
        }
    }
    return false;
}
void solve(int arg) {
    int n;
    string s;
    int k;
    cin >> n >> s >> k;
    vector<char> sp(k);
    rep(i, 0, k-1) cin >> sp[i];
    ll res = LLONG_MIN;
    ll prev = 0;
    ll count = 0;
    for (int i=0; i<n; i++) { 
        if (search(s[i], sp)) {
            count++;
        } 
    }
    if (count == 0) {
        cout<<0<<endl;
        return;
    }
    if (count == n) {
        cout<<1<<endl;
        return;
    }
    for (int i=0; i<n; i++) {
        if (search(s[i],sp)) {
            ll temp = i-prev-1;
            if (res < temp) {
                res = temp;
            }
            prev = i;
        }
    }
    cout<<res+1<<endl;
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