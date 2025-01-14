#include <bits/stdc++.h>

using namespace std;

int arr[101];

void generator(int n, int k, int index, int start ){
    if (index == k){
        for (int i = 0; i < k; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");

    }
    else {
        for (int i = start; i <= n;){
            arr[index] = i;
            i++;
            generator(n, k, index + 1, i);

        }
    }
}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    generator(n, k, 0, 1);


    return 0;
}

/*init 
4 2 0 1

	4 2 1 2 [1]
		4 2 2 2 [1 2]
		4 2 2 3 [1 3]
		4 2 2 4 [1 4]
	
	4 2 1 3 [2]
		4 2 2 3 [2 3]
		4 2 2 4 [2 4]
	
	4 2 1 4 [3]
		4 2 2 4 [3 4]

	4 2 1 5 (nothing)*/