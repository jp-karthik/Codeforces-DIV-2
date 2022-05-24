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
    string s;
    cin>>s;
    int itr = 0;
    for (; itr < n; itr++) {
        if (s[itr] == '0') {
            break;
        } 
    }
    //first male idx
    int res = 0;
    for (int i=itr+1; i<n; i++) {
        int count = 0;
        while (s[i] != '0') {
            if (i == n-1) {
                if (s[i] == '1') {
                    count = 2;
                    break;
                }
                break;
            }
            i++;
            count++;
        }
        if (count < 2) {
            res += 2-count;
        }
    }
    cout<<res<<endl;
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