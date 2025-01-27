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
int n = 0; 

void print_LIS(int i) {                            // backtracking routine
  if (p[i] == -1) { cout << A[i] << endl; return; }  // base case
  print_LIS(p[i]);                                 // backtrack
  cout << A[i] << endl;
}

signed main() {
    fastio();
    int a;
    while (cin >> a) {
        A.push_back(a);
        n++;
    }

    int k = 0, lis_end = 0;
    vi L(n, 0), L_id(n, 0);
    p.assign(n, -1);

    for (int i = 0; i < n; ++i) {                  
        int pos = lower_bound(L.begin(), L.begin()+k, A[i]) - L.begin();
        L[pos] = A[i];                             
        L_id[pos] = i;                             
        p[i] = pos ? L_id[pos-1] : -1;             
        if (pos == k) {                            
            k = pos+1;                             
            lis_end = i;                           
        }
    }

    cout << k << endl;
    cout << "-" << endl;
    print_LIS(lis_end); 
    return 0;
}