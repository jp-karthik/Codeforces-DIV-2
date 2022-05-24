#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define PB push_back;
#define REP(i, a, b) for(int i=a; i<=b; i++)
void solve() {
    int n;
    cin>>n;
    vector<pair<int,int>> points(n);
    REP(i, 0, n-1) cin>>points[i].first>>points[i].second;
    vector< vector<int> > matrix(n, vector<int>(n));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (i == j) {
                matrix[i][j] = INT_MAX;
            } else {
                matrix[i][j] = abs(points[i].first-points[j].first) + abs(points[i].second - points[j].second);
            }
        }
    }
    for (int i=0; i<n; i++) {
        int bestVal = INT_MAX;
        int bestIdx;
        for (int j=0; j<n; j++) {
            if (i == j) {
                continue;
            }
            if (matrix[i][j] < bestVal) bestVal = matrix[i][j], bestIdx = j;
        }   
        cout<<points[bestIdx].first<<" "<<points[bestIdx].second<<endl;
    }
}
int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
        solve(); 
    return 0;
}