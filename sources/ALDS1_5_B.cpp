
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<queue>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MAX 1000000001

int ctr = 0;

vector<int> mergee(vector<int> L, vector<int> R){
    int left = 0;
    int right = L.size() + R.size() + 1;
    int mid = (right + left ) / 2;
    L.push_back(MAX);
    R.push_back(MAX);
    vector<int> merged(right - 1);
    int i = 0;
    int j = 0;
    int loopctr = right - 1;
    int k = 0;
    while(loopctr){
        loopctr--;
        ctr++;
        if(L[i] <= R[j]){
            merged[k] = L[i];
            i++;
            k++;
        } else {
            merged[k] = R[j];
            j++;
            k++;
        }
    }
    R.pop_back();
    L.pop_back();
    return merged;
}


vector<int> mergesort(vector<int> A){
    if(A.size() == 1) return A;
    int left = 0;
    int right = A.size();
    int mid = (right + left) / 2;
    vector<int> L,R;
    int n1 = mid - left;
    int n2 = right - mid;
    for(int i = 0; i < n1; i++) L.push_back(A[left + i]);
    for(int i = 0; i < n2; i++) R.push_back(A[mid + i]);
    return mergee(mergesort(L), mergesort(R));
}





int n;
int main(){
    cin >> n;
    vector<int> IN(n);
    rep(i, n) cin >> IN[i];
    vector<int> OUT(n);
    OUT = mergesort(IN);     
    for(int i=0; i < OUT.size() - 1; i++) cout << OUT[i] << " ";
    cout << OUT[OUT.size() - 1] << "\n";
    cout << ctr << "\n";
    return 0;
}