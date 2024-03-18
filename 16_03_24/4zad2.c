#include <stdio.h>

int binarySearch(int array[], int left, int right, int x)
{
    if(right >= left)
    {
        int mid = left + (right-left)/2;

        if ((array[mid]) ==x)
            return mid;
        if ((array[mid]) > x)
            return binarySearch(array,left,mid-1,x);
        return binarySearch(array,mid+1,right,x);
    }
    return -1;
}

int main(){
    int array[] = {2,4,6,8,10,12,14,16,18,20};
    int n = sizeof(array)/ sizeof(array[0]);
    int x = 8;
    int result = binarySearch(array,0,n-1,x);

    if (result==-1)
        printf("Couldn't find %d.\n", x);
    else
        printf("%d has been found successfully. It has index no: %d. ",x,result);
    return 0;
}