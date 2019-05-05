#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// isalnum()
int isAlphaNum(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) return 1;
    return 0;
}

int isPalindrome(char *s)
{
    int n = strlen(s);
    if (!n) return 1;

    char *p1 = s, *p2 = s + n - 1;
    while (p1 < p2) {
        if (!isAlphaNum(*p1)) { p1++; continue; }
        if (!isAlphaNum(*p2)) { p2--; continue; }
        // tolower()
        if ((*p1++ + 32 - 'a') % 32 != (*p2-- + 32 - 'a') % 32) return 0;
    }
    return 1;
}

int main()
{
    char *s = "A man, a plan, a canal: Panama";
    if (isPalindrome(s)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
