
#include <iostream>
#include<ctime>

using namespace std;
enum enchoice{stone=1,paper=2,scissor=3};
int PlayerWonTimes=0,AIWonTimes=0,DrawTimes=0;

int randomNumber(int from,int to)
{
    int random=rand()%(to-from+1)+from ;
    return random;
}

int readPositiveNumber(string msg)
{
	int number;
	do
	{
		cout<<msg;
		cin>>number;
	} while (number<0);
	return number;
}

int readPlayerChoice(int choice)
{
	cout<<"\nyour choice \n [1]:stone \n [2]:paper \n [3]:scissor\n";
	do
	{
		cout<<"Enter your choice : ";
		cin>>choice;
	} while (choice!=1 && choice!=2 && choice !=3);
}

string printChoice(int c)
{
	switch (c)
	{
	case enchoice::stone:
		return " stone";
		break;
	case enchoice::paper:
		return " paper";
		break;
	case enchoice::scissor:
		return " scissor";
		break;	
	}
}

void winner(int playerChoice,int AIChoice)
{
	switch (playerChoice)
	{
	case enchoice::paper :
		if (AIChoice==paper)
		{
			system("color 6F");
			cout<<"[Nowinner]";
			DrawTimes++;
		}
		else if (AIChoice==stone)
		{
			system("color 2F");
			cout<<"[Player]";
			PlayerWonTimes++;
		}
		else
		{
			system("color 4F");
			cout<<"[AI]";
			AIWonTimes++;
		}
		break;
	case enchoice::stone :
		if (AIChoice==paper)
		{
			system("color 4F");
			cout<<"[AI]";
			AIWonTimes++;
		}
		else if (AIChoice==stone)
		{
			system("color 6F");
			cout<<"[Nowinner]";
			DrawTimes++;
		}
		else
		{
			system("color 2F");
			cout<<"[Player]";
			PlayerWonTimes++;
		}
		break;
	case enchoice::scissor :
		if (AIChoice==paper)
		{
			system("color 2F");
			cout<<"[Player]";
			PlayerWonTimes++;
		}
		else if (AIChoice==stone)
		{
			system("color 4F");
			cout<<"[AI]";
			AIWonTimes++;
		}
		else
		{
			system("color 6F");
			cout<<"[Nowinner]";
			DrawTimes++;
		}
		break;

	}


}

void roundResult(int numberOfRound,int playerChoice,int AiChoice)
{
	cout<<"\n_________Round ["<<numberOfRound<<"]_________ "<<endl;
	cout<<"Player choice : "<<printChoice(playerChoice)<<endl;
	cout<<"AI choice : "<<printChoice(AiChoice)<<endl;
	cout<<"The winner : ";
	winner(playerChoice,AiChoice);
	cout<<"\n____________________________"<<endl;

}

void Round(int numberOfRound)
{
	cout<<"Round ["<<numberOfRound<<"] begins  \n";
	int playerChoice=readPlayerChoice(playerChoice);
	enchoice AiChoice=(enchoice)randomNumber(1,3);
	roundResult(numberOfRound,playerChoice,AiChoice);
}

void finalResult(int rounds)
{
	system("cls");
	string winner;
	if (PlayerWonTimes==AIWonTimes)
	winner="No Winner";
	else if (PlayerWonTimes>AIWonTimes)
	winner="Player";
	else
	winner="AI";
	cout<<"\n\t\t____________________________"<<endl;
	cout<<"\t\t\t GAME OVER "<<endl;
	cout<<"\t\t____________________________\n"<<endl;
	cout<<"\t\t_______[Game Results]_______\n"<<endl;
	cout<<"\t\tGame Rounds      : "<<rounds<<endl;
	cout<<"\t\tPlayer won times : "<<PlayerWonTimes<<endl;
	cout<<"\t\tAI won times     : "<<AIWonTimes<<endl;
	cout<<"\t\tDraw times       : "<<DrawTimes<<endl;
	cout<<"\t\tFinale winner    : "<<winner;	
}

void start()
{
	char repat;
	do
	{
		system("cls");
		PlayerWonTimes=0;
		AIWonTimes=0;
		DrawTimes=0;
		int rounds=readPositiveNumber("How many rounds do want to play : ");
		for (int i = 1; i <=rounds; i++)
		{
			Round(i);
		}
		finalResult(rounds);
		do
		{
			cout<<"\n\t\tDO you want to play again ? Y/N";
			cin>>repat;
		} while (repat!='y'&& repat!='Y' && repat!='n' && repat!='N');

	} while (repat!='n'&& repat!='N');
}

int main()
{
	srand((unsigned)time(NULL));
	start();
}

