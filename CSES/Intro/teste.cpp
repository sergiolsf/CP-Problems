#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

vi A;
vi p;   // predecessor array
int n;                                             

void print_LIS(int i) {                            // backtracking routine
  if (p[i] == -1) { printf("%d", A[i]); return; }  // base case
  print_LIS(p[i]);                                 // backtrack
  printf(" %d", A[i]);
}

signed main() {
    fastio();

    // inside int main()
    int k = 0, lis_end = 0;
    vi L(n, 0), L_id(n, 0);
    p.assign(n, -1);

    for (int i = 0; i < n; ++i) {                  // O(n)
        int pos = lower_bound(L.begin(), L.begin()+k, A[i]) - L.begin();
        L[pos] = A[i];                             // greedily overwrite this
        L_id[pos] = i;                             // remember the index too
        p[i] = pos ? L_id[pos-1] : -1;             // predecessor info
        if (pos == k) {                            // can extend LIS?
            k = pos+1;                             // k = longer LIS by +1
            lis_end = i;                           // keep best ending i
        }
    }

    printf("Final LIS is of length %d: ", k);
    print_LIS(lis_end); printf("\n");


    
    return 0;
}