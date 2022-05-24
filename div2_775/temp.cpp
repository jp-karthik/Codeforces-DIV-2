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
    int start = 0;
    int end = n-1;
    while (true) {
        if (start == n-1) {
            cout<<0<<endl;
            return;
        }
        if (loc[start+1] == 1) {
            start++;
        } else {
            break;
        }
    }
    while (true) {
        if (end == 0) {
            cout<<0<<endl;
        }
        if (loc[end-1] == 1) {
            end--;
        } else {
            break;
        }
    }
    cout<<end-start<<endl;
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