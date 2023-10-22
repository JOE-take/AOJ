#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<stack>
using namespace std;

int main(){
    int n,q;
    cin >> n;
    vector<int> S(n);
    for(int i=0; i<n; i++){
        cin >> S[i];
    }
    cin >> q;
    vector<int> T(q);
    for(int i=0; i<q; i++){ 
        cin >> T[i];
    }
    vector<int> P;
    for(int i=0; i<n; i++){
        
    }
    int k = 0;
    int count;
    S.push_back(0);
    for(int i=0; i<T.size(); i++){
        k = 0;
        S[n] = T[i];
        while(S[k] != T[i]) k++;
        if(k != n) count++;
    }
    cout << count << "\n";
    return 0;
}