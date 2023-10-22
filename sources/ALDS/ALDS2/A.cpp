//バブルソート
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



void bubbleSort(vector<int> A,int n){
    int count = 0;
    bool flag = true;
    while(flag){
        flag = false;
        for(int i=n-1; i>0; i--){
            if(A[i] < A[i-1]){
                swap(A[i],A[i-1]);
                flag = true;
                count++;
            }
        }
    }
    for(int i=0; i<n-1; i++){
        cout << A[i] << " ";
    }
    cout << A[n-1] << endl << count << endl;
}

int main(){

    int n,i;
    cin >> n;
    vector<int> in(n);
    for(i=0;i<n;i++) cin >> in[i];
    bubbleSort(in,n);
    return 0;
}