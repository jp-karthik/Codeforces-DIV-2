#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define PB push_back;
#define REP(i, a, b) for(int i=a; i<=b; i++)
void solve() {
    int n;
    string s;
    cin>>n>>s;
    int opr = 0;
    int curr = 0;
    while (1) {
        bool present = false;
        if (curr == s.length()-1) break;
        if (s[curr] == '(') {
            curr += 2;
            opr++;
            present = true;
            continue;
        }
        if (s[curr] == ')') {
            if (s[curr+1] == ')') {
                curr += 2;
                opr++;
                present = true;
                continue;
            }
            for (int k=curr+2; k<s.length(); k++) {
                if (s[k] == ')') {
                    curr = k+1;
                    opr++;
                    present = true;
                    break;
                }
            }
        }
        if (present == false) break;
    }
    cout<<opr<<" "<<s.length()-curr<<endl;
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