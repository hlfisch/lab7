//COP3502C Programming Assignment 2a
//<Toast Fischer> <Spring 2024>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int n){
    int fArr[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int temp[n];
    for(int i = 0; i < n; i++){
        temp[i] = arr[i];
    }

    int min;
    int total = 0;
    for(int i = 0; i < n-1; i++){
        min = i; 
        for(int j = i+1; j < n; j++){ 
            if(arr[j] < arr[min]){ 
                min = j;
            }
            if(min != i){
                total++;
                for(int k = 0; k < n; k++){
                    if(arr[j] == temp[k]){
                        fArr[k]++;
                    }
                }
                swap(&arr[min], &arr[i]);
            }
        }
    }

    //Print
    printf("Total # of swaps: %d\n", total);
    for(int i = 0; i < n; i++){
        printf("Times %d was swapped: %d\n", temp[i], fArr[i]);
    }
}

void bubbleSort(int arr[], int n){
    int fArr[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int temp[n];
    for(int i = 0; i < n; i++){
        temp[i] = arr[i];
    }

    bool done;
    int total = 0;
    for(int i = 0; i < n-1; i++) {
        done = true;
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j + 1]) {
                for(int k = 0; k < n; k++){
                    if(arr[j] == temp[k]){
                        fArr[k]++;
                    }
                }
                swap(&arr[j], &arr[j + 1]);
                total++;
                done = false;
            }
        }
        if (done == true)
            break;
    }

    //Print
    printf("Total # of swaps: %d\n", total);
    for(int i = 0; i < n; i++){
        printf("Times %d was swapped: %d\n", temp[i], fArr[i]);
    }
}

//MAIN FUNCTION
void main(){
    int arr1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int arr2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n = 9;
    printf("Bubble sort array 1:\n");
    bubbleSort(arr1, n);
    printf("\n");
    printf("Bubble sort array 2:\n");
    bubbleSort(arr2, n);
    printf("\n");

    int arr3[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int arr4[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    printf("Selection sort array 1:\n");
    selectionSort(arr3, n);
    printf("\n");
    printf("Selection sort array 2:\n");
    selectionSort(arr4, n);
}