#include <stdio.h>
#include <string.h>
#include <math.h>

int isPalindrome(int num) {
    int reverse_num=0, remainder, temp;

   /* Here we are generating a new number (reverse_num)
    * by reversing the digits of original input number
    */
   temp=num;
   while(temp!=0)
   {
      remainder=temp%10;
      reverse_num=reverse_num*10+remainder;
      temp/=10;
   }
    return reverse_num == num ? 0 : -1;
}

int main ()
{
    printf("%i\n", isPalindrome(1123211));
    printf("%i\n", isPalindrome(1123213));
    printf("%i\n", isPalindrome(1221));
    return 0;
}