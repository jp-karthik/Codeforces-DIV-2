#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define PB push_back;
#define REP(i, a, b) for(int i=a; i<=b; i++)
int mod(int x, int y) {
    if (x>y) return x-y;
    else return y-x;
}
void solve() {
    int n, m;
    cin>>n>>m;
    vector<vector<int>> matrix(n, vector<int>(m));
    REP(i, 0, n-1) {
        REP(j, 0, m-1) {
            cin>>matrix[i][j];
        }
    }
    long long result = 0;
    REP(i, 0, n-1) {
        REP(j, 0, m-1) {
            for (int x=0; x<n; x++) {
                for (int y=0; y<m; y++) {
                    if (matrix[x][y] == matrix[i][j]) {
                        result += mod(x, i) + mod(y, j);
                    }
                }
            }
        }
    }
    result = result/2;
    cout<<result<<endl;
}
int main() {
        solve(); 
    return 0;
}