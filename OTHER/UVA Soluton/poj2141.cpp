#include <algorithm>

char    a[26];
char    s[100];
int     i;

int main()
{
    for (i = 0; i < 26; i++)
        a[i] = getchar();
    getchar();
    gets(s);
    for (i = 0; i < strlen(s); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            putchar(a[s[i]-'a']);
        else
        if (s[i] >= 'A' && s[i] <= 'Z')
            putchar( toupper( a[tolower(s[i])-'a'] ) );
        else putchar(s[i]);
    }
    putchar('\n');
    std::system("pause");
    return 0;
}
