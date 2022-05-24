#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define PB push_back;
#define REP(i, a, b) for(int i=a; i<=b; i++)
void solve() {
    long long n;
    cin>>n;
    vector<long long> A(n);
    vector<long long> B(n);
    REP(i, 0, n-1) cin>>A[i];
    REP(i, 0, n-1) cin>>B[i];
    long long best = abs(A[0]- B[0]) + abs(A[n-1]+B[n-1]);
    long long next = abs(A[0]-B[0]);
    for (long long i=1; i<n; i++) {
        long long c1 = abs(A[i-1]-B[i]) + abs(A[i]-B[i-1]);
        long long c2 = abs(A[i-1]-B[i-1]) + abs(A[i]-B[i]);
        if (c2 < c1) {
            next += abs(A[i]-B[i]);
        } else {
            next += c1 - abs(A[i-1]-B[i-1]);
        }
    }
    if (next > best) {
        cout<<best<<endl;
    } else {
        cout<<next<<endl;
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