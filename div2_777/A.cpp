#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define PB push_back;
#define REP(i, a, b) for(int i=a; i<=b; i++)
void solve() {
    int n;
    cin>>n;
    string sol;
    //three cases
    if (n%3 == 0) {
        for (int i=0; i<n/3; i++) {
            sol.append("21");
        }
    } else if (n%3 == 1) {
        for (int i=0; i<n/3; i++) {
            sol.append("12");
        }
        sol.append("1");
    } else {
        for (int i=0; i<n/3; i++) {
            sol.append("21");
        }
        sol.append("2");
    }
    cout<<sol<<endl;
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