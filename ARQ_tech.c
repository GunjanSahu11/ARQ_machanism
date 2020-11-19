#include<stdio.h>
#include<string.h>
#include<conio.h>

struct frame
{
	int da,sa,f_no,crc;
	char data[20];
	
};

void make_frame(int);
int wait_for_event();
void display_frame();

struct frame f;
void main()
{
	int d,e,y,sn=0,cansend=0;
	while(1)
	{
		//clrscr();
		d = wait_for_event();
		if(d==1)
		{
			if(cansend==0)
			{
				printf("\n Wait for the acknowledgment frame from reciever");
			}
			
			else
			{
				make_frame(sn);
				display_frame();
				printf("\n copy of frame %d is kept",sn);
				printf("\n frame %d is sent",sn);
				sn=(sn+1)%2;
				cansend=0;
				
			}
		}
		
			else if(d==2)
			{
				printf("\n Is right acknowlegment recieved? \n 1.Yes \n 2.No \n");
				scanf("%d",&y);
				
				if(y==1)
				{
					printf("\n Timer stopped");
					if(sn==0)
					{
						e=1;	
					}
					
					else
					{
						e=0;
					}
				printf("\n Frame %d is successfully recieved by reciever : ",e);
				printf("\n Purge the Frame %d : ",e);
				cansend = 1;
				
				}
			else
			{
			 
			 printf("\n Acknowledgment Frame got corrupted !! ");	
			 
			}	
				
			}
		else if(d==3)
		{
			printf("\n Timer restarted ! \n");
			
			if(sn==0)
			{
				e=1;
				
			}
			
			else 
			{
				e=0;
			}
		printf("\n Frame %d is present : ",e);
		}
		
		else
		{
			break;
		}
		
		getch();
	}
}

int wait_for_event()
{
	int ch;
	printf("\n Describe the event \n 1.Request to sent \n 2.arrival notification \n 3.Timer Expired \n 4.Exit \n Enter your event no ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1: return(1);
		
		case 2: return(2);
		
		case 3: return(3);
		
		default: return(4);
		
	}
}

void make_frame(int x)
{
	printf("\n Enter the destination address : ");
	scanf("%d",&f.da);
	printf("\n Enter the source address : ");
	scanf("%d",&f.sa);
	printf("\n Enter the data : ");
	scanf("%s",&f.data);
	f.crc=strlen(f.data);
	f.f_no = x;
}

void display_frame()
{
	printf("\n The frame you have netered is : ");
	printf("\n Frame_no : %d  \n Destination address : %d  \n Source address : %d  \n Data : %s \n CRC : %d ",f.f_no,f.da,f.sa,f.data,f.crc);
}


