
/* difftime example */
#include <stdio.h>
#include <time.h>
#include <string>

#define totalSec=86400

int main ()
{
  struct tm* start,*end;
   char * weekday[] = { "Sunday", "Monday",
                       "Tuesday", "Wednesday",
                       "Thursday", "Friday", "Saturday"};

  int year, month, day;
  char szInput [256];
  double dif;
  printf("Enter start day:" );
  scanf("%d %d %d",&month,&day,&year);
  printf("xong!");
  
  start->tm_year = year - 1900;
  start->tm_mon = month - 1;
  start->tm_mday = day;
  
 
  //Read End day/.
  fflush(stdin);
  printf("Enter end day:" );
  scanf("%d\%d\%d",&month,&day,&year);
  end->tm_year = year - 1900;
  end->tm_mon = month - 1;
  end->tm_mday = day;
  
  printf("%x - %x",start,end);
  printf("Start day is: %s\n",weekday[start->tm_wday]);
  printf("End day is: %s\n",weekday[end->tm_wday]);
  //printf("Gap days is: %d\n",difftime(start,end)/totalSec);
  
//  printf("The distance: %d",(int)dif/totalSec);
 
  return 0;
}
