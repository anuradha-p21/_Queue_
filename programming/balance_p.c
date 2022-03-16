#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define false 0
#define true 1

int isValid(char * s){
    int l = strlen(s);
    int j = 0;
   // printf("%d", l);
    char *stack = (char*)malloc(l * sizeof(char));
    if(stack == NULL) return false;
    for(int i =0; i<= l-1; i++)
    {
        char c = s[i];
        char pop;
        switch(c)
        {
            case '(' :
            stack[j] = ')';
            j++;
            break;
                
           case '{' :
            stack[j] = '}';
            j++;
            break;
            
            case '[' :
            stack[j] = ']';
            j++;
            break;
        
            default :
                pop = stack[--j];
                printf("%d", j);
                if(j == -1)
                    return false;
                if(c != pop)
                    return false;
                break;
        }
    }
    return true;
}
                
            
int main()
{
    char exp[100] = "()))";
 
    // Function call
    if (isValid(exp))
        printf("Balanced \n");
    else
        printf("Not Balanced \n");
    return 0;
}
 