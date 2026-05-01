#include <iostream>
using namespace std;

int main(){
    int arr[105][105] = {0, };
    int n;
    int answer = 0;
    cin >> n;

    for(int k = 0; k < n; k++){
        int x, y;
        cin >> x >> y;
        for(int i = x; i < x + 10; i++){
            for(int j = y; j < y + 10; j++){
                arr[i][j] = 1;
            }
        }
    }
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            if(arr[i][j] == 1){
                if(arr[i + 1][j] == 0){
                    answer++;
                }
                if(arr[i - 1][j] == 0){
                    answer++;
                }
                if(arr[i][j + 1] == 0){
                    answer++;
                }
                if(arr[i][j - 1] == 0){
                    answer++;
                }
            }
        }
    }
    cout << answer << endl;
    return 0;
}