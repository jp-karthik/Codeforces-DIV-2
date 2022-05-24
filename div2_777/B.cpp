#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define PB push_back;
#define REP(i, a, b) for(int i=a; i<=b; i++)
void solve() {
    int n, m;
    cin>>n>>m;
    vector<string> matrix(n);
    REP(i, 0, n-1) {
        cin>>matrix[i];
    } 
    bool result = true;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (matrix[i][j] == '1') {
                if (i>0 && j>0) {
                    if (matrix[i-1][j] == '1' && matrix[i][j-1] == '1') {
                        if (matrix[i-1][j-1] == '0') {
                            result = false;
                            break;
                        }
                    }
                }
                if (i>0 && j<m-1) {
                    if (matrix[i-1][j] == '1' && matrix[i][j+1] == '1') {
                        if (matrix[i-1][j+1] == '0') {
                            result = false;
                            break;
                        }
                    }
                }
                if (i<n-1 && j<m-1) {
                    if (matrix[i+1][j] == '1' && matrix[i][j+1] == '1') {
                        if (matrix[i+1][j+1] == '0') {
                            result = false;
                            break;
                        }
                    }
                }
                if (i<n-1 && j>0) {
                    if (matrix[i+1][j] == '1' && matrix[i][j-1] == '1') {
                        if (matrix[i+1][j-1] == '0') {
                            result = false;
                            break;
                        }
                    }
                }
            }
        }
        if (!result) {
            break;
        }
    }
    if (result) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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