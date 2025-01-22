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

const int MAX_N = 1000010;


string T, P;                                     // T = text, P = pattern
int n, m;                                        // n = |T|, m = |P|
int b[MAX_N];                                    // b = back table


void kmpPreprocess() {                           // call this first
  int i = 0, j = -1; b[0] = -1;                  
  while (i < m) {                                
    while ((j >= 0) && (P[i] != P[j])) j = b[j];
    ++i; ++j;                                    
    b[i] = j;
  }
}


int kmpSearch() {                              
  int freq = 0;
  int i = 0, j = 0;                              
  while (i < n) {                                
    while ((j >= 0) && (T[i] != P[j])) j = b[j];
    ++i; ++j;                                    
    if (j == m) {                                
      ++freq;
      // cout << "P is found at index " << i-j << " in T\n";
      j = b[j];                                
    }
  }
  return freq;
}

signed main() {
    fastio();
    cin >> T >> P;

    n = T.size();
    m = P.size();

    kmpPreprocess();
    cout << kmpSearch() << endl;

    return 0;
}