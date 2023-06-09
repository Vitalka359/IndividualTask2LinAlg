#include <iostream>
using namespace std;

void f2 (long double a[3], long double b[3]){
    long double res[3][3] = {{0,0,0}, {0,0,0}, {0,0,0}};
    for(int i = 0; i<3; i++)
        for(int u = 0; u<3; u++)
            res[i][u] = a[i]*b[u];
    long double ans[3][3] = {{0,0,0}, {0,0,0}, {0,0,0}};
    for(int i = 0; i<3; i++)
        for(int u = 0; u<3; u++)
            ans[i][u] = (res[i][u]-res[u][i])/2;
    
    cout << "\\left[\\begin{array}{ccc}\n";
    for(int i = 0; i<3; i++)
        for(int u = 0; u<3; u++)
            if(u == 2) cout << res[i][u] << "\\\\ \n";
            else cout << res[i][u] << " & ";
    cout << "\\end{array}\\right] \n\n";
}

void f3 (long double a[3], long double b[3], long double c[3]){
    long double res[3][3][3] = {{{0,0,0}, {0,0,0}, {0,0,0}}, {{0,0,0}, {0,0,0}, {0,0,0}}, {{0,0,0}, {0,0,0}, {0,0,0}}};
    for(int i = 0; i<3; i++)
        for(int u = 0; u<3; u++)
            for(int o = 0; o<3; o++)
                res[i][u][o] = a[i]*b[u]*c[o];
    long double ans[3][3][3] = {{{0,0,0}, {0,0,0}, {0,0,0}}, {{0,0,0}, {0,0,0}, {0,0,0}}, {{0,0,0}, {0,0,0}, {0,0,0}}};
    for(int i = 0; i<3; i++)
        for(int u = 0; u<3; u++)
            for(int o = 0; o<3; o++)
                ans[i][u][o] = (res[i][u][o]-res[i][o][u]+res[o][i][u]-res[o][u][i]+res[u][o][i]-res[u][i][o])/6;
    
    cout << "\\left[";
    for(int i = 0; i<3; i++){
        cout << "\\left[\\begin{array}{ccc}\n";
        for(int u = 0; u<3; u++){
            for(int o = 0; o<3; o++){
                if(o == 2) cout << ans[i][u][o] << "\\\\ \n";
                else cout << ans[i][u][o] << " & ";
            }
        }
        cout << "\\end{array}\\right] \n";
    } cout << "\\right] \n\n\n";
}
void f4 (long double a[3], long double b[3], long double c[3], long double d[3]){
    long double res[3][3][3][3] = {{{{0,0,0}, {0,0,0}, {0,0,0}}, {{0,0,0}, {0,0,0}, {0,0,0}}, {{0,0,0}, {0,0,0}, {0,0,0}}}, {{{0,0,0}, {0,0,0}, {0,0,0}}, {{0,0,0}, {0,0,0}, {0,0,0}}, {{0,0,0}, {0,0,0}, {0,0,0}}}, {{{0,0,0}, {0,0,0}, {0,0,0}}, {{0,0,0}, {0,0,0}, {0,0,0}}, {{0,0,0}, {0,0,0}, {0,0,0}}}};
    for(int i = 0; i<3; i++)
        for(int u = 0; u<3; u++)
            for(int o = 0; o<3; o++)
                for(int k = 0; k<3; k++)
                res[i][u][o][k] = a[i]*b[u]*c[o]*d[k];
    long double ans[3][3][3][3] = {{{{0,0,0}, {0,0,0}, {0,0,0}}, {{0,0,0}, {0,0,0}, {0,0,0}}, {{0,0,0}, {0,0,0}, {0,0,0}}}, {{{0,0,0}, {0,0,0}, {0,0,0}}, {{0,0,0}, {0,0,0}, {0,0,0}}, {{0,0,0}, {0,0,0}, {0,0,0}}}, {{{0,0,0}, {0,0,0}, {0,0,0}}, {{0,0,0}, {0,0,0}, {0,0,0}}, {{0,0,0}, {0,0,0}, {0,0,0}}}};
    for(int i = 0; i<3; i++)
        for(int u = 0; u<3; u++)
            for(int o = 0; o<3; o++)
                for(int k = 0; k<3; k++)
            ans[i][u][o][k] = (res[i][u][o][k]-res[i][o][u][k]+res[o][i][u][k]-res[o][u][i][k]+res[u][o][i][k]-res[u][i][o][k]+
                res[i][k][u][o]-res[i][k][o][u]+res[o][k][i][u]-res[o][k][u][i]+res[u][k][o][i]-res[u][k][i][o]-
                (res[k][i][u][o]-res[k][i][o][u]+res[k][o][i][u]-res[k][o][u][i]+res[k][u][o][i]-res[k][u][i][o]+
                res[i][u][k][o]-res[i][o][k][u]+res[o][i][k][u]-res[o][u][k][i]+res[u][o][k][i]-res[u][i][k][o]))/24;
    
    cout << "\\left[";
    for(int i = 0; i<3; i++){
        for(int u = 0; u<3; u++){
            cout << "\\left[\\begin{array}{ccc}\n";
            for(int o = 0; o<3; o++)
                for(int k = 0; k<3; k++)
                    if(k == 2) cout << ans[i][u][o][k] << "\\\\ \n";
                    else cout << ans[i][u][o][k] << " & ";
            cout << "\\end{array}\\right] \n";
        }
    } cout << "\\right] \n\n\n";
}

int main() {
    long double arr[3]= {-3, -1, -2};
    long double brr[3]= {-3, 3, 1};
    long double crr[3]= {3, 3, -1};
    long double drr[3]= {-2, 3, 2};
    
    long double res[3][3][3] = {{{0,0,0}, {0,0,0}, {0,0,0}}, {{0,0,0}, {0,0,0}, {0,0,0}}, {{0,0,0}, {0,0,0}, {0,0,0}}};
/*
    cout << "A_i \\wedge B_j = "; f2(arr, brr);
    cout << "A_i \\wedge C_k = "; f2(arr, crr);
    cout << "A_i \\wedge D_l = "; f2(arr, drr);
    cout << "B_j \\wedge C_k = "; f2(brr, crr);
    cout << "B_j \\wedge D_l = "; f2(brr, drr);
    cout << "C_k \\wedge D_l = "; f2(crr, drr);
    
    cout << "B_j \\wedge A_i = "; f2(arr, brr);
    cout << "C_k \\wedge A_i = "; f2(arr, crr);
    cout << "D_l \\wedge A_i = "; f2(arr, drr);
    cout << "C_k \\wedge B_j = "; f2(brr, crr);
    cout << "D_l \\wedge B_j = "; f2(brr, drr);
    cout << "D_l \\wedge C_k= "; f2(crr, drr);
    */
/*
    cout << "A_i \\wedge B_j \\wedge C_k = "; f3(arr, brr, crr);
    cout << "A_i \\wedge B_j \\wedge D_l = "; f3(arr, brr, drr);
    cout << "A_i \\wedge C_k \\wedge B_j = "; f3(arr, crr, brr);
    cout << "A_i \\wedge C_k \\wedge D_l = "; f3(arr, crr, drr);
    cout << "A_i \\wedge D_l \\wedge B_j = "; f3(arr, drr, brr);
    cout << "A_i \\wedge D_l \\wedge C_k = "; f3(arr, drr, crr);

    cout << "B_j \\wedge A_i \\wedge C_k = "; f3(brr, arr, crr);
    cout << "B_j \\wedge A_i \\wedge D_l = "; f3(brr, arr, drr);
    cout << "B_j \\wedge C_k \\wedge A_i = "; f3(brr, crr, arr);
    cout << "B_j \\wedge C_k \\wedge D_l = "; f3(brr, crr, drr);
    cout << "B_j \\wedge D_l \\wedge A_i = "; f3(brr, drr, arr);
    cout << "B_j \\wedge D_l \\wedge C_k = "; f3(brr, drr, crr);

    cout << "C_k \\wedge B_j \\wedge A_i = "; f3(crr, brr, arr);
    cout << "C_k \\wedge B_j \\wedge D_l = "; f3(crr, brr, drr);
    cout << "C_k \\wedge A_i \\wedge B_j = "; f3(crr, arr, brr);
    cout << "C_k \\wedge A_i \\wedge D_l = "; f3(crr, arr, drr);
    cout << "C_k \\wedge D_l \\wedge B_j = "; f3(crr, drr, brr);
    cout << "C_k \\wedge D_l \\wedge A_i = "; f3(crr, drr, arr);

    cout << "D_l \\wedge B_j \\wedge C_k = "; f3(drr, brr, crr);
    cout << "D_l \\wedge B_j \\wedge A_i = "; f3(drr, brr, arr);
    cout << "D_l \\wedge C_k \\wedge B_j = "; f3(drr, crr, brr);
    cout << "D_l \\wedge C_k \\wedge A_i = "; f3(drr, crr, arr);
    cout << "D_l \\wedge A_i \\wedge B_j = "; f3(drr, arr, brr);
    cout << "D_l \\wedge A_i \\wedge C_k = "; f3(drr, arr, crr);
    */
    cout << "A_i \\wedge B_j \\wedge C_k \\wedge D_l = "; f4(arr, brr, crr, drr);
} 