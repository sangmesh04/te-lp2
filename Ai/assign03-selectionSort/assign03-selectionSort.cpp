//
// Created by Sangmeshwar on 5/23/2023.
//

/*
 Implement Greedy search algorithm for any of the following application:
    I. Selection Sort
 */
#include<bits/stdc++.h>
using namespace std;

int *selectionSort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        int minIndex = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
    return arr;
}

int main(){
    int n, a;
    cout<<"Enter the size of an array: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter the "<<i<<"th element: ";
        cin>>arr[i];
    }
    cout<<"\nInitial array: "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int *sortedArr = selectionSort(arr, n);
    cout<<"\nSorted array: "<<endl;
    for(int i=0;i<n;i++){
        cout<<sortedArr[i]<<" ";
    }
    cout<<endl;
    return 0;
}