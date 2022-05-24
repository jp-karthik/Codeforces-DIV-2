#include <bits/stdc++.h>
using namespace std;
// -------------------
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<long, long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int,int>> vpi;
typedef vector<pair<long long, long long>> vpll;
// --------------------
#define PB push_back
#define REP(i, a, b) for(int i=a; i<=b; i++)
#define sort(v) sort(v.begin(), v.end())
//------------------
bool dec(int x, int y) {
    return x>y;
}
bool inc(int x, int y) {
    return x<y;
}
//-----------------
void solve(int arg) {
    ll n, m;
    cin>>n>>m;

    vll v(n);
    REP(i, 0, n-1) cin>>v[i];

    sort(v);
    ll p = 1;

    bool res = true;
    
    for (int i=n-1; i>=0; i--) {
        if (p > m-v[n-1]) {
            res = false;
            break;
        }
        if (i == 0) {
            break;
        }
        p += v[i]+1;
    }

    if (res) {
        if (p > m-v[n-1]) {
            cout<<"NO"<<endl;
        } else {
            cout<<"YES"<<endl;
        }
    } else {
        cout<<"NO"<<endl;
    }
}
int main() {
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