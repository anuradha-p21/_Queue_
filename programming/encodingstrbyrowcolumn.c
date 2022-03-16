#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void encodeStrRowC( char *s, int rows)
{
    char *p[rows];
    int n = strlen(s);
    int col = n/ rows;
    for(int i =0; i<rows; i++)
    {
        p[i] = (char*)malloc(sizeof(char)* col);
    }
    for(int i = 0 ; i<n;i++)
    {
        p[(i % rows)][(i/rows)] = s[i];        //a  d 
                                            //b  [1][0]           //e -> 4 1 1 
                                    //c             // ->5 2 1 p[2][1]
    } 
    int k = 0;
     for(int i = 0 ; i<rows;i++)
        {
            for(int j = 0 ; j<col;j++)
            {
                if(p[i][j] != '\0'){
                s[k] = p[i][j];
                k++;
                }
            }
        }
            



}
int main()
{
   char *s;

   s = (char*)malloc(sizeof(char) * 100);
    scanf("%s[^/n]", s); // will now read spaces. except "enter" it will read everything
    encodeStrRowC(s, 3);
    printf("%s", s);


    

}