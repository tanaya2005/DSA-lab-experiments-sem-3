#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

void bubblesort(int arr[], int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1-i;j++){
            if (arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

void insertionsort(int arr[], int n){
    for(int i=0;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

void selectionsort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        int minind=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minind]){
                minind=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[minind];
        arr[minind]=temp;
    }
}

int main() {
    int a,n,choice;
   
    printf("enter the no.of elements in the array : ");
    scanf("%d",&n);
     int arr[n];
    for(int i=0;i<n;i++){
    printf("element %d: ",i+1);
    scanf("%d",&arr[i]);
    }
    
    printf("\nchose a sorting method for your array:\n1.bubble sort\n2.insertion sort\n3.selection sort\n4.exit\n ");
        scanf("%d",&choice);
        switch(choice){
        case 1:
        bubblesort(arr,n);
        break;
        case 2:
        insertionsort(arr,n);
        break;
        case 3:
        selectionsort(arr,n);
        break;
        case 4:
        exit(0);
        break;
        }
    printf("\nthe SORTED array is: \n");
    for(int i=0;i<n;i++){
        printf("%d  ",arr[i]);
    }
    
    return 0;
}
