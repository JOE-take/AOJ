#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<queue>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int n,q;

bool search(int A[], int m, int cur){
    if(m == 0) return true;
    if(cur >= n) return false;
    return search(A, m, cur + 1) || search(A, m - A[cur], cur + 1);
}

int main(){
    cin >> n;
    int A[n];
    rep(i,n) cin >> A[i];
    cin >> q;
    int M[q];
    rep(i,q) cin >> M[i]; 
    for(int i=0; i<q; i++){
        if(search(A, M[i], 0)) cout << "yes" << "\n";
        else cout << "no" << "\n";
    }
    return 0;
}