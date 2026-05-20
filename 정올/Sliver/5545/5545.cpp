#include <iostream>
using namespace std;

long long gcd(long long a, long long b){
    if (b == 0) 
        return a;
    return gcd(b, a % b);
}

long long lcm(long long a, long long b){
    return (a / gcd(a, b)) * b;
}

int main(){
    int p, v, k;
    cin >> p >> v >> k;

    long long cnt[4];
    cnt[1] = k / lcm(p + 1, v + 1);
    cnt[2] = k / (v + 1) - cnt[1];
    cnt[3] = k / (p + 1) - cnt[1];
    cnt[0] = k - cnt[2] - cnt[1] - cnt[3];
    for(int i = 0; i < 4; i++){
        cout << cnt[i] << " ";
    }
    return 0;
}