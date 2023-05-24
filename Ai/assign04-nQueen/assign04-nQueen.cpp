//
// Created by Sangmeshwar on 5/23/2023.
//

/*
    Implement a solution for a Constraint Satisfaction Problem using Branch and Bound and
    Backtracking for n-queens problem or a graph coloring problem
 */

#include<bits/stdc++.h>
using namespace std;

bool isSafePlace(int **arr, int x, int y, int n){
    // row wise
    for(int row=0;row<x;row++){
        if(arr[row][y]){
            return false;
        }
    }
    // diagonally left
    int row = x, col = y;
    while(row>=0 && col>=0){
        if(arr[row][col]){
            return false;
        }
        row--;
        col--;
    }
    // diagonally right
    row = x, col = y;
    while(row>=0 && col<n){
        if(arr[row][col]){
            return false;
        }
        row--;
        col++;
    }
    return true;
}

bool nQueen(int **arr, int x, int n){
    if(x>=n){
        return true;
    }
    for(int col=0;col<n;col++){
        if(isSafePlace(arr, x, col, n)){
            arr[x][col] = 1;
            if(nQueen(arr, x+1, n)){
                return true;
            }
            // backtracking
            arr[x][col] = 0;
        }
    }
    return false;
}

int main(){
    int n;
    cout<<"Enter num of queens: ";
    cin>>n;
    int **arr = new int *[n];
    for(int i=0;i<n;i++){
        arr[i] = new int[n];
        for(int j=0;j<n;j++){
            arr[i][j] = 0;
        }
    }
    if(nQueen(arr, 0, n)){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j]){
                    cout<<"Q ";
                }else{
                    cout<<". ";
                }
            }
            cout<<endl;
        }
    }else{
        cout<<"Solution does not exists!"<<endl;
    }
    return 0;
}