#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<set>
#include<string>
using namespace std;

struct Node
{
    char data;
    Node *next;
    Node(char ch)
    {
        this->data = ch;
        this->next = NULL;
    }
};
/***********************************************************
 * returns string which is the longest possible palindrome in a given input string
 *  abbbcdabbc ===> abbcdcbba or anything 
 **********************************************************/
  string expand_longest( string s, int low, int high)
    {
        //this function takes each char of string and checks the i-1 and i+1 trying to check for palindrom
        //first when i = 0 is passed. a is taken since 0-1 low goes out of boundary, it returns just a.
        while(low >= 0 && high < s.length() && (s[low] == s[high]))
        {
            low--; high++;
        }
        //if it does not match, it comes out of the loop  suppose abbbc i was 2 will break when low = 0(a)
        // high is 4 but our palindrom is just bbb which is low = 1 and high =3
        //that is why low+1 and high-low-1
        return s.substr(low+1, high - low-1);
    }
    string longestPalindrome(string s) {
        int l = s.length();
        if(l ==0) return s;
        string max_str;
        string cur_str;
        int max_len = 0, cur_len;
        //apple  appllppa
        for(int i  = 0; i < l; i++)
        {
            //cases where length is odda apple
            cur_str = expand_longest(s, i, i);
            cur_len = cur_str.length();
            if(cur_len > max_len)
            {
                max_len = cur_len;
                max_str = cur_str;
            }
            //cases where length is even appllppa
             cur_str = expand_longest(s, i, i+1);
            cur_len = cur_str.length();
            if(cur_len > max_len)
            {
                max_len = cur_len;
                max_str = cur_str;
            }
            
        }
        return max_str;
    }



/************************************************
 * return all possible palindrom strings 
 * *********************************************/

void expand_all(string s, int low, int high, auto &str_set)
{
    while(low >=0 && high < s.length() && s[low] == s[high])
    {
        //substr args : start and lenght we want to make as a substr
        /*s0, start is low and then lenght is 
         First arg is starting index of the substring
        Second is num of chars of the substring
        Geeksforgeeks . Substr(5, 3) gives ‘for’
        */
        str_set.insert(s.substr(low, high-low+1));
        low--;
        high++;
    }
}

void allpalindromesubstrings(string s)
{
    unordered_set<string>str_set;
    for( int i = 0; i <s.length(); i++)
    {
        expand_all(s, i, i , str_set);
        expand_all(s, i, i+1, str_set);
    }
    for(auto i : str_set)
    {
        cout<<i <<endl;
    }
}
/********************************************/

/******************************************
 * form a longest substring from given string 
 * can shuffle characters 
 *******************************************/
string formlongestpalindrome(string s)
{
    //we put the characters and their freq in a map
    unordered_map<char, int>map;
    for(char ch:s)
    {
        //puts the character in the map and increments the count 
        //if a char comes first time, an entry is madde
        //next all times count is increased.
        map[ch]++; 
    }
    //now we need to form a string
    // if count = even , we split the str evenly 
    //if odd, we split the even part and try putting the 1 left one 
    //in middle 
    string mid_char; // the one odd character
    string left; // stores left string

    //iterate through freq map
    for(auto p : map)
    {
        char ch = p.first; //get the current char
        int count = p.second; //get the current count
        //if current char freq is odd
        //update the mid char to curr char (discards old one) mid char is always the latest one
        if(count & 1)
        {
            mid_char = ch;
        }
        //append half to left
        left.append(count/2, ch);
    }
    //now, the right half is the reverse of the left
    string right(left.rbegin(), left.rend());
    //return string formed by left, mid and right 
    return(left + mid_char + right);

}

/*************************************************
 * check if binary form of a number is palindrom or not
 * input 5 then it i palindrome because 101 is palindrome
 * ****************************************************/
bool binaryispalindrome(unsigned n)
{
    // rev stores the binary form of num
    unsigned rev = 0;
    //do till all bits of n are processed
    unsigned k = n;
    while(k)
    {
        rev = (rev << 1) |(k & 1);
        k = k >>1;
    }
    return (n == rev);
}

/********************************************
 * check if linked list is palindrome using RECURSION
 * *******************************************/
void construct(Node *head, string &s1, string &s2)
{
    if(head == NULL) return;
    //before calling recursion add the data into s1
    s1 +=head->data;

    construct(head->next, s1, s2);
    s2 +=head->data;
}
bool llispalindrome(Node *head)
{
    string s1, s2;
    construct(head, s1, s2);
    return s1 == s2;
}
/*******************************************/

/********************************************
 * check if a string is a rotated palindrome or not 
 * CBAABCD is a rotated palindrome as it is a rotation of palindrome ABCDCBA
 * ***************************************************/

/********************************************
 * check if a number is palindrome or not 
 * 1221 
 * ***************************************************/
bool isPalindrome(int x) {
        //if x is divisible by 10 then definetely not a palindrome
        if(x < 0 || x %10 ==0 && x!= 0)
            return false;
        int rev =0;
        //we dont have to reverse number completely 
        //12321 then 
        /* rev = 1 x = 1232
              = 12 x = 123
              = 123 x = 12 next while wont enter */
            while(x > rev)
            {
                rev  = rev * 10 + x % 10 ;
                x = x/10;
                
            }
            //we check x == rev for even digit cases 1221 then while breaks when x = 12 rev =12 
            // second condition is for odd digit 12321 while breaks rev = 123 x  = 12 then rev/10 = 12 ==> 
            //which is equal to x
        return ( (x == rev) || (x == rev / 10) );  
    }


int main()
{
    string str = "google";
    string s  = "ABBDAB";
    allpalindromesubstrings(str);
    cout<<formlongestpalindrome(s) << endl;
    Node* head = new Node('A');
    head->next = new Node('B');
    head->next->next = new Node('C');
    head->next->next->next = new Node('B');
    head->next->next->next->next = new Node('D');
 
    if (llispalindrome(head)) {
        cout << "Linked List is a palindrome.";
    }
    else {
        cout << "Linked List is not a palindrome.";
    }
 
    return 0;
}