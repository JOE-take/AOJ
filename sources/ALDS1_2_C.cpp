#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


vector<string> selectionSort(vector<string> A, int n){
    for(int i=0; i<n; i++){
        int minj = i;
        for(int j=i; j<n; j++){
            if(A[minj].at(1) > A[j].at(1)){
                minj = j;
            }
        }
        if(minj != i){
            swap(A[minj], A[i]);
        }  
    }

    for(int i=0; i<n-1; i++){
        cout << A[i] << " ";
    }
    cout << A[n-1] << endl;
    return A;
}


vector<string> bubbleSort(vector<string> A,int n){
    bool flag = true;
    while(flag){
        flag = false;
        for(int i=n-1; i>0; i--){
            if(A[i].at(1) < A[i-1].at(1)){
                swap(A[i],A[i-1]);
                flag = true;
            }
        }
    }
    for(int i=0; i<n-1; i++){
        cout << A[i] << " ";
    }
    cout << A[n-1] << endl;
    cout << "Stable" << endl;
    return A;
}



int main(){

    int n,i;
    cin >> n;
    vector<string> in(n);
    for(i=0;i<n;i++) cin >> in[i];
    vector<string> bubble  = bubbleSort(in,n);
    vector<string> select = selectionSort(in,n);
    int count=0;
    for(i=0; i<bubble.size(); i++){
        if(bubble[i] != select[i]) count++; 
    }
    if(count) cout << "Not stable" << endl;
    else cout << "Stable" << endl;
    return 0;
}