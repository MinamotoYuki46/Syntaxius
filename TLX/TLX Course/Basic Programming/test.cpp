#include <bits/stdc++.h>
using namespace std;

struct Point {
	int x, y;
};


bool doOverlap(Point l1, Point r1, Point l2, Point r2)
{
	// if rectangle has area 0, no overlap
	if (l1.x == r1.x || l1.y == r1.y || r2.x == l2.x || l2.y == r2.y)
		return false;

	// If one rectangle is on left side of other
	if (l1.x > r2.x || l2.x > r1.x)
		return true;

	// If one rectangle is above other
	if (r1.y > l2.y || r2.y > l1.y)
		return false;

	return true;
}

/* Driver program to test above function */
int main()
{
    int testcase;
    cin >> testcase;

    while(testcase--){
        int x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        Point l1 = { x1, y1 }, r1 = { x2, y2 };
	    Point l2 = { x3, y3 }, r2 = { x4, y4 };


	    if (doOverlap(l1, r1, l2, r2))
		    printf("YA\n");
	    else
		printf("TIDAK\n");
    }
	
	return 0;
}
