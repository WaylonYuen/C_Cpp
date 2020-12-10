#include<stdio.h> 
#include<stdlib.h>

typedef struct Node {  
    int coef;//系数  
    int exp;//指数  
    struct Node *next; 
}PolyNode;

PolyNode *Creatpoly() {      //creat 多項式   
    PolyNode *h, *p, *q;  
    h=(PolyNode *)malloc(sizeof(PolyNode));  
    p=h;  p->next=NULL;  
    printf("请输入多项式的系数及其指数a，b，当系数输入0时停止输入\n");  
    q=(PolyNode *)malloc(sizeof(PolyNode));  
    scanf("%d %d",&q->coef,&q->exp);  
    while(q->coef!=0){   
        p->next=q;   
        p=q;   
        q=(PolyNode *)malloc(sizeof(PolyNode));   
        scanf("%d %d",&q->coef,&q->exp);  
    }  
    p->next=NULL;  
    return(h); 
} 

void Prin_poly(PolyNode *h)         //多项式输出 
{  
    PolyNode *p;  
    p=h->next;  
    while(p!=NULL){    
        if(p->coef>0&&p!=h->next){    
            if(p->exp>0)
                printf("+%dx^%d",p->coef,p->exp);    
            else if(p->exp<0)     
                printf("+%dx^(%d)",p->coef,p->exp);    
            else     
                printf("+%d",p->coef);   
        }else if(p->coef<0&&p!=h->next){    
            if(p->exp>0)
                printf("%dx^%d",p->coef,p->exp);    
            else if(p->exp<0)     
                printf("%dx^(%d)",p->coef,p->exp);    
            else     
                printf("%d",p->coef);    
        }else{    
            if(p->exp>0)     
                printf("%dx^%d",p->coef,p->exp);    
            else if(p->exp<0)     
                printf("%dx^(%d)",p->coef,p->exp);    
            else     
                printf("%d",p->coef);   
        }   
        p=p->next;  
    } 
}  

void Insort(PolyNode *h)        //排序
{  
    PolyNode *s,*p;  
    int t,m;  
    for(p=h->next;p!=NULL;p=p->next){        //类似于冒泡排序  
        for(s=h->next;s->next!=NULL;s=s->next){    
            if(s->exp<s->next->exp){     
                t=s->exp;     
                m=s->coef;     
                s->coef=s->next->coef;     
                s->exp=s->next->exp;     
                s->next->coef=m;     
                s->next->exp=t;    
            }   
        }  
    } 
}  

void UnitePoly(PolyNode *h){             //合拼 
    PolyNode *p1,*p2,*q1,*q2,*temp;  
    q1=h;
    p1=q1->next;  
    while(p1!=NULL){   
        p2=p1->next;   
        q2=p1;   
        while(p2!=NULL){    
            if(p1->exp==p2->exp){     
                p1->coef=p1->coef+p2->coef;     
                if(p1->coef==0){      
                    temp=p2;      
                    q2->next=p2->next;      
                    free(temp);      
                    temp=p1;      
                    q1->next=p1->next;      
                    p1=q1;      
                    free(temp);      
                    break;     
                }else{      
                    temp=p2;      
                    q2->next=p2->next;      
                    p2=p2->next;      
                    free(temp);     
                }    
            }else{     
                q2=p2;     
                p2=p2->next;    
            }   
        }   
        q1=p1;   
        p1=p1->next;  
    } 
}  


//合并同类项 (Ans)
void UnitePoly2(PolyNode *h){ 

    PolyNode *p1,*p2,*q1,*q2,*temp;  
    q1 = h;
    p1 = q1->next; 

    while(p1 != NULL){   
        p2 = p1->next;   
        q2 = p1;   
        while(p2 != NULL){    
            if(p1->exp == p2->exp && p1->coef == p2->coef){     
                temp = p2;
                q2->next = p2->next;
                free(temp);

                temp = p1;
                q1->next = p1->next;
                p1 = q1;
                free(temp);
                //break;             
            }else{     
                q2 = p2;     
                p2 = p2->next;    
            }   
        }   
        q1 = p1;   
        p1=p1->next;  
    } 
}  




PolyNode *polymuti(PolyNode *h1,PolyNode *h2){       //多项式相+  

    PolyNode *h,*p,*p1,*p2,*q, *m;  
    p1 = h1->next;

    h = p = (PolyNode *)malloc(sizeof(PolyNode));
    p->next = NULL;  

    int Hold = 1;

    while(p1){   
        p2 = h2->next;   
        while(p2){    
            if(p1->exp == p2->exp) {
                q = (PolyNode *)malloc(sizeof(PolyNode)); 
                q->coef = p1->coef + p2->coef;
                q->exp = p1->exp;

                p->next = q;    
                p = q;    
                p2 = p2->next; 

                Hold = 0;
                break;
            }  
            p2 = p2->next; 
        }

        if(Hold == 1){
            q = (PolyNode *)malloc(sizeof(PolyNode)); 
            q->coef = p1->coef;
            q->exp = p1->exp;

            p->next = q;
            p = q;
        }
        Hold = 1;
        p1 = p1->next;  
    }  

    p2 = h2->next;
    while(p2){   
        p1 = h1->next;   
        while(p1){    
            if(p1->exp == p2->exp) {
                Hold = 0;
                //printf("T1 %dx^%d ", p1->coef, p1->exp);
                break;
            }  
            p1 = p1->next; 
        }

        if(Hold == 1){
            q = (PolyNode *)malloc(sizeof(PolyNode)); 
            q->coef = p2->coef;
            q->exp = p2->exp;

            p->next = q;
            p = q;
            //printf("T2 %dx^%d ", p->coef, p->exp);
        }
        Hold = 1;
        p2 = p2->next;  
    }

    p->next = NULL; 

    // puts("Test0: ");
    // while(h){
    //     printf("%dx^%d ", h->coef, h->exp);
    //     h = h->next;
    // }
    // int i;
    // scanf("%d", &i);



    return(h); 
}  

int main(){  
    PolyNode *h1,*h2,*h;  
    h1=Creatpoly();  
    printf("多项式1 = ");  
    UnitePoly(h1);  
    Insort(h1);  
    Prin_poly(h1);  
    printf("\n");  

    h2=Creatpoly();  
    printf("多项式2 = ");  
    UnitePoly(h2);  
    Insort(h2);  
    Prin_poly(h2);  
    printf("\n");    
    printf("相＋后的多项式为P(x)=");  


    h = polymuti(h1,h2);  
    UnitePoly(h);  
    Insort(h);  
    Prin_poly(h);  
    printf("\n"); 
}

