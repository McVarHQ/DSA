#include<stdio.h>
void main(){
    int num[10]={1,2,3,4,3,2,3,4,5,3}, temp, n;
    n=10;
    for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (num[j] < num[j + 1]) {
				temp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = temp;
			}
		}
	}
    for (int i=0; i<10; i++){
        printf("\n%d", num[i]);
    }
}