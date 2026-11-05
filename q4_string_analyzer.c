#include <stdio.h>
#include <ctype.h>

void analyze(char *str, int *v, int *c, int *d, int *s);
void reverse(char *str);
int isPalindrome(char *str);

void analyze(char *str, int *v, int *c, int *d, int *s) {
    char *p = str;
    char ch;
    *v = 0; *c = 0; *d = 0; *s = 0;
    while (*p != '\0') {
        ch = tolower(*p);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            (*v)++;
        else if (ch >= 'a' && ch <= 'z')
            (*c)++;
        else if (ch >= '0' && ch <= '9')
            (*d)++;
        else if (ch != ' ')
            (*s)++;
        p++;
    }
}

void reverse(char *str) {
    char *start = str;
    char *end = str;
    char temp;
    while (*end != '\0') end++;
    end--;
    while (start < end) {
        temp   = *start;
        *start = *end;
        *end   = temp;
        start++;
        end--;
    }
}

int isPalindrome(char *str) {
    char copy[200];
    char *src = str, *dst = copy;

    /* Copy without spaces, all lowercase — original str is NOT modified */
    while (*src != '\0') {
        if (*src != ' ') {
            *dst = tolower(*src);
            dst++;
        }
        src++;
    }
    *dst = '\0';

    char *left = copy, *right = dst - 1;
    while (left < right) {
        if (*left != *right) return 0;
        left++;
        right--;
    }
    return 1;
}

int main() {
    char str[200];
    char *p;
    int vowels, consonants, digits, special;

    printf("Enter a sentence: ");
    fgets(str, 200, stdin);

    /* Strip newline from fgets */
    p = str;
    while (*p != '\0') {
        if (*p == '\n') { *p = '\0'; break; }
        p++;
    }

    analyze(str, &vowels, &consonants, &digits, &special);

    printf("\n=== String Analysis ===\n");
    printf("  Original           : %s\n", str);
    printf("  Vowels             : %d\n", vowels);
    printf("  Consonants         : %d\n", consonants);
    printf("  Digits             : %d\n", digits);
    printf("  Special characters : %d\n", special);
    printf("  Palindrome         : %s\n", isPalindrome(str) ? "Yes" : "No");

    reverse(str);
    printf("  Reversed           : %s\n", str);

    return 0;
}
