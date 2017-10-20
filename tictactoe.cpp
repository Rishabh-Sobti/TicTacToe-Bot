#include<iostream.h>
#include<conio.h>

char gridchar(int i)
	{
	 switch(i)
		{
		 case -1: return 'X';
		 case 0: return ' ';
		 case 1: return 'O';
		}
	 return ' ';
	}

void draw(int b[9])
	{
	 cout<<" "<<gridchar(b[0])<<" | "<<gridchar(b[1])" | "<<gridchar(b[2])<<"\n";
	 cout<<"---+---+---\n";
	 cout<<" "<<gridchar(b[3])<<" | "<<gridchar(b[4])" | "<<gridchar(b[5])<<"\n";
	 cout<<"---+---+---\n";
	 cout<<" "<<gridchar(b[6])<<" | "<<gridchar(b[7])" | "<<gridchar(b[8])<<"\n";
	}

int win(int board[9])
	{
	 int wins[8][3]={{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
	 int i;
	 for(i=0; i<8; i++)
		{
		 if(board[wins[i][0]]!=0 && board[wins[i][0]]==board[wins[i][1]] && board[wins[i][0]]==board[wins[i][2]])
			return board[wins[i][0]];
		}
	 return 0;
	}

int minmax(int board[9], int player)
	{
	 int winner = win(board);
	 int i, currscore, move=-1, score=-2;
	 if(winner!=0)
		return winner*player;
	 for(i=0; i<9; i++)
		{
		 if(board[i]==0)
			{
			 board[i]=player;
			 currscore= -minmax(board, player*-1);
			 if(currscore>score)
				{
				 score=currscore;
				 move=i;
				}
			 board[i]=0;
			}
		}
	 if(move==-1)
		return 0;
	 return score;
	}

void computer(int board[9])
	{
	 int i, temp, move=-1, score=-2;
	 for(i=0; i<9; i++)
		{
		 if(board[i]==0)
			{
			 board[i]=1;
			 temp= -minmax(board, -1);
			 board[i]=0;
			 if(temp>score)
				{
				 score=temp;
				 move=i;
				}
			}
		}
	 board[move]=1;
	}

void playermove(int board[9])
	{
	 int move=0;
	 do
		{
		 cout<<"\nYour Move (1-9): ";
		 cin>>move;
		 move=move-1;
		}while(move>=9||move<0 && board[move]==0);
	 board[move]=-1;
	}

int main()
	{
	 int board[9]={0,0,0,0,0,0,0,0,0};
	 int turn, player=0;
	 clrscr();
	 cout<<"\t\tBEAT ME!!\n\nMe: O, You: X\nDo you wanna go (1)st or (2)nd??  ";
	 cin>>player;
	 for(turn=0; turn<9 && win(board)==0; turn++)
		{
		 if((turn+player)%2==0)
			computer(board);
		 else
			{
			 draw(board);
			 playermove(board);
			}
		}
	 switch(win(board))
		{
		 case 0: cout<<"\nLucky You! It's a draw."; break;
		 case 1: draw(board);
			 cout<<"\nTold You! It's impossible to beat me!";
			 break;
		 case -1: cout<<"\nWOAH! You have won!";
			  break;
		}
	 getch();
	 return 0;
	}
