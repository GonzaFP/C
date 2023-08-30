#include <ctype.h>
#include <stdio.h>
#include <string.h>

 int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
 int compute_score(char word[]);

int main(void)
{
  char word1[] = "Scrabble";
  char word2[] = "wiNNeR";
  int score1 = compute_score(word1);
  int score2 = compute_score(word2);

printf("score2 %d\n", score2);
printf("score1 %d\n", score1);
  if (score1 > score2)
  {
   printf("Player1 wins\n");
  }
  else if (score2 > score1)
  {
   printf("Player2 wins\n");
  }
  else
  {
   printf("Tie\n");
  }
}

int compute_score(char word[])
{
 char alpha[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
 int score = 0;
 int length = strlen(word);

 for (int j = 0; j < length; j++)
 {
    for (int i = 0; i < 26 ; i++)
    {
      if ((word[j] >= 'a' || word[j] <= 'z') || (word[j] >= 'A' && word[j] <= 'Z'))
      {
        if (toupper(word[j])  == alpha[i])
        {
           score += POINTS[i];
           break;
         }
        else
        {
          continue;;
        }
       }
      else
      {
       continue;
      }
     }
  }
  return score;
}