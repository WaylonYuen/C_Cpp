#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

void show(int Data[], int top){

    int i;
    system("clear");
    printf("Data: ");
    for(i=0; i<=top; i++){
        printf("%d ", Data[i]);
    }

}

int push(int Data[], int information, int top){
    top++;
    if(top > SIZE){
        top--;
        printf("full\n");
        
    }else{
        Data[top] = information;  
        show(Data, top);  
    }
    

    return top;
}

int pop(int Data[], int top){
    if(top < 0){
        printf("Empty\n");
    }
    else{
        top--;
        printf("pop: %d\n", Data[top]);
        puts("------------------------------\n");
        show(Data, top);
    }

    return top;
}




int main(){

    int top=-1;
    int data;
    int Container[SIZE];
    int request;

    while(1){
        puts("\nPlz input the request:");
        scanf("%d", &request);
        puts("\n");
        switch(request){
            case 1:
                puts("Plz input the data:\n"
                     "------------------------------\n");
                scanf("%d", &data);
                top = push(Container, data, top);
                break;
            case 2:
                top = pop(Container, top);
                break;
            case 3:
                puts("data:\n"
                     "------------------------------\n");
                show(Container, top);
                puts("\n");
                break;
            case 4:
                exit(1);
                break;
            default:
                puts("Error\n");
                break;
            
        }

    }

    return 0;
}