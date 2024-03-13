#include<iostream>
#include<vector>
using namespace std;

void pr(int A[],int n){
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
}
void swap(int &a,int &b){
    int c = a;
    a = b;
    b = c;
}
//Select Sort
void selectSort(int A[],int n){
    for(int i=0;i<n-1;i++){
        int min = i;
        for(int j = i;j<n;j++){
            if(A[j] < A[min])
                min = j;
        }
        swap(A[min],A[i]);
    }
}
//Bubble Sort
void bubbleSort(int A[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(A[j]>A[j+1]){
                swap(A[j],A[j+1]);
            }
        }
    }
}
//Insertion Sort
void insertionSort(int A[],int n){
    for(int i = 1; i < n ; i++){
        int key = A[i];
        int j = i-1;
        while (j>=0 && A[j] > key)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }
}
//Merge Sort - O(nlogn)
void merge(int A[],int l,int m,int r){
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1],R[n2];

    for(int i=0; i<n1; i++){
        L[i] = A[l + i];
    }
    for(int j = 0; j < n2; j++){
        R[j] = A[m + 1 + j];
    }
    int i=0,j=0;
    int k = l;
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }
        else{
            A[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        A[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        A[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int A[],int l,int r){
    // if(l>=r)
    //     return;
    if(r>l){
        // Tương tự (l+r)/2, nhưng cách này tránh tràn số khi l và r lớn
        int m = l+(r-l)/2;
        mergeSort(A,l,m);
        mergeSort(A,m+1,r);
        merge(A,l,m,r);
    }
}
//Gnome Sort
void gnomeSort(int A[],int n){
    int i = 0;
    while (i < n )
    {
        if(i == 0 || A[i] >= A[i-1]){
            i++;
        }
        else{
            swap(A[i],A[i-1]);
            i--;
        }
    }
    
}
int partition(int A[],int low,int high){
    int pivot = A[high];
    int i = low -1;

    for(int j = low; j<=high-1; j++){
        if(A[j] < pivot){
            i++;
            if(j != i)
                swap(A[i],A[j]);
        }
    }
    swap(A[i+1],A[high]);
    return i+1;

}
//Quick Sort nlogn
void quickSort(int A[],int low,int high){
    if(low < high){
        int index = partition(A,low,high);
        quickSort(A,low,index - 1);
        quickSort(A,index + 1,high);
    }
}
//
int main(){
    int n=10;
    int A[10] = {10,2,1,3,2,2,9,6,7,5};
    vector<int> Arr = {10,2,1,3,2,2,9,6,7,5};
    pr(A,n);
    cout<<"\n";

    //cout << "Selecet Sort: ";
    //selectSort(A,n);

    //cout << "Bubble Sort: ";
    //bubbleSort(A,n);

    //cout << "Insertion Sort: ";
    //insertionSort(A,n);

    //cout << "Merge Sort: ";
    //mergeSort(A,0,n - 1);
    
    // cout << "Gnome Sort: ";
    // gnomeSort(A,n);
    //
    cout << "Quick Sort: ";
    quickSort(A,0,n - 1);
    
    pr(A,n);
}