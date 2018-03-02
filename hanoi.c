  1 
  2 
  3 void hanno(int n,char A, char B,char C)
  4 {
  5     if (n == 1)
  6     {
  7         printf("%c => %c\n",A,C);
  8     } else
  9     {
 10         hanno(n-1,A,C,B);
 11         printf("%c => %c\n",A,C);
 12         hanno(n-1,B,A,C);
 13     }
 14 }
