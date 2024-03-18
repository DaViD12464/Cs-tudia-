#include <stdio.h>

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void permute(int array[], int start, int end) {
    if (start == end)
    {
        //displaying permutations
        for (int i = 0; i <= end; i++) {
            printf("%d ", array[i]);
        }
        printf("\n");
    } else {
        for (int i = start; i <= end; i++) {
            int isSwap = 1;
            for (int j = start; j < i; j++) {
                if (array[j] == array[i]) {
                    isSwap = 0;
                    break;
                }
            }
            if (isSwap) {
                swap(&array[start], &array[i]);
                permute(array, start + 1, end);
                swap(&array[start], &array[i]);
            }
        }
    }
}

int main(){
    int array[]={4,5,5,7,9};
    int n = sizeof(array)/sizeof(array[0]);
    printf("All permutations:\n");
    permute(array,0,n-1);
    return 0;
}