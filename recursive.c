#include <stdio.h>

int maxInt(int a, int b) {
    return a > b ? a : b;
}

int isBalanced(char* subStr) {
  int count1 = 0, count2 = 0;
  for (int i = 0; subStr[i]; i++)
    if (subStr[i] == subStr[0]) count1++;
      else if (subStr[i] == subStr[1]) count2++;
      else return 0;
  return count1 == count2;
}

int lBSFromIndex(char* s, int index) {
  if (!s[index]) return 0;
  int maxLength = 0;
  for (int i = index + 1; s[i]; i++) {
    int strLin = i - index + 1;
    char subStr[strLin];
    for (int j = 0; j <= i - index; j++) subStr[j] = s[index + j];
    subStr[strLin] = '\0';

    isBalanced(subStr) && (maxLength = maxInt(maxLength, strLin));
  }
  return maxInt(maxLength, lBSFromIndex(s, index + 1));
} 

int longestBalancedSubstring(char* s) {
  return lBSFromIndex(s, 0);
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