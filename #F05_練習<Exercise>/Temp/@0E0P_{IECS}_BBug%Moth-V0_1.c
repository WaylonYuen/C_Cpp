///input：數字格式日期: 12/12
///output：中文格式日期: 十二月十二日
///BBug
#include <stdio.h>
#include <string.h>

int main(){

    char Number[30][30] = {"一","二","三","四","五","六","七","八","九","十","月","日"};
    char Str[20] = {};
    
    int j;
    for( j = 0; j < 10; j++){
        printf("%s ", Number[j]);
    }

    scanf("%s", Str);

    int i = 0;
    while(Str[i] != '\0'){


        switch (Str[i]) {

            case '/':
                printf("%s", Number[10]);
                break;
            case '1':
                if(Str[i+1] == '0') printf("%s", Number[9]);
                else printf("%s", Number[0]);
                break;
            case '2':
                printf("%s", Number[1]);
                break;
            case '3':
                printf("%s", Number[2]);
                break;
            case '4':
                printf("%s", Number[3]);
                break;
            case '5':
                printf("%s", Number[4]);
                break;
            case '6':
                printf("%s", Number[5]);
                break;
            case '7':
                printf("%s", Number[6]);
                break;
            case '8':
                printf("%s", Number[7]);
                break;  
            case '9':
                printf("%s", Number[8]);
                break;  

            default:
                break;
        }

        if(i == 0 || i == 3) {
            if(Str[i] != '0' && Str[i+1] != '0') printf("%s", Number[9]);
            if(Str[i] != '1' && Str[i+1] == '0') printf("%s", Number[9]);       
        }
        i++;
    }
    printf("%s", Number[11]);

    return 0;
}