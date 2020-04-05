#include <stdio.h>

int main(void)
{
	int arr[10] = {0};
    for(int i = 0; i < 8; ++i){
    	arr[i] = 1;
    }
    printf("%d\n",arr[0]);
}