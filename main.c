#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void getSize(int* columns, int* rows)
{
    printf("Enter the matrix's rows: ");
    scanf("%d", rows);
    printf("Enter the matrix's column: ");
    scanf("%d", columns);
}

void getMatrix(double matrix[50][50], int columns, int rows)
{
    int i, j;
    for(i=0; i<rows; i++)
    {
        for(j=0; j<columns; j++)
        {
            printf("Enter the value of matrix[%d][%d]: ", i+1, j+1);
            scanf("%lf", &matrix[i][j]);
        }
    }
}

void printMatrix(double matrix[50][50], int columns, int rows)
{
    int i, j;
    printf("\n");
    for(i=0; i<rows; i++)
    {
        for(j=0; j<columns; j++)
        {
            printf("%0.1lf\t", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void add(double matrixOne[50][50],double matrixTwo[50][50], int columns, int rows, double result[50][50])
{
    int i, j;
    printf("Enter the Second matrix: \n");
    getMatrix(matrixTwo, columns, rows);

    for(i=0; i<rows; i++)
    {
        for(j=0; j<columns; j++)
        {
            result[i][j] = matrixOne[i][j] + matrixTwo[i][j];
        }
    }
    printf("\nThe Result: \n--------------------\n");
    printMatrix(result, columns, rows);
}

void sub(double matrixOne[50][50],double matrixTwo[50][50], int columns, int rows, double result[50][50])
{
    int i, j;
    printf("Enter the Second matrix: \n");
    getMatrix(matrixTwo, columns, rows);

    for(i=0; i<rows; i++)
    {
        for(j=0; j<columns; j++)
        {
            result[i][j] = matrixOne[i][j] - matrixTwo[i][j];
        }
    }
    printf("\nThe Result: \n--------------------\n");
    printMatrix(result, columns, rows);
}

void multi(double matrixOne[50][50],double matrixTwo[50][50], int* frstColumns, int* frstRows,int* secColumns, int* secRows, double result[50][50])
{
    int i,j,k;
    *secRows = *frstColumns;
    for(i=0; i<50; i++)
    {
        for(j=0; j<50; j++)
        {
            result[i][j] =0;
        }
    }
    printf("\nEnter the second matrix's columns: ");
    scanf("%d", secColumns);
    printf("\nEnter the Second matrix: \n");
    getMatrix(matrixTwo, *secColumns, *secRows);

    for(i=0; i<*frstRows; i++)
    {
        for(j=0; j<*secColumns; j++)
        {
            for(k=0; k<*secRows; k++)
            {
                result[i][j] += matrixOne[i][k] * matrixTwo[k][j];
            }
        }
    }
    printf("\nThe Result: \n--------------------\n");
    printMatrix(result, *secColumns, *frstRows);
}

int main()
{
    //Declaring the variables
    char choice =0;
    double matrixOne[50][50] = {};
    double matrixTwo[50][50] = {};
    double result[50][50] = {};
    int columns =0, rows=0 ,secColumns =0, secRows=0;

    printf("Matrices Operations\n---------------------------------\n");
    while(1) //for repeating as much the user want
    {
        printf("\n1-Enter Matrix 1 \t 2-Print the matrices \n3-Addition \t\t 4-Subtraction \n5-Multiplication \t Exit: Type 'end'\n");
        printf("\n*Choose an option: ");
        backAgain: // in case a wrong input of "end" statement
    do
    {
        if(choice!=0) printf("Wrong input!, Please try again: ");
//        scanf("%d", &choice);
        choice = getche();
        if(choice == 'e' || choice == 'E') break;
        printf("\n");
    }   while(choice>'5' || choice <'1');

    if(choice == 'e' || choice == 'E') break;
        switch(choice)
        {
            case '1':
                getSize(&columns, &rows);
                getMatrix(matrixOne, columns, rows);
                secRows = rows;
                secColumns = columns;
                choice =0;
                system("cls");
                break;
            case '2':
                printf("\nMatrix 1:");
                printMatrix(matrixOne, columns, rows);
                printf("Matrix 2:");
                printMatrix(matrixTwo, secColumns, secRows);
                printf("Result:");
                printMatrix(result, secColumns, rows);
                choice =0;
                break;
            case '3':
                secColumns = columns;
                secRows = rows;
                add(matrixOne, matrixTwo, columns, rows, result);
                choice =0;
                break;
            case '4':
                secColumns = columns;
                secRows = rows;
                sub(matrixOne, matrixTwo, columns, rows, result);
                choice =0;
                break;
            case '5':
                multi(matrixOne, matrixTwo, &columns, &rows, &secColumns, &secRows, result);
                choice =0;
                break;
//            case 6:
//                exit(0);
        }

    }
    if(choice == 'e' || choice == 'E')
            {
                choice = getche();
                if(choice == 'n' || choice == 'N')
                {
                    choice = getche();
                    if(choice == 'd' || choice == 'D')
                    {
                        exit(0);
                    }
                }
            }
        goto backAgain;

    return 0;
}
