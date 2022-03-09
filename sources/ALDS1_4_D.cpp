#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<queue>
using namespace std;

int n,k;
    
int func(long long W[], long long P){
    int j = 0;
    long long sum = 0;
    for(int i=0; i<k; i++){
        sum = 0;
        while(sum + W[j] <= P){
            sum += W[j];
            j++;
            if(j == n) return n;
        }
    }
    return j;
}

int main(){
    cin >> n >> k;
    long long W[n];
    for(int i=0; i<n; i++) cin >> W[i];

    long long left = 0;
    long long right = 100000*10000;
    long long mid = 0;
    while(right - left > 1){
        mid = (right + left) / 2;
        if(func(W, mid) >= n) right = mid;
        else left = mid;
    }
    cout << right << "\n";
    return 0;
}