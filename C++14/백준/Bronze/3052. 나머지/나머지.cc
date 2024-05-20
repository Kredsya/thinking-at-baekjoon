#include <stdio.h>

int main()
{
    int tmp, ans=0;
    int arr[50]={0};
    for(int i=0; i<10; i++) {
        scanf("%d", &tmp);
        arr[tmp%42]=1;
    }
    for(int i=0; i<42; i++) {
        if(arr[i]>0) ans++;
    }

    printf("%d", ans);
    return 0;
}

