#include <iostream>
using namespace std;

int main(){
    int n;
    int cnt = 0;
    cin >> n;
    int arr[50];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int i, j;
    for(int i = 1; i < n; i++){
        int key = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] >= key){
            arr[j + 1] = arr[j];
            j--;
            cnt++;
        }
        arr[j + 1] = key;
    }
    cout << cnt << endl;
    return 0;
}