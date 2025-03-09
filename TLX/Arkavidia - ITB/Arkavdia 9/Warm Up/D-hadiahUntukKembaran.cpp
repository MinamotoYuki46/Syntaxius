#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
   int q;
   cin >> q;
   while (q--)
   {
      int n, x, y;
      cin >> n >> x >> y;

      long long kpk = (1LL * x / __gcd(x, y)) * y;
      int cntX = (n / x) - (n / kpk);
      int cntY = (n / y) - (n / kpk);
      
      cout << cntX << ' ' << cntY << endl;
   }

   return 0;
}
