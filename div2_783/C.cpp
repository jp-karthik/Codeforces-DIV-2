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
    int n;
    cin>>n;

    vll v(n);
    REP(i, 0, n-1) cin>>v[i];
    
    ll minop = LLONG_MAX;
    for (int i=0; i<n; i++) {
        ll op = 0;
        vll b(n);
        b[i] = 0;
        for (int j=i+1; j<n; j++) {
            ll lo = b[j-1]/v[j] + 1;
            op += lo; 
            b[j] = lo*v[j];
        }
        for (int j=i-1; j>=0; j--) {
            ll lo = b[j+1]/v[j] + 1;
            op += lo;
            b[j] = lo*v[j];
        }
        if (op < minop) {
            minop = op;
        }
    }
    cout<<minop<<endl;
}
int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    int arg = 1;
    // cin>>t;
    // while(t > 0) {
        solve(arg);
    //     t--;
    //     arg++;
    // };
    return 0;
}