#include<iostream.h>
#include<conio.h>

int main()
{
    char str1[] = "all the best";
    char str2[] = "e";
    int count = 0;int t;
    for(int i = 0; str1[i] != '\0'; i++) 
    {
        t=0;
        for(int j = 0; str2[j] != '\0'; j++) 
        {
            if (str1[i + j] != str2[j]) 
            {
                t = 1;}
                
            
        }
        if (t==0)
        count++;
    }
    if(count!=0)
    cout<<"YES string 2 is a substring of string 1\n";
    else
    cout<<"string 2 is NOT a substring of string 1\n";
    getch();
    return 0;
}
