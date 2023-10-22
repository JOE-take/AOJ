//選択ソート
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void selectionSort(vector<int> A, int n){
    int count = 0;
    for(int i=0; i<n; i++){
        int minj = i;
        for(int j=i; j<n; j++){
            if(A[minj] > A[j]){
                minj = j;
            }
        }
        if(minj != i){
            swap(A[minj], A[i]);
            count++;
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
    selectionSort(in, n);
    return 0;
}