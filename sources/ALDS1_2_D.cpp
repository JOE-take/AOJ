//shell sort
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int cnt = 0;

void insertationSort(vector<int>& A, int n, int g){
    for(int i=g; i<n; i++){
        int v = A[i];
        int j = i - g;
        while(j>=0 && A[j]>v){
            A[j+g] = A[j];
            A[j] = v;
            j = j - g;
            cnt++;
        }
    }
}


void shellSort(vector<int>& A,int n){

    //G‚Ì”—ñ‚ğ‚Â‚­‚é
    vector<int> G(1,1);
    while( n >= G.back()){
        G.push_back( 3 * G.back() + 1);
    }
    G.pop_back();
    reverse(G.begin(), G.end());
    for(auto it : G){
        insertationSort(A, n, it);   
    }
    if(cnt > pow(cnt, 1.5)){
        cout << "cnt exeeds the allowable amount ";
        return;
    }
    cout << G.size() << "\n";
    for(int i = 0; i < G.size() -1; i++){
        cout << G[i] << " ";
    }
    cout << G.back() << "\n" << cnt << "\n";
    for(auto it : A) cout << it << "\n";

 }


int main(){

    int n,i;
    cin >> n;
    vector<int> in(n);
    for(i=0;i<n;i++) cin >> in[i];
    shellSort(in,n);
    return 0;
}