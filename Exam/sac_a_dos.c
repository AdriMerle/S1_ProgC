#include <stdio.h>
#define MaxSize 100000
#define MaxNbObject 100

int main(){
    int size, o[MaxNbObject], input = 1, i =0, object=0, L[MaxSize], j=0, k=1, count =0;
    
    scanf("%d",&size);

    while(input && count < MaxNbObject){
        scanf("%d", &object);
        if (object!=-1){
            o[i]=object;
            i++;
            count +=1;
        }else{
            input = 0;
            i-=1;
        }
    }
    
    for (int j=0;j<=i;j++){
        printf("o[%d] = %d\r\n", j, o[j]);
    }

    L[0] = 1;

    while(k<=size){
        while(j<=i){ 
            if(k-o[j]>=0 && L[k-o[j]]==1){
                L[k]=1;
                j=i;
            }
            j++;   
        }             
        k++;
        j=0; //Erreur principale : oubli de redéfinir ce sur quoi on boucle while dans while (habitude de for dans for)
    }

    for (int z=0;z<=size;z++){
        printf("L[%d] = %d \r\n", z, L[z]);
    }
    
    if (L[size]){
        printf("OUI\r\n");
    }else{
        printf("NON\r\n");
    }
    return 0;
}

