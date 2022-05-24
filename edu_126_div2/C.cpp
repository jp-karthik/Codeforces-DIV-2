#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
#define PB push_back
#define REP(i, a, b) for(int i=a; i<=b; i++)
//------------------
bool dec(int x, int y) {
    return x>y;
}
bool inc(int x, int y) {
    return x<y;
}
//-----------------
void solve() {
    int n;
    cin>>n;

    vll h(n);
    REP(i, 0, n-1) cin>>h[i];
    
    sort(h.begin(), h.end(), greater<ll>());

    //case 1 h = hmax
    ll min = LLONG_MAX;
    
    ll e = 0, o = 0;

    for (int i=0; i<n; i++) {
        ll d = abs(h[i]-h[0]);
        e += d/2;
        o += d%2;
    }
    if (! (o - e > 1) ) {
        ll d1 = abs(e-o)/3;
        e -= d1;
        o += 2*d1;
    }

    
    while (abs(e-o) > 1) {
        if (o - e > 1) break;
        e -= 1;
        o += 2;
    }

    if (o > e) {
        min = 2*o-1;
    } else {
        min = 2*e;
    }

    e = 0, o = 0;

    int g = h[0]+1;
    for (int i=0; i<n; i++) {
        ll d = abs(g-h[i]);
        e += d/2;
        o += d%2;
    }

    if (!(o-e > 1)) {
        ll d2 = abs(e-o)/3;
        e -= d2;
        o += 2*d2;
    }
    

    while (abs(e-o) > 1) {
        if (o - e > 1) break;
        e -= 1;
        o += 2;
    }

    if (o > e) {
        if (min > 2*o-1) {
            min =  2*o-1;
        }
    } else {
        if (min > 2*e) {
            min = 2*e;
        } 
    }
    cout<<min<<endl;
}
int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin>>t;
    while(t > 0) {
        solve(); 
        t--;
    };
    return 0;
}