#include <stdio.h>
#include <string.h>

int main() {
    //freopen("input.txt", "r", stdin);
    int t;
    scanf("%d ", &t);
    
    char input[1005];
    int start, end, i, len;
    while(t--) {
        gets(input);
        strcat(input, " ");
        len = strlen(input);
        i = 0;
        while(i < len) {
            start = i;
            for(int j=i+1; j<len; j++) {
                if(input[j] == ' ') {
                    end = j-1;
                    break;
                }
            }
            for(int j=end; j>=start; j--) {
                printf("%c", input[j]);
            }
            printf(" ");
            i = end + 2;
        }
        printf("\n");
    }
    
    return 0;
}