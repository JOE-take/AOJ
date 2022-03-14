#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<queue>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define PI 3.141592
struct coordinate{
    double x;
    double y;
};

vector<coordinate> _OUTPUT(1); 

void koch(int n, coordinate left, coordinate right){
    if ( n == 0 ){
        return;
    }
    coordinate s, t, u;
    s.x = left.x - (left.x - right.x) / 3;
    s.y = left.y - (left.y - right.y) / 3;
    t.x = left.x - 2 * (left.x - right.x) / 3;
    t.y = left.y - 2 * (left.y - right.y) / 3;
    u.x = (t.x - s.x)*cos(60*PI/180) - (t.y - s.y)*sin(60*PI/180) + s.x;
    u.y = (t.x - s.x)*sin(60*PI/180) + (t.y - s.y)*cos(60*PI/180) + s.y;
    koch(n - 1, left, s);
    _OUTPUT.push_back(s);
    koch(n - 1, s, u);
    _OUTPUT.push_back(u);
    koch(n - 1, u, t);
    _OUTPUT.push_back(t);
    koch(n - 1, t, right);
}


int main(){
    int n = 0;
    cin >> n;
    _OUTPUT[0].x = 0; _OUTPUT[0].y = 0;
    coordinate finite; finite.x = 100; finite.y = 0;
    koch(n, _OUTPUT[0], finite); 
    _OUTPUT.push_back(finite);    
    for(auto it : _OUTPUT ) cout << it.x << " " << it.y << "\n";
    return 0;
}