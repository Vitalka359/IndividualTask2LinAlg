#include <iostream>
using namespace std;


int main() {
    float arr[3][3][3]= {{{0, -3, -1}, {1, 0, 2}, {1, -2, 2}}, {{-1, 0, 0}, {-2, -3, -2}, {2, -2, -3}}, {{3, -3, -3}, {-3, -2, -2}, {2, -3, 0}}};
    float res[3][3][3] = {{{0,0,0}, {0,0,0}, {0,0,0}}, {{0,0,0}, {0,0,0}, {0,0,0}}, {{0,0,0}, {0,0,0}, {0,0,0}}};
    for(int i = 0; i<3; i++){
        for(int u = 0; u<3; u++){
            for(int y = 0; y<3; y++){
                res[i][u][y] = (arr[i][u][y]+arr[i][y][u]+arr[y][u][i]+arr[y][i][u]+arr[u][i][y]+arr[u][y][i])/6;
    }}}
    cout << "\\left[";
    for(int i = 0; i<3; i++){
        cout << "\\left[\\begin{array}{ccc}\n";
        for(int u = 0; u<3; u++){
            for(int y = 0; y<3; y++){
                if(y == 2) cout << res[u][i][y] << "\\\\ \n";
                else cout << res[u][i][y] << " & ";
            }
        }
        cout << "\\end{array}\\right] \n";
    } cout << "\\right] \n\n\n";

    for(int i = 0; i<3; i++){
        for(int u = 0; u<3; u++){
            for(int y = 0; y<3; y++){
                res[i][u][y] = (arr[i][u][y]-arr[i][y][u]-arr[y][u][i]+arr[y][i][u]-arr[u][i][y]+arr[u][y][i])/6;
    }}}

    
    cout << "\\left[";
    for(int i = 0; i<3; i++){
        cout << "\\left[\\begin{array}{ccc}\n";
        for(int u = 0; u<3; u++){
            for(int y = 0; y<3; y++){
                if(y == 2) cout << res[u][i][y] << "\\\\ \n";
                else cout << res[u][i][y] << " & ";
            }
        }
        cout << "\\end{array}\\right] \n";
    } cout << "\\right] \n\n\n";
} 