#include <stdio.h>

int main(void) {

    int i = 0;
    int counter = 0;
    char str[100] = {" "};
    char dict[] = {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,."};
    
    scanf("%[^\n]", str);
    while(str[i] != '\0') {
        
        int j = 0;
        while (dict[j] != '\0') {
            
            if(str[i] == dict[j]) {
                counter++;
                break;
            }

            j++;
        }
        
        i++;       
    }

    printf("Counter: %d\n", counter);

    return 0;
}