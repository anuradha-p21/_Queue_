#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

bool isPalindrome(char *s1)
{
    int l1 = strlen(s1) -1;
  
    int i = 0;
  
    while( i < l1)
    {
        if(s1[i++] != s1[l1--])
        {
            return false;
        }
    }   
    return true; 
}

bool isAnagram(char *s1, char *s2)
{
    int count[256] = {0};
    if(strlen(s1) != strlen(s2)) return false;
    for(int i = 0; i< strlen(s1); i++)
    {
        count[s1[i] - 'a']++;
    }
      for(int i = 0; i< strlen(s2); i++)
    {
        count[s2[i] - 'a']--;
    }
    for(int i =0; i<256; i++)
    {
        if(count[i]) return false;
    }
    return true;
    

}
/*int main()
{
    printf( "%d\n", isPalindrome("anuradhaaahijeincudv"));
    printf( "%d", isAnagram("12345v", "1234566"));
}*/

int main()
{
    char *s1 = (char*)malloc(sizeof(char) * 30);
    char *s2 = (char*)malloc(sizeof(char) * 30);
    //scanf("%[^\n]s", s1);
    //scanf("%[^\n]s", s2);
    gets(s1);
    gets(s2);
      printf( "%s\n", isPalindrome(s1) ? "true":"false");
    printf( "%s", isAnagram(s1, s2)? "true":"false");

}