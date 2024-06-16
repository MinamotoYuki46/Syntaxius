#include <bits/stdc++.h>
using namespace std;

int main(){
    int testcase;
    cin >> testcase;

    while (testcase--){
        int num_shape;
        cin >> num_shape;

        int xmin = INT_MAX, ymin = INT_MAX, xmax = INT_MIN, ymax = INT_MIN;

        while (num_shape--){
            char type;
            cin >> type;

            if (type == 'p'){
                int x, y;
                cin >> x >> y;

                xmin = min(xmin, x);
                xmax = max(xmax, x);
                ymin = min(ymin, y);
                ymax = max(ymax, y);                
            }
            else if (type == 'c'){
                int x, y, r;
                cin >> x >> y >> r;

                xmin = min(xmin, x - r);
                xmax = max(xmax, x + r);
                ymin = min(ymin, y - r);
                ymax = max(ymax, y + r);                
            }
            else if (type == 'l'){
                int x1, x2, y1, y2;
                cin >> x1 >> y1 >> x2 >> y2;

                xmin = min(xmin, min(x1, x2));
                xmax = max(xmax, max(x1, x2));
                ymin = min(ymin, min(y1, y2));
                ymax = max(ymax, max(y1, y2));
            }
        }
        
        cout << xmin << " " << ymin << " " << xmax << " " << ymax << endl;
    }
    return 0;
}
