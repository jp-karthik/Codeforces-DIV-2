#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define PB push_back;
#define REP(i, a, b) for(int i=a; i<=b; i++)
void solve() {
    float x, y;
    cin>>x>>y;
    float dist = x*x + y*y;
    dist = sqrt(dist);
    // cout<<dist<<endl;
    if (x == 0 && y==0) {
        cout<<0<<endl;
        return;
    }
    if (dist - (int)dist == (float)0) {
        cout<<1<<endl;
    } else {
        cout<<2<<endl;
    }
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