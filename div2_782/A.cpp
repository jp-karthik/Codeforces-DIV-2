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
    int n, r, b;
    cin>>n>>r>>b;
    vi v(b+1, 0);
    for (int i=0; i<b+1; i++) {
        v[i] = r/(b+1);
    }
    for (int i=0; i<r%(b+1); i++) {
        v[i] += 1;
    }
    for (int i=0; i<b+1; i++) {
        while (v[i] != 0) {
            cout<<"R";
            v[i]--;
        }
        if (i == b) {
            break;
        }
        cout<<"B";
    }
    cout<<endl;
}
int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin>>t;
    while(t > 0) {
        int arg = 0;
        solve(arg);
        t--;
        arg++;
    };
    return 0;
}