#include <stdio.h>
int binsearch(float arr[10], int l, int r, float x){
    int mid;
    if (l<=r){
        mid=(l+r)/2;
        if (arr[mid]==x){
            return mid;
        }
        else if (x>arr[mid]){
            binsearch(arr, mid+1, r, x);
        }
        else{
            binsearch(arr, l, mid, x);
        }
    }
    else{
        return -1;
    }
}
void main(){
    float num[10]={1,2,3,4,5,6,7,8,9,10};
    float n;
    printf("Enter number to be searched - ");
    scanf("%f", &n);
    printf("%d", binsearch(num, 0, 10, n));

}