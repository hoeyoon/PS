#include <iostream>
using namespace std;

int main(){
    int n, key;
    int i, j;
    cin >> n;

    int arr[n];
    for(i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(i = 1; i < n; i++){
        key = arr[i];
        for(j = i - 1; j >= 0 && arr[j] > key; j--){
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = key;
        for(j = 0; j < n; j++){
            cout << arr[j] << " ";
        }
        cout << endl;
    }
    return 0;
}