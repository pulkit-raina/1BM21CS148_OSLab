#include<stdio.h>

void matrix_addition(int a[100][100], int b[100][100], int c[100][100], int n);
void matrix_subraction(int a[100][100], int b[100][100], int c[100][100], int n);
void matrix_multiplication(int a[100][100], int b[100][100], int c[100][100], int n);
void matrix_print(int c[100][100], int n);
void matrix_insertion(int c[100][100],int n);

void main(){
    int n, choice;
    int a[100][100], b[100][100], c[100][100];
    printf("Enter the dimension of matrix: ");
    scanf("%d", &n);
    printf("Enter the first matrix: ");
    matrix_insertion(a, n);
    printf("Enter the second matrix: ");
    matrix_insertion(b, n);
    printf("Enter\n1. Matrix Addition\n2. Matrix Subtraction\n3. Matrix Multiplication\n4. Exit: ");
    do{
        scanf("%d", &choice);
        switch(choice){
            case 1: matrix_addition(a, b, c, n);
                    break;
            case 2: matrix_subraction(a, b, c, n);
                    break;
            case 3: matrix_multiplication(a, b, c, n);
                    break;
            case 4: exit(0);
            default: printf("Incorrect Input!\n");
                    break;
        }
        printf("Result Matrix is: \n");
        matrix_print(c, n);
    }while(choice!=4);
}

void matrix_addition(int a[100][100], int b[100][100], int c[100][100], int n){
    int i, j;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void matrix_subraction(int a[100][100], int b[100][100], int c[100][100], int n){
    int i, j;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            c[i][j] = a[i][j] - b[i][j];
        }
    }
}

void matrix_multiplication(int a[100][100], int b[100][100], int c[100][100], int n){
    int i, j, k;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            c[i][j] = 0;
            for(k = 0; k<n; k++){
                c[i][j] += a[i][k]*b[k][j];
            }
        }
    }
}

void matrix_print(int c[100][100], int n){
    int i, j;
    for(i=0; i<n; i++){
        for(j = 0; j<n; j++){
            printf("%d  ", c[i][j]);
        }
        printf("\n");
    }
}

void matrix_insertion(int c[100][100], int n){
    int i, j;
    for(i=0; i<n; i++){
        for(j = 0; j<n; j++){
            scanf("%d", &c[i][j]);
        }
    }
}