#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>

bool verify(char *k);

int main(int argc, char *argv[])
{   
    
    int i,l,m,r,n;
    char p,c;
    char *s, *k;
    
    r = 0;

    if(argc==2 && argv[1])
    {  
        k = argv[1];
        
        if(!verify(k))
        {
            printf("Error inputting arguments! Please try again...");
            return 1;   
        }
        
        s = GetString();
        m = strlen(k);
        
         
        for(i=0, l = strlen(s); i<l; i++)
        {
            p = s[i];
    
            r = r%m;
            c = k[r];
            
            if(c>='a' && c<='z')
            {
                n = (c-'a');
            }
            else if(c>='A' && c<='Z')
            {
                n = (c-'A');
            }
            
            if(p>='a' && p<='z')
            {
                s[i] = 'a' + (p+n-'a')%26;
                r++;
            }
            else if(p>='A' && p<='Z')
            {
                s[i] = 'A' + (p+n-'A')%26;
                r++;
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


bool verify(char *k)
{
    int len = strlen(k);
    char c;
    
    for(int i=0; i<len; i++)
    {   
        c = k[i];
        if(c>='a' && c<='z')
        {
            continue;
        }
        else if(c>='A' && c<='Z')
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}