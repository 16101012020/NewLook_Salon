#include<stdio.h>
#include<string.h>

struct first
{
  char name[59];
  int num;
  int cnum;
  int cost;
} p[1000];

int ocount = 0, scount = 0, waiting = 0;

int
booking ()
{
  int a, b,d, temp;
  char c;
  printf ("\nPlease Enter Your Name: ");
  gets (p[ocount].name);
  
  menu ();
  p[ocount].cnum = 0;
  p[ocount].num = 0;
  p[ocount].cost = 0;
level:
  printf ("\nHow many services you want: \n");
  scanf ("%d", &a);
  while (a--)
    {
      printf ("\nEnter the choosen code: \n");
      scanf ("%d", &b);
      switch (b)
	{
	case 11:
	  printf ("\nTHREADING");
	  p[ocount].num ++;
	  p[ocount].cost += 30;
	 
	  break;
	case 12:
	  printf ("\nUPPER LIPS");
	  p[ocount].num ++;
	  p[ocount].cost += 20;
	  break;
	case 13:
	  printf ("\nFOREHEAD");
	  p[ocount].num ++;
	  p[ocount].cost += 20;
	  break;
	case 14:
	  printf ("\nWAXING");
	  printf ("\nWhich wax do you want?");
	  printf ("\n1.NORMAL WAX");
	  printf ("\n2.RICA WAX\n");
	  scanf ("%d", &temp);
	  printf ("\nDo you want to have arm wax?y/n\n");
	  scanf ("%s", &c);
	  printf ("\nDo you want to have leg wax?y/n\n");
	  scanf ("%s", &d);
	  p[ocount].num ++;
	  if (temp == 1)
	  { { if(c=='y' || c=='Y')
	    p[ocount].cost += 200;
	  }{
	    if(d=='Y' || d=='y')
	    p[ocount].cost += 300;
	  } }
	  	  else if(temp==2)
	    { { if(c=='y' || c=='Y')
	    p[ocount].cost += 350;
	  }{
	    if(d=='Y' || d=='y')
	    p[ocount].cost += 450;
	  } }
	  
	  
	  break;
	case 15:
	  printf ("\nBLEACH");
	  p[ocount].num ++;
	  p[ocount].cost += 190 ;
	  break;
	case 16:
	  printf ("\nDE_TAN");
	  p[ocount].num ++;
	  p[ocount].cost += 170;
	  break;
	case 17:
	facial:
	  printf ("\nFACIAL");
	  printf ("\nWhich facial do you want?");
	  printf ("\n---------NORMAL FACIALS--------");
	  printf ("\n1.FRUIT FACIAL");
	  printf ("\n2.SKIN TIGHTENING");
	  printf ("\n3.SKIN BRIGHTENING");
	  printf ("\n4.ANTITAN");
	  printf ("\n---------O3 PREMIUM------------");
	  printf ("\n5.STAY YOUNG");
	  printf ("\n6.LIGHT ANG BRIGHT");
	  printf ("\n7.SIGNATURE GLOW\n");
	  scanf ("%d", &temp);
	  
	  if (temp == 1)
	    p[ocount].cost += 500  ;
	  else if (temp == 2)
	    p[ocount].cost += 550 ;
	  else if (temp == 3)
	    p[ocount].cost += 570 ;
	  else if (temp == 4)
	    p[ocount].cost += 580 ;
	  else if (temp == 5)
	    p[ocount].cost += 1200 ;
	  else if (temp == 6)
	    p[ocount].cost += 1200 ;
	  else if (temp == 7)
	    p[ocount].cost += 1800 ;
	  else
	    {
	      printf ("\nEnter valid choice");
	      goto facial;
	    }
	  p[ocount].num++;
	  break;

	case 18:
	  printf ("\nBODY MASSAGE");
	 
	  p[ocount].num ++;
	  p[ocount].cost += 650 ;
	  break;
	case 19:
	  printf ("\nBODY SCRUB");
	 
	  p[ocount].num ++;
	  p[ocount].cost += 600 ;
	  break;
	case 20:
	  printf ("\nBODY BLEACH");
	 
	  p[ocount].num ++;
	  p[ocount].cost += 650 ;
	  break;
	default:
	  printf ("\nInvalid code\n");
	  break;
	  a++;
	}
    }
    
  char ch;
  printf ("\nDo you want any other services?y/n\n");
   scanf("%s",&ch);
  if (ch == 'y' || ch == 'Y')
    goto level;
  printf ("\nNumber of services:  %d\n", p[ocount].num);
  printf ("\nThank you %s for coming.Your bill is Rs%d\n", p[ocount].name,
	  p[ocount].cost);
  ocount++;
}

int
receive ()
{
  if (ocount == 0)
    {
      printf ("Please book your service first\n");
      return;
    }

  else if (scount == ocount)
    {
      printf ("All bookings done!!!\n");
      return;
    }

  printf ("Booking no. %d of %s is done\n", ocount, p[scount].name);
  printf ("We hope you enjoyed our service!!!!\n\n");
  scount++;
}

int
display ()
{
  printf ("\nTotal number of bookings:                %d bookings\n", ocount);
  printf ("Total number of bookings done:             %d bookings\n", scount);
  printf ("Number of Currently waiting customers:     %d customers\n",
	  ocount - scount);
  printf ("Currently doing work of:                   %d customers\n",
	  p[scount].num);
}


void menu ()
{
  printf (".................MENU.........................\n");

  printf ("SERVICE CODE#   SERVICES-----------------------Price(Rs)\n");

  printf ("[11]------------THREADING----------------------30\n");
  printf ("[12]------------UPPER LIPS---------------------20\n");
  printf ("[13]------------FOREHEAD-----------------------20\n");
  printf ("[14]------------WAXING-------------------------500/800\n");
  printf ("[15]------------BLEACH-------------------------190\n");
  printf ("[16]------------DE_TAN-------------------------170\n");
  printf ("[17]------------FACIAL-------------------------550/1200/1800\n");
  printf ("[18]------------BODY MASSAGE-------------------650\n");
  printf ("[19]------------BODY SCRUB---------------------600\n");
  printf ("[20]------------BODY BLEACH--------------------650\n");

}

int
main ()
{
  printf ("\t\t**********WELCOME TO NEWLOOK SALOON**********\n");
  while (1)
    {
      printf ("1. BOOKING\n2. WAITING CUSTOMERS\n3. DISPLAY \n4. EXIT\n");

      int in;
      scanf ("%d", &in);
      getchar ();
      switch (in)
	{
	case 1:
	  {
	    booking ();
	    break;
	  }
	case 2:
	  {
	    receive ();
	    break;
	  }
	case 3:
	  {
	    display ();
	    break;
	  }
	case 4:
	  {
	    printf ("We are closed come by again\n\n");
	    return 0;
	  }
	}
    }
}








