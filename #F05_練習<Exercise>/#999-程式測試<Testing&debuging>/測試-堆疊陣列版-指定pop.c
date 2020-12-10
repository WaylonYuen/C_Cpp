#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

void show(int Data[], int top);
int push(int Data[], int information, int top);
int pop(int Data[], int top, int LeaveID);

int main(){

    int top=-1;
    int data;
    int Container[SIZE];
    int request;
    int LeaveID;

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
                printf("Plz input the Leave Data:");
                scanf("%d", &LeaveID);
                top = pop(Container, top, LeaveID);
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
        system("clear");
        show(Data, top);
        printf("full\n");
        
    }else{
        Data[top] = information;  
        show(Data, top);  
    }
    

    return top;
}

int pop(int Data[], int top, int LeaveID){

    int i;
    int Leave;

    if(top < 0){
        printf("Empty\n");
    }
    else{
        
        /* Find the Leave Number's Address in Array */
        for(i=0; i<=top; i++){
            if(Data[i] == LeaveID){
                Leave = i;
                break;
            }
        }

        /* Delete Leave number and adjust Array */
        for(i=Leave; i<top; i++){
            Data[i] = Data[i+1];
        }
        Data[top] = 0;
        top--;

        printf("pop: %d\n", Data[top]);
        puts("------------------------------\n");
        show(Data, top);
    }

    return top;
}




