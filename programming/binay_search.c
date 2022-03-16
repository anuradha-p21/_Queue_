
#include<stdio.h>
#include<stdlib.h>
int mybinary_search(int arr[], int left, int right, int x)
{
    int rt = right -1;
    int mid ;
    while(left < rt)
    {
        mid = left + (rt - left)/2;
        if(arr[mid] == x){   //if x is same element 
        return mid;
        }
        else if(arr[mid] < x){ // x should go to right
            left = mid +1;
        }
        else{
            rt = mid -1;
        }

    }
    if(arr[left] < x) return left;
    return left+1;
}

void mysort(int ans[], int ele, int len)
{
    if(len == 0) { ans[len] = ele; return; }

    int pos = mybinary_search(ans, 0, len, ele);
    printf(" p: %d ", pos);

    if(pos > len) {ans[pos]= ele; return; }

    for(int i = len; i>=pos; i--){
        ans[i+1] = ans[i];
    }
    ans[pos]= ele;
}

void sortStream(int arr[], int n){   //{ 4, 1, 7, 6, 2 };
int ans[n+1];
 for (int i = 0; i < n; i++) {
 // the stream is a continous flow of intergers, so first 1 ele and then 2 ele and so on, we send each ele one by one to sort
  mysort(ans, arr[i], i);   //i=0, ans is null;  i =1 then ans has 1 element, i =2 ans has 2 ele, ans[0], ans[1], so i is len of ans
// Print the array after every insertion
  for (int j = 0; j <= i; j++) {
          printf("%d",  ans[j]);
        }
  printf("\n");
}
}





int main()
{
    int arr[] = { 4, 1, 7, 6, 2 };
    int N = sizeof(arr) / sizeof(arr[0]);

    sortStream(arr, N);

    return 0;

}