#include<stdio.h>

int main(int argc, char const *argv[]){
    
    float salary;

    scanf("%f", &salary);

    if(salary>=0.0 && salary<=5000.0){
        //nothing
    }
    else if(salary>=5001.0 && salary<=10000.0){
        salary = salary*(1+0.1);
    }
    else if(salary>=10001.0 && salary<=15000.0){
        salary = salary*(1+0.15);
    }
    else if(salary>15000.0){
        salary = salary*(1+0.2);
    }
    else{
        puts("Data Erorr!\n");
    }

    printf("salary: %.1f\n\n\n", salary);

    return 0;
}