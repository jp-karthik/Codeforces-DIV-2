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
    ll res = 0;
    ll v = n-1;
    ll h = m-1;
    if (v == 0 && h > 1) {
        cout<<-1<<endl;
        return;
    }
    if (h == 0 && v > 1) {
        cout<<-1<<endl;
        return;
    }
    res += 2*(min(v, h));
    ll left = max(v, h)- min(v, h);
    if (left%2 == 0) {
        res += 2*left;
    } else {
        res += 2*left - 1;
    }
    cout<<res<<endl;
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