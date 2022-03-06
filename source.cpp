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
    int count = 0;
    int current = 0;
    int left = 0;
    int right = n;

    for(int i=0; i<q; i++){
        while(left < right){
            current = (right + left) / 2;
            if(T[i] == S[current]){
                count++;
                break;
            }
            else if(S[current] < T[i]){
                left = current + 1;
            }
            else if(T[i] < S[current]){
                right = current;
            }
        }
        current = 0; left = 0; right = n;
    }
    cout << count << "\n";
    return 0;
}