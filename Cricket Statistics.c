#include<stdio.h>
#include<string.h>

//player structure defined
struct player { 
char player_id[25];
int match_id;
int previous_total_score;
float previous_avg;
int previous_total_wickets;
float previous_wicket_avg;
int total_runs_in_last_five_matches;
int total_wickets_in_last_five_matches;
int century;
int present_match_score;
int present_match_wicket;
int player_role;
int out_not_out;
int man_of_the_match;
};

//team structure defined
struct team {
char teamname[15];
struct player abc[300];
};

//match_played structure defined
struct match_played {
int  match_id;
char team1[15];
char team2[15];
int result;
int highest_run;
int wicket_taken_by_pacer1;
int wicket_taken_by_pacer2;
};

void initialize(struct player abc[],struct team def[],struct match_played xyz[],int p,int matches)
{
	int i=0,j=0;
	for(i=0;i<p;i++)
   { 	
abc[i].player_id[0]='\0';
abc[i].match_id=0;
abc[i].previous_total_score=0;
abc[i].previous_avg=0.0;
abc[i].previous_total_wickets=0;
abc[i].previous_wicket_avg=0.0;
abc[i].total_runs_in_last_five_matches=0;
abc[i].total_wickets_in_last_five_matches=0;
abc[i].century=0;
abc[i].present_match_score=0;
abc[i].present_match_wicket=0;
abc[i].player_role=0;
abc[i].out_not_out=0;
abc[i].man_of_the_match=0;
}
i=0;
while(i<p)
{
	for(j=i;j<i+15;j++)
	{
	def[j].teamname[0]='\0';
    def[j].abc[j].player_id[0]='\0';
    }
   i=i+15; 
}
 for(i=0;i<matches;i++)
 {
 
 xyz[i].match_id=0;
 xyz[i].team1[0]='\0';
 xyz[i].team2[0]='\0';
 xyz[i].result=-1;
 xyz[i].highest_run=0;
 xyz[i].wicket_taken_by_pacer1=0;
 xyz[i].wicket_taken_by_pacer2=0;
}

}

void teamcheck(struct player abc[],struct team def[],int p)
{
	int i=0,j=0;
	int count_bowl=0,count_bat=0,max_runs=0,s_max_runs=0,max_wickets=0,s_max_wickets=0;
	float max_avg=0.0,s_max_avg=0.0,s_high_avg=0.0,high_avg=0.0;
	int best_bat=0,best_bowl=0;
	while(i<p)
	{
	  if((abc[i].previous_total_score>max_runs)&&(abc[i].previous_avg>max_avg))
	  {
	  	s_max_runs=max_runs;
	  	max_runs=abc[i].previous_total_score;
	  	s_max_avg=max_avg;
	  	max_avg=abc[i].previous_avg;
	  }
	  if((abc[i].previous_total_wickets>max_wickets)&&(abc[i].previous_wicket_avg>high_avg))
	  {
	  	s_max_wickets=max_wickets;
	  	max_wickets=abc[i].previous_total_wickets;
	  	s_high_avg=high_avg;
	  	high_avg=abc[i].previous_wicket_avg;
	  }
	}
	
	while(i<p)
	{
	  count_bat=count_bowl=0;
	  
	  for(j=i;j<i+15;j++)
	  {
	  	if(abc[j].player_role==1)
	  	count_bat++;
	  	if(abc[j].player_role==2)
	  	count_bowl++;
	  }
	if(count_bat>=5&&count_bowl>=4)
	 {
	 	for(j=i;j<i+15;j++)
	 	{
	 	  	if((abc[i].previous_total_score==max_runs)&&(abc[i].previous_avg==max_avg))
	 	  	{
	 	  		best_bat++;
			}
			if((abc[i].previous_total_score==s_max_runs)&&(abc[i].previous_avg==s_max_avg))
			{
			    best_bat++;
			}
			if((abc[i].previous_total_wickets==max_wickets)&&(abc[i].previous_avg==high_avg))
			{
			    best_bowl++;
			}
			if((abc[i].previous_total_score==s_max_wickets)&&(abc[i].previous_avg==s_high_avg))
			{
			    best_bowl++;
			}
			
		}
		
		if(best_bat>=2&&best_bowl>=2)
		  printf("playing 11 of %s team is valid",def[i].teamname);
		else
		  printf("playing 11 of %s team is invalid",def[i].teamname);
	}
	else
	  printf("playing 11 of %s team is invalid",def[i].teamname);
	 
	 i=i+15;
	}
}

void highrungetter_mom(struct player abc[],struct match_played xyz[],int p,int m)
{
	int max_score=0,i,j,k,t,max_mom=0,a=0;
	for(i=0;i<p;i++)
	{
		if(abc[i].previous_total_score > max_score)
		{
			max_score=abc[i].previous_total_score;
		}
			if(abc[i].man_of_the_match > max_mom)
		{
			max_mom=abc[i].man_of_the_match;
		}
	}
	char arr1[p][25],arr2[p][25],temp1[25],temp2[25];
	j=0;t=0;
	for(i=0;i<p;i++)
	{
		if(abc[i].previous_total_score == max_score)
		{
			arr1[j][25]=abc[i].player_id;
		}
		if(abc[i].man_of_the_match == max_mom)
		{
			arr2[j][25]=abc[i].player_id;
		}
		j=j+1;
		t=t+1;
	}
		for(i=0;i<j;i++)
		{
			for(k=i+1;k<j;++k)
			{
				if(strcmp(arr1[i],arr1[k])>0)
				{
					strcpy(temp1,arr1[i]);
					strcpy(arr1[i],arr1[k]);
					strcpy(arr1[k],temp1);
				}
		   }
	    }
	    for(i=0;i<t;i++)
		{
			for(k=i+1;k<t;++k)
			{
				if(strcmp(arr2[i],arr2[k])>0)
				{
					strcpy(temp2,arr2[i]);
					strcpy(arr2[i],arr2[k]);
					strcpy(arr2[k],temp2);
				}
			}
		}
		for(i=0;i<j;i++)
		{
			printf("%s%d",arr1[i],max_score);
	    }
	    for(i=0;i<t;i++)
	    {
			printf("%s%d",arr2[i],max_mom);
		}
		if(j==t)
		{
			for(i=0;i<t;i++)
			{
				if(strcmp(arr1[i],arr2[i])!=0)
				{
						a=0;
				}
			}
			if(a==0)
			printf("not equal");
			else
			printf("same");
			
		}
		else
		printf("not equal");
}

void high_avg( struct player abc[],int p)
{
    int j=0,pos=0,pos1=0;
	float max_bat_avg=0.0,max_bowl_avg=0.0;
	while(j<p)
	{
	if(abc[j].previous_avg > max_bat_avg)
		{
		max_bat_avg=abc[j].previous_avg;
		}
	if(abc[j].previous_wicket_avg > max_bowl_avg)
	{ 
	    max_bowl_avg=abc[j].previous_wicket_avg;
	}
	   j++;
	}
    for(j=0;j<p;j++)
    {
    	if(abc[j].previous_avg==max_bat_avg)
    	{
    		pos=j;
    		printf("%s %f",abc[pos].player_id,max_bat_avg);
		}
			if(abc[j].previous_wicket_avg==max_bowl_avg)
    	{
    		pos1=j;
    		printf("%s %f",abc[pos1].player_id,max_bowl_avg);
		}
	}
}

void diff( struct team def[],struct player abc[],struct match_played xyz[],int p,int m)
{
	int i=0,j,k;
	int wp=0,tw=0;
	while(i<p)
	{
		j=0;wp=0;tw=0;
		while(j<m)
		{
			if(def[i].teamname==xyz[j].team1)
			{
				wp=wp+xyz[j].wicket_taken_by_pacer1;
			}
			if(def[i].teamname==xyz[j].team2)
			{
				wp=wp+xyz[j].wicket_taken_by_pacer2;
			}
			j++;
		}
		for(k=i;k<i+15;k++)
		{
			tw=tw+abc[k].previous_total_wickets;
		}
		if(((2*wp)-tw)>0)
		{
			printf("diff of wickets taken by pacers and spinners in %s team is %d",def[i].teamname,(2*wp)-tw);
		}
		else
		{
			printf("diff of wickets taken by pacers and spinners in %s team is %d",def[i].teamname,tw-(2*wp));
		}
		i=i+15;
	}
}

void mom_century (struct player abc[],int p, int k)
{
		int i=0,max_century=0;
		for(i=0;i<p;i++)
		{
			if(abc[i].man_of_the_match >=k)
			{
				if(abc[i].century > max_century)
			    {
				max_century=abc[i].century=abc[i].century;
			    }
			}
		}
		char arr[p][25],temp[25],j=0;
		for(i=0;i<p;i++)
		{
			if(abc[i].man_of_the_match >= k &&abc[i].century==max_century)
			{
				arr[j][25]=abc[i].player_id;
				j=j+1;
			}
		}
		for(i=0;i<j;i++)
		{
			for(k=i+1;k<j;++k)
			{
				if(strcmp(arr[i],arr[k])>0)
				{
					strcpy(temp,arr[i]);
					strcpy(arr[i],arr[k]);
					strcpy(arr[k],temp);
				}
			}
		}
		for(i=0;i<j;i++)
		{
			printf("%s",arr[i]);
		}
		
}






int main()
{

int n=1,i=-1,p,j,matches,d=0,k=0,result=-1;


printf("enter no of teams");
scanf("%d",&n);
matches=((n/2)*((n/2)-1))+3;

print("enter k for no of man of the matches");
scanf("%d",&k);

struct player abc[n*15];
struct team def[n];
struct match_played xyz[matches];

initialize(abc,def,xyz,n*15,matches);


printf("for 1.data entry of player enter 1\n2.data entry of all the matches in the tournament enter 2\n3.data entry of team enter 3\n 4.to solve the questions enter 4\n\n to exit anything else \n");
scanf("%d",&i);
if(i==1){p=n*15;
for(i=0;i<p;i++)
{
printf("\nEnter the name of the player");
scanf("%s",abc[i].player_id);
printf("\nenter no. of matches:");
scanf("%d",&abc[i].match_id);
printf("\nenter previous total score:");
scanf("%d",&abc[i].previous_total_score);
printf("\nenter previous total wickets:");
scanf("%d",&abc[i].previous_total_wickets);
printf("\nenter runs in last 5 matches:");
scanf("%d",&abc[i].total_runs_in_last_five_matches);
printf("\nenter wickets in last 5 matches:");
scanf("%d",&abc[i].total_wickets_in_last_five_matches);
printf("\nenter no. of centuries:");
scanf("%d",&abc[i].century);
printf("\nenter present score:");
scanf("%d",&abc[i].present_match_score);
printf("\nenter present wickets:");
scanf("%d",&abc[i].present_match_wicket);
printf("\nenter player_Role: batsman(1) : bowler(2) : all-rounder(3) :");
scanf("%d",&abc[i].player_role);
printf("\nenter present out(1) : not out(2):");
scanf("%d",&abc[i].out_not_out);
printf("\n enter man of the match no :");
scanf("%d",&abc[i].man_of_the_match);
abc[i].previous_avg=(abc[i].previous_total_score*1.0) / abc[i].match_id;
abc[i].previous_wicket_avg=(abc[i].previous_total_wickets*1.0) / abc[i].match_id;
}
printf("\nplayers data entry completed");
i=1;
}
if(i==2)
{p=n*15;
while(d<p){
printf("\nEnter one by one player _id for  team %d and press enter\n",i+1);
scanf("%s",def[i].teamname);
for(j=i;j<i+15;j++){

scanf("%s%s",def[j].abc[j].player_id,def[j].teamname);
}d=d+15;
}

printf("\nteams data entry completed");
i=2;
}
if(i==3)
{p=matches;
for(i=0;i<p;i++)
{
printf("\nEnter the data for %d th match",i);
xyz[i].match_id=i;
printf("\nenter team 1's name");
scanf("%s",xyz[i].team1);
printf("\nenter team 2's name");
scanf("%s",xyz[i].team2);
printf("\nenter highest run");
scanf("%d",&xyz[i].highest_run);
printf("\nenter No. of wickets by pacer in team1");
scanf("%d",&xyz[i].wicket_taken_by_pacer1);
printf("\nenter No. of wickets by pacer in team2");
scanf("%d",&xyz[i].wicket_taken_by_pacer2);
}
do{
printf("\nenter the winner 1 or 2 (0 if match tied)");
scanf("%d",&result);
} while (result<0||result>2);

if(result==0) 
{printf("Match between %s and %s is tied ",xyz[i].team1,xyz[i].team2);}
else if(result==1)
{ printf(" %s won the match ",xyz[i].team1);}
else 
{printf(" %s won the match ",xyz[i].team2);}

printf("\n Matches data entry completed");
i=3;
}
if(i==4){
//questions_data_entry()
teamcheck(abc,def,n*15);
highrungetter_mom(abc,xyz,n*15,matches-3);
high_avg(abc,n*15);
diff(def,abc,xyz,n*15,matches);
mom_century(abc,n*15,k);

}


printf("Program Completed");
return 0;
}
