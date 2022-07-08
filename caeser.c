#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{   
    
    int i,l,k;
    char p;
    char *s;

    if(argc==2 && argv[1])
    {
        k = atoi(argv[1]);
        s = GetString();
         
        for(i=0, l = strlen(s); i<l; i++)
        {
            p = s[i];
            
            if(p>='a' && p<='z')
            {
                s[i] = 'a' + (p+k-'a')%26;
            }
            else if(p>='A' && p<='Z')
            {
                s[i] = 'A' + (p+k-'A')%26;
            }
        }
        
        printf("%s",s);
        printf("\n");
        
        return 0;        
    }
        
    else
    {
        printf("Error inputting arguments! Please try again...");
        return 1;
    }
    
}