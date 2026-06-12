#include <bits/stdc++.h>
using namespace std;

int main(){
    

// Methods Of Representation 


    // 1. Everything in stack region 
    int A[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};


    // 2. Elements are in heap, where pointers pointing to those rows are in stack
    int * B[3];
    B[0] = new int[4];
    B[1] = new int[4];
    B[2] = new int[4];

    int num = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            B[i][j] = num++;
        }
    }


    // 3. Elements and the pointer pointing to those rows both in heap, 
    // where the pointer pointing to the array of pointers is in the stack
    int **C;   
    C = new int *[3];

    C[0] = new int[4];
    C[1] = new int[4]; 
    C[2] = new int[4]; 

    num = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            C[i][j] = num++;
        }
    }


// Accessing elements through different representations
    
    printf("Representation 1 \n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++)
            printf("%d ", A[i][j]);
        printf("\n");
    }

    printf("\nRepresentation 2 \n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++)
            printf("%d ", B[i][j]);
        printf("\n");
    }

    printf("\nRepresentation 3 \n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }


// Deallocation
    
    for (int i = 0; i < 3; i++) {
        delete[] B[i];
    }

    for (int i = 0; i < 3; i++) {
        delete[] C[i];
    }
    delete[] C;

    return 0;
}