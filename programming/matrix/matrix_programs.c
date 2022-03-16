#include<stdio.h>
#include<stdlib.h>


/******************************************
 *          UTILITY FUNCTION TO SWAP STUFF IN MATRIX
 * **************************************************/

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a= *b;
    *b = temp;
}
//to pass a 2d array to a function you can simply do this. 
void printmatrix(int n, int arr[n][n] )
{
    for(int i =0 ; i<n; i++)
    {
        for(int j =0 ; j<n; j++)
        {
           printf("%d ", arr[i][j]);
           //arr[i][j] = arr[i][j];

            
        }
        printf("\n");
    }
}
/******************************************************
 * program to rotate 90 degrees clockwise 
 * 
 * ******************************************************/

void rotate90Clock(int r, int c, int arr[][c])
{
    //first we do the transpose of the matrix
    //transpose --- (0,1) --> (1, 0) and so on
    for(int i =0; i<r; i++)
    {
        for(int j =i; j<c; j++)
        {
            swap(&arr[i][j], &arr[j][i]);
        }
    }
    //then we reverse the matrix
    //for reverse WE SWAP COLUMNS
    for(int i =0; i<r; i++)
    {
        for(int j =0; j<c/2; j++)
        {
            swap(&arr[i][j], &arr[i][c-1-j]);
        }
    }

}




void printSpiralMatrix(int r, int c, int arr[][c]) // if i pass only arr[n][n], it shows error n not defined, have to ask y
{

    int top = 0; //changed from 0 -->row-1;
    int bottom = r-1; // changes from row-1 to 0
    int left = 0; // changes from 0 -->col-1
    int right  = c-1; //changes from c-1 to 0;

    /*now we have 4 indices that will help us traverse through the matrix
    
    1 2 3 4 5 
    6 7 8 9 10
    11 12 13 14 15
    16 17 18 19 20
    21 22 23 24 25 */

    while(1)
    {
        if(left >right) break;
    //print 1 2 3 4 5 , aka the top rows
    for(int i =0; i<=right; i++)
    {
        printf("%d ", arr[top][i]);
    }
    top++;

    if(top > bottom) break;
    //print 10 15 20 25 , aka the right side column , now top is 1 coz 5 which is at a[0][4] was already
    //printed in the first go.
    for(int i = top; i<=bottom; i++)
    {
         printf("%d ", arr[i][right]);
    }
    right--;
     if(left >right) break;
    //print 24 23 22 21 , aka the lower row, 
      for(int i = right; i<=left; i++)
    {
         printf("%d ", arr[i][bottom]);
    }
    bottom--;
    //print left column 
    if(top > bottom) break;
      for(int i = bottom; i<=top; i++)
    {
         printf("%d ", arr[i][left]);
    }
    left++;
    }


}
int main()
{
    int n = 3;
    int m=0;
    int k =4;
    int arr[n][n] ;
    for(int i =0 ; i<n; i++)
    {
        for(int j =0 ; j<n; j++)
        {
            arr[i][j] = m;
            m++;
        }
    }
    printmatrix(n, arr); //this is passing by reference only.
    //whatever change are done in the function are represented here even when we do not pass by *
    for(int i =0 ; i<n; i++)
    {
        for(int j =0 ; j<n; j++)
        {
            printf("%d ", arr[i][j]);
           
            
        }
        printf("\n");
    }
   // printf("\n sprial matrix\n");
    //printSpiralMatrix(n,n,arr);
   int arr2[4][4] = { 1, 2, 3, 4 , 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
     printf("\n before 90 clockwise reverse\n");
    printmatrix(k, arr2);
  rotate90Clock(k, k, arr2);
  printf("\n after 90 clockwise reverse\n");
   printmatrix(k, arr2);
}