#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct stack
{
    long int top;
    char *s;
} st;
void create()
{
    st.top = -1;
    st.s = (char *)malloc(100001 * sizeof(char));
}
int main()
{

    long int l1, l2, l3;
    scanf("%ld %ld %ld", &l1, &l2, &l3);
    char s1[l1 + 1], s2[l2 + 1], s3[l3 + 1];
    scanf("%s", s1);
    scanf("%s", s2);
    scanf("%s", s3);
    printf("%s", s1);
    create();
    st.s[++st.top] = s2[0];
    for (int i = 1; i < l2; i++)
    {
        if (s2[i] <= s3[0])
        {
            while (s2[i] < st.s[st.top] && st.top > -1)
                st.top--;
            st.s[++st.top] = s2[i];
        }
    }
    int ch = 0, index;
    for (int i = 1; i < l3; i++)
    {
        if (s3[i] != s3[0])
        {
            ch = 1;
            index = i;
            break;
        }
    }
    if (st.s[0] <= s3[0])
    {
        for (int i = 0; i <= st.top; i++)
        {

            if (st.s[i] != s3[0])
                printf("%c", st.s[i]);
            else if (st.s[i] == s3[0] && ch == 1 && s3[index] >= s3[0])
                printf("%c", st.s[i]);
        }
    }
    printf("%s\n", s3);
    return 0;
}