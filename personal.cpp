#include <iostream>
#include<stdio.h>
using namespace std;

void line_vect_solve(double* matrix[],int rp,int r,int s);
void print_matrix(double* matrix[],int r,int s);
void reverse_line_vect_solve(double* matrix[],int rp,int s);

int main(){
    int r = 4,s = 5;
    cout<<"Pocitanie matic\n==============\n\n";
    cout <<"Zadajte pocet riakov a stlpcov: \n";
    //cin >> r >> s;

    double* matrix[r];
    for(int i = 0; i<r;i++) matrix[i] = new double[s];
    /*
    for(int i = 0; i<r;i++){
        cout<<"Zadavajte cisla v "<<i<<"-tom riadku:\n";
        for(int j = 0; j<s;j++){
            if(j == s-1){
                cout<<"Vyseldok pre "<<i<<"ty riadok: ";
                cin>>matrix[i][j];
            } else{
                cout<<i<<" "<<j<<": ";
                cin >> matrix[i][j];
            }
        }
    }
    */
    matrix[0][0] =2;
    matrix[0][1] =-1;
    matrix[0][2] =1;
    matrix[0][3] =3;
    matrix[0][4] = -3;
    //matrix[0][5] = 12

    matrix[1][0] =-1;
    matrix[1][1] =2;
    matrix[1][2] =-1;
    matrix[1][3] =-1;
    matrix[1][4] =11;

    matrix[2][0] =3;
    matrix[2][1] =3;
    matrix[2][2] =2;
    matrix[2][3] =-2;
    matrix[2][4] =-32;

    matrix[3][0] =1;
    matrix[3][1] =1;
    matrix[3][2] =1;
    matrix[3][3] =1;
    matrix[3][4] =-2;
    
    
    print_matrix(matrix,r,s);
    printf("Riesenie matice je:\n");
    //cout<<"Matica ma "<<(r>s)?s:r<<" riesenia.\n";
    for(int i = 0; i < r; i++) line_vect_solve(matrix,i,r,s);
    print_matrix(matrix,r,s);
    for(int i = r-2; i >= 0; i--) reverse_line_vect_solve(matrix,i,s);
    print_matrix(matrix,r,s);
    /*for(int rr = r;rr>=0;rr--){
        for(int rs = rr-1; rs>=0;rs--){
            matrix[rr][s-1] += -1*matrix[10][2]*matrix[2][3];
        }
    }
    matrix[1][3] += -1*matrix[1][2]*matrix[2][3];
    matrix[0][3] += -1*matrix[0][2]*matrix[2][3] + (-1) * matrix[1][3]*matrix[0][1];
    matrix[0][1] = 0;
    matrix[0][2] = 0;
    matrix[1][2] = 0;
    */
    cout<<"======\n";
    print_matrix(matrix,r,s);
    for(int i = 0; i<r;i++) delete matrix[i];
    return 0;
}
void line_vect_solve(double* matrix[],int rp,int r,int s){
   
    try{
        if(matrix[rp][rp]==0){
            int plus_r = 1;
            while(matrix[rp][rp] == 0){
                if(matrix[rp+plus_r][rp]==0) plus_r++;
                else{
                    int counter = 0;
                    for(int i= 0; i<s;i++){
                        if(matrix[r-1][i]==0)counter++;
                        if(counter==s){
                            cout<<"Matica ma nekonecne vela rieseni.";
                            exit;
                        }
                    }
                    for(int i = 0;i < s;i++){
                        double temp = matrix[rp+plus_r][i];
                        matrix[rp+plus_r][i] = matrix[rp][i];
                        matrix[rp][i] = temp;
                    }
                    break;
                }
            }
        }
    }catch(int){
        cout<<"Matica ma nekonecne vela rieseni";
    }
    if(matrix[rp][rp]!=1){
        for(int p = s;p>=0;p--){
            matrix[rp][p]/= matrix[rp][rp];
        }
    }
    if(rp==s)exit;
    try{
        for(int i = rp+1; i<s-1;i++){
            int posun = 0;
            double mult = matrix[i][rp];
            for(int j=rp;j<s;j++){
                double substructer = matrix[rp][rp+posun]*mult;
                matrix[i][j]-=substructer;
                posun++;
            }
        }
    }catch(int){
        cout<<"Matica ma nekonecne vela rieseni";
    }
}

void reverse_line_vect_solve(double* matrix[],int cr,int s){
    for(int i = s-2;i>cr;i--){
        matrix[cr][s-1] += -1*matrix[i][s-1]*matrix[cr][i];
        matrix[cr][i] = 0;
    }
}

void print_matrix(double* matrix[],int r,int s){
    for(int i = 0; i<r; i++){
        for(int j = 0; j<s;j++)
            if(j==0)cout<<"( "<<matrix[i][j]<<" ";
            else if(j==(s-1))cout<<"| "<<matrix[i][3]<<" )\n";
            else cout <<matrix[i][j]<<" ";
    }
}