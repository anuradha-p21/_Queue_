/* ab#c and acd# 
whenever there is # , it means backspace and the previous element must be deleted.
ab#c --> ac
acd# --> ac 
and it must compare both strings and return if they are equal or no.
https://leetcode.com/problems/backspace-string-compare/
1. take top = -1;
2. if s[i] not # then put enteries on stack st[top] = s[i] top++
3. if it is # then top-- , the next element will just over write it now.
4. append a '/0' to indicate end of str.

void build(char * s)
{
    char st[strlen(s) +1 ];
    int i = 0;
    int top = -1; //we take top -1 as start
    while(s[i] != '\0') //ab#c
    {
        //if # then it means backspace so top ++ 
        if(s[i] != '#')
        {
            top++;
            st[top] = s[i]; //ab
        }
        else { //#
            if(top >= 0)  
            top -- ;  //a , now top-- so top will be at b now so next time b is over written . 
        }
        i++;
    } //we get ac. 
    
    //copy the st to s now. 
    strcpy(s, st); //strcpy( dest, source)
    //if there is no #, abcd then top will be equal to strlen and we do not need to insert \0
    if(top != strlen(s)) 
    s[top+1] = '\0'; // we insert '\0' at the end because we are building a new string and we need to indicate
    //end of str.
    
        
}

bool backspaceCompare(char * s, char * t){
    build(s);
    build(t);
    if(strcmp(s, t) ==0) return true;
    return false;
    
}