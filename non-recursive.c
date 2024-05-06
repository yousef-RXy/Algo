#include <stdio.h>

int length(char* s) {
  int cnt = 0;
  for (int i = 0; s[i]; i++) cnt++;
  return cnt;
}

int longestBalancedSubstring(char* s) {
  int n = length(s);
  if (n < 2) return 0;
  int maxLength = 0;
  for (int i = 0; i < n - 1; i++) {
    int count1 = 0, count2 = 0;
    for (int j = i; s[j] == s[i] || s[j] == s[i + 1]; j++) {
      s[j] == s[i] ? count1++ : count2++;
      count1 == count2 && (count1 + count2) > maxLength && (maxLength = count1 + count2);
    }
  }
  return maxLength;
}

int main() {
  char string[100];
  int exit = 1;
  while (exit != 0) {
    printf("Enter a string: ");
    scanf("%s", string);
    printf("%d\n", longestBalancedSubstring(string));
    printf("Do you want to continue? (0/1): ");
    scanf("%d", &exit);
  }
}