#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define PB push_back;
#define REP(i, a, b) for(int i=a; i<=b; i++)
bool comp(int a, int b) {
    return a<b;
}
void solve() {
    int n;
    cin>>n;
    vector<int> w(n);
    REP(i, 0, n-1) cin>>w[i];
    if (w.size()==2) {
        cout<<w[1]+w[0]<<endl;
        return;
    }
    int r = 0;
    vi::iterator m1 = max_element(w.begin(), w.end(), comp);
    r += *m1;
    w.erase(m1);
    vi::iterator m2 = max_element(w.begin(), w.end(), comp);
    r += *m2;
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