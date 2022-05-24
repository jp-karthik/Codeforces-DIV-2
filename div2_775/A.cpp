#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
#define PB push_back;
#define REP(i, a, b) for(int i=a; i<=b; i++)
void solve() {
    long long n;
    cin>>n;
    vector<int> loc(n);
    for (long long i=0; i<n; i++) {
        cin>>loc[i];
    }
    long long cost = 0;
    for (long long i=0; i<n-1; i++) {
        if (loc[i+1] == 0) {
            cost += 1;
        }
        if (loc[i+1] == 1 && loc[i] == 0) {
            cost += 1;
        }
    }
    cout<<cost<<endl;
}
int main() {
    int t;
    cin>>t;
    while(t > 0) {
        solve(); 
        t--;
    };
    return 0;
}