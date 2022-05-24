#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define PB push_back;
#define REP(i, a, b) for(int i=a; i<=b; i++)
bool isP(string s, int len, int curr) {
    bool a = true;
    int l = curr;
    int r = curr+len-1;
    while (l<=r) {
        if (s[l] == s[r]) {
            l++;
            r--;
        } else {
            a = false;
            break;
        }
    }
    return a;
}
bool isBal(string s, int len, int curr) {
    stack<char> bal;
    bool valid = true;
    for (int i=curr; i<curr+len; i++) {
        if (s[i] == '(') {
            bal.push('(');
            continue;
        }
        if (s[i] == ')') {
            if (!bal.size() || bal.top() == ')') {
                valid = false;
                break;
            }
            if (bal.top() == '(') {
                bal.pop();
            }
        }
    }
    if (!bal.size() && valid) {
        return true;
    } else {
        return false;
    }
}
void solve() {
    int n;
    string s;
    cin>>n;
    cin>>s;
    int opr = 0;
    int curr = 0;
    do {
        if (curr >= s.length()-1) {
            break;
        }
        bool present = 0;
        for (int i=2; i<s.length()+1; i++) {
            bool val = isP(s, i, curr) || isBal(s, i, curr);
            if (val) {
                curr += i;
                present = 1;
                opr++;
                break;
            }
        }
        if (present == 0) {
            break;
        }
    }while (1);
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