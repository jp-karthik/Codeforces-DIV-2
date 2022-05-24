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

    for (int i=0; i<n; i++) cin>>v[i];

    ll c2 = 0;
    ll c3 = 0;

    for (int i=0; i<n-1; i++) {
        if (abs(v[i+1]-v[i]) > 3) {
            cout<<"NO"<<endl;
            return;
        }
        if (abs(v[i+1]-v[i]) == 2) {
            c2++;
        }
        if (abs(v[i+1]-v[i]) == 3) {
            c3++;
        }
        if (c2 > 2) {
            cout<<"NO"<<endl;
            return;
        }
        if (c2 && c3) {
            cout<<"NO"<<endl;
            return;
        }
    }
    if (c2 <= 2 && c3 == 0) {
        cout<<"YES"<<endl;
        return;
    } 
    if (c3 == 1 && c2 == 0) {
        cout<<"YES"<<endl;
        return;
    }
    cout<<"NO"<<endl;
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