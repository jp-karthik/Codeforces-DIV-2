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
#define Sort(v) sort(v.begin(), v.end())
//------------------
bool dec(int x, int y) {
    return x>y;
}
bool inc(int x, int y) {
    return x<y;
}
//-----------------
void solve(int arg) {
    ll n;
    cin>>n;

    vll v(n-1);
    REP(i, 0, n-2) cin>>v[i];

    Sort(v); //O(nlogn)

    ll u = 1;
    for (int i = 1; i<n-1; i++) {
        if (v[i] != v[i-1]) u++;
    }

    vll g(u);

    int k = 1;
    for (int i=0; i<g.size(); i++) {
        int lc = 1;
        while (k < n-1 && v[k] == v[k-1]) {
            lc++;
            k++;
        }
        k++;
        g[i] = lc-1;
    }
    
    sort(g.begin(), g.end(), greater<long long>()); //O(nlogn)

    //infecting every component
    for (int i=0; i<g.size(); i++) {
        if (g[i] > g.size()-i) {
            g[i] -= g.size()-i;
            continue;
        }
        g[i] = 0;
    }

    sort(g.begin(), g.end(), greater<long long>()); //O(nlogn)
    
    ll op = g.size()+1;
    
    //after infecting every component
    while (g[0] != 0) {
        for (int i=0; i<g.size(); i++) {
            if (g[i] == 0) continue;
            g[i]--;
        }

        if(g[0] > 0) g[0]--;
        sort(g.begin(), g.end(), greater<long long>());
        op++;
    } 
    cout<<op<<endl;
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