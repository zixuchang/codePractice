#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int lengthOfLongestSubstring1(char * s){
    int maxlen = 1;
    int tempLen =1;
    int strLenth = 0;
    int i,j;
    int flag =0;
    strLenth = strlen(s);
    for (i =0; i < strLenth -1; i ++) {
        tempLen =1;
        for (j =i+1; j < strLenth; j ++) {
            if (s[i] != s[j]) {
                tempLen ++;
            } else {
               flag =1;
               break;                 
            }
            
        }
        if (flag) {
            flag =0;
            continue;
        }
        maxlen = fmax(tempLen, maxlen);
    }
    return maxlen;

}
int lengthOfLongestSubstring(char * s){
    int i, count = 0, max = 0, index[128] = {0}, start = 0;
    int strLenth = strlen(s);
    for(i=0;i < strLenth;i++)     
    {
        if(index[s[i]]>start)   //index用来储存出现重复字符时
        {                       //子串起始下标应移动到的地方
            count = i-start;
            max = fmax(count, max);
            start = index[s[i]];
        }
        index[s[i]] = i+1;
    }
    count = i-start;
    max = fmax(count, max);
    return max;
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
