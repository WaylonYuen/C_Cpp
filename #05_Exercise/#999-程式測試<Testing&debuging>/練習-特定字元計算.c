#include<stdio.h>

int main(){

    int counter[5]={};
    char data[64];
    int i;

    for(i=0; i<64; i++){

        scanf("%c", &data[i]);
        if(data[i] == '\n'){
            break;
        }
        switch(data[i]){
            case 'a':
            case 'A':
                counter[0]++;
                break;

            case 'e':
            case 'E':
                counter[1]++;
                break;

            case 'i':
            case 'I':
                counter[2]++;
                break;

            case 'o':
            case 'O':
                counter[3]++;
                break;

            case 'U':
            case 'u':
                counter[4]++;
                break;

            default:
                continue;
                break;
        }

    }
    data[i] = '\0';

    printf("%s\n", data);
    
    for(i=0; i<5; i++){
        printf("%d", counter[i]);
    }

    puts("\n\nEnd of run....\n");

    return 0;
}