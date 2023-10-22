//‘}“üƒ\[ƒg
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


void insertationSort(vector<int> in, int n){
    for(int k=0; k<n-1; k++){
        cout << in[k] << " ";
    }
    cout << in[n-1] << endl;
    
    for(int i=1;i<n;i++){
        int j = i-1;
        int v = in[i];
        while( j>=0 && v < in[j]){
        in[j+1] = in[j];
        in[j] = v;
        j--;
        }

        for(int k=0; k<n-1; k++){
            cout << in[k] << " ";
        }
        cout << in[n-1] << endl;
    }
}


int main(){

    int n,i;
    cin >> n;
    vector<int> in(n);
    for(i=0;i<n;i++) cin >> in[i];
    insertationSort(in, n);

    return 0;
}