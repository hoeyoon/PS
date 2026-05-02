#include <iostream>
using namespace std;

int main(){
    int n;
    int idx;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < n - 1; i++){
        int min = 101;
        for(int j = i; j < n; j++){
            if(min > arr[j]){
                min = arr[j];
                idx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[idx];
        arr[idx] = temp;
        for(int j = 0; j < n; j++){
            cout << arr[j] << " ";
        }
        cout << endl;
    }
    return 0;
}