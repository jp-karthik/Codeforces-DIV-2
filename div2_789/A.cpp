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
    cin >> n;
    vll v(n);
    rep (i, 0, n-1) cin >> v[i];
    sort(v);
    if (v[0] == 0) {
        ll zeros = count(v.begin(), v.end(), 0);
        cout << n-zeros << endl;
        return;
    }
    for (int i=0; i<n-1; i++) {
        if (v[i] == v[i+1]) {
            cout << n << endl;
            return;
        }
    }
    cout << n+1 <<endl;
    return;
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