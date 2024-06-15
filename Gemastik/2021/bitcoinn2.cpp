#include <iostream>
using namespace std;

int main(){
    int hasil, i;
    int n;
    cin>>n;
    int arr[n];

    for(i = 0; i<n; i++){
        cin>>arr[i];
    }

    hasil = 0;
    for(i = 1; i<n; i++){
        if(arr[i]>arr[i-1]){
            hasil += arr[i]-arr[i-1];
        }
    }
    cout<<hasil<<endl;
}