#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
#define PB push_back;
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
    vll a(n);
    vll b(n);
    REP(i, 0, n-1) cin>>a[i];
    REP(i, 0, n-1) cin>>b[i];
    //process
    long long r = 0;
    for (int i=1; i<n; i++) {
        long long v1 = abs(a[i]-a[i-1])+abs(b[i]-b[i-1]);
        long long v2 = abs(b[i]-a[i-1])+abs(a[i]-b[i-1]);
        if (v2 < v1) {
            swap(a[i], b[i]);
            r += v2;
        } else {
            r += v1;
        }
    }
    cout<<r<<endl;
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