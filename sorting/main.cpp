// REVISE SOON  
#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n)
{
    for (int i = 0; i <= n - 2; i++)
    {
        int minIdx = i;
        for (int j = i; j <= n - 1; j++)
        {
            if (arr[j] < arr[minIdx])
            {
                minIdx = j;
            }
        }
        int temp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = temp;
    }
}


void bubbleSort(int arr[],int n){
    for(int i = n-1;i>=1;i--){
        for(int j=0;j<=i;j++){
            if(arr[j]>arr[j+1]){
                // swap
            }
        }
    }
}

void insertionSort(int arr[], int n){
    for(int i =0;i<=n-1;i++){
        int j = i;
        while(j>0 &&  arr[j-1]>arr[j]){
            if(arr[j]<arr[j-1]){
                swap(arr[j],arr[j-1]);
                j--;
            }
        }
    }
}

int main()
{
    int arr[] = {21, 5, 2, 32, 65};
    // selectionSort(arr, 5);
    insertionSort(arr,5);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}