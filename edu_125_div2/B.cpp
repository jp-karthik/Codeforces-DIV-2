#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define PB push_back;
#define REP(i, a, b) for(int i=a; i<=b; i++)
void solve() {
    long long n, B, x, y;
    cin>>n>>B>>x>>y;
    vector<long long> v(n+1);
    for (long long i=1; i<=n; i++) {
        if (v[i-1]+x <= B) {
            v[i] = v[i-1]+x;
        } else {
            v[i] = v[i-1]-y;
        }
    }
    long long result = 0;
    for (long long i=0; i<=n; i++) result += v[i];
    cout<<result<<endl;
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