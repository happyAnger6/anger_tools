#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char szBuf[1024+1]={0};

    char *pcSubStr = argv[1];
    char t = 0;
    int i = 0;
    while(i<1024)
    {
        if((t=getchar())==EOF) break;
        szBuf[i]=t;
        i++;
    }
    szBuf[i]=0;

    int totalLen = strlen(szBuf);

    int j = 0, k = 0;
    for(j = 0; szBuf[j]!=0; j++)
    {
        for(k = 0; pcSubStr[k] != 0; k++)
        {
            if(pcSubStr[k] != szBuf[j+k])
                break;
        } 
    
        if(pcSubStr[k]==0)
            break;
    }

    

}
