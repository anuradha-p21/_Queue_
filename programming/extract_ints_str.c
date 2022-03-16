//program takes input of a string, just collects the integers in the string and places in a passed pointer
//ignores all the alphabets
//considers only numbers

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//you cannot send the address of the local variable back to main.
//YOU MUST malloc it in function and only then return char* 
//even in main, if you wish to send a string that you wish to make changes on. MALLOC it
//if you dont want to malloc in function --> malloc in main, send the string, make changes IN PLACE and return void. If you can not do in plce
// char buf[l] in function and strcpy(s, buf); or if strcpy not to use use for and copy.

void extractInts(char *s, int *data)
{
    int l = strlen(s);
    char res[l];
    int j =0;
    for(int i = 0; i<l; i++)
    {
        if(isdigit(s[i]))
        {
            res[j++] = s[i];
        }
    }
    for(int i =0; i< strlen(res); i++)
    {
        *data = (*data)* 10 + (res[i] - '0') ;      
    }
   
	//strcpy(s, res);
	int i;
	//if not strcpy then this for 
	for( i =0; i<l; i++)
	{
		s[i] = res[i];
	} 
	//s[i] = '\0'; -->this is needed if we use strlen(res) in for
	//because here, res has less chars than s and the null char wont be added. 
	//when copying char by char take care of the null char. 
	
}
int main(){
    
    int *p = (int*)malloc(sizeof(int));
	//char *s = (char*)malloc(sizeof(char)* 30);
	char s[] = "anu 45 d 89 eee 00 o";

	//gets(s);  //-->reads the whole line
	//scanf("%[^\n]s", s); //-->reads the whole line. 
	extractInts(s, p);
    printf(" %s : %d in main\n",s,  *p);
}


