#include <iostream>
#define ll long long int
#define forn(t,n) for(t=0;t<n;t++)
using namespace std;

int main() {
  ll n,t;
  cin >> n;

  ll *a = new ll[n];
  ll sum = 0;
  forn(t,n){
    cin >> a[t];
    sum += a[t];

    if (sum >= n) {
      cout << t+1 << '\n';
      break;
    }
  }
}
