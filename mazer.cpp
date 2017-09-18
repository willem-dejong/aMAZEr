//Willem DeJong
//cs 2
//Fall 2014
// it's a little long but fast and will find the shortest path EVERY time.
//mazes are from dimension of 1 by 1 to 10 by 10
// each maze is represented in a .in file by with the first line that contains only 2 ints with a single space in between the first int
//is the height the second int is the width of the maze. starting on the second line is the maze which is made up of walls('*') and floors('.') and bread crums (',') which are only tossed in the s,e,w,n, order. 
//the dimensions of this maze must match the previous 2 ints.
//EXAMPLE
//3 3
//...
//**.
//**.
//to traverse the maze I must check a direction to see if I can move there if I can I move in that direction (by recursion)
//if I am surounded by walls and a space I already have been I will back track one space and check one of the other directions. 
//given I cant move diagonally there are four directions possible to check.
// the logic behind this solver is for every maze that has a solution, out of the 24 possible orders and the 8 back track orders 
//I have made, atleast one isthe best method for that maze. In a 10 by 10 maze that longest shortest path possible is 59 therefor
//I will never let my path be larger than 66 also I will not let any method do more than 101 recursions.
//to print out the number of recursions done find ALL '#' in the program and uncomment those sections and than remove the '#' and in the case of the return the '0'
#include <iostream>     // std::cin, std::cout
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include<time.h>//for randommazes
typedef char maze[10][10];
typedef int ara[32];
using namespace std;
void randommazes(int n)//creates n number of mazes to file "randmaze.in"
{//(1.0.0.0.0.0)
	ofstream out;
	try//try and open
	{//(1.1.0.0.0.0)
		out.open("randmaze.in");
	}//(1.1.0.0.0.0)
	catch(const std::exception&)
	{//(1.2.0.0.0.0)
		cout<<"error in opening \"randmaze.in\"";
		return;
	}//(1.2.0.0.0.0)
	srand(time(NULL));
	int z=0;
	double perc=0.0,inc=100.0/n;
	cout<<"n=0:"<<perc<<"\%\n";
	while(z<n)
	{//(1.3.0.0.0.0)
		int w=10;//rand()%5+6;
		int h=10;//rand()%5+6;
		out<<h<<" "<<w<<endl;
		for(int y=0;y<h;y++)
		{//(1.3.1.0.0.0)
			for(int x=0;x<w;x++)
			{//(1.3.1.1.0.0)
				if((x==0&&y==0)||(x==w-1&&y==h-1))
					out<<'.';
				else if(rand()%10>rand()%5)
					out<<'.';
				else
					out<<'*';
			}//(1.3.1.1.0.0)
			out<<endl;
		}//(1.3.1.0.0.0)
		z++;
		perc=perc+inc;
		cout<<"n="<<z<<":"<<perc<<"\%\n";
	}//(1.3.0.0.0.0)
	out.close();
}//(1.0.0.0.0.0)
static void printMazes(std::ostream& out,const maze shortest,const maze c1,const maze c2,maze c3,const maze c4,const maze c5,const maze c6,const maze c7,const maze c8,const maze c9,const maze c10,const maze c11,const maze c12,const maze c13,const maze c14
	,const maze c15,const maze c16,const maze c17,const maze c18,const maze c19,const maze c20,const maze c21,const maze c22,const maze c23,const maze c24,const maze c25,const maze c26,const maze c27,const maze c28,const maze c29,const maze c30,
	maze c31,const maze c32,const int w, const int h/*#,const int total_recursions*/)
{//(2.0.0.0.0.0)
	out<<"result      |sewn        |senw        |snew        |snwe        |swne        |swen        |wsen        |wsne        |wnse        |wnes        |wens        |wesn        |ewsn        |ewns        |enws        |ensw        |esnw        |eswn        |nesw        |news        |nwes        |nwse        |nswe        |nsew        |bnews       |bwsne       |bswen       |bensw       |bsenw       |bnwse       |bwnes       |beswn;\n";
	for(int y=0;y<h;y++)
	{//(2.1.0.0.0.0)
		for(int x=0;x<w;x++)
		{//(2.1.1.0.0.0)
			out<<shortest[x][y];
		}//(2.1.1.0.0.0)
		for(int z=0;z<12-w;z++)
			out<<" ";
		out<<"|";
		for(int x=0;x<w;x++)
		{//(2.1.2.0.0.0)
			out<<c1[x][y];
		}//(2.1.2.0.0.0)
		for(int z=0;z<12-w;z++)
			out<<" ";
		out<<"|";
		for(int x=0;x<w;x++)
		{//(2.1.3.0.0.0)
			out<<c2[x][y];
		}//(2.1.3.0.0.0)
		for(int z=0;z<12-w;z++)
			out<<" ";
		out<<"|";
		for(int x=0;x<w;x++)
		{//(2.1.4.0.0.0)
			out<<c3[x][y];
		}//(2.1.4.0.0.0)
		for(int z=0;z<12-w;z++)
			out<<" ";
		out<<"|";
		for(int x=0;x<w;x++)
		{//(2.1.5.0.0.0)
			out<<c4[x][y];
		}//(2.1.5.0.0.0)
		for(int z=0;z<12-w;z++)
			out<<" ";
		out<<"|";
		for(int x=0;x<w;x++)
		{//(2.1.6.0.0.0)
			out<<c5[x][y];
		}//(2.1.6.0.0.0)
		for(int z=0;z<12-w;z++)
			out<<" ";
		out<<"|";
		for(int x=0;x<w;x++)
		{//(2.1.7.0.0.0)
			out<<c6[x][y];
		}//(2.1.7.0.0.0)
		for(int z=0;z<12-w;z++)
			out<<" ";
		out<<"|";
		for(int x=0;x<w;x++)
		{//(2.1.8.0.0.0)
			out<<c7[x][y];
		}//(2.1.8.0.0.0)
		for(int z=0;z<12-w;z++)
			out<<" ";
		out<<"|";
		for(int x=0;x<w;x++)
		{//(2.1.9.0.0.0)
			out<<c8[x][y];
		}//(2.1.9.0.0.0)
		for(int z=0;z<12-w;z++)
			out<<" ";
		out<<"|";
		for(int x=0;x<w;x++)
		{//(2.1.10.0.0.0)
			out<<c9[x][y];
		}//(2.1.10.0.0.0)
		for(int z=0;z<12-w;z++)
			out<<" ";
		out<<"|";
		for(int x=0;x<w;x++)
		{//(2.1.11.0.0.0)
			out<<c10[x][y];
		}//(2.1.11.0.0.0)
		for(int z=0;z<12-w;z++)
			out<<" ";
		out<<"|";
		for(int x=0;x<w;x++)
		{//(2.1.12.0.0.0)
			out<<c11[x][y];
		}//(2.1.12.0.0.0)
		for(int z=0;z<12-w;z++)
			out<<" ";
		out<<"|";
		for(int x=0;x<w;x++)
		{//(2.1.13.0.0.0)
			out<<c12[x][y];
		}//(2.1.13.0.0.0)
		for(int z=0;z<12-w;z++)
			out<<" ";
		out<<"|";
		for(int x=0;x<w;x++)
		{//(2.1.14.0.0.0)
			out<<c13[x][y];
		}//(2.1.14.0.0.0)
		for(int z=0;z<12-w;z++)
			out<<" ";
		out<<"|";
		for(int x=0;x<w;x++)
		{//(2.1.15.0.0.0)
			out<<c14[x][y];
		}//(2.1.15.0.0.0)
		for(int z=0;z<12-w;z++)
			out<<" ";
		out<<"|";
		for(int x=0;x<w;x++)
		{//(2.1.16.0.0.0)
			out<<c15[x][y];
		}//(2.1.16.0.0.0)
		for(int z=0;z<12-w;z++)
			out<<" ";
		out<<"|";
		for(int x=0;x<w;x++)
		{//(2.1.17.0.0.0)
			out<<c16[x][y];
		}//(2.1.17.0.0.0)
		for(int z=0;z<12-w;z++)
			out<<" ";
		out<<"|";
		for(int x=0;x<w;x++)
		{//(2.1.18.0.0.0)
			out<<c17[x][y];
		}//(2.1.18.0.0.0)
		for(int z=0;z<12-w;z++)
			out<<" ";
		out<<"|";
		for(int x=0;x<w;x++)
		{//(2.1.19.0.0.0)
			out<<c18[x][y];
		}//(2.1.19.0.0.0)
		for(int z=0;z<12-w;z++)
			out<<" ";
		out<<"|";
		for(int x=0;x<w;x++)
		{//(2.1.20.0.0.0)
			out<<c19[x][y];
		}//(2.1.20.0.0.0)
		for(int z=0;z<12-w;z++)
			out<<" ";
		out<<"|";
		for(int x=0;x<w;x++)
		{//(2.1.21.0.0.0)
			out<<c20[x][y];
		}//(2.1.21.0.0.0)
		for(int z=0;z<12-w;z++)
			out<<" ";
		out<<"|";
		for(int x=0;x<w;x++)
		{//(2.1.22.0.0.0)
			out<<c21[x][y];
		}//(2.1.22.0.0.0)
		for(int z=0;z<12-w;z++)
			out<<" ";
		out<<"|";
		for(int x=0;x<w;x++)
		{//(2.1.23.0.0.0)
			out<<c22[x][y];
		}//(2.1.23.0.0.0)
		for(int z=0;z<12-w;z++)
			out<<" ";
		out<<"|";
		for(int x=0;x<w;x++)
		{//(2.1.24.0.0.0)
			out<<c23[x][y];
		}//(2.1.24.0.0.0)
		for(int z=0;z<12-w;z++)
			out<<" ";
		out<<"|";
		for(int x=0;x<w;x++)
		{//(2.1.25.0.0.0)
			out<<c24[x][y];
		}//(2.1.25.0.0.0)
		for(int z=0;z<12-w;z++)
			out<<" ";
		out<<"|";
		for(int x=0;x<w;x++)
		{//(2.1.26.0.0.0)
			out<<c25[x][y];
		}//(2.1.26.0.0.0)
		for(int z=0;z<12-w;z++)
			out<<" ";
		out<<"|";
		for(int x=0;x<w;x++)
		{//(2.1.27.0.0.0)
			out<<c26[x][y];
		}//(2.1.27.0.0.0)
		for(int z=0;z<12-w;z++)
			out<<" ";
		out<<"|";
		for(int x=0;x<w;x++)
		{//(2.1.28.0.0.0)
			out<<c27[x][y];
		}//(2.1.28.0.0.0)
		for(int z=0;z<12-w;z++)
			out<<" ";
		out<<"|";
		for(int x=0;x<w;x++)
		{//(2.1.29.0.0.0)
			out<<c28[x][y];
		}//(2.1.29.0.0.0)
		for(int z=0;z<12-w;z++)
			out<<" ";
		out<<"|";
		for(int x=0;x<w;x++)
		{//(2.1.30.0.0.0)
			out<<c29[x][y];
		}//(2.1.30.0.0.0)
		for(int z=0;z<12-w;z++)
			out<<" ";
		out<<"|";
		for(int x=0;x<w;x++)
		{//(2.1.31.0.0.0)
			out<<c30[x][y];
		}//(2.1.31.0.0.0)
		for(int z=0;z<12-w;z++)
			out<<" ";
		out<<"|";
		for(int x=0;x<w;x++)
		{//(2.1.32.0.0.0)
			out<<c31[x][y];
		}//(2.1.32.0.0.0)
		for(int z=0;z<12-w;z++)
			out<<" ";
		out<<"|";
		for(int x=0;x<w;x++)
		{//(2.1.33.0.0.0)
			out<<c32[x][y];
		}//(2.1.33.0.0.0)
		out<<"\n";
	}//(2.1.0.0.0.0)
	out/*#<<"recursions to solve:"<<total_recursions*/<<"\n";
}//(2.0.0.0.0.0)
//this is the print for what you want
static void printMaze(std::ostream& out, maze c,const int w,const int h)//prints maze
{//(3.0.0.0.0.0)
	out<<h<<" "<<w<<endl;
	for(int y=0;y<h;y++)
	{//(3.1.0.0.0.0)
		for(int x=0;x<w;x++)
		{//(3.1.1.0.0.0)
			out<<c[x][y];
		}//(3.1.1.0.0.0)
		out<<endl;
	}//(3.1.0.0.0.0)
}//(3.0.0.0.0.0)
//the following methods' names will tell you what the order of n,s,w,e will tell you the order of checking. n=north,s=south,w=west,e=east
//other then that they each are nearly identical
bool sewntraverse(maze& cc, int x, int y, char c, const int width, const int height,int& endc,bool& badsit, int& reccount)
{//(4.0.0.0.0.0)
	//this will prevent a rare event that the shortest path wont be found
	int nadj=0;
	if(x!=width-1&&cc[x+1][y]!='.'&&cc[x+1][y]!='*'&&cc[x+1][y]!=',')
		nadj++;
	if(y!=height-1&&cc[x][y+1]!='.'&&cc[x][y+1]!='*'&&cc[x][y+1]!=',')
		nadj++;
	if(y!=0&&cc[x][y-1]!='.'&&cc[x][y-1]!='*'&&cc[x][y-1]!=',')
		nadj++;
	if(x!=0&&cc[x-1][y]!='.'&&cc[x-1][y]!='*'&&cc[x-1][y]!=',')
		nadj++;
	if(nadj>1)
		return false;
	if(reccount==0&&(cc[0][0]=='*'||cc[width-1][height-1]=='*'))////if the start and end are walls them selves are found to be walls method returns false and ends recursion
		return false;
	reccount++;//keeps track of the amount of time there has been a recursive call
	//if(reccount>100)//takes care of inefici i am able to do this because there must be another function that will find the path within a proper time
	//{//(4.1.0.0.0.0)
	//	badsit=true;//aloows for the swift exit of the stack of recursion
	//	return false;
	//}//(4.1.0.0.0.0)
	endc++;//keeps track of path length
	if(endc>65)//checks to see if the current path length is greater then current min
	{//(4.2.0.0.0.0)
		endc--;//if endc>pastmin this square is treated as if path is blocked
		return false;
	}//(4.2.0.0.0.0)
	if(c>'z')//loops char value
		c='a';
	bool b=false;//bool that reprasents if the end was reached
	cc[x][y]=c;//marks trail by alphabet
	if((x+1)==width&&(y+1)==height)//checks to see if at end
	{//(4.3.0.0.0.0)
		return true;//returns true to signify the maze has been finished
	}//(4.3.0.0.0.0)
	if(!badsit&&!b&&(y+1)<height&&cc[x][y+1]=='.')//checks south 
	{//(4.4.0.0.0.0)
		b=sewntraverse(cc,x,y+1,c+1,width,height,endc,badsit,reccount);//goes south a block
	}//(4.4.0.0.0.0)
	if(!badsit&&!b&&(x+1)<width&&cc[x+1][y]=='.')//checks east
	{//(4.5.0.0.0.0)
		b=sewntraverse(cc,x+1,y,c+1,width,height,endc,badsit,reccount);//goes east
	}//(4.5.0.0.0.0)
	if(!badsit&&!b&&(x-1)>=0&&cc[x-1][y]=='.')//checks west
	{//(4.6.0.0.0.0)
		b=sewntraverse(cc,x-1,y,c+1,width,height,endc,badsit,reccount);//goes west
	}//(4.6.0.0.0.0)
	if(!badsit&&!b&&(y-1)>=0&&cc[x][y-1]=='.')//checks north
	{//(4.7.0.0.0.0)
		b=sewntraverse(cc,x,y-1,c+1,width,height,endc,badsit,reccount);//goes north
	}//(4.7.0.0.0.0)
	if(!b)//if path is blocked unmarks path and decrements path length
	{//(4.8.0.0.0.0)
		cc[x][y]=',';//this method has a ',' instead of '.' to account for the excessive spiralling that accures in some mazes with no path
		endc--;
	}//(4.8.0.0.0.0)
	return b;
}//(4.0.0.0.0.0)
bool senwtraverse(maze& cc, int x, int y, char c, const int width, const int height,int& endc,const int pastmin,bool& badsit,int& reccount)
{//(5.0.0.0.0.0)
	//this will prevent a rare event that the shortest path wont be found
	int nadj=0;
	if(x!=width-1&&cc[x+1][y]!='.'&&cc[x+1][y]!='*'&&cc[x+1][y]!=',')
		nadj++;
	if(y!=height-1&&cc[x][y+1]!='.'&&cc[x][y+1]!='*'&&cc[x][y+1]!=',')
		nadj++;
	if(y!=0&&cc[x][y-1]!='.'&&cc[x][y-1]!='*'&&cc[x][y-1]!=',')
		nadj++;
	if(x!=0&&cc[x-1][y]!='.'&&cc[x-1][y]!='*'&&cc[x-1][y]!=',')
		nadj++;
	if(nadj>1)//if more than one adjacent path marker returns to back track since there is a short cut.
		return false;
	if(reccount==0&&(cc[0][0]=='*'||cc[width-1][height-1]=='*'))////if the start and end are walls them selves are found to be walls method returns false and ends recursion
		return false;
	reccount++;//keeps track of the amount of time there has been a recursive call
	if(reccount>100)//takes care of a time issue i am able to do this because there must be another function that will find the path within a proper time
	{//(5.1.0.0.0.0)
		badsit=true;//aloows for the swift exit of the stack of recursion
		return false;
	}//(5.1.0.0.0.0)
	endc++;//keeps track of path length
	if(endc>pastmin)//checks to see if the current path length is greater then current min
	{//(5.2.0.0.0.0)
		endc--;//if endc>pastmin this square is treated as if path is blocked
		return false;
	}//(5.2.0.0.0.0)
	if(c>'z')//loops char value
		c='a';
	bool b=false;//bool that reprasents if the end was reached
	cc[x][y]=c;//marks trail by alphabet
	if((x+1)==width&&(y+1)==height)//checks to see if at end
	{//(5.3.0.0.0.0)
		return true;//returns true to signify the maze has been finished
	}//(5.3.0.0.0.0)
	if(!badsit&&!b&&(y+1)<height&&cc[x][y+1]=='.')//if maze still unfinished checks south for path
	{//(5.4.0.0.0.0)
		b=senwtraverse(cc,x,y+1,c+1,width,height,endc,pastmin,badsit,reccount);//goes south a block
	}//(5.4.0.0.0.0)
	if(!badsit&&!b&&(x+1)<width&&cc[x+1][y]=='.')//if maze is still unfinished checks east for path
	{//(5.5.0.0.0.0)
		b=senwtraverse(cc,x+1,y,c+1,width,height,endc,pastmin,badsit,reccount);//goes east
	}//(5.5.0.0.0.0)
	if(!badsit&&!b&&(y-1)>=0&&cc[x][y-1]=='.')//checks north
	{//(5.6.0.0.0.0)
		b=senwtraverse(cc,x,y-1,c+1,width,height,endc,pastmin,badsit,reccount);//goes north
	}//(5.6.0.0.0.0)
	if(!badsit&&!b&&(x-1)>=0&&cc[x-1][y]=='.')//checks west
	{//(5.7.0.0.0.0)
		b=senwtraverse(cc,x-1,y,c+1,width,height,endc,pastmin,badsit,reccount);//goes west
	}//(5.7.0.0.0.0)
	if(!b)//if path is blocked unmarks path and decrements path length
	{//(5.8.0.0.0.0)
		cc[x][y]='.';
		endc--;
	}//(5.8.0.0.0.0)
	return b;
}//(5.0.0.0.0.0)
bool snewtraverse(maze& cc, int x, int y, char c, const int width, const int height,int& endc,const int pastmin,bool& badsit,int& reccount)
{//(6.0.0.0.0.0)
	//this will prevent a rare event that the shortest path wont be found
	int nadj=0;
	if(x!=width-1&&cc[x+1][y]!='.'&&cc[x+1][y]!='*'&&cc[x+1][y]!=',')
		nadj++;
	if(y!=height-1&&cc[x][y+1]!='.'&&cc[x][y+1]!='*'&&cc[x][y+1]!=',')
		nadj++;
	if(y!=0&&cc[x][y-1]!='.'&&cc[x][y-1]!='*'&&cc[x][y-1]!=',')
		nadj++;
	if(x!=0&&cc[x-1][y]!='.'&&cc[x-1][y]!='*'&&cc[x-1][y]!=',')
		nadj++;
	if(nadj>1)
		return false;
	if(reccount==0&&(cc[0][0]=='*'||cc[width-1][height-1]=='*'))////if the start and end are walls them selves are found to be walls method returns false and ends recursion
		return false;
	reccount++;//keeps track of the amount of time there has been a recursive call
	if(reccount>100)//takes care of a time issue i am able to do this because there must be another function that will find the path within a proper time
	{//(6.1.0.0.0.0)
		badsit=true;//allows for the swift exit of the stack of recursion
		return false;
	}//(6.1.0.0.0.0)
	endc++;//keeps track of path length
	if(endc>pastmin)//checks to see if the current path length is greater then current min
	{//(6.2.0.0.0.0)
		endc--;//if endc>pastmin this square is treated as if path is blocked
		return false;
	}//(6.2.0.0.0.0)
	if(c>'z')//loops char value
		c='a';
	bool b=false;//bool that reprasents if the end was reached
	cc[x][y]=c;//marks trail by alphabet
	if((x+1)==width&&(y+1)==height)//checks to see if at end
	{//(6.3.0.0.0.0)
		return true;//returns true to signify the maze has been finished
	}//(6.3.0.0.0.0)
	if(!badsit&&!b&&(y+1)<height&&cc[x][y+1]=='.')//checks south
	{//(6.4.0.0.0.0)
		b=snewtraverse(cc,x,y+1,c+1,width,height,endc,pastmin,badsit,reccount);//goes south a block
	}//(6.4.0.0.0.0)
	if(!badsit&&!b&&(y-1)>=0&&cc[x][y-1]=='.')//checks north
	{//(6.5.0.0.0.0)
		b=snewtraverse(cc,x,y-1,c+1,width,height,endc,pastmin,badsit,reccount);//goes north
	}//(6.5.0.0.0.0)
	if(!badsit&&!b&&(x+1)<width&&cc[x+1][y]=='.')//checks east
	{//(6.6.0.0.0.0)
		b=snewtraverse(cc,x+1,y,c+1,width,height,endc,pastmin,badsit,reccount);//goes east
	}//(6.6.0.0.0.0)
	if(!badsit&&!b&&(x-1)>=0&&cc[x-1][y]=='.')//checks west
	{//(6.7.0.0.0.0)
		b=snewtraverse(cc,x-1,y,c+1,width,height,endc,pastmin,badsit,reccount);//goes west
	}//(6.7.0.0.0.0)
	if(!b)//if path is blocked unmarks path and decrements path length
	{//(6.8.0.0.0.0)
		cc[x][y]='.';
		endc--;
	}//(6.8.0.0.0.0)
	return b;
}//(6.0.0.0.0.0)
bool snwetraverse(maze& cc, int x, int y, char c, const int width, const int height,int& endc,const int pastmin,bool& badsit,int& reccount)
{//(7.0.0.0.0.0)
	//this will prevent a rare event that the shortest path wont be found
	int nadj=0;
	if(x!=width-1&&cc[x+1][y]!='.'&&cc[x+1][y]!='*'&&cc[x+1][y]!=',')
		nadj++;
	if(y!=height-1&&cc[x][y+1]!='.'&&cc[x][y+1]!='*'&&cc[x][y+1]!=',')
		nadj++;
	if(y!=0&&cc[x][y-1]!='.'&&cc[x][y-1]!='*'&&cc[x][y-1]!=',')
		nadj++;
	if(x!=0&&cc[x-1][y]!='.'&&cc[x-1][y]!='*'&&cc[x-1][y]!=',')
		nadj++;
	if(nadj>1)
		return false;
	if(reccount==0&&(cc[0][0]=='*'||cc[width-1][height-1]=='*'))////if the start and end are walls them selves are found to be walls method returns false and ends recursion
		return false;
	reccount++;//keeps track of the amount of time there has been a recursive call
	if(reccount>100)//takes care of a time issue i am able to do this because there must be another function that will find the path within a proper time
	{//(7.1.0.0.0.0)
		badsit=true;//aloows for the swift exit of the stack of recursion
		return false;
	}//(7.1.0.0.0.0)
	endc++;//keeps track of path length
	if(endc>pastmin)//checks to see if the current path length is greater then current min
	{//(7.2.0.0.0.0)
		endc--;//if endc>pastmin this square is treated as if path is blocked
		return false;
	}//(7.2.0.0.0.0)
	if(c>'z')//loops char value
		c='a';
	bool b=false;//bool that reprasents if the end was reached
	cc[x][y]=c;//marks trail by alphabet
	if((x+1)==width&&(y+1)==height)//checks to see if at end
	{//(7.3.0.0.0.0)
		return true;//returns true to signify the maze has been finished
	}//(7.3.0.0.0.0)
	if(!badsit&&!b&&(y+1)<height&&cc[x][y+1]=='.')//checks south
	{//(7.4.0.0.0.0)
		b=snwetraverse(cc,x,y+1,c+1,width,height,endc,pastmin,badsit,reccount);//goes south a block
	}//(7.4.0.0.0.0)
	if(!badsit&&!b&&(y-1)>=0&&cc[x][y-1]=='.')//checks north
	{//(7.5.0.0.0.0)
		b=snwetraverse(cc,x,y-1,c+1,width,height,endc,pastmin,badsit,reccount);//goes north
	}//(7.5.0.0.0.0)
	if(!badsit&&!b&&(x-1)>=0&&cc[x-1][y]=='.')//checks west
	{//(7.6.0.0.0.0)
		b=snwetraverse(cc,x-1,y,c+1,width,height,endc,pastmin,badsit,reccount);//goes west
	}//(7.6.0.0.0.0)
	if(!badsit&&!b&&(x+1)<width&&cc[x+1][y]=='.')//checks east
	{//(7.7.0.0.0.0)
		b=snwetraverse(cc,x+1,y,c+1,width,height,endc,pastmin,badsit,reccount);//goes east
	}//(7.7.0.0.0.0)
	if(!b)//if path is blocked unmarks path and decrements path length
	{//(7.8.0.0.0.0)
		cc[x][y]='.';
		endc--;
	}//(7.8.0.0.0.0)
	return b;
}//(7.0.0.0.0.0)
bool swnetraverse(maze& cc, int x, int y, char c, const int width, const int height,int& endc,const int pastmin,bool& badsit,int& reccount)
{//(8.0.0.0.0.0)
	//this will prevent a rare event that the shortest path wont be found
	int nadj=0;
	if(x!=width-1&&cc[x+1][y]!='.'&&cc[x+1][y]!='*'&&cc[x+1][y]!=',')
		nadj++;
	if(y!=height-1&&cc[x][y+1]!='.'&&cc[x][y+1]!='*'&&cc[x][y+1]!=',')
		nadj++;
	if(y!=0&&cc[x][y-1]!='.'&&cc[x][y-1]!='*'&&cc[x][y-1]!=',')
		nadj++;
	if(x!=0&&cc[x-1][y]!='.'&&cc[x-1][y]!='*'&&cc[x-1][y]!=',')
		nadj++;
	if(nadj>1)
		return false;
	if(reccount==0&&(cc[0][0]=='*'||cc[width-1][height-1]=='*'))////if the start and end are walls them selves are found to be walls method returns false and ends recursion
		return false;
	reccount++;//keeps track of the amount of time there has been a recursive call
	if(reccount>100)//takes care of a time issue i am able to do this because there must be another function that will find the path within a proper time
	{//(8.1.0.0.0.0)
		badsit=true;//aloows for the swift exit of the stack of recursion
		return false;
	}//(8.1.0.0.0.0)
	endc++;//keeps track of path length
	if(endc>pastmin)//checks to see if the current path length is greater then current min
	{//(8.2.0.0.0.0)
		endc--;//if endc>pastmin this square is treated as if path is blocked
		return false;
	}//(8.2.0.0.0.0)
	if(c>'z')//loops char value
		c='a';
	bool b=false;//bool that reprasents if the end was reached
	cc[x][y]=c;//marks trail by alphabet
	if((x+1)==width&&(y+1)==height)//checks to see if at end
	{//(8.3.0.0.0.0)
		return true;//returns true to signify the maze has been finished
	}//(8.3.0.0.0.0)
	if(!badsit&&!b&&(y+1)<height&&cc[x][y+1]=='.')//checks south 
	{//(8.4.0.0.0.0)
		b=swnetraverse(cc,x,y+1,c+1,width,height,endc,pastmin,badsit,reccount);//goes south a block
	}//(8.4.0.0.0.0)
	if(!badsit&&!b&&(x-1)>=0&&cc[x-1][y]=='.')//checks west
	{//(8.5.0.0.0.0)
		b=swnetraverse(cc,x-1,y,c+1,width,height,endc,pastmin,badsit,reccount);//goes west
	}//(8.5.0.0.0.0)
	if(!badsit&&!b&&(y-1)>=0&&cc[x][y-1]=='.')//checks north
	{//(8.6.0.0.0.0)
		b=swnetraverse(cc,x,y-1,c+1,width,height,endc,pastmin,badsit,reccount);//goes north
	}//(8.6.0.0.0.0)
	if(!badsit&&!b&&(x+1)<width&&cc[x+1][y]=='.')//checks east for path
	{//(8.7.0.0.0.0)
		b=swnetraverse(cc,x+1,y,c+1,width,height,endc,pastmin,badsit,reccount);//goes east
	}//(8.7.0.0.0.0)
	if(!b)//if path is blocked unmarks path and decrements path length
	{//(8.8.0.0.0.0)
		cc[x][y]='.';
		endc--;
	}//(8.8.0.0.0.0)
	return b;
}//(8.0.0.0.0.0)
bool swentraverse(maze& cc, int x, int y, char c, const int width, const int height,int& endc,const int pastmin,bool& badsit,int& reccount)
{//(9.0.0.0.0.0)
	//this will prevent a rare event that the shortest path wont be found
	int nadj=0;
	if(x!=width-1&&cc[x+1][y]!='.'&&cc[x+1][y]!='*'&&cc[x+1][y]!=',')
		nadj++;
	if(y!=height-1&&cc[x][y+1]!='.'&&cc[x][y+1]!='*'&&cc[x][y+1]!=',')
		nadj++;
	if(y!=0&&cc[x][y-1]!='.'&&cc[x][y-1]!='*'&&cc[x][y-1]!=',')
		nadj++;
	if(x!=0&&cc[x-1][y]!='.'&&cc[x-1][y]!='*'&&cc[x-1][y]!=',')
		nadj++;
	if(nadj>1)
		return false;
	if(reccount==0&&(cc[0][0]=='*'||cc[width-1][height-1]=='*'))////if the start and end are walls them selves are found to be walls method returns false and ends recursion
		return false;
	reccount++;//keeps track of the amount of time there has been a recursive call
	if(reccount>100)//takes care of a time issue i am able to do this because there must be another function that will find the path within a proper time
	{//(9.1.0.0.0.0)
		badsit=true;//aloows for the swift exit of the stack of recursion
		return false;
	}//(9.1.0.0.0.0)
	endc++;//keeps track of path length
	if(endc>pastmin)//checks to see if the current path length is greater then current min
	{//(9.2.0.0.0.0)
		endc--;//if endc>pastmin this square is treated as if path is blocked
		return false;
	}//(9.2.0.0.0.0)
	if(c>'z')//loops char value
		c='a';
	bool b=false;//bool that reprasents if the end was reached
	cc[x][y]=c;//marks trail by alphabet
	if((x+1)==width&&(y+1)==height)//checks to see if at end
	{//(9.3.0.0.0.0)
		return true;//returns true to signify the maze has been finished
	}//(9.3.0.0.0.0)
	if(!badsit&&!b&&(y+1)<height&&cc[x][y+1]=='.')//checks south for path
	{//(9.4.0.0.0.0)
		b=swentraverse(cc,x,y+1,c+1,width,height,endc,pastmin,badsit,reccount);//goes south a block
	}//(9.4.0.0.0.0)
	if(!badsit&&!b&&(x-1)>=0&&cc[x-1][y]=='.')//checks west
	{//(9.5.0.0.0.0)
		b=swentraverse(cc,x-1,y,c+1,width,height,endc,pastmin,badsit,reccount);//goes west
	}//(9.5.0.0.0.0)
	if(!badsit&&!b&&(x+1)<width&&cc[x+1][y]=='.')//checks east for path
	{//(9.6.0.0.0.0)
		b=swentraverse(cc,x+1,y,c+1,width,height,endc,pastmin,badsit,reccount);//goes east
	}//(9.6.0.0.0.0)
	if(!badsit&&!b&&(y-1)>=0&&cc[x][y-1]=='.')//checks north
	{//(9.7.0.0.0.0)
		b=swentraverse(cc,x,y-1,c+1,width,height,endc,pastmin,badsit,reccount);//goes north
	}//(9.7.0.0.0.0)
	if(!b)//if path is blocked unmarks path and decrements path length
	{//(9.8.0.0.0.0)
		cc[x][y]='.';
		endc--;
	}//(9.8.0.0.0.0)
	return b;
}//(9.0.0.0.0.0)
bool wsentraverse(maze& cc, int x, int y, char c, const int width, const int height,int& endc,const int pastmin,bool& badsit,int& reccount)
{//(10.0.0.0.0.0)
	//this will prevent a rare event that the shortest path wont be found
	int nadj=0;
	if(x!=width-1&&cc[x+1][y]!='.'&&cc[x+1][y]!='*'&&cc[x+1][y]!=',')
		nadj++;
	if(y!=height-1&&cc[x][y+1]!='.'&&cc[x][y+1]!='*'&&cc[x][y+1]!=',')
		nadj++;
	if(y!=0&&cc[x][y-1]!='.'&&cc[x][y-1]!='*'&&cc[x][y-1]!=',')
		nadj++;
	if(x!=0&&cc[x-1][y]!='.'&&cc[x-1][y]!='*'&&cc[x-1][y]!=',')
		nadj++;
	if(nadj>1)
		return false;
	if(reccount==0&&(cc[0][0]=='*'||cc[width-1][height-1]=='*'))////if the start and end are walls them selves are found to be walls method returns false and ends recursion
		return false;
	reccount++;//keeps track of the amount of time there has been a recursive call
	if(reccount>100)//takes care of a time issue i am able to do this because there must be another function that will find the path within a proper time
	{//(10.1.0.0.0.0)
		badsit=true;//allows for the swift exit of the stack of recursion
		return false;
	}//(10.1.0.0.0.0)
	endc++;//keeps track of path length
	if(endc>pastmin)//checks to see if the current path length is greater then current min
	{//(10.2.0.0.0.0)
		endc--;//if endc>pastmin this square is treated as if path is blocked
		return false;
	}//(10.2.0.0.0.0)
	if(c>'z')//loops char value
		c='a';
	bool b=false;//bool that reprasents if the end was reached
	cc[x][y]=c;//marks trail by alphabet
	if((x+1)==width&&(y+1)==height)//checks to see if at end
	{//(10.3.0.0.0.0)
		return true;//returns true to signify the maze has been finished
	}//(10.3.0.0.0.0)
	if(!badsit&&!b&&(x-1)>=0&&cc[x-1][y]=='.')//checks west
	{//(10.4.0.0.0.0)
		b=wsentraverse(cc,x-1,y,c+1,width,height,endc,pastmin,badsit,reccount);//goes west
	}//(10.4.0.0.0.0)
	if(!badsit&&!b&&(y+1)<height&&cc[x][y+1]=='.')//checks south for path
	{//(10.5.0.0.0.0)
		b=wsentraverse(cc,x,y+1,c+1,width,height,endc,pastmin,badsit,reccount);//goes south a block
	}//(10.5.0.0.0.0)
	if(!badsit&&!b&&(x+1)<width&&cc[x+1][y]=='.')// checks east for path
	{//(10.6.0.0.0.0)
		b=wsentraverse(cc,x+1,y,c+1,width,height,endc,pastmin,badsit,reccount);//goes east
	}//(10.6.0.0.0.0)
	if(!badsit&&!b&&(y-1)>=0&&cc[x][y-1]=='.')//checks north
	{//(10.7.0.0.0.0)
		b=wsentraverse(cc,x,y-1,c+1,width,height,endc,pastmin,badsit,reccount);//goes north
	}//(10.7.0.0.0.0)
	if(!b)//if path is blocked unmarks path and decrements path length
	{//(10.8.0.0.0.0)
		cc[x][y]='.';
		endc--;
	}//(10.8.0.0.0.0)
	return b;
}//(10.0.0.0.0.0)
bool wsnetraverse(maze& cc, int x, int y, char c, const int width, const int height,int& endc,const int pastmin,bool& badsit,int& reccount)
{//(11.0.0.0.0.0)
	//this will prevent a rare event that the shortest path wont be found
	int nadj=0;
	if(x!=width-1&&cc[x+1][y]!='.'&&cc[x+1][y]!='*'&&cc[x+1][y]!=',')
		nadj++;
	if(y!=height-1&&cc[x][y+1]!='.'&&cc[x][y+1]!='*'&&cc[x][y+1]!=',')
		nadj++;
	if(y!=0&&cc[x][y-1]!='.'&&cc[x][y-1]!='*'&&cc[x][y-1]!=',')
		nadj++;
	if(x!=0&&cc[x-1][y]!='.'&&cc[x-1][y]!='*'&&cc[x-1][y]!=',')
		nadj++;
	if(nadj>1)
		return false;
	if(reccount==0&&(cc[0][0]=='*'||cc[width-1][height-1]=='*'))////if the start and end are walls them selves are found to be walls method returns false and ends recursion
		return false;
	reccount++;//keeps track of the amount of time there has been a recursive call
	if(reccount>100)//takes care of a time issue i am able to do this because there must be another function that will find the path within a proper time
	{//(11.1.0.0.0.0)
		badsit=true;//allows for the swift exit of the stack of recursion
		return false;
	}//(11.1.0.0.0.0)
	endc++;//keeps track of path length
	if(endc>pastmin)//checks to see if the current path length is greater then current min
	{//(11.2.0.0.0.0)
		endc--;//if endc>pastmin this square is treated as if path is blocked
		return false;
	}//(11.2.0.0.0.0)
	if(c>'z')//loops char value
		c='a';
	bool b=false;//bool that reprasents if the end was reached
	cc[x][y]=c;//marks trail by alphabet
	if((x+1)==width&&(y+1)==height)//checks to see if at end
	{//(11.3.0.0.0.0)
		return true;//returns true to signify the maze has been finished
	}//(11.3.0.0.0.0)
	if(!badsit&&!b&&(x-1)>=0&&cc[x-1][y]=='.')//checks west
	{//(11.4.0.0.0.0)
		b=wsnetraverse(cc,x-1,y,c+1,width,height,endc,pastmin,badsit,reccount);//goes west
	}//(11.4.0.0.0.0)
	if(!badsit&&!b&&(y+1)<height&&cc[x][y+1]=='.')// checks south
	{//(11.5.0.0.0.0)
		b=wsnetraverse(cc,x,y+1,c+1,width,height,endc,pastmin,badsit,reccount);//goes south a block
	}//(11.5.0.0.0.0)
	if(!badsit&&!b&&(y-1)>=0&&cc[x][y-1]=='.')//checks north
	{//(11.6.0.0.0.0)
		b=wsnetraverse(cc,x,y-1,c+1,width,height,endc,pastmin,badsit,reccount);//goes north
	}//(11.6.0.0.0.0)
	if(!badsit&&!b&&(x+1)<width&&cc[x+1][y]=='.')//checks east
	{//(11.7.0.0.0.0)
		b=wsnetraverse(cc,x+1,y,c+1,width,height,endc,pastmin,badsit,reccount);//goes east
	}//(11.7.0.0.0.0)
	if(!b)//if path is blocked unmarks path and decrements path length
	{//(11.8.0.0.0.0)
		endc--;
		cc[x][y]='.';
	}//(11.8.0.0.0.0)
	return b;
}//(11.0.0.0.0.0)
bool wnsetraverse(maze& cc, int x, int y, char c, const int width, const int height,int& endc,const int pastmin,bool& badsit,int& reccount)
{//(12.0.0.0.0.0)
	//this will prevent a rare event that the shortest path wont be found
	int nadj=0;
	if(x!=width-1&&cc[x+1][y]!='.'&&cc[x+1][y]!='*'&&cc[x+1][y]!=',')
		nadj++;
	if(y!=height-1&&cc[x][y+1]!='.'&&cc[x][y+1]!='*'&&cc[x][y+1]!=',')
		nadj++;
	if(y!=0&&cc[x][y-1]!='.'&&cc[x][y-1]!='*'&&cc[x][y-1]!=',')
		nadj++;
	if(x!=0&&cc[x-1][y]!='.'&&cc[x-1][y]!='*'&&cc[x-1][y]!=',')
		nadj++;
	if(nadj>1)
		return false;
	if(reccount==0&&(cc[0][0]=='*'||cc[width-1][height-1]=='*'))////if the start and end are walls them selves are found to be walls method returns false and ends recursion
		return false;
	reccount++;//keeps track of the amount of time there has been a recursive call
	if(reccount>100)//takes care of a time issue i am able to do this because there must be another function that will find the path within a proper time
	{//(12.1.0.0.0.0)
		badsit=true;//allows for the swift exit of the stack of recursion
		return false;
	}//(12.1.0.0.0.0)
	endc++;//keeps track of path length
	if(endc>pastmin)//checks to see if the current path length is greater then current min
	{//(12.2.0.0.0.0)
		endc--;//if endc>pastmin this square is treated as if path is blocked
		return false;
	}//(12.2.0.0.0.0)
	if(c>'z')//loops char value
		c='a';
	bool b=false;//bool that reprasents if the end was reached
	cc[x][y]=c;//marks trail by alphabet
	if((x+1)==width&&(y+1)==height)//checks to see if at end
	{//(12.3.0.0.0.0)
		return true;//returns true to signify the maze has been finished
	}//(12.3.0.0.0.0)
	if(!badsit&&!b&&(x-1)>=0&&cc[x-1][y]=='.')//checks west
	{//(12.4.0.0.0.0)
		b=wnsetraverse(cc,x-1,y,c+1,width,height,endc,pastmin,badsit,reccount);//goes west
	}//(12.4.0.0.0.0)
	if(!badsit&&!b&&(y-1)>=0&&cc[x][y-1]=='.')//checks north
	{//(12.5.0.0.0.0)
		b=wnsetraverse(cc,x,y-1,c+1,width,height,endc,pastmin,badsit,reccount);//goes north
	}//(12.5.0.0.0.0)
	if(!badsit&&!b&&(y+1)<height&&cc[x][y+1]=='.')// checks south
	{//(12.6.0.0.0.0)
		b=wnsetraverse(cc,x,y+1,c+1,width,height,endc,pastmin,badsit,reccount);//goes south a block
	}//(12.6.0.0.0.0)
	if(!badsit&&!b&&(x+1)<width&&cc[x+1][y]=='.')//checks east
	{//(12.7.0.0.0.0)
		b=wnsetraverse(cc,x+1,y,c+1,width,height,endc,pastmin,badsit,reccount);//goes east
	}//(12.7.0.0.0.0)
	if(!b)//if path is blocked unmarks path and decrements path length
	{//(12.8.0.0.0.0)
		endc--;
		cc[x][y]='.';
	}//(12.8.0.0.0.0)
	return b;
}//(12.0.0.0.0.0)
bool wnestraverse(maze& cc, int x, int y, char c, const int width, const int height,int& endc,const int pastmin,bool& badsit,int& reccount)
{//(13.0.0.0.0.0)
	//this will prevent a rare event that the shortest path wont be found
	int nadj=0;
	if(x!=width-1&&cc[x+1][y]!='.'&&cc[x+1][y]!='*'&&cc[x+1][y]!=',')
		nadj++;
	if(y!=height-1&&cc[x][y+1]!='.'&&cc[x][y+1]!='*'&&cc[x][y+1]!=',')
		nadj++;
	if(y!=0&&cc[x][y-1]!='.'&&cc[x][y-1]!='*'&&cc[x][y-1]!=',')
		nadj++;
	if(x!=0&&cc[x-1][y]!='.'&&cc[x-1][y]!='*'&&cc[x-1][y]!=',')
		nadj++;
	if(nadj>1)
		return false;
	if(reccount==0&&(cc[0][0]=='*'||cc[width-1][height-1]=='*'))////if the start and end are walls them selves are found to be walls method returns false and ends recursion
		return false;
	reccount++;//keeps track of the amount of time there has been a recursive call
	if(reccount>100)//takes care of a time issue i am able to do this because there must be another function that will find the path within a proper time
	{//(13.1.0.0.0.0)
		badsit=true;//allows for the swift exit of the stack of recursion
		return false;
	}//(13.1.0.0.0.0)
	endc++;//keeps track of path length
	if(endc>pastmin)//checks to see if the current path length is greater then current min
	{//(13.2.0.0.0.0)
		endc--;//if endc>pastmin this square is treated as if path is blocked
		return false;
	}//(13.2.0.0.0.0)
	if(c>'z')//loops char value
		c='a';
	bool b=false;//bool that reprasents if the end was reached
	cc[x][y]=c;//marks trail by alphabet
	if((x+1)==width&&(y+1)==height)//checks to see if at end
	{//(13.3.0.0.0.0)
		return true;//returns true to signify the maze has been finished
	}//(13.3.0.0.0.0)
	if(!badsit&&!b&&(x-1)>=0&&cc[x-1][y]=='.')//checks west
	{//(13.4.0.0.0.0)
		b=wnestraverse(cc,x-1,y,c+1,width,height,endc,pastmin,badsit,reccount);//goes west
	}//(13.4.0.0.0.0)
	if(!badsit&&!b&&(y-1)>=0&&cc[x][y-1]=='.')//checks north
	{//(13.5.0.0.0.0)
		b=wnestraverse(cc,x,y-1,c+1,width,height,endc,pastmin,badsit,reccount);//goes north
	}//(13.5.0.0.0.0)
	if(!badsit&&!b&&(x+1)<width&&cc[x+1][y]=='.')//checks east
	{//(13.6.0.0.0.0)
		b=wnestraverse(cc,x+1,y,c+1,width,height,endc,pastmin,badsit,reccount);//goes east
	}//(13.6.0.0.0.0)
	if(!badsit&&!b&&(y+1)<height&&cc[x][y+1]=='.')// checks south
	{//(13.7.0.0.0.0)
		b=wnestraverse(cc,x,y+1,c+1,width,height,endc,pastmin,badsit,reccount);//goes south a block
	}//(13.7.0.0.0.0)
	if(!b)//if path is blocked unmarks path and decrements path length
	{//(13.8.0.0.0.0)
		endc--;
		cc[x][y]='.';
	}//(13.8.0.0.0.0)
	return b;
}//(13.0.0.0.0.0)
bool wenstraverse(maze& cc, int x, int y, char c, const int width, const int height,int& endc,const int pastmin,bool& badsit,int& reccount)
{//(14.0.0.0.0.0)
	//this will prevent a rare event that the shortest path wont be found
	int nadj=0;
	if(x!=width-1&&cc[x+1][y]!='.'&&cc[x+1][y]!='*'&&cc[x+1][y]!=',')
		nadj++;
	if(y!=height-1&&cc[x][y+1]!='.'&&cc[x][y+1]!='*'&&cc[x][y+1]!=',')
		nadj++;
	if(y!=0&&cc[x][y-1]!='.'&&cc[x][y-1]!='*'&&cc[x][y-1]!=',')
		nadj++;
	if(x!=0&&cc[x-1][y]!='.'&&cc[x-1][y]!='*'&&cc[x-1][y]!=',')
		nadj++;
	if(nadj>1)
		return false;
	if(reccount==0&&(cc[0][0]=='*'||cc[width-1][height-1]=='*'))////if the start and end are walls them selves are found to be walls method returns false and ends recursion
		return false;
	reccount++;//keeps track of the amount of time there has been a recursive call
	if(reccount>100)//takes care of a time issue i am able to do this because there must be another function that will find the path within a proper time
	{//(14.1.0.0.0.0)
		badsit=true;//allows for the swift exit of the stack of recursion
		return false;
	}//(14.1.0.0.0.0)
	endc++;//keeps track of path length
	if(endc>pastmin)//checks to see if the current path length is greater then current min
	{//(14.2.0.0.0.0)
		endc--;//if endc>pastmin this square is treated as if path is blocked
		return false;
	}//(14.2.0.0.0.0)
	if(c>'z')//loops char value
		c='a';
	bool b=false;//bool that reprasents if the end was reached
	cc[x][y]=c;//marks trail by alphabet
	if((x+1)==width&&(y+1)==height)//checks to see if at end
	{//(14.3.0.0.0.0)
		return true;//returns true to signify the maze has been finished
	}//(14.3.0.0.0.0)
	if(!badsit&&!b&&(x-1)>=0&&cc[x-1][y]=='.')//checks west
	{//(14.4.0.0.0.0)
		b= wenstraverse(cc,x-1,y,c+1,width,height,endc,pastmin,badsit,reccount);//goes west
	}//(14.4.0.0.0.0)
	if(!badsit&&!b&&(x+1)<width&&cc[x+1][y]=='.')//checks east
	{//(14.5.0.0.0.0)
		b= wenstraverse(cc,x+1,y,c+1,width,height,endc,pastmin,badsit,reccount);//goes east
	}//(14.5.0.0.0.0)
	if(!badsit&&!b&&(y-1)>=0&&cc[x][y-1]=='.')//checks north
	{//(14.6.0.0.0.0)
		b= wenstraverse(cc,x,y-1,c+1,width,height,endc,pastmin,badsit,reccount);//goes north
	}//(14.6.0.0.0.0)
	if(!badsit&&!b&&(y+1)<height&&cc[x][y+1]=='.')// checks south
	{//(14.7.0.0.0.0)
		b= wenstraverse(cc,x,y+1,c+1,width,height,endc,pastmin,badsit,reccount);//goes south a block
	}//(14.7.0.0.0.0)
	if(!b)//if path is blocked unmarks path and decrements path length
	{//(14.8.0.0.0.0)
		endc--;
		cc[x][y]='.';
	}//(14.8.0.0.0.0)
	return b;
}//(14.0.0.0.0.0)
bool wesntraverse(maze& cc, int x, int y, char c, const int width, const int height,int& endc,const int pastmin,bool& badsit,int& reccount)
{//(15.0.0.0.0.0)
	//this will prevent a rare event that the shortest path wont be found
	int nadj=0;
	if(x!=width-1&&cc[x+1][y]!='.'&&cc[x+1][y]!='*'&&cc[x+1][y]!=',')
		nadj++;
	if(y!=height-1&&cc[x][y+1]!='.'&&cc[x][y+1]!='*'&&cc[x][y+1]!=',')
		nadj++;
	if(y!=0&&cc[x][y-1]!='.'&&cc[x][y-1]!='*'&&cc[x][y-1]!=',')
		nadj++;
	if(x!=0&&cc[x-1][y]!='.'&&cc[x-1][y]!='*'&&cc[x-1][y]!=',')
		nadj++;
	if(nadj>1)
		return false;
	if(reccount==0&&(cc[0][0]=='*'||cc[width-1][height-1]=='*'))////if the start and end are walls them selves are found to be walls method returns false and ends recursion
		return false;
	reccount++;//keeps track of the amount of time there has been a recursive call
	if(reccount>100)//takes care of a time issue i am able to do this because there must be another function that will find the path within a proper time
	{//(15.1.0.0.0.0)
		badsit=true;//allows for the swift exit of the stack of recursion
		return false;
	}//(15.1.0.0.0.0)
	endc++;//keeps track of path length
	if(endc>pastmin)//checks to see if the current path length is greater then current min
	{//(15.2.0.0.0.0)
		endc--;//if endc>pastmin this square is treated as if path is blocked
		return false;
	}//(15.2.0.0.0.0)
	if(c>'z')//loops char value
		c='a';
	bool b=false;//bool that reprasents if the end was reached
	cc[x][y]=c;//marks trail by alphabet
	if((x+1)==width&&(y+1)==height)//checks to see if at end
	{//(15.3.0.0.0.0)
		return true;//returns true to signify the maze has been finished
	}//(15.3.0.0.0.0)
	if(!badsit&&!b&&(x-1)>=0&&cc[x-1][y]=='.')//checks west
	{//(15.4.0.0.0.0)
		b=wesntraverse(cc,x-1,y,c+1,width,height,endc,pastmin,badsit,reccount);//goes west
	}//(15.4.0.0.0.0)
	if(!badsit&&!b&&(x+1)<width&&cc[x+1][y]=='.')//checks east
	{//(15.5.0.0.0.0)
		b=wesntraverse(cc,x+1,y,c+1,width,height,endc,pastmin,badsit,reccount);//goes east
	}//(15.5.0.0.0.0)
	if(!badsit&&!b&&(y+1)<height&&cc[x][y+1]=='.')// checks south
	{//(15.6.0.0.0.0)
		b=wesntraverse(cc,x,y+1,c+1,width,height,endc,pastmin,badsit,reccount);//goes south a block
	}//(15.6.0.0.0.0)
	if(!badsit&&!b&&(y-1)>=0&&cc[x][y-1]=='.')//checks north
	{//(15.7.0.0.0.0)
		b=wesntraverse(cc,x,y-1,c+1,width,height,endc,pastmin,badsit,reccount);//goes north
	}//(15.7.0.0.0.0)
	if(!b)//if path is blocked unmarks path and decrements path length
	{//(15.8.0.0.0.0)
		endc--;
		cc[x][y]='.';
	}//(15.8.0.0.0.0)
	return b;
}//(15.0.0.0.0.0)
bool ewsntraverse(maze& cc, int x, int y, char c, const int width, const int height,int& endc,const int pastmin,bool& badsit,int& reccount)
{//(16.0.0.0.0.0)
	//this will prevent a rare event that the shortest path wont be found
	int nadj=0;
	if(x!=width-1&&cc[x+1][y]!='.'&&cc[x+1][y]!='*'&&cc[x+1][y]!=',')
		nadj++;
	if(y!=height-1&&cc[x][y+1]!='.'&&cc[x][y+1]!='*'&&cc[x][y+1]!=',')
		nadj++;
	if(y!=0&&cc[x][y-1]!='.'&&cc[x][y-1]!='*'&&cc[x][y-1]!=',')
		nadj++;
	if(x!=0&&cc[x-1][y]!='.'&&cc[x-1][y]!='*'&&cc[x-1][y]!=',')
		nadj++;
	if(nadj>1)
		return false;
	if(reccount==0&&(cc[0][0]=='*'||cc[width-1][height-1]=='*'))////if the start and/or end themselves are found to be walls method returns false and no recursion is done
		return false;
	reccount++;//keeps track of the amount of time there has been a recursive call
	if(reccount>100)//takes care of a time issue i am able to do this because there must be another function that will find the path within a proper time
	{//(16.1.0.0.0.0)
		badsit=true;//allows for the swift exit of the stack of recursion
		return false;
	}//(16.1.0.0.0.0)
	endc++;//keeps track of path length
	if(endc>pastmin)//checks to see if the current path length is greater then current min
	{//(16.2.0.0.0.0)
		endc--;//if endc>pastmin this square is treated as if path is blocked
		return false;
	}//(16.2.0.0.0.0)
	if(c>'z')//loops char value
		c='a';
	bool b=false;//bool that reprasents if the end was reached
	cc[x][y]=c;//marks trail by alphabet
	if((x+1)==width&&(y+1)==height)//checks to see if at end
	{//(16.3.0.0.0.0)
		return true;//returns true to signify the maze has been finished
	}//(16.3.0.0.0.0)
	if(!badsit&&!b&&(x+1)<width&&cc[x+1][y]=='.')//checks east
	{//(16.4.0.0.0.0)
		b=ewsntraverse(cc,x+1,y,c+1,width,height,endc,pastmin,badsit,reccount);//goes east
	}//(16.4.0.0.0.0)
	
	if(!badsit&&!b&&(x-1)>=0&&cc[x-1][y]=='.')//checks west
	{//(16.5.0.0.0.0)
		b=ewsntraverse(cc,x-1,y,c+1,width,height,endc,pastmin,badsit,reccount);//goes west
	}//(16.5.0.0.0.0)
	
	if(!badsit&&!b&&(y+1)<height&&cc[x][y+1]=='.')// checks south
	{//(16.6.0.0.0.0)
		b=ewsntraverse(cc,x,y+1,c+1,width,height,endc,pastmin,badsit,reccount);//goes south a block
	}//(16.6.0.0.0.0)
	if(!badsit&&!b&&(y-1)>=0&&cc[x][y-1]=='.')//checks north
	{//(16.7.0.0.0.0)
		b=ewsntraverse(cc,x,y-1,c+1,width,height,endc,pastmin,badsit,reccount);//goes north
	}//(16.7.0.0.0.0)
	if(!b)//if path is blocked unmarks path and decrements path length
	{//(16.8.0.0.0.0)
		endc--;
		cc[x][y]='.';
	}//(16.8.0.0.0.0)
	return b;
}//(16.0.0.0.0.0)
bool ewnstraverse(maze& cc, int x, int y, char c, const int width, const int height,int& endc,const int pastmin,bool& badsit,int& reccount)
{//(17.0.0.0.0.0)
	//this will prevent a rare event that the shortest path wont be found
	int nadj=0;
	if(x!=width-1&&cc[x+1][y]!='.'&&cc[x+1][y]!='*'&&cc[x+1][y]!=',')
		nadj++;
	if(y!=height-1&&cc[x][y+1]!='.'&&cc[x][y+1]!='*'&&cc[x][y+1]!=',')
		nadj++;
	if(y!=0&&cc[x][y-1]!='.'&&cc[x][y-1]!='*'&&cc[x][y-1]!=',')
		nadj++;
	if(x!=0&&cc[x-1][y]!='.'&&cc[x-1][y]!='*'&&cc[x-1][y]!=',')
		nadj++;
	if(nadj>1)
		return false;
	if(reccount==0&&(cc[0][0]=='*'||cc[width-1][height-1]=='*'))////if the start and end are walls them selves are found to be walls method returns false and ends recursion
		return false;
	reccount++;//keeps track of the amount of time there has been a recursive call
	if(reccount>100)//takes care of a time issue i am able to do this because there must be another function that will find the path within a proper time
	{//(17.1.0.0.0.0)
		badsit=true;//allows for the swift exit of the stack of recursion
		return false;
	}//(17.1.0.0.0.0)
	endc++;//keeps track of path length
	if(endc>pastmin)//checks to see if the current path length is greater then current min
	{//(17.2.0.0.0.0)
		endc--;//if endc>pastmin this square is treated as if path is blocked
		return false;
	}//(17.2.0.0.0.0)
	if(c>'z')//loops char value
		c='a';
	bool b=false;//bool that reprasents if the end was reached
	cc[x][y]=c;//marks trail by alphabet
	if((x+1)==width&&(y+1)==height)//checks to see if at end
	{//(17.3.0.0.0.0)
		return true;//returns true to signify the maze has been finished
	}//(17.3.0.0.0.0)
	if(!badsit&&!b&&(x+1)<width&&cc[x+1][y]=='.')//checks east
	{//(17.4.0.0.0.0)
		b=ewnstraverse(cc,x+1,y,c+1,width,height,endc,pastmin,badsit,reccount);//goes east
	}//(17.4.0.0.0.0)
	if(!badsit&&!b&&(x-1)>=0&&cc[x-1][y]=='.')//checks west
	{//(17.5.0.0.0.0)
		b=ewnstraverse(cc,x-1,y,c+1,width,height,endc,pastmin,badsit,reccount);//goes west
	}//(17.5.0.0.0.0)
	if(!badsit&&!b&&(y-1)>=0&&cc[x][y-1]=='.')//checks north
	{//(17.6.0.0.0.0)
		b=ewnstraverse(cc,x,y-1,c+1,width,height,endc,pastmin,badsit,reccount);//goes north
	}//(17.6.0.0.0.0)
	if(!badsit&&!b&&(y+1)<height&&cc[x][y+1]=='.')// checks south
	{//(17.7.0.0.0.0)
		b=ewnstraverse(cc,x,y+1,c+1,width,height,endc,pastmin,badsit,reccount);//goes south a block
	}//(17.7.0.0.0.0)
	if(!b)//if path is blocked unmarks path and decrements path length
	{//(17.8.0.0.0.0)
		endc--;
		cc[x][y]='.';
	}//(17.8.0.0.0.0)
	return b;
}//(17.0.0.0.0.0)
bool enwstraverse(maze& cc, int x, int y, char c, const int width, const int height,int& endc,const int pastmin,bool& badsit,int& reccount)
{//(18.0.0.0.0.0)
	//this will prevent a rare event that the shortest path wont be found
	int nadj=0;
	if(x!=width-1&&cc[x+1][y]!='.'&&cc[x+1][y]!='*'&&cc[x+1][y]!=',')
		nadj++;
	if(y!=height-1&&cc[x][y+1]!='.'&&cc[x][y+1]!='*'&&cc[x][y+1]!=',')
		nadj++;
	if(y!=0&&cc[x][y-1]!='.'&&cc[x][y-1]!='*'&&cc[x][y-1]!=',')
		nadj++;
	if(x!=0&&cc[x-1][y]!='.'&&cc[x-1][y]!='*'&&cc[x-1][y]!=',')
		nadj++;
	if(nadj>1)
		return false;
	if(reccount==0&&(cc[0][0]=='*'||cc[width-1][height-1]=='*'))////if the start and end are walls them selves are found to be walls method returns false and ends recursion
		return false;
	reccount++;//keeps track of the amount of time there has been a recursive call
	if(reccount>100)//takes care of a time issue i am able to do this because there must be another function that will find the path within a proper time
	{//(18.1.0.0.0.0)
		badsit=true;//allows for the swift exit of the stack of recursion
		return false;
	}//(18.1.0.0.0.0)
	endc++;//keeps track of path length
	if(endc>pastmin)//checks to see if the current path length is greater then current min
	{//(18.2.0.0.0.0)
		endc--;//if endc>pastmin this square is treated as if path is blocked
		return false;
	}//(18.2.0.0.0.0)
	if(c>'z')//loops char value
		c='a';
	bool b=false;//bool that reprasents if the end was reached
	cc[x][y]=c;//marks trail by alphabet
	if((x+1)==width&&(y+1)==height)//checks to see if at end
	{//(18.3.0.0.0.0)
		return true;//returns true to signify the maze has been finished
	}//(18.3.0.0.0.0)
	if(!badsit&&!b&&(x+1)<width&&cc[x+1][y]=='.')//checks east
	{//(18.4.0.0.0.0)
		b=enwstraverse(cc,x+1,y,c+1,width,height,endc,pastmin,badsit,reccount);//goes east
	}//(18.4.0.0.0.0)
	if(!badsit&&!b&&(y-1)>=0&&cc[x][y-1]=='.')//checks north
	{//(18.5.0.0.0.0)
		b=enwstraverse(cc,x,y-1,c+1,width,height,endc,pastmin,badsit,reccount);//goes north
	}//(18.5.0.0.0.0)
	if(!badsit&&!b&&(x-1)>=0&&cc[x-1][y]=='.')//checks west
	{//(18.6.0.0.0.0)
		b=enwstraverse(cc,x-1,y,c+1,width,height,endc,pastmin,badsit,reccount);//goes west
	}//(18.6.0.0.0.0)
	if(!badsit&&!b&&(y+1)<height&&cc[x][y+1]=='.')// checks south
	{//(18.7.0.0.0.0)
		b=enwstraverse(cc,x,y+1,c+1,width,height,endc,pastmin,badsit,reccount);//goes south a block
	}//(18.7.0.0.0.0)
	if(!b)//if path is blocked unmarks path and decrements path length
	{//(18.8.0.0.0.0)
		endc--;
		cc[x][y]='.';
	}//(18.8.0.0.0.0)
	return b;
}//(18.0.0.0.0.0)
bool enswtraverse(maze& cc, int x, int y, char c, const int width, const int height,int& endc,const int pastmin,bool& badsit,int& reccount)
{//(19.0.0.0.0.0)
	//this will prevent a rare event that the shortest path wont be found
	int nadj=0;
	if(x!=width-1&&cc[x+1][y]!='.'&&cc[x+1][y]!='*'&&cc[x+1][y]!=',')
		nadj++;
	if(y!=height-1&&cc[x][y+1]!='.'&&cc[x][y+1]!='*'&&cc[x][y+1]!=',')
		nadj++;
	if(y!=0&&cc[x][y-1]!='.'&&cc[x][y-1]!='*'&&cc[x][y-1]!=',')
		nadj++;
	if(x!=0&&cc[x-1][y]!='.'&&cc[x-1][y]!='*'&&cc[x-1][y]!=',')
		nadj++;
	if(nadj>1)
		return false;
	if(reccount==0&&(cc[0][0]=='*'||cc[width-1][height-1]=='*'))////if the start and end are walls them selves are found to be walls method returns false and ends recursion
		return false;
	reccount++;//keeps track of the amount of time there has been a recursive call
	if(reccount>100)//takes care of a time issue i am able to do this because there must be another function that will find the path within a proper time
	{//(19.1.0.0.0.0)
		badsit=true;//allows for the swift exit of the stack of recursion
		return false;
	}//(19.1.0.0.0.0)
	endc++;//keeps track of path length
	if(endc>pastmin)//checks to see if the current path length is greater then current min
	{//(19.2.0.0.0.0)
		endc--;//if endc>pastmin this square is treated as if path is blocked
		return false;
	}//(19.2.0.0.0.0)
	if(c>'z')//loops char value
		c='a';
	bool b=false;//bool that reprasents if the end was reached
	cc[x][y]=c;//marks trail by alphabet
	if((x+1)==width&&(y+1)==height)//checks to see if at end
	{//(19.3.0.0.0.0)
		return true;//returns true to signify the maze has been finished
	}//(19.3.0.0.0.0)
	if(!badsit&&!b&&(x+1)<width&&cc[x+1][y]=='.')//checks east
	{//(19.4.0.0.0.0)
		b=enswtraverse(cc,x+1,y,c+1,width,height,endc,pastmin,badsit,reccount);//goes east
	}//(19.4.0.0.0.0)
	if(!badsit&&!b&&(y-1)>=0&&cc[x][y-1]=='.')//checks north
	{//(19.5.0.0.0.0)
		b=enswtraverse(cc,x,y-1,c+1,width,height,endc,pastmin,badsit,reccount);//goes north
	}//(19.5.0.0.0.0)
	if(!badsit&&!b&&(y+1)<height&&cc[x][y+1]=='.')// checks south
	{//(19.6.0.0.0.0)
		b=enswtraverse(cc,x,y+1,c+1,width,height,endc,pastmin,badsit,reccount);//goes south a block
	}//(19.6.0.0.0.0)
	if(!badsit&&!b&&(x-1)>=0&&cc[x-1][y]=='.')//checks west
	{//(19.7.0.0.0.0)
		b=enswtraverse(cc,x-1,y,c+1,width,height,endc,pastmin,badsit,reccount);//goes west
	}//(19.7.0.0.0.0)
	if(!b)//if path is blocked unmarks path and decrements path length
	{//(19.8.0.0.0.0)
		endc--;
		cc[x][y]='.';
	}//(19.8.0.0.0.0)
	return b;
}//(19.0.0.0.0.0)
bool esnwtraverse(maze& cc, int x, int y, char c, const int width, const int height,int& endc,const int pastmin,bool& badsit,int& reccount)
{//(20.0.0.0.0.0)
	//this will prevent a rare event that the shortest path wont be found
	int nadj=0;
	if(x!=width-1&&cc[x+1][y]!='.'&&cc[x+1][y]!='*'&&cc[x+1][y]!=',')
		nadj++;
	if(y!=height-1&&cc[x][y+1]!='.'&&cc[x][y+1]!='*'&&cc[x][y+1]!=',')
		nadj++;
	if(y!=0&&cc[x][y-1]!='.'&&cc[x][y-1]!='*'&&cc[x][y-1]!=',')
		nadj++;
	if(x!=0&&cc[x-1][y]!='.'&&cc[x-1][y]!='*'&&cc[x-1][y]!=',')
		nadj++;
	if(nadj>1)
		return false;
	if(reccount==0&&(cc[0][0]=='*'||cc[width-1][height-1]=='*'))////if the start and end are walls them selves are found to be walls method returns false and ends recursion
		return false;
	reccount++;//keeps track of the amount of time there has been a recursive call
	if(reccount>100)//takes care of a time issue i am able to do this because there must be another function that will find the path within a proper time
	{//(20.1.0.0.0.0)
		badsit=true;//allows for the swift exit of the stack of recursion
		return false;
	}//(20.1.0.0.0.0)
	endc++;//keeps track of path length
	if(endc>pastmin)//checks to see if the current path length is greater then current min
	{//(20.2.0.0.0.0)
		endc--;//if endc>pastmin this square is treated as if path is blocked
		return false;
	}//(20.2.0.0.0.0)
	if(c>'z')//loops char value
		c='a';
	bool b=false;//bool that reprasents if the end was reached
	cc[x][y]=c;//marks trail by alphabet
	if((x+1)==width&&(y+1)==height)//checks to see if at end
	{//(20.3.0.0.0.0)
		return true;//returns true to signify the maze has been finished
	}//(20.3.0.0.0.0)
	if(!badsit&&!b&&(x+1)<width&&cc[x+1][y]=='.')//checks east
	{//(20.4.0.0.0.0)
		b=esnwtraverse(cc,x+1,y,c+1,width,height,endc,pastmin,badsit,reccount);//goes east
	}//(20.4.0.0.0.0)
	if(!badsit&&!b&&(y+1)<height&&cc[x][y+1]=='.')// checks south
	{//(20.5.0.0.0.0)
		b=esnwtraverse(cc,x,y+1,c+1,width,height,endc,pastmin,badsit,reccount);//goes south a block
	}//(20.5.0.0.0.0)
	if(!badsit&&!b&&(y-1)>=0&&cc[x][y-1]=='.')//checks north
	{//(20.6.0.0.0.0)
		b=esnwtraverse(cc,x,y-1,c+1,width,height,endc,pastmin,badsit,reccount);//goes north
	}//(20.6.0.0.0.0)
	if(!badsit&&!b&&(x-1)>=0&&cc[x-1][y]=='.')//checks west
	{//(20.7.0.0.0.0)
		b=esnwtraverse(cc,x-1,y,c+1,width,height,endc,pastmin,badsit,reccount);//goes west
	}//(20.7.0.0.0.0)
	if(!b)//if path is blocked unmarks path and decrements path length
	{//(20.8.0.0.0.0)
		endc--;
		cc[x][y]='.';
	}//(20.8.0.0.0.0)
	return b;
}//(20.0.0.0.0.0)
bool eswntraverse(maze& cc, int x, int y, char c, const int width, const int height,int& endc,const int pastmin,bool& badsit,int& reccount)
{//(21.0.0.0.0.0)
	//this will prevent a rare event that the shortest path wont be found
	int nadj=0;
	if(x!=width-1&&cc[x+1][y]!='.'&&cc[x+1][y]!='*'&&cc[x+1][y]!=',')
		nadj++;
	if(y!=height-1&&cc[x][y+1]!='.'&&cc[x][y+1]!='*'&&cc[x][y+1]!=',')
		nadj++;
	if(y!=0&&cc[x][y-1]!='.'&&cc[x][y-1]!='*'&&cc[x][y-1]!=',')
		nadj++;
	if(x!=0&&cc[x-1][y]!='.'&&cc[x-1][y]!='*'&&cc[x-1][y]!=',')
		nadj++;
	if(nadj>1)
		return false;
	if(reccount==0&&(cc[0][0]=='*'||cc[width-1][height-1]=='*'))////if the start and end are walls them selves are found to be walls method returns false and ends recursion
		return false;
	reccount++;//keeps track of the amount of time there has been a recursive call
	if(reccount>100)//takes care of a time issue i am able to do this because there must be another function that will find the path within a proper time
	{//(21.1.0.0.0.0)
		badsit=true;//allows for the swift exit of the stack of recursion
		return false;
	}//(21.1.0.0.0.0)
	endc++;//keeps track of path length
	if(endc>pastmin)//checks to see if the current path length is greater then current min
	{//(21.2.0.0.0.0)
		endc--;//if endc>pastmin this square is treated as if path is blocked
		return false;
	}//(21.2.0.0.0.0)
	if(c>'z')//loops char value
		c='a';
	bool b=false;//bool that reprasents if the end was reached
	cc[x][y]=c;//marks trail by alphabet
	if((x+1)==width&&(y+1)==height)//checks to see if at end
	{//(21.3.0.0.0.0)
		return true;//returns true to signify the maze has been finished
	}//(21.3.0.0.0.0)
	if(!badsit&&!b&&(x+1)<width&&cc[x+1][y]=='.')//if maze is still unfinished checks east for path
	{//(21.4.0.0.0.0)
		b=eswntraverse(cc,x+1,y,c+1,width,height,endc,pastmin,badsit,reccount);//goes east
	}//(21.4.0.0.0.0)
	if(!badsit&&!b&&(y+1)<height&&cc[x][y+1]=='.')//if maze still unfinished checks south for path
	{//(21.5.0.0.0.0)
		b=eswntraverse(cc,x,y+1,c+1,width,height,endc,pastmin,badsit,reccount);//goes south a block
	}//(21.5.0.0.0.0)
	if(!badsit&&!b&&(x-1)>=0&&cc[x-1][y]=='.')//checks west
	{//(21.6.0.0.0.0)
		b=eswntraverse(cc,x-1,y,c+1,width,height,endc,pastmin,badsit,reccount);//goes west
	}//(21.6.0.0.0.0)
	if(!badsit&&!b&&(y-1)>=0&&cc[x][y-1]=='.')//checks north
	{//(21.7.0.0.0.0)
		b=eswntraverse(cc,x,y-1,c+1,width,height,endc,pastmin,badsit,reccount);//goes north
	}//(21.7.0.0.0.0)
	if(!b)//if path is blocked unmarks path and decrements path length
	{//(21.8.0.0.0.0)
		endc--;
		cc[x][y]='.';
	}//(21.8.0.0.0.0)
	return b;
}//(21.0.0.0.0.0)
bool neswtraverse(maze& cc, int x, int y, char c, const int width, const int height,int& endc,const int pastmin,bool& badsit,int& reccount)
{//(22.0.0.0.0.0)
	//this will prevent a rare event that the shortest path wont be found
	int nadj=0;
	if(x!=width-1&&cc[x+1][y]!='.'&&cc[x+1][y]!='*'&&cc[x+1][y]!=',')
		nadj++;
	if(y!=height-1&&cc[x][y+1]!='.'&&cc[x][y+1]!='*'&&cc[x][y+1]!=',')
		nadj++;
	if(y!=0&&cc[x][y-1]!='.'&&cc[x][y-1]!='*'&&cc[x][y-1]!=',')
		nadj++;
	if(x!=0&&cc[x-1][y]!='.'&&cc[x-1][y]!='*'&&cc[x-1][y]!=',')
		nadj++;
	if(nadj>1)
		return false;
	if(reccount==0&&(cc[0][0]=='*'||cc[width-1][height-1]=='*'))////if the start and end are walls them selves are found to be walls method returns false and ends recursion
		return false;
	reccount++;//keeps track of the amount of time there has been a recursive call
	if(reccount>100)//takes care of a time issue i am able to do this because there must be another function that will find the path within a proper time
	{//(22.1.0.0.0.0)
		badsit=true;//allows for the swift exit of the stack of recursion
		return false;
	}//(22.1.0.0.0.0)
	endc++;//keeps track of path length
	if(endc>pastmin)//checks to see if the current path length is greater then current min
	{//(22.2.0.0.0.0)
		endc--;//if endc>pastmin this square is treated as if path is blocked
		return false;
	}//(22.2.0.0.0.0)
	if(c>'z')//loops char value
		c='a';
	bool b=false;//bool that reprasents if the end was reached
	cc[x][y]=c;//marks trail by alphabet
	if((x+1)==width&&(y+1)==height)//checks to see if at end
	{//(22.3.0.0.0.0)
		return true;//returns true to signify the maze has been finished
	}//(22.3.0.0.0.0)
	if(!badsit&&!b&&(y-1)>=0&&cc[x][y-1]=='.')//checks north
	{//(22.4.0.0.0.0)
		b=neswtraverse(cc,x,y-1,c+1,width,height,endc,pastmin,badsit,reccount);//goes north
	}//(22.4.0.0.0.0)
	if(!badsit&&!b&&(x+1)<width&&cc[x+1][y]=='.')//checks east
	{//(22.5.0.0.0.0)
		b=neswtraverse(cc,x+1,y,c+1,width,height,endc,pastmin,badsit,reccount);//goes east
	}//(22.5.0.0.0.0)
	if(!badsit&&!b&&(y+1)<height&&cc[x][y+1]=='.')//checks south
	{//(22.6.0.0.0.0)
		b=neswtraverse(cc,x,y+1,c+1,width,height,endc,pastmin,badsit,reccount);//goes south a block
	}//(22.6.0.0.0.0)
	if(!badsit&&!b&&(x-1)>=0&&cc[x-1][y]=='.')//checks west
	{//(22.7.0.0.0.0)
		b=neswtraverse(cc,x-1,y,c+1,width,height,endc,pastmin,badsit,reccount);//goes west
	}//(22.7.0.0.0.0)
	if(!b)//if path is blocked unmarks path and decrements path length
	{//(22.8.0.0.0.0)
		endc--;
		cc[x][y]='.';
	}//(22.8.0.0.0.0)
	return b;
}//(22.0.0.0.0.0)
bool newstraverse(maze& cc, int x, int y, char c, const int width, const int height,int& endc,const int pastmin,bool& badsit,int& reccount)
{//(23.0.0.0.0.0)
	//this will prevent a rare event that the shortest path wont be found
	int nadj=0;
	if(x!=width-1&&cc[x+1][y]!='.'&&cc[x+1][y]!='*'&&cc[x+1][y]!=',')
		nadj++;
	if(y!=height-1&&cc[x][y+1]!='.'&&cc[x][y+1]!='*'&&cc[x][y+1]!=',')
		nadj++;
	if(y!=0&&cc[x][y-1]!='.'&&cc[x][y-1]!='*'&&cc[x][y-1]!=',')
		nadj++;
	if(x!=0&&cc[x-1][y]!='.'&&cc[x-1][y]!='*'&&cc[x-1][y]!=',')
		nadj++;
	if(nadj>1)
		return false;
	if(reccount==0&&(cc[0][0]=='*'||cc[width-1][height-1]=='*'))//if the start and end are walls them selves are found to be walls method returns false and ends recursion
		return false;
	reccount++;//keeps track of the amount of time there has been a recursive call
	if(reccount>100)//takes care of a time issue i am able to do this because there must be another function that will find the path within a proper time
	{//(23.1.0.0.0.0)
		badsit=true;//allows for the swift exit of the stack of recursion
		return false;
	}//(23.1.0.0.0.0)
	endc++;//keeps track of path length
	if(endc>pastmin)//checks to see if the current path length is greater then current min
	{//(23.2.0.0.0.0)
		endc--;//if endc>pastmin this square is treated as if path is blocked
		return false;
	}//(23.2.0.0.0.0)
	if(c>'z')//loops char value
		c='a';
	bool b=false;//bool that reprasents if the end was reached
	cc[x][y]=c;//marks trail by alphabet
	if((x+1)==width&&(y+1)==height)//checks to see if at end
	{//(23.3.0.0.0.0)
		return true;//returns true to signify the maze has been finished
	}//(23.3.0.0.0.0)
	if(!badsit&&!b&&(y-1)>=0&&cc[x][y-1]=='.')//checks north
	{//(23.4.0.0.0.0)
		b=newstraverse(cc,x,y-1,c+1,width,height,endc,pastmin,badsit,reccount);//goes north
	}//(23.4.0.0.0.0)
	if(!badsit&&!b&&(x+1)<width&&cc[x+1][y]=='.')//checks east
	{//(23.5.0.0.0.0)
		b=newstraverse(cc,x+1,y,c+1,width,height,endc,pastmin,badsit,reccount);//goes east
	}//(23.5.0.0.0.0)
	if(!badsit&&!b&&(x-1)>=0&&cc[x-1][y]=='.')//checks west
	{//(23.6.0.0.0.0)
		b=newstraverse(cc,x-1,y,c+1,width,height,endc,pastmin,badsit,reccount);//goes west
	}//(23.6.0.0.0.0)
	if(!badsit&&!b&&(y+1)<height&&cc[x][y+1]=='.')//checks south
	{//(23.7.0.0.0.0)
		b=newstraverse(cc,x,y+1,c+1,width,height,endc,pastmin,badsit,reccount);//goes south a block
	}//(23.7.0.0.0.0)
	if(!b)//if path is blocked unmarks path and decrements path length
	{//(23.8.0.0.0.0)
		endc--;
		cc[x][y]='.';
	}//(23.8.0.0.0.0)
	return b;
}//(23.0.0.0.0.0)
bool nwestraverse(maze& cc, int x, int y, char c, const int width, const int height,int& endc,const int pastmin,bool& badsit,int& reccount)
{//(24.0.0.0.0.0)
	//this will prevent a rare event that the shortest path wont be found
	int nadj=0;
	if(x!=width-1&&cc[x+1][y]!='.'&&cc[x+1][y]!='*'&&cc[x+1][y]!=',')
		nadj++;
	if(y!=height-1&&cc[x][y+1]!='.'&&cc[x][y+1]!='*'&&cc[x][y+1]!=',')
		nadj++;
	if(y!=0&&cc[x][y-1]!='.'&&cc[x][y-1]!='*'&&cc[x][y-1]!=',')
		nadj++;
	if(x!=0&&cc[x-1][y]!='.'&&cc[x-1][y]!='*'&&cc[x-1][y]!=',')
		nadj++;
	if(nadj>1)
		return false;
	if(reccount==0&&(cc[0][0]=='*'||cc[width-1][height-1]=='*'))////if the start and end are walls them selves are found to be walls method returns false and ends recursion
		return false;
	reccount++;//keeps track of the amount of time there has been a recursive call
	if(reccount>100)//takes care of a time issue i am able to do this because there must be another function that will find the path within a proper time
	{//(24.1.0.0.0.0)
		badsit=true;//allows for the swift exit of the stack of recursion
		return false;
	}//(24.1.0.0.0.0)
	endc++;//keeps track of path length
	if(endc>pastmin)//checks to see if the current path length is greater then current min
	{//(24.2.0.0.0.0)
		endc--;//if endc>pastmin this square is treated as if path is blocked
		return false;
	}//(24.2.0.0.0.0)
	if(c>'z')//loops char value
		c='a';
	bool b=false;//bool that reprasents if the end was reached
	cc[x][y]=c;//marks trail by alphabet
	if((x+1)==width&&(y+1)==height)//checks to see if at end
	{//(24.3.0.0.0.0)
		return true;//returns true to signify the maze has been finished
	}//(24.3.0.0.0.0)
	if(!badsit&&!b&&(y-1)>=0&&cc[x][y-1]=='.')//checks north
	{//(24.4.0.0.0.0)
		b=nwestraverse(cc,x,y-1,c+1,width,height,endc,pastmin,badsit,reccount);//goes north
	}//(24.4.0.0.0.0)
	if(!badsit&&!b&&(x-1)>=0&&cc[x-1][y]=='.')//checks west
	{//(24.5.0.0.0.0)
		b=nwestraverse(cc,x-1,y,c+1,width,height,endc,pastmin,badsit,reccount);//goes west
	}//(24.5.0.0.0.0)
	if(!badsit&&!b&&(x+1)<width&&cc[x+1][y]=='.')//checks east
	{//(24.6.0.0.0.0)
		b=nwestraverse(cc,x+1,y,c+1,width,height,endc,pastmin,badsit,reccount);//goes east
	}//(24.6.0.0.0.0)
	if(!badsit&&!b&&(y+1)<height&&cc[x][y+1]=='.')//checks south
	{//(24.7.0.0.0.0)
		b=nwestraverse(cc,x,y+1,c+1,width,height,endc,pastmin,badsit,reccount);//goes south a block
	}//(24.7.0.0.0.0)
	if(!b)//if path is blocked unmarks path and decrements path length
	{//(24.8.0.0.0.0)
		endc--;
		cc[x][y]='.';
	}//(24.8.0.0.0.0)
	return b;
}//(24.0.0.0.0.0)
bool nwsetraverse(maze& cc, int x, int y, char c, const int width, const int height,int& endc,const int pastmin,bool& badsit,int& reccount)
{//(25.0.0.0.0.0)
	int nadj=0;
	if(x!=width-1&&cc[x+1][y]!='.'&&cc[x+1][y]!='*'&&cc[x+1][y]!=',')
		nadj++;
	if(y!=height-1&&cc[x][y+1]!='.'&&cc[x][y+1]!='*'&&cc[x][y+1]!=',')
		nadj++;
	if(y!=0&&cc[x][y-1]!='.'&&cc[x][y-1]!='*'&&cc[x][y-1]!=',')
		nadj++;
	if(x!=0&&cc[x-1][y]!='.'&&cc[x-1][y]!='*'&&cc[x-1][y]!=',')
		nadj++;
	if(nadj>1)
		return false;
	if(reccount==0&&(cc[0][0]=='*'||cc[width-1][height-1]=='*'))////if the start and end are walls them selves are found to be walls method returns false and ends recursion
		return false;
	reccount++;//keeps track of the amount of time there has been a recursive call
	if(reccount>100)//takes care of a time issue i am able to do this because there must be another function that will find the path within a proper time
	{//(25.1.0.0.0.0)
		badsit=true;//allows for the swift exit of the stack of recursion
		return false;
	}//(25.1.0.0.0.0)
	endc++;//keeps track of path length
	if(endc>pastmin)//checks to see if the current path length is greater then current min
	{//(25.2.0.0.0.0)
		endc--;//if endc>pastmin this square is treated as if path is blocked
		return false;
	}//(25.2.0.0.0.0)
	if(c>'z')//loops char value
		c='a';
	bool b=false;//bool that reprasents if the end was reached
	cc[x][y]=c;//marks trail by alphabet
	if((x+1)==width&&(y+1)==height)//checks to see if at end
	{//(25.3.0.0.0.0)
		return true;//returns true to signify the maze has been finished
	}//(25.3.0.0.0.0)
	if(!badsit&&!b&&(y-1)>=0&&cc[x][y-1]=='.')//checks north
	{//(25.4.0.0.0.0)
		b=nwsetraverse(cc,x,y-1,c+1,width,height,endc,pastmin,badsit,reccount);//goes north
	}//(25.4.0.0.0.0)
	if(!badsit&&!b&&(x-1)>=0&&cc[x-1][y]=='.')//checks west
	{//(25.5.0.0.0.0)
		b=nwsetraverse(cc,x-1,y,c+1,width,height,endc,pastmin,badsit,reccount);//goes west
	}//(25.5.0.0.0.0)
	if(!badsit&&!b&&(y+1)<height&&cc[x][y+1]=='.')//checks south
	{//(25.6.0.0.0.0)
		b=nwsetraverse(cc,x,y+1,c+1,width,height,endc,pastmin,badsit,reccount);//goes south a block
	}//(25.6.0.0.0.0)
	if(!badsit&&!b&&(x+1)<width&&cc[x+1][y]=='.')//checks east
	{//(25.7.0.0.0.0)
		b=nwsetraverse(cc,x+1,y,c+1,width,height,endc,pastmin,badsit,reccount);//goes east
	}//(25.7.0.0.0.0)
	if(!b)//if path is blocked unmarks path and decrements path length
	{//(25.8.0.0.0.0)
		endc--;
		cc[x][y]='.';
	}//(25.8.0.0.0.0)
	return b;
}//(25.0.0.0.0.0)
bool nswetraverse(maze& cc, int x, int y, char c, const int width, const int height,int& endc,const int pastmin,bool& badsit,int& reccount)
{//(26.0.0.0.0.0)
	//this will prevent a rare event that the shortest path wont be found
	int nadj=0;
	if(x!=width-1&&cc[x+1][y]!='.'&&cc[x+1][y]!='*'&&cc[x+1][y]!=',')
		nadj++;
	if(y!=height-1&&cc[x][y+1]!='.'&&cc[x][y+1]!='*'&&cc[x][y+1]!=',')
		nadj++;
	if(y!=0&&cc[x][y-1]!='.'&&cc[x][y-1]!='*'&&cc[x][y-1]!=',')
		nadj++;
	if(x!=0&&cc[x-1][y]!='.'&&cc[x-1][y]!='*'&&cc[x-1][y]!=',')
		nadj++;
	if(nadj>1)
		return false;
	if(reccount==0&&(cc[0][0]=='*'||cc[width-1][height-1]=='*'))////if the start and end are walls them selves are found to be walls method returns false and ends recursion
		return false;
	reccount++;//keeps track of the amount of time there has been a recursive call
	if(reccount>100)//takes care of a time issue i am able to do this because there must be another function that will find the path within a proper time
	{//(26.1.0.0.0.0)
		badsit=true;//allows for the swift exit of the stack of recursion
		return false;
	}//(26.1.0.0.0.0)
	endc++;//keeps track of path length
	if(endc>pastmin)//checks to see if the current path length is greater then current min
	{//(26.2.0.0.0.0)
		endc--;//if endc>pastmin this square is treated as if path is blocked
		return false;
	}//(26.2.0.0.0.0)
	if(c>'z')//loops char value
		c='a';
	bool b=false;//bool that reprasents if the end was reached
	cc[x][y]=c;//marks trail by alphabet
	if((x+1)==width&&(y+1)==height)//checks to see if at end
	{//(26.3.0.0.0.0)
		return true;//returns true to signify the maze has been finished
	}//(26.3.0.0.0.0)
	if(!badsit&&!b&&(y-1)>=0&&cc[x][y-1]=='.')//checks north
	{//(26.4.0.0.0.0)
		b=nswetraverse(cc,x,y-1,c+1,width,height,endc,pastmin,badsit,reccount);//goes north
	}//(26.4.0.0.0.0)
	if(!badsit&&!b&&(y+1)<height&&cc[x][y+1]=='.')//checks south
	{//(26.5.0.0.0.0)
		b=nswetraverse(cc,x,y+1,c+1,width,height,endc,pastmin,badsit,reccount);//goes south a block
	}//(26.5.0.0.0.0)
	if(!badsit&&!b&&(x-1)>=0&&cc[x-1][y]=='.')//checks west
	{//(26.6.0.0.0.0)
		b=nswetraverse(cc,x-1,y,c+1,width,height,endc,pastmin,badsit,reccount);//goes west
	}//(26.6.0.0.0.0)
	if(!badsit&&!b&&(x+1)<width&&cc[x+1][y]=='.')//checks east
	{//(26.7.0.0.0.0)
		b=nswetraverse(cc,x+1,y,c+1,width,height,endc,pastmin,badsit,reccount);//goes east
	}//(26.7.0.0.0.0)
	if(!b)//if path is blocked unmarks path and decrements path length
	{//(26.8.0.0.0.0)
		endc--;
		cc[x][y]='.';
	}//(26.8.0.0.0.0)
	return b;
}//(26.0.0.0.0.0)
bool nsewtraverse(maze& cc, int x, int y, char c, const int width, const int height,int& endc,const int pastmin,bool& badsit,int& reccount)
{//(27.0.0.0.0.0)
	//this will prevent a rare event that the shortest path wont be found
	int nadj=0;
	if(x!=width-1&&cc[x+1][y]!='.'&&cc[x+1][y]!='*'&&cc[x+1][y]!=',')
		nadj++;
	if(y!=height-1&&cc[x][y+1]!='.'&&cc[x][y+1]!='*'&&cc[x][y+1]!=',')
		nadj++;
	if(y!=0&&cc[x][y-1]!='.'&&cc[x][y-1]!='*'&&cc[x][y-1]!=',')
		nadj++;
	if(x!=0&&cc[x-1][y]!='.'&&cc[x-1][y]!='*'&&cc[x-1][y]!=',')
		nadj++;
	if(nadj>1)
		return false;
	if(reccount==0&&(cc[0][0]=='*'||cc[width-1][height-1]=='*'))////if the start and end are walls them selves are found to be walls method returns false and ends recursion
		return false;
	reccount++;//keeps track of the amount of time there has been a recursive call
	if(reccount>100)//takes care of a time issue i am able to do this because there must be another function that will find the path within a proper time
	{//(27.1.0.0.0.0)
		badsit=true;//allows for the swift exit of the stack of recursion
		return false;
	}//(27.1.0.0.0.0)
	endc++;//keeps track of path length
	if(endc>pastmin)//checks to see if the current path length is greater then current min
	{//(27.2.0.0.0.0)
		endc--;//if endc>pastmin this square is treated as if path is blocked
		return false;
	}//(27.2.0.0.0.0)
	if(c>'z')//loops char value
		c='a';
	bool b=false;//bool that reprasents if the end was reached
	cc[x][y]=c;//marks trail by alphabet
	if((x+1)==width&&(y+1)==height)//checks to see if at end
	{//(27.3.0.0.0.0)
		return true;//returns true to signify the maze has been finished
	}//(27.3.0.0.0.0)
	if(!badsit&&!b&&(y-1)>=0&&cc[x][y-1]=='.')//checks north
	{//(27.4.0.0.0.0)
		b=nsewtraverse(cc,x,y-1,c+1,width,height,endc,pastmin,badsit,reccount);//goes north
	}//(27.4.0.0.0.0)
	if(!badsit&&!b&&(y+1)<height&&cc[x][y+1]=='.')//checks south
	{//(27.5.0.0.0.0)
		b=nsewtraverse(cc,x,y+1,c+1,width,height,endc,pastmin,badsit,reccount);//goes south a block
	}//(27.5.0.0.0.0)
	if(!badsit&&!b&&(x+1)<width&&cc[x+1][y]=='.')//checks east
	{//(27.6.0.0.0.0)
		b=nsewtraverse(cc,x+1,y,c+1,width,height,endc,pastmin,badsit,reccount);//goes east
	}//(27.6.0.0.0.0)
	if(!badsit&&!b&&(x-1)>=0&&cc[x-1][y]=='.')//checks west
	{//(27.7.0.0.0.0)
		b=nsewtraverse(cc,x-1,y,c+1,width,height,endc,pastmin,badsit,reccount);//goes west
	}//(27.7.0.0.0.0)
	if(!b)//if path is blocked unmarks path and decrements path length
	{//(27.8.0.0.0.0)
		endc--;
		cc[x][y]='.';
	}//(27.8.0.0.0.0)
	return b;
}//(27.0.0.0.0.0)
//the following traverse the maze backwords this is a neccesary redundancy (only the first is needed atleast for all of the possiblities i know of a 10 by 10 maze can present however i will add seven more for precaution and should this program ever fail to find the fastest route it's an easy fix, just add another backwards traversal method)
bool bnewstraverse(maze& cc, int x, int y, int c, const int width, const int height, int& pathc,const int pastmin,bool& badsit,int& reccount)
{//(28.0.0.0.0.0)
	//this will prevent a rare event that the shortest path wont be found
	int nadj=0;
	if(x!=width-1&&cc[x+1][y]!='.'&&cc[x+1][y]!='*'&&cc[x+1][y]!=',')
		nadj++;
	if(y!=height-1&&cc[x][y+1]!='.'&&cc[x][y+1]!='*'&&cc[x][y+1]!=',')
		nadj++;
	if(y!=0&&cc[x][y-1]!='.'&&cc[x][y-1]!='*'&&cc[x][y-1]!=',')
		nadj++;
	if(x!=0&&cc[x-1][y]!='.'&&cc[x-1][y]!='*'&&cc[x-1][y]!=',')
		nadj++;
	if(nadj>1)
		return false;
	if(reccount==0&&(cc[0][0]=='*'||cc[width-1][height-1]=='*'))////if the start and end are walls them selves are found to be walls method returns false and ends recursion
		return false;
	reccount++;
	if(reccount>100)//takes care of a time issue i am able to do this because there must be another function that will find the path within a proper time
	{//(28.1.0.0.0.0)
		badsit=true;//allows for the swift exit of the stack of recursion
		return false;
	}//(28.1.0.0.0.0)
	bool b=false;
	if((x)==0&&(y)==0)
	{//(28.2.0.0.0.0)
		b= true;
	}//(28.2.0.0.0.0)
	pathc++;
	if(!b&&pathc>pastmin)
	{//(28.3.0.0.0.0)
		pathc--;
		return false;
	}//(28.3.0.0.0.0)
	cc[x][y]='x';
	if(!badsit&&!b&&(y-1)>=0&&cc[x][y-1]=='.')//checks north
	{//(28.4.0.0.0.0)
		b=bnewstraverse(cc,x,y-1,c+1,width,height,pathc,pastmin,badsit,reccount);//goes north
	}//(28.4.0.0.0.0)
	if(!badsit&&!b&&(x+1)<width&&cc[x+1][y]=='.')//checks east for path
	{//(28.5.0.0.0.0)
		b=bnewstraverse(cc,x+1,y,c+1,width,height,pathc,pastmin,badsit,reccount);//goes east
	}//(28.5.0.0.0.0)
	if(!badsit&&!b&&(x-1)>=0&&cc[x-1][y]=='.')//checks west
	{//(28.6.0.0.0.0)
		b=bnewstraverse(cc,x-1,y,c+1,width,height,pathc,pastmin,badsit,reccount);//goes west
	}//(28.6.0.0.0.0)
	if(!badsit&&!b&&(y+1)<height&&cc[x][y+1]=='.')//checks south for path
	{//(28.7.0.0.0.0)
		b=bnewstraverse(cc,x,y+1,c+1,width,height,pathc,pastmin,badsit,reccount);//goes south a block
	}//(28.7.0.0.0.0)
	if(!b)//if path is blocked unmarks path and decrements path lengt
	{//(28.8.0.0.0.0)
		cc[x][y]='.';
		pathc--;
	}//(28.8.0.0.0.0)
	else
	{//(28.9.0.0.0.0)
		cc[x][y]=('a'+(pathc-c-1)%26);//marks path the reason for the difference from the forward traversals is that a correction was needed to make 'a' start at the begining not the end
	}//(28.9.0.0.0.0)
	return b;
}//(28.0.0.0.0.0)
bool bwsnetraverse(maze& cc, int x, int y, int c, const int width, const int height, int& pathc,const int pastmin,bool& badsit,int& reccount)
{//(29.0.0.0.0.0)
	//this will prevent a rare event that the shortest path wont be found
	int nadj=0;
	if(x!=width-1&&cc[x+1][y]!='.'&&cc[x+1][y]!='*'&&cc[x+1][y]!=',')
		nadj++;
	if(y!=height-1&&cc[x][y+1]!='.'&&cc[x][y+1]!='*'&&cc[x][y+1]!=',')
		nadj++;
	if(y!=0&&cc[x][y-1]!='.'&&cc[x][y-1]!='*'&&cc[x][y-1]!=',')
		nadj++;
	if(x!=0&&cc[x-1][y]!='.'&&cc[x-1][y]!='*'&&cc[x-1][y]!=',')
		nadj++;
	if(nadj>1)
		return false;
	if(reccount==0&&(cc[0][0]=='*'||cc[width-1][height-1]=='*'))////if the start and end are walls them selves are found to be walls method returns false and ends recursion
		return false;
	reccount++;
	if(reccount>100)//takes care of a time issue i am able to do this because there must be another function that will find the path within a proper time
	{//(29.1.0.0.0.0)
		badsit=true;//allows for the swift exit of the stack of recursion
		return false;
	}//(29.1.0.0.0.0)
	bool b=false;
	if((x)==0&&(y)==0)
	{//(29.2.0.0.0.0)
		b= true;
	}//(29.2.0.0.0.0)
	pathc++;
	if(!b&&pathc>pastmin)
	{//(29.3.0.0.0.0)
		pathc--;
		return false;
	}//(29.3.0.0.0.0)
	cc[x][y]='x';
	if(!badsit&&!b&&(x-1)>=0&&cc[x-1][y]=='.')//checks west
	{//(29.4.0.0.0.0)
		b=bwsnetraverse(cc,x-1,y,c+1,width,height,pathc,pastmin,badsit,reccount);//goes west
	}//(29.4.0.0.0.0)
	if(!badsit&&!b&&(y+1)<height&&cc[x][y+1]=='.')//checks south for path
	{//(29.5.0.0.0.0)
		b=bwsnetraverse(cc,x,y+1,c+1,width,height,pathc,pastmin,badsit,reccount);//goes south a block
	}//(29.5.0.0.0.0)
	if(!badsit&&!b&&(y-1)>=0&&cc[x][y-1]=='.')//checks north
	{//(29.6.0.0.0.0)
		b=bwsnetraverse(cc,x,y-1,c+1,width,height,pathc,pastmin,badsit,reccount);//goes north
	}//(29.6.0.0.0.0)
	if(!badsit&&!b&&(x+1)<width&&cc[x+1][y]=='.')//checks east for path
	{//(29.7.0.0.0.0)
		b=bwsnetraverse(cc,x+1,y,c+1,width,height,pathc,pastmin,badsit,reccount);//goes east
	}//(29.7.0.0.0.0)
	if(!b)//if path is blocked unmarks path and decrements path lengt
	{//(29.8.0.0.0.0)
		cc[x][y]='.';
		pathc--;
	}//(29.8.0.0.0.0)
	else
	{//(29.9.0.0.0.0)
		cc[x][y]=('a'+(pathc-c-1)%26);//marks path the reason for the difference from the forward traversals is that a correction was needed to make 'a' start at the begining not the end
	}//(29.9.0.0.0.0)
	return b;
}//(29.0.0.0.0.0)
bool bswentraverse(maze& cc, int x, int y, int c, const int width, const int height, int& pathc,const int pastmin,bool& badsit,int& reccount)
{//(30.0.0.0.0.0)
	//this will prevent a rare event that the shortest path wont be found
	int nadj=0;
	if(x!=width-1&&cc[x+1][y]!='.'&&cc[x+1][y]!='*'&&cc[x+1][y]!=',')
		nadj++;
	if(y!=height-1&&cc[x][y+1]!='.'&&cc[x][y+1]!='*'&&cc[x][y+1]!=',')
		nadj++;
	if(y!=0&&cc[x][y-1]!='.'&&cc[x][y-1]!='*'&&cc[x][y-1]!=',')
		nadj++;
	if(x!=0&&cc[x-1][y]!='.'&&cc[x-1][y]!='*'&&cc[x-1][y]!=',')
		nadj++;
	if(nadj>1)
		return false;
	if(reccount==0&&(cc[0][0]=='*'||cc[width-1][height-1]=='*'))//if the start and end are walls them selves are found to be walls method returns false and ends recursion
		return false;
	reccount++;
	if(reccount>100)//takes care of a time issue i am able to do this because there must be another function that will find the path within a proper time
	{//(30.1.0.0.0.0)
		badsit=true;//allows for the swift exit of the stack of recursion
		return false;
	}//(30.1.0.0.0.0)
	bool b=false;
	if((x)==0&&(y)==0)
	{//(30.2.0.0.0.0)
		b= true;
	}//(30.2.0.0.0.0)
	pathc++;
	if(!b&&pathc>pastmin)
	{//(30.3.0.0.0.0)
		pathc--;
		return false;
	}//(30.3.0.0.0.0)
	cc[x][y]='x';
	if(!badsit&&!b&&(y+1)<height&&cc[x][y+1]=='.')//checks south for path
	{//(30.4.0.0.0.0)
		b=bswentraverse(cc,x,y+1,c+1,width,height,pathc,pastmin,badsit,reccount);//goes south a block
	}//(30.4.0.0.0.0)
	if(!badsit&&!b&&(x-1)>=0&&cc[x-1][y]=='.')//checks west
	{//(30.5.0.0.0.0)
		b=bswentraverse(cc,x-1,y,c+1,width,height,pathc,pastmin,badsit,reccount);//goes west
	}//(30.5.0.0.0.0)
	if(!badsit&&!b&&(x+1)<width&&cc[x+1][y]=='.')//checks east for path
	{//(30.6.0.0.0.0)
		b=bswentraverse(cc,x+1,y,c+1,width,height,pathc,pastmin,badsit,reccount);//goes east
	}//(30.6.0.0.0.0)
	if(!badsit&&!b&&(y-1)>=0&&cc[x][y-1]=='.')//checks north
	{//(30.7.0.0.0.0)
		b=bswentraverse(cc,x,y-1,c+1,width,height,pathc,pastmin,badsit,reccount);//goes north
	}//(30.7.0.0.0.0)
	if(!b)//if path is blocked unmarks path and decrements path lengt
	{//(30.8.0.0.0.0)
		cc[x][y]='.';
		pathc--;
	}//(30.8.0.0.0.0)
	else
	{//(30.9.0.0.0.0)
		cc[x][y]=('a'+(pathc-c-1)%26);//marks path the reason for the difference from the forward traversals is that a correction was needed to make 'a' start at the begining not the end
	}//(30.9.0.0.0.0)
	return b;
}//(30.0.0.0.0.0)
bool benswtraverse(maze& cc, int x, int y, int c, const int width, const int height, int& pathc,const int pastmin,bool& badsit,int& reccount)
{//(31.0.0.0.0.0)
	//this will prevent a rare event that the shortest path wont be found
	int nadj=0;
	if(x!=width-1&&cc[x+1][y]!='.'&&cc[x+1][y]!='*'&&cc[x+1][y]!=',')
		nadj++;
	if(y!=height-1&&cc[x][y+1]!='.'&&cc[x][y+1]!='*'&&cc[x][y+1]!=',')
		nadj++;
	if(y!=0&&cc[x][y-1]!='.'&&cc[x][y-1]!='*'&&cc[x][y-1]!=',')
		nadj++;
	if(x!=0&&cc[x-1][y]!='.'&&cc[x-1][y]!='*'&&cc[x-1][y]!=',')
		nadj++;
	if(nadj>1)
		return false;
	if(reccount==0&&(cc[0][0]=='*'||cc[width-1][height-1]=='*'))////if the start and end are walls them selves are found to be walls method returns false and ends recursion
		return false;
	reccount++;
	if(reccount>100)//takes care of a time issue i am able to do this because there must be another function that will find the path within a proper time
	{//(31.1.0.0.0.0)
		badsit=true;//allows for the swift exit of the stack of recursion
		return false;
	}//(31.1.0.0.0.0)
	bool b=false;
	if((x)==0&&(y)==0)
	{//(31.2.0.0.0.0)
		b= true;
	}//(31.2.0.0.0.0)
	pathc++;
	if(!b&&pathc>pastmin)
	{//(31.3.0.0.0.0)
		pathc--;
		return false;
	}//(31.3.0.0.0.0)
	cc[x][y]='x';
	if(!badsit&&!b&&(x+1)<width&&cc[x+1][y]=='.')//checks east for path
	{//(31.4.0.0.0.0)
		b=benswtraverse(cc,x+1,y,c+1,width,height,pathc,pastmin,badsit,reccount);//goes east
	}//(31.4.0.0.0.0)
	if(!badsit&&!b&&(y-1)>=0&&cc[x][y-1]=='.')//checks north
	{//(31.5.0.0.0.0)
		b=benswtraverse(cc,x,y-1,c+1,width,height,pathc,pastmin,badsit,reccount);//goes north
	}//(31.5.0.0.0.0)
	if(!badsit&&!b&&(y+1)<height&&cc[x][y+1]=='.')//checks south for path
	{//(31.6.0.0.0.0)
		b=benswtraverse(cc,x,y+1,c+1,width,height,pathc,pastmin,badsit,reccount);//goes south a block
	}//(31.6.0.0.0.0)
	if(!badsit&&!b&&(x-1)>=0&&cc[x-1][y]=='.')//checks west
	{//(31.7.0.0.0.0)
		b=benswtraverse(cc,x-1,y,c+1,width,height,pathc,pastmin,badsit,reccount);//goes west
	}//(31.7.0.0.0.0)
	if(!b)//if path is blocked unmarks path and decrements path lengt
	{//(31.8.0.0.0.0)
		cc[x][y]='.';
		pathc--;
	}//(31.8.0.0.0.0)
	else
	{//(31.9.0.0.0.0)
		cc[x][y]=('a'+(pathc-c-1)%26);//marks path the reason for the difference from the forward traversals is that a correction was needed to make 'a' start at the begining not the end
	}//(31.9.0.0.0.0)
	return b;
}//(31.0.0.0.0.0)
bool bsenwtraverse(maze& cc, int x, int y, int c, const int width, const int height, int& pathc,const int pastmin,bool& badsit,int& reccount)
{//(32.0.0.0.0.0)
	//this will prevent a rare event that the shortest path wont be found
	int nadj=0;
	if(x!=width-1&&cc[x+1][y]!='.'&&cc[x+1][y]!='*'&&cc[x+1][y]!=',')
		nadj++;
	if(y!=height-1&&cc[x][y+1]!='.'&&cc[x][y+1]!='*'&&cc[x][y+1]!=',')
		nadj++;
	if(y!=0&&cc[x][y-1]!='.'&&cc[x][y-1]!='*'&&cc[x][y-1]!=',')
		nadj++;
	if(x!=0&&cc[x-1][y]!='.'&&cc[x-1][y]!='*'&&cc[x-1][y]!=',')
		nadj++;
	if(nadj>1)
		return false;
	if(reccount==0&&(cc[0][0]=='*'||cc[width-1][height-1]=='*'))////if the start and end are walls them selves are found to be walls method returns false and ends recursion
		return false;
	reccount++;
	if(reccount>100)//takes care of a time issue i am able to do this because there must be another function that will find the path within a proper time
	{//(32.1.0.0.0.0)
		badsit=true;//allows for the swift exit of the stack of recursion
		return false;
	}//(32.1.0.0.0.0)
	bool b=false;
	if((x)==0&&(y)==0)
	{//(32.2.0.0.0.0)
		b= true;
	}//(32.2.0.0.0.0)
	pathc++;
	if(!b&&pathc>pastmin)
	{//(32.3.0.0.0.0)
		pathc--;
		return false;
	}//(32.3.0.0.0.0)
	cc[x][y]='x';
	if(!badsit&&!b&&(y+1)<height&&cc[x][y+1]=='.')//checks south for path
	{//(32.4.0.0.0.0)
		b=bsenwtraverse(cc,x,y+1,c+1,width,height,pathc,pastmin,badsit,reccount);//goes south a block
	}//(32.4.0.0.0.0)
	if(!badsit&&!b&&(x+1)<width&&cc[x+1][y]=='.')//checks east for path
	{//(32.5.0.0.0.0)
		b=bsenwtraverse(cc,x+1,y,c+1,width,height,pathc,pastmin,badsit,reccount);//goes east
	}//(32.5.0.0.0.0)
	if(!badsit&&!b&&(y-1)>=0&&cc[x][y-1]=='.')//checks north
	{//(32.6.0.0.0.0)
		b=bsenwtraverse(cc,x,y-1,c+1,width,height,pathc,pastmin,badsit,reccount);//goes north
	}//(32.6.0.0.0.0)
	if(!badsit&&!b&&(x-1)>=0&&cc[x-1][y]=='.')//checks west
	{//(32.7.0.0.0.0)
		b=bsenwtraverse(cc,x-1,y,c+1,width,height,pathc,pastmin,badsit,reccount);//goes west
	}//(32.7.0.0.0.0)
	if(!b)//if path is blocked unmarks path and decrements path lengt
	{//(32.8.0.0.0.0)
		cc[x][y]='.';
		pathc--;
	}//(32.8.0.0.0.0)
	else
	{//(32.9.0.0.0.0)
		cc[x][y]=('a'+(pathc-c-1)%26);//marks path the reason for the difference from the forward traversals is that a correction was needed to make 'a' start at the begining not the end
	}//(32.9.0.0.0.0)
	return b;
}//(32.0.0.0.0.0)
bool bnwsetraverse(maze& cc, int x, int y, int c, const int width, const int height, int& pathc,const int pastmin,bool& badsit,int& reccount)
{//(33.0.0.0.0.0)
	//this will prevent a rare event that the shortest path wont be found
	int nadj=0;
	if(x!=width-1&&cc[x+1][y]!='.'&&cc[x+1][y]!='*'&&cc[x+1][y]!=',')
		nadj++;
	if(y!=height-1&&cc[x][y+1]!='.'&&cc[x][y+1]!='*'&&cc[x][y+1]!=',')
		nadj++;
	if(y!=0&&cc[x][y-1]!='.'&&cc[x][y-1]!='*'&&cc[x][y-1]!=',')
		nadj++;
	if(x!=0&&cc[x-1][y]!='.'&&cc[x-1][y]!='*'&&cc[x-1][y]!=',')
		nadj++;
	if(nadj>1)
		return false;
	if(reccount==0&&(cc[0][0]=='*'||cc[width-1][height-1]=='*'))////if the start and end are walls them selves are found to be walls method returns false and ends recursion
		return false;
	reccount++;
	if(reccount>100)//takes care of a time issue i am able to do this because there must be another function that will find the path within a proper time
	{//(33.1.0.0.0.0)
		badsit=true;//allows for the swift exit of the stack of recursion
		return false;
	}//(33.1.0.0.0.0)
	bool b=false;
	if((x)==0&&(y)==0)
	{//(33.2.0.0.0.0)
		b= true;
	}//(33.2.0.0.0.0)
	pathc++;
	if(!b&&pathc>pastmin)
	{//(33.3.0.0.0.0)
		pathc--;
		return false;
	}//(33.3.0.0.0.0)
	cc[x][y]='x';
	if(!badsit&&!b&&(y-1)>=0&&cc[x][y-1]=='.')//checks north
	{//(33.4.0.0.0.0)
		b=bnwsetraverse(cc,x,y-1,c+1,width,height,pathc,pastmin,badsit,reccount);//goes north
	}//(33.4.0.0.0.0)
	if(!badsit&&!b&&(x-1)>=0&&cc[x-1][y]=='.')//checks west
	{//(33.5.0.0.0.0)
		b=bnwsetraverse(cc,x-1,y,c+1,width,height,pathc,pastmin,badsit,reccount);//goes west
	}//(33.5.0.0.0.0)
	if(!badsit&&!b&&(y+1)<height&&cc[x][y+1]=='.')//checks south for path
	{//(33.6.0.0.0.0)
		b=bnwsetraverse(cc,x,y+1,c+1,width,height,pathc,pastmin,badsit,reccount);//goes south a block
	}//(33.6.0.0.0.0)
	if(!badsit&&!b&&(x+1)<width&&cc[x+1][y]=='.')//checks east for path
	{//(33.7.0.0.0.0)
		b=bnwsetraverse(cc,x+1,y,c+1,width,height,pathc,pastmin,badsit,reccount);//goes east
	}//(33.7.0.0.0.0)
	if(!b)//if path is blocked unmarks path and decrements path lengt
	{//(33.8.0.0.0.0)
		cc[x][y]='.';
		pathc--;
	}//(33.8.0.0.0.0)
	else
	{//(33.9.0.0.0.0)
		cc[x][y]=('a'+(pathc-c-1)%26);//marks path the reason for the difference from the forward traversals is that a correction was needed to make 'a' start at the begining not the end
	}//(33.9.0.0.0.0)
	return b;
}//(33.0.0.0.0.0)
bool bwnestraverse(maze& cc, int x, int y, int c, const int width, const int height, int& pathc,const int pastmin,bool& badsit,int& reccount)
{//(34.0.0.0.0.0)
	//this will prevent a rare event that the shortest path wont be found
	int nadj=0;
	if(x!=width-1&&cc[x+1][y]!='.'&&cc[x+1][y]!='*'&&cc[x+1][y]!=',')
		nadj++;
	if(y!=height-1&&cc[x][y+1]!='.'&&cc[x][y+1]!='*'&&cc[x][y+1]!=',')
		nadj++;
	if(y!=0&&cc[x][y-1]!='.'&&cc[x][y-1]!='*'&&cc[x][y-1]!=',')
		nadj++;
	if(x!=0&&cc[x-1][y]!='.'&&cc[x-1][y]!='*'&&cc[x-1][y]!=',')
		nadj++;
	if(nadj>1)
		return false;
	if(reccount==0&&(cc[0][0]=='*'||cc[width-1][height-1]=='*'))////if the start and end are walls them selves are found to be walls method returns false and ends recursion
		return false;
	reccount++;
	if(reccount>100)//takes care of a time issue i am able to do this because there must be another function that will find the path within a proper time
	{//(34.1.0.0.0.0)
		badsit=true;//allows for the swift exit of the stack of recursion
		return false;
	}//(34.1.0.0.0.0)
	bool b=false;
	if((x)==0&&(y)==0)
	{//(34.2.0.0.0.0)
		b= true;
	}//(34.2.0.0.0.0)
	pathc++;
	if(!b&&pathc>pastmin)
	{//(34.3.0.0.0.0)
		pathc--;
		return false;
	}//(34.3.0.0.0.0)
	cc[x][y]='x';
	if(!badsit&&!b&&(x-1)>=0&&cc[x-1][y]=='.')//checks west
	{//(34.4.0.0.0.0)
		b=bwnestraverse(cc,x-1,y,c+1,width,height,pathc,pastmin,badsit,reccount);//goes west
	}//(34.4.0.0.0.0)
	if(!badsit&&!b&&(y-1)>=0&&cc[x][y-1]=='.')//checks north
	{//(34.5.0.0.0.0)
		b=bwnestraverse(cc,x,y-1,c+1,width,height,pathc,pastmin,badsit,reccount);//goes north
	}//(34.5.0.0.0.0)
	if(!badsit&&!b&&(x+1)<width&&cc[x+1][y]=='.')//checks east for path
	{//(34.6.0.0.0.0)
		b=bwnestraverse(cc,x+1,y,c+1,width,height,pathc,pastmin,badsit,reccount);//goes east
	}//(34.6.0.0.0.0)
	if(!badsit&&!b&&(y+1)<height&&cc[x][y+1]=='.')//checks south for path
	{//(34.7.0.0.0.0)
		b=bwnestraverse(cc,x,y+1,c+1,width,height,pathc,pastmin,badsit,reccount);//goes south a block
	}//(34.7.0.0.0.0)
	if(!b)//if path is blocked unmarks path and decrements path lengt
	{//(34.8.0.0.0.0)
		cc[x][y]='.';
		pathc--;
	}//(34.8.0.0.0.0)
	else
	{//(34.9.0.0.0.0)
		cc[x][y]=('a'+(pathc-c-1)%26);//marks path the reason for the difference from the forward traversals is that a correction was needed to make 'a' start at the begining not the end
	}//(34.9.0.0.0.0)
	return b;
}//(34.0.0.0.0.0)
bool beswntraverse(maze& cc, int x, int y, int c, const int width, const int height, int& pathc,const int pastmin,bool& badsit,int& reccount)
{//(35.0.0.0.0.0)
	//this will prevent a rare event that the shortest path wont be found
	int nadj=0;
	if(x!=width-1&&cc[x+1][y]!='.'&&cc[x+1][y]!='*'&&cc[x+1][y]!=',')
		nadj++;
	if(y!=height-1&&cc[x][y+1]!='.'&&cc[x][y+1]!='*'&&cc[x][y+1]!=',')
		nadj++;
	if(y!=0&&cc[x][y-1]!='.'&&cc[x][y-1]!='*'&&cc[x][y-1]!=',')
		nadj++;
	if(x!=0&&cc[x-1][y]!='.'&&cc[x-1][y]!='*'&&cc[x-1][y]!=',')
		nadj++;
	if(nadj>1)
		return false;
	if(reccount==0&&(cc[0][0]=='*'||cc[width-1][height-1]=='*'))////if the start and end are walls them selves are found to be walls method returns false and ends recursion
		return false;
	reccount++;
	if(reccount>100)//takes care of a time issue i am able to do this because there must be another function that will find the path within a proper time
	{//(35.1.0.0.0.0)
		badsit=true;//allows for the swift exit of the stack of recursion
		return false;
	}//(35.1.0.0.0.0)
	bool b=false;
	if((x)==0&&(y)==0)
	{//(35.2.0.0.0.0)
		b= true;
	}//(35.2.0.0.0.0)
	pathc++;
	if(!b&&pathc>pastmin)
	{//(35.3.0.0.0.0)
		pathc--;
		return false;
	}//(35.3.0.0.0.0)
	cc[x][y]='x';
	if(!badsit&&!b&&(x+1)<width&&cc[x+1][y]=='.')//checks east for path
	{//(35.4.0.0.0.0)
		b=beswntraverse(cc,x+1,y,c+1,width,height,pathc,pastmin,badsit,reccount);//goes east
	}//(35.4.0.0.0.0)
	if(!badsit&&!b&&(y+1)<height&&cc[x][y+1]=='.')//checks south for path
	{//(35.5.0.0.0.0)
		b=beswntraverse(cc,x,y+1,c+1,width,height,pathc,pastmin,badsit,reccount);//goes south a block
	}//(35.5.0.0.0.0)
	if(!badsit&&!b&&(x-1)>=0&&cc[x-1][y]=='.')//checks west
	{//(35.6.0.0.0.0)
		b=beswntraverse(cc,x-1,y,c+1,width,height,pathc,pastmin,badsit,reccount);//goes west
	}//(35.6.0.0.0.0)
	if(!badsit&&!b&&(y-1)>=0&&cc[x][y-1]=='.')//checks north
	{//(35.7.0.0.0.0)
		b=beswntraverse(cc,x,y-1,c+1,width,height,pathc,pastmin,badsit,reccount);//goes north
	}//(35.7.0.0.0.0)
	if(!b)//if path is blocked unmarks path and decrements path lengt
	{//(35.8.0.0.0.0)
		cc[x][y]='.';
		pathc--;
	}//(35.8.0.0.0.0)
	else
	{//(35.9.0.0.0.0)
		cc[x][y]=('a'+(pathc-c-1)%26);//marks path the reason for the difference from the forward traversals is that a correction was needed to make 'a' start at the begining not the end
	}//(35.9.0.0.0.0)
	return b;
}//(35.0.0.0.0.0)
void Mazecopy(maze& returned,const maze result, const int h,const int w)
{//(36.0.0.0.0.0)
	for(int x=0;x<w;x++)
	{//(36.1.0.0.0.0)
		for(int y=0;y<h;y++)
		{//(36.1.1.0.0.0)
			returned[x][y]=result[x][y];
		}//(36.1.1.0.0.0)
	}//(36.1.0.0.0.0)
}//(36.0.0.0.0.0)
int Solve(ara a,std::ofstream& out,bool alltravshown, bool& nopath,maze &cc,const int height,const int width)
{//(37.0.0.0.0.0)
		maze sewn;//these will allow me to find the optimal path fast.
		maze senw;
		maze snew;
		maze snwe;
		maze swne;
		maze swen;
		maze wsen;
		maze wsne;
		maze wnse;
		maze wnes;
		maze wens;
		maze wesn;
		maze ewsn;
		maze ewns;
		maze enws;
		maze ensw;
		maze esnw;
		maze eswn;
		maze nesw;
		maze news;
		maze nwes;
		maze nwse;
		maze nswe;
		maze nsew;
		maze bnews;
		maze bwsne;
		maze bswen;
		maze bensw;
		maze bsenw;
		maze bnwse;
		maze bwnes;
		maze beswn;
		bool golden=false;//this boolean is in the case of the shortest path possible is the shortest shortest path possible for that size of a maze;
		int xx1=0;//this will be for the length of the paths
		int min=65;//this will be for keeping track of the fastest path found the largest maze the maximum shartest path length possible I found to be 59
		int casen=0;//this will keep track which array to print for the fastest path
		int reccount;//special int for timing issues, what this and the bool below will do is allow the methods to stop if they are having trouble, allowing another method to pick up where the previouses weakness is a strength
		bool tempb;//special bool to correct a timing issue
		if(width==0&&height==0&&width<=10&&height<=10)//makes sure the bounds are not out of range of values for the maze dimensions
		{//(37.1.0.0.0.0)
			return 0;
		}//(37.1.0.0.0.0)
		for(int y=0;y<height;y++)//outerloop for building arrays from file
		{//(37.2.0.0.0.0)
			for(int x=0;x<width;x++)//innerloop for building array from file
			{//(37.2.1.0.0.0)
				sewn[x][y]=cc[x][y]; //assigns the char to all the arrays
				senw[x][y]=cc[x][y];//2
				snew[x][y]=cc[x][y];//3
				snwe[x][y]=cc[x][y];//4
				swne[x][y]=cc[x][y];//5
				swen[x][y]=cc[x][y];//6
				wsen[x][y]=cc[x][y];//7
				wsne[x][y]=cc[x][y];//8
				wnse[x][y]=cc[x][y];//9
				wnes[x][y]=cc[x][y];//10
				wens[x][y]=cc[x][y];//11
				wesn[x][y]=cc[x][y];//12
				ewsn[x][y]=cc[x][y];//13
				ewns[x][y]=cc[x][y];//14
				enws[x][y]=cc[x][y];//15
				ensw[x][y]=cc[x][y];//16
				esnw[x][y]=cc[x][y];//17
				eswn[x][y]=cc[x][y];//18
				nesw[x][y]=cc[x][y];//19
				news[x][y]=cc[x][y];//20
				nwes[x][y]=cc[x][y];//21
				nwse[x][y]=cc[x][y];//22
				nswe[x][y]=cc[x][y];//23
				nsew[x][y]=cc[x][y];//24
				bnews[x][y]=cc[x][y];//25
				bwsne[x][y]=cc[x][y];//26
				bswen[x][y]=cc[x][y];//27
				bensw[x][y]=cc[x][y];//28
				bsenw[x][y]=cc[x][y];//29
				bnwse[x][y]=cc[x][y];//30
				bwnes[x][y]=cc[x][y];//31
				beswn[x][y]=cc[x][y];//32
			}//(37.2.1.0.0.0)
		}//(37.2.0.0.0.0)
		tempb=false;//special bool to correct a timing issue
		reccount=0;//special int for timing issues
		nopath=false;//this bool will keep from running all the traverse methods on a pathless maze
		if(sewntraverse(sewn, 0, 0, 'a',  width,  height,xx1,tempb,reccount))//if a path is found tests since it is the first traversal it will automatically be shortest
		{//(37.3.0.0.0.0)
			min=xx1;//min path length get the path length of prev traversal
			casen=1;//keeps track of which path that will need to be printed
			if(xx1==width+height-1)
				golden=true;
		}//(37.3.0.0.0.0)
		else if(!tempb)//if tempb is not true yet the function failed to find a path then there is no path
		{//(37.4.0.0.0.0)
			nopath=true;
		}//(37.4.0.0.0.0)
		//#int total_recursions=reccount;
		//#out<<"|sewn|senw|snew|snwe|swne|swen|wsen|wsne|wnse|wnes|wens|wesn|ewsn|ewns|enws|ensw|esnw|eswn|nesw|news|nwes|nwse|nswe|nsew|bnews|bwsne|bswen|bensw|bsenw|bnwse|bwnes|beswn\n";
		//#out<<"|"<<setw(4)<<reccount;
		xx1=0;//perpares path length for next traverse
		tempb=false;//special bool to correct a timing issue
		reccount=0;//prepares reccount for next traversal
		if(golden||nopath){}
		else if(senwtraverse(senw, 0, 0, 'a',  width,  height,xx1,min,tempb,reccount))//if a path is found tests tests to see if the path is shorter than the already min path
		{//(37.5.0.0.0.0)
			if(xx1<min)//test to see if previous path length is less than current min
			{//(37.5.1.0.0.0)
				min=xx1;//min path length get the path length of prev traversal
				casen=2;//keeps track of which path that will need to be printed
				if(xx1==width+height-1)
					golden=true;
			}//(37.5.1.0.0.0)
		}//(37.5.0.0.0.0)
		else if(!tempb)//if tempb is not true yet the function failed to find a path then there is no path
		{//(37.6.0.0.0.0)
			nopath=true;
		}//(37.6.0.0.0.0)
		//#total_recursions=total_recursions+reccount;
		//#out<<"|"<<setw(4)<<reccount;
		xx1=0;//perpares path length for next traverse
		tempb=false;//special bool to correct a timing issue
		reccount=0;//prepares reccount for next traversal
		if(golden||nopath){}
		else if(snewtraverse(snew, 0, 0, 'a',  width,  height,xx1,min,tempb,reccount))//if a path is found tests tests to see if the path is shorter than the already min path
		{//(37.7.0.0.0.0)
			if(xx1<min)//test to see if previous path length is less than current min
			{//(37.7.1.0.0.0)
				min=xx1;//min path length get the path length of prev traversal
				casen=3;//keeps track of which path that will need to be printed
				if(xx1==width+height-1)
					golden=true;
			}//(37.7.1.0.0.0)
		}//(37.7.0.0.0.0)
		else if(!tempb)//if tempb is not true yet the function failed to find a path then there is no path
		{//(37.8.0.0.0.0)
			nopath=true;
		}//(37.8.0.0.0.0)
		//#total_recursions=total_recursions+reccount;
		//#out<<"|"<<setw(4)<<reccount;
		tempb=false;//special bool to correct a timing issue
		xx1=0;//perpares path length for next traverse
		reccount=0;//prepares reccount for next traversal
		if(golden||nopath){}
		else if(snwetraverse(snwe, 0, 0, 'a',  width,  height,xx1,min,tempb,reccount))//if a path is found tests tests to see if the path is shorter than the already min path
		{//(37.9.0.0.0.0)
			if(xx1<min)//test to see if previous path length is less than current min
			{//(37.9.1.0.0.0)
				min=xx1;//min path length get the path length of prev traversal
				casen=4;//keeps track of which path that will need to be printed
				if(xx1==width+height-1)
					golden=true;
			}//(37.9.1.0.0.0)
		}//(37.9.0.0.0.0)
		else if(!tempb)//if tempb is not true yet the function failed to find a path then there is no path
		{//(37.10.0.0.0.0)
			nopath=true;
		}//(37.10.0.0.0.0)
		//#total_recursions=total_recursions+reccount;
		//#out<<"|"<<setw(4)<<reccount;
		xx1=0;//perpares path length for next traverse
		tempb=false;//special bool to correct a timing issue
		reccount=0;//prepares reccount for next traversal
		if(golden||nopath){}
		else if(swnetraverse(swne, 0, 0, 'a',  width,  height,xx1,min,tempb,reccount))//if a path is found tests tests to see if the path is shorter than the already min path
		{//(37.11.0.0.0.0)
			if(xx1<min)//test to see if previous path length is less than current min
			{//(37.11.1.0.0.0)
				min=xx1;//min path length get the path length of prev traversal
				casen=5;//keeps track of which path that will need to be printed
				if(xx1==width+height-1)
					golden=true;
			}//(37.11.1.0.0.0)
		}//(37.11.0.0.0.0)
		else if(!tempb)//if tempb is not true yet the function failed to find a path then there is no path
		{//(37.12.0.0.0.0)
			nopath=true;
		}//(37.12.0.0.0.0)
		//#total_recursions=total_recursions+reccount;
		//#out<<"|"<<setw(4)<<reccount;
		xx1=0;//perpares path length for next traverse
		tempb=false;//special bool to correct a timing issue
		reccount=0;//prepares reccount for next traversal
		if(golden||nopath){}
		else if(swentraverse(swen, 0, 0, 'a',  width,  height,xx1,min,tempb,reccount))//if a path is found tests tests to see if the path is shorter than the already min path
		{//(37.13.0.0.0.0)
			if(xx1<min)//test to see if previous path length is less than current min
			{//(37.13.1.0.0.0)
				min=xx1;//min path length get the path length of prev traversal
				casen=6;//keeps track of which path that will need to be printed
				if(xx1==width+height-1)
					golden=true;
			}//(37.13.1.0.0.0)
		}//(37.13.0.0.0.0)
		else if(!tempb)//if tempb is not true yet the function failed to find a path then there is no path
		{//(37.14.0.0.0.0)
			nopath=true;
		}//(37.14.0.0.0.0)
		//#total_recursions=total_recursions+reccount;
		//#out<<"|"<<setw(4)<<reccount;
		xx1=0;//perpares path length for next traverse
		tempb=false;//special bool to correct a timing issue
		reccount=0;//prepares reccount for next traversal
		if(golden||nopath){}
		else if(wsentraverse(wsen, 0, 0, 'a',  width,  height,xx1,min,tempb,reccount))//if a path is found tests tests to see if the path is shorter than the already min path
		{//(37.15.0.0.0.0)
			if(xx1<min)//test to see if previous path length is less than current min
			{//(37.15.1.0.0.0)
				min=xx1;//min path length get the path length of prev traversal
				casen=7;//keeps track of which path that will need to be printed
				if(xx1==width+height-1)
					golden=true;
			}//(37.15.1.0.0.0)
		}//(37.15.0.0.0.0)
		else if(!tempb)//if tempb is not true yet the function failed to find a path then there is no path
		{//(37.16.0.0.0.0)
			nopath=true;
		}//(37.16.0.0.0.0)
		//#total_recursions=total_recursions+reccount;
		//#out<<"|"<<setw(4)<<reccount;
		xx1=0;//perpares path length for next traveres
		tempb=false;//special bool to correct a timing issue
		reccount=0;//prepares reccount for next traversal
		if(golden||nopath){}
		else if(wsnetraverse(wsne, 0, 0, 'a',  width,  height,xx1,min,tempb,reccount))//if a path is found tests tests to see if the path is shorter than the already min path
		{//(37.17.0.0.0.0)
			if(xx1<min)//test to see if previous path length is less than current min
			{//(37.17.1.0.0.0)
				min=xx1;//min path length get the path length of prev traversal
				casen=8;//keeps track of which path that will need to be printed
				if(xx1==width+height-1)
					golden=true;
			}//(37.17.1.0.0.0)
		}//(37.17.0.0.0.0)
		else if(!tempb)//if tempb is not true yet the function failed to find a path then there is no path
		{//(37.18.0.0.0.0)
			nopath=true;
		}//(37.18.0.0.0.0)
		//#total_recursions=total_recursions+reccount;
		//#out<<"|"<<setw(4)<<reccount;
		xx1=0;//perpares path length for next traverse
		tempb=false;//special bool to correct a timing issue
		reccount=0;//prepares reccount for next traversal
		if(golden||nopath){}
		else if(wnsetraverse(wnse, 0, 0, 'a',  width,  height,xx1,min,tempb,reccount))//if a path is found tests tests to see if the path is shorter than the already min path
		{//(37.19.0.0.0.0)
			if(xx1<min)//test to see if previous path length is less than current min
			{//(37.19.1.0.0.0)
				min=xx1;//min path length get the path length of prev traversal
				casen=9;//keeps track of which path that will need to be printed
				if(xx1==width+height-1)
					golden=true;
			}//(37.19.1.0.0.0)
		}//(37.19.0.0.0.0)
		else if(!tempb)//if tempb is not true yet the function failed to find a path then there is no path
		{//(37.20.0.0.0.0)
			nopath=true;
		}//(37.20.0.0.0.0)
		//#total_recursions=total_recursions+reccount;
		//#out<<"|"<<setw(4)<<reccount;
		xx1=0;//perpares path length for next traverse
		tempb=false;//special bool to correct a timing issue
		reccount=0;//prepares reccount for next traversal
		if(golden||nopath){}
		else if(wnestraverse(wnes, 0, 0, 'a',  width,  height,xx1,min,tempb,reccount))//if a path is found tests tests to see if the path is shorter than the already min path
		{//(37.21.0.0.0.0)
			if(xx1<min)//test to see if previous path length is less than current min
			{//(37.21.1.0.0.0)
				min=xx1;//min path length get the path length of prev traversal
				casen=10;//keeps track of which path that will need to be printed
				if(xx1==width+height-1)
					golden=true;
			}//(37.21.1.0.0.0)
		}//(37.21.0.0.0.0)
		else if(!tempb)//if tempb is not true yet the function failed to find a path then there is no path
		{//(37.22.0.0.0.0)
			nopath=true;
		}//(37.22.0.0.0.0)
		//#total_recursions=total_recursions+reccount;
		//#out<<"|"<<setw(4)<<reccount;
		xx1=0;//perpares path length for next traverse
		tempb=false;//special bool to correct a timing issue
		reccount=0;//prepares reccount for next traversal
		if(golden||nopath){}
		else if(wenstraverse(wens, 0, 0, 'a',  width,  height,xx1,min,tempb,reccount))//if a path is found tests tests to see if the path is shorter than the already min path
		{//(37.23.0.0.0.0)
			if(xx1<min)//test to see if previous path length is less than current min
			{//(37.23.1.0.0.0)
				min=xx1;//min path length get the path length of prev traversal
				casen=11;//keeps track of which path that will need to be printed
				if(xx1==width+height-1)
					golden=true;
			}//(37.23.1.0.0.0)
		}//(37.23.0.0.0.0)
		else if(!tempb)//if tempb is not true yet the function failed to find a path then there is no path
		{//(37.24.0.0.0.0)
			nopath=true;
		}//(37.24.0.0.0.0)
		//#total_recursions=total_recursions+reccount;
		//#out<<"|"<<setw(4)<<reccount;
		xx1=0;//perpares path length for next traverse
		tempb=false;//special bool to correct a timing issue
		reccount=0;//prepares reccount for next traversal
		if(golden||nopath){}
		else if(wesntraverse(wesn, 0, 0, 'a',  width,  height,xx1,min,tempb,reccount))//if a path is found tests tests to see if the path is shorter than the already min path
		{//(37.25.0.0.0.0)
			if(xx1<min)//test to see if previous path length is less than current min
			{//(37.25.1.0.0.0)
				min=xx1;//min path length get the path length of prev traversal
				casen=12;//keeps track of which path that will need to be printed
				if(xx1==width+height-1)
					golden=true;
			}//(37.25.1.0.0.0)
		}//(37.25.0.0.0.0)
		else if(!tempb)//if tempb is not true yet the function failed to find a path then there is no path
		{//(37.26.0.0.0.0)
			nopath=true;
		}//(37.26.0.0.0.0)
		//#total_recursions=total_recursions+reccount;
		//#out<<"|"<<setw(4)<<reccount;
		xx1=0;//perpares path length for next traverse
		tempb=false;//pr=repares special bool for next traversal
		reccount=0;//prepares special int for next traversal
		if(golden||nopath){}
		else if(ewsntraverse(ewsn, 0, 0, 'a',  width,  height,xx1,min,tempb,reccount))//if a path is found tests tests to see if the path is shorter than the already min path
		{//(37.27.0.0.0.0)
			if(xx1<min)//test to see if previous path length is less than current min
			{//(37.27.1.0.0.0)
				min=xx1;//min path length get the path length of prev traversal
				casen=13;//keeps track of which path that will need to be printed
				if(xx1==width+height-1)
					golden=true;
			}//(37.27.1.0.0.0)
		}//(37.27.0.0.0.0)
		else if(!tempb)//if tempb is not true yet the function failed to find a path then there is no path
		{//(37.28.0.0.0.0)
			nopath=true;
		}//(37.28.0.0.0.0)
		//#total_recursions=total_recursions+reccount;
		//#out<<"|"<<setw(4)<<reccount;
		xx1=0;//perpares path length for next traverse
		tempb=false;//special bool to correct a timing issue
		reccount=0;//prepares special int for next traversal
		if(golden||nopath){}
		else if(ewnstraverse(ewns, 0, 0, 'a',  width,  height,xx1,min,tempb,reccount))//if a path is found tests tests to see if the path is shorter than the already min path
		{//(37.29.0.0.0.0)
			if(xx1<min)//test to see if previous path length is less than current min
			{//(37.29.1.0.0.0)
				min=xx1;//min path length get the path length of prev traversal
				casen=14;//keeps track of which path that will need to be printed
				if(xx1==width+height-1)
					golden=true;
			}//(37.29.1.0.0.0)
		}//(37.29.0.0.0.0)
		else if(!tempb)//if tempb is not true yet the function failed to find a path then there is no path
		{//(37.30.0.0.0.0)
			nopath=true;
		}//(37.30.0.0.0.0)
		//#total_recursions=total_recursions+reccount;
		//#out<<"|"<<setw(4)<<reccount;
		xx1=0;//perpares path length for next traverse
		tempb=false;//special bool to correct a timing issue
		reccount=0;//prepares reccount for next traversal
		if(golden||nopath){}
		else if(enwstraverse(enws, 0, 0, 'a',  width,  height,xx1,min,tempb,reccount))//if a path is found tests tests to see if the path is shorter than the already min path
		{//(37.31.0.0.0.0)
			if(xx1<min)//test to see if previous path length is less than current min
			{//(37.31.1.0.0.0)
				min=xx1;//min path length get the path length of prev traversal
				casen=15;//keeps track of which path that will need to be printed
				if(xx1==width+height-1)
					golden=true;
			}//(37.31.1.0.0.0)
		}//(37.31.0.0.0.0)
		else if(!tempb)//if tempb is not true yet the function failed to find a path then there is no path
		{//(37.32.0.0.0.0)
			nopath=true;
		}//(37.32.0.0.0.0)
		//#total_recursions=total_recursions+reccount;
		//#out<<"|"<<setw(4)<<reccount;
		xx1=0;//perpares path length for next traverse
		tempb=false;//special bool to correct a timing issue
		reccount=0;//prepares reccount for next traversal
		if(golden||nopath){}
		else if(enswtraverse(ensw, 0, 0, 'a',  width,  height,xx1,min,tempb,reccount))//if a path is found tests tests to see if the path is shorter than the already min path
		{//(37.33.0.0.0.0)
			if(xx1<min)//test to see if previous path length is less than current min
			{//(37.33.1.0.0.0)
				min=xx1;//min path length get the path length of prev traversal
				casen=16;//keeps track of which path that will need to be printed
				if(xx1==width+height-1)
					golden=true;
			}//(37.33.1.0.0.0)
		}//(37.33.0.0.0.0)
		else if(!tempb)//if tempb is not true yet the function failed to find a path then there is no path
		{//(37.34.0.0.0.0)
			nopath=true;
		}//(37.34.0.0.0.0)
		//#total_recursions=total_recursions+reccount;
		//#out<<"|"<<setw(4)<<reccount;
		xx1=0;//perpares path length for next traverse
		tempb=false;//special bool to correct a timing issue
		reccount=0;//prepares reccount for next traversal
		if(golden||nopath){}
		else if(esnwtraverse(esnw, 0, 0, 'a',  width,  height,xx1,min,tempb,reccount))//if a path is found tests tests to see if the path is shorter than the already min path
		{//(37.35.0.0.0.0)
			if(xx1<min)//test to see if previous path length is less than current min
			{//(37.35.1.0.0.0)
				min=xx1;//min path length get the path length of prev traversal
				casen=17;//keeps track of which path that will need to be printed
				if(xx1==width+height-1)
					golden=true;
			}//(37.35.1.0.0.0)
		}//(37.35.0.0.0.0)
		else if(!tempb)//if tempb is not true yet the function failed to find a path then there is no path
		{//(37.36.0.0.0.0)
			nopath=true;
		}//(37.36.0.0.0.0)
		//#total_recursions=total_recursions+reccount;
		//#out<<"|"<<setw(4)<<reccount;
		xx1=0;//perpares path length for next traverse
		tempb=false;//special bool to correct a timing issue
		reccount=0;//prepares reccount for next traversal
		if(golden||nopath){}
		else if(eswntraverse(eswn, 0, 0, 'a',  width,  height,xx1,min,tempb,reccount))//if a path is found tests tests to see if the path is shorter than the already min path
		{//(37.37.0.0.0.0)
			if(xx1<min)//test to see if previous path length is less than current min
			{//(37.37.1.0.0.0)
				min=xx1;//min path length get the path length of prev traversal
				casen=18;//keeps track of which path that will need to be printed
				if(xx1==width+height-1)
					golden=true;
			}//(37.37.1.0.0.0)
		}//(37.37.0.0.0.0)
		else if(!tempb)//if tempb is not true yet the function failed to find a path then there is no path
		{//(37.38.0.0.0.0)
			nopath=true;
		}//(37.38.0.0.0.0)
		//#total_recursions=total_recursions+reccount;
		//#out<<"|"<<setw(4)<<reccount;
		xx1=0;//perpares path length for next traverse
		tempb=false;//special bool to correct a timing issue
		reccount=0;//prepares reccount for next traversal
		if(golden||nopath){}
		else if(neswtraverse(nesw, 0, 0, 'a',  width,  height,xx1,min,tempb,reccount))//if a path is found tests tests to see if the path is shorter than the already min path
		{//(37.39.0.0.0.0)
			if(xx1<min)//test to see if previous path length is less than current min
			{//(37.39.1.0.0.0)
				min=xx1;//min path length get the path length of prev traversal
				casen=19;//keeps track of which path that will need to be printed
				if(xx1==width+height-1)
					golden=true;
			}//(37.39.1.0.0.0)
		}//(37.39.0.0.0.0)
		else if(!tempb)//if tempb is not true yet the function failed to find a path then there is no path
		{//(37.40.0.0.0.0)
			nopath=true;
		}//(37.40.0.0.0.0)
		//#total_recursions=total_recursions+reccount;
		//#out<<"|"<<setw(4)<<reccount;
		xx1=0;//perpares path length for next traverse
		tempb=false;//special bool to correct a timing issue
		reccount=0;//prepares reccount for next traversal
		if(golden||nopath){}
		else if(newstraverse(news, 0, 0, 'a',  width,  height,xx1,min,tempb,reccount))//if a path is found tests tests to see if the path is shorter than the already min path
		{//(37.41.0.0.0.0)
			if(xx1<min)//test to see if previous path length is less than current min
			{//(37.41.1.0.0.0)
				min=xx1;//min path length get the path length of prev traversal
				casen=20;//keeps track of which path that will need to be printed
				if(xx1==width+height-1)
					golden=true;
			}//(37.41.1.0.0.0)
		}//(37.41.0.0.0.0)
		else if(!tempb)//if tempb is not true yet the function failed to find a path then there is no path
		{//(37.42.0.0.0.0)
			nopath=true;
		}//(37.42.0.0.0.0)
		//#total_recursions=total_recursions+reccount;
		//#out<<"|"<<setw(4)<<reccount;
		xx1=0;//perpares path length for next traverse
		tempb=false;//special bool to correct a timing issue
		reccount=0;//prepares reccount for next traversal
		if(golden||nopath){}
		else if(nwestraverse(nwes, 0, 0, 'a',  width,  height,xx1,min,tempb,reccount))//if a path is found tests tests to see if the path is shorter than the already min path
		{//(37.43.0.0.0.0)
			if(xx1<min)//test to see if previous path length is less than current min
			{//(37.43.1.0.0.0)
				min=xx1;//min path length get the path length of prev traversal
				casen=21;//keeps track of which path that will need to be printed
				if(xx1==width+height-1)
					golden=true;
			}//(37.43.1.0.0.0)
		}//(37.43.0.0.0.0)
		else if(!tempb)//if tempb is not true yet the function failed to find a path then there is no path
		{//(37.44.0.0.0.0)
			nopath=true;
		}//(37.44.0.0.0.0)
		//#total_recursions=total_recursions+reccount;
		//#out<<"|"<<setw(4)<<reccount;
		xx1=0;//perpares path length for next traverse
		tempb=false;//special bool to correct a timing issue
		reccount=0;//prepares reccount for next traversal
		if(golden||nopath){}
		else if(nwsetraverse(nwse, 0, 0, 'a',  width,  height,xx1,min,tempb,reccount))//if a path is found tests tests to see if the path is shorter than the already min path
		{//(37.45.0.0.0.0)
			if(xx1<min)//test to see if previous path length is less than current min
			{//(37.45.1.0.0.0)
				min=xx1;//min path length get the path length of prev traversal
				casen=22;//keeps track of which path that will need to be printed
				if(xx1==width+height-1)
					golden=true;
			}//(37.45.1.0.0.0)
		}//(37.45.0.0.0.0)
		//#total_recursions=total_recursions+reccount;
		//#out<<"|"<<setw(4)<<reccount;
		xx1=0;//perpares path length for next traverse
		tempb=false;//special bool to correct a timing issue
		reccount=0;//prepares reccount for next traversal
		if(golden||nopath){}
		else if(nswetraverse(nswe, 0, 0, 'a',  width,  height,xx1,min,tempb,reccount))//if a path is found tests tests to see if the path is shorter than the already min path
		{//(37.46.0.0.0.0)
			if(xx1<min)//test to see if previous path length is less than current min
			{//(37.46.1.0.0.0)
				min=xx1;//min path length get the path length of prev traversal
				casen=23;//keeps track of which path that will need to be printed
				if(xx1==width+height-1)
					golden=true;
			}//(37.46.1.0.0.0)
		}//(37.46.0.0.0.0)
		else if(!tempb)//if tempb is not true yet the function failed to find a path then there is no path
		{//(37.47.0.0.0.0)
			nopath=true;
		}//(37.47.0.0.0.0)
		//#total_recursions=total_recursions+reccount;
		//#out<<"|"<<setw(4)<<reccount;
		xx1=0;//perpares path length for next traverse
		tempb=false;//special bool to correct a timing issue
		reccount=0;//prepares reccount for next traversal
		if(golden||nopath){}
		else if(nsewtraverse(nsew, 0, 0, 'a',  width,  height,xx1,min,tempb,reccount))//if a path is found tests tests to see if the path is shorter than the already min path
		{//(37.48.0.0.0.0)
			if(xx1<min)//test to see if previous path length is less than current min
			{//(37.48.1.0.0.0)
				min=xx1;//min path length get the path length of prev traversal
				casen=24;//keeps track of which path that will need to be printed
				if(xx1==width+height-1)
					golden=true;
			}//(37.48.1.0.0.0)
		}//(37.48.0.0.0.0)
		else if(!tempb)//if tempb is not true yet the function failed to find a path then there is no path
		{//(37.49.0.0.0.0)
			nopath=true;
		}//(37.49.0.0.0.0)
		//#total_recursions=total_recursions+reccount;
		//#out<<"|"<<setw(4)<<reccount;
		xx1=0;//perpares path length for next traverse
		tempb=false;//special bool to correct a timing issue
		reccount=0;//prepares reccount for next traversal
		if(golden||nopath){}
		else if(bnewstraverse(bnews, width-1, height-1, 0,  width,  height,xx1,min,tempb,reccount))//if a path is found tests tests to see if the path is shorter than the already min path
		{//(37.50.0.0.0.0)
			if(xx1<min)//test to see if previous path length is less than current min
			{//(37.50.1.0.0.0)
				min=xx1;//min path length get the path length of prev traversal
				casen=25;//keeps track of which path that will need to be printed
				if(xx1==width+height-1)
					golden=true;
			}//(37.50.1.0.0.0)
		}//(37.50.0.0.0.0)
		else if(!tempb)//if tempb is not true yet the function failed to find a path then there is no path
		{//(37.51.0.0.0.0)
			nopath=true;
		}//(37.51.0.0.0.0)
		//#total_recursions=total_recursions+reccount;
		//#out<<"|"<<setw(5)<<reccount;
		xx1=0;//perpares path length for next traverse
		tempb=false;//special bool to correct a timing issue
		reccount=0;//prepares reccount for next traversal
		if(golden||nopath){}
		else if(bwsnetraverse(bwsne, width-1, height-1, 0,  width,  height,xx1,min,tempb,reccount))//if a path is found tests tests to see if the path is shorter than the already min path
		{//(37.52.0.0.0.0)
			if(xx1<min)//test to see if previous path length is less than current min
			{//(37.52.1.0.0.0)
				min=xx1;//min path length get the path length of prev traversal
				casen=26;//keeps track of which path that will need to be printed
				if(xx1==width+height-1)
					golden=true;
			}//(37.52.1.0.0.0)
		}//(37.52.0.0.0.0)
		else if(!tempb)//if tempb is not true yet the function failed to find a path then there is no path
		{//(37.53.0.0.0.0)
			nopath=true;
		}//(37.53.0.0.0.0)
		//#total_recursions=total_recursions+reccount;
		//#out<<"|"<<setw(5)<<reccount;
		xx1=0;//perpares path length for next traverse
		tempb=false;//special bool to correct a timing issue
		reccount=0;//prepares reccount for next traversal
		if(golden||nopath){}
		else if(bswentraverse(bswen, width-1, height-1, 0,  width,  height,xx1,min,tempb,reccount))//if a path is found tests tests to see if the path is shorter than the already min path
		{//(37.54.0.0.0.0)
			if(xx1<min)//test to see if previous path length is less than current min
			{//(37.54.1.0.0.0)
				min=xx1;//min path length get the path length of prev traversal
				casen=27;//keeps track of which path that will need to be printed
				if(xx1==width+height-1)
					golden=true;
			}//(37.54.1.0.0.0)
		}//(37.54.0.0.0.0)
		else if(!tempb)//if tempb is not true yet the function failed to find a path then there is no path
		{//(37.55.0.0.0.0)
			nopath=true;
		}//(37.55.0.0.0.0)
		//#total_recursions=total_recursions+reccount;
		//#out<<"|"<<setw(5)<<reccount;
		xx1=0;//perpares path length for next traverse
		tempb=false;//special bool to correct a timing issue
		reccount=0;//prepares reccount for next traversal
		if(golden||nopath){}
		else if(benswtraverse(bensw, width-1, height-1, 0,  width,  height,xx1,min,tempb,reccount))//if a path is found tests tests to see if the path is shorter than the already min path
		{//(37.56.0.0.0.0)
			if(xx1<min)//test to see if previous path length is less than current min
			{//(37.56.1.0.0.0)
				min=xx1;//min path length get the path length of prev traversal
				casen=28;//keeps track of which path that will need to be printed
				if(xx1==width+height-1)
					golden=true;
			}//(37.56.1.0.0.0)
		}//(37.56.0.0.0.0)
		else if(!tempb)//if tempb is not true yet the function failed to find a path then there is no path
		{//(37.57.0.0.0.0)
			nopath=true;
		}//(37.57.0.0.0.0)
		//#total_recursions=total_recursions+reccount;
		//#out<<"|"<<setw(5)<<reccount;
		xx1=0;//perpares path length for next traverse
		tempb=false;//special bool to correct a timing issue
		reccount=0;//prepares reccount for next traversal
		if(golden||nopath){}
		else if(bsenwtraverse(bsenw, width-1, height-1, 0,  width,  height,xx1,min,tempb,reccount))//if a path is found tests tests to see if the path is shorter than the already min path
		{//(37.58.0.0.0.0)
			if(xx1<min)//test to see if previous path length is less than current min
			{//(37.58.1.0.0.0)
				min=xx1;//min path length get the path length of prev traversal
				casen=29;//keeps track of which path that will need to be printed
				if(xx1==width+height-1)
					golden=true;
			}//(37.58.1.0.0.0)
		}//(37.58.0.0.0.0)
		else if(!tempb)//if tempb is not true yet the function failed to find a path then there is no path
		{//(37.59.0.0.0.0)
			nopath=true;
		}//(37.59.0.0.0.0)
		//#total_recursions=total_recursions+reccount;
		//#out<<"|"<<setw(5)<<reccount;
		xx1=0;//perpares path length for next traverse
		tempb=false;//special bool to correct a timing issue
		reccount=0;//prepares reccount for next traversal
		if(golden||nopath){}
		else if(bnwsetraverse(bnwse, width-1, height-1, 0,  width,  height,xx1,min,tempb,reccount))//if a path is found tests tests to see if the path is shorter than the already min path
		{//(37.60.0.0.0.0)
			if(xx1<min)//test to see if previous path length is less than current min
			{//(37.60.1.0.0.0)
				min=xx1;//min path length get the path length of prev traversal
				casen=30;//keeps track of which path that will need to be printed
				if(xx1==width+height-1)
					golden=true;
			}//(37.60.1.0.0.0)
		}//(37.60.0.0.0.0)
		else if(!tempb)//if tempb is not true yet the function failed to find a path then there is no path
		{//(37.61.0.0.0.0)
			nopath=true;
		}//(37.61.0.0.0.0)
		//#total_recursions=total_recursions+reccount;
		//#out<<"|"<<setw(5)<<reccount;
		xx1=0;//perpares path length for next traverse
		tempb=false;//special bool to correct a timing issue
		reccount=0;//prepares reccount for next traversal
		if(golden||nopath){}
		else if(bwnestraverse(bwnes, width-1, height-1, 0,  width,  height,xx1,min,tempb,reccount))//if a path is found tests tests to see if the path is shorter than the already min path
		{//(37.62.0.0.0.0)
			if(xx1<min)//test to see if previous path length is less than current min
			{//(37.62.1.0.0.0)
				min=xx1;//min path length get the path length of prev traversal
				casen=31;//keeps track of which path that will need to be printed
				if(xx1==width+height-1)
					golden=true;
			}//(37.62.1.0.0.0)
		}//(37.62.0.0.0.0)
		else if(!tempb)//if tempb is not true yet the function failed to find a path then there is no path
		{//(37.63.0.0.0.0)
			nopath=true;
		}//(37.63.0.0.0.0)
		//#total_recursions=total_recursions+reccount;
		//#out<<"|"<<setw(5)<<reccount;
		xx1=0;//perpares path length for next traverse
		tempb=false;//special bool to correct a timing issue
		reccount=0;//prepares reccount for next traversal
		if(golden||nopath){}
		else if(beswntraverse(beswn, width-1, height-1, 0,  width,  height,xx1,min,tempb,reccount))//if a path is found tests tests to see if the path is shorter than the already min path
		{//(37.64.0.0.0.0)
			if(xx1<min)//test to see if previous path length is less than current min
			{//(37.64.1.0.0.0)
				min=xx1;//min path length get the path length of prev traversal
				casen=32;//keeps track of which path that will need to be printed
				if(xx1==width+height-1)
					golden=true;
			}//(37.64.1.0.0.0)
		}//(37.64.0.0.0.0)
		else if(!tempb)//if tempb is not true yet the function failed to find a path then there is no path
		{//(37.65.0.0.0.0)
			nopath=true;
		}//(37.65.0.0.0.0)
		//#total_recursions=total_recursions+reccount;
		//#out<<"|"<<setw(5)<<reccount<<endl;
		if(nopath)//checks to see if all the traversals failed
		{//(37.66.0.0.0.0)
			casen=49;
		}//(37.66.0.0.0.0)
		if(casen!=49)
		{
			a[casen-1]++;
		}
		out<<casen<<endl;
		switch(casen)//these will print out the proper path
		{//(37.67.0.0.0.0)
		case 1:
			if(alltravshown)
			{//(37.67.1.0.0.0)
				printMazes(out,sewn,sewn, senw,snew,snwe, swne, swen, wsen, wsne, wnse, wnes, wens, wesn, ewsn,ewns, enws, ensw, esnw, eswn, nesw, news, nwes, nwse, nswe, nsew,bnews,bwsne, bswen, bensw, bsenw, bnwse, bwnes, beswn,width,height/*#,total_recursions*/);
				//Mazecopy(cc,sewn,height,width);
			}//(37.67.1.0.0.0)
			else
			{//(37.67.2.0.0.0)
				printMaze(out,sewn,width,height);
				//Mazecopy(cc,sewn,height,width);
			}//(37.67.2.0.0.0)
			break;
		case 2:
			if(alltravshown)
			{//(37.67.3.0.0.0)
				printMazes(out,senw,sewn, senw,snew,snwe, swne, swen, wsen, wsne, wnse, wnes, wens, wesn, ewsn,ewns, enws, ensw, esnw, eswn, nesw, news, nwes, nwse, nswe, nsew,bnews,bwsne, bswen, bensw, bsenw, bnwse, bwnes, beswn,width,height/*#,total_recursions*/);
				//Mazecopy(cc,senw,height,width); 
			}//(37.67.3.0.0.0)
			else
			{//(37.67.4.0.0.0)
				printMaze(out,senw,width,height);
				//Mazecopy(cc,senw,height,width); 
			}//(37.67.4.0.0.0)
			break;
		case 3:
			if(alltravshown)
			{//(37.67.5.0.0.0)
				printMazes(out,snew,sewn, senw,snew,snwe, swne, swen, wsen, wsne, wnse, wnes, wens, wesn, ewsn,ewns, enws, ensw, esnw, eswn, nesw, news, nwes, nwse, nswe, nsew,bnews,bwsne, bswen, bensw, bsenw, bnwse, bwnes, beswn,width,height/*#,total_recursions*/);
				//Mazecopy(cc,snew,height,width); 
			}//(37.67.5.0.0.0)
			else
			{//(37.67.6.0.0.0)
				printMaze(out,snew,width,height);
				//Mazecopy(cc,snew,height,width);
			}//(37.67.6.0.0.0)
			break;
		case 4:
			if(alltravshown)
			{//(37.67.7.0.0.0)
				printMazes(out,snwe,sewn, senw,snew,snwe, swne, swen, wsen, wsne, wnse, wnes, wens, wesn, ewsn,ewns, enws, ensw, esnw, eswn, nesw, news, nwes, nwse, nswe, nsew,bnews,bwsne, bswen, bensw, bsenw, bnwse, bwnes, beswn,width,height/*#,total_recursions*/);
				//Mazecopy(cc,snwe,height,width);
			}//(37.67.7.0.0.0)
			else
			{//(37.67.8.0.0.0)
				printMaze(out,snwe,width,height);
				//Mazecopy(cc,snwe,height,width);
			}//(37.67.8.0.0.0)
			break;
		case 5:
			if(alltravshown)
			{//(37.67.9.0.0.0)
				printMazes(out,swne,sewn, senw,snew,snwe, swne, swen, wsen, wsne, wnse, wnes, wens, wesn, ewsn,ewns, enws, ensw, esnw, eswn, nesw, news, nwes, nwse, nswe, nsew,bnews,bwsne, bswen, bensw, bsenw, bnwse, bwnes, beswn,width,height/*#,total_recursions*/);
				//Mazecopy(cc,swne,height,width);
			}//(37.67.9.0.0.0)
			else
			{//(37.67.10.0.0.0)
				printMaze(out,swne,width,height);
				//Mazecopy(cc,swne,height,width);
			}//(37.67.10.0.0.0)
			break;
		case 6:
			if(alltravshown)
			{//(37.67.11.0.0.0)
				printMazes(out,swen,sewn, senw,snew,snwe, swne, swen, wsen, wsne, wnse, wnes, wens, wesn, ewsn,ewns, enws, ensw, esnw, eswn, nesw, news, nwes, nwse, nswe, nsew,bnews,bwsne, bswen, bensw, bsenw, bnwse, bwnes, beswn,width,height/*#,total_recursions*/);
				//Mazecopy(cc,swen,height,width);
			}//(37.67.11.0.0.0)
			else
			{//(37.67.12.0.0.0)
				printMaze(out,swen,width,height);
				//Mazecopy(cc,swen,height,width);
			}//(37.67.12.0.0.0)
			break;
		case 7:
			if(alltravshown)
			{//(37.67.13.0.0.0)
				printMazes(out,wsen,sewn, senw,snew,snwe, swne, swen, wsen, wsne, wnse, wnes, wens, wesn, ewsn,ewns, enws, ensw, esnw, eswn, nesw, news, nwes, nwse, nswe, nsew,bnews,bwsne, bswen, bensw, bsenw, bnwse, bwnes, beswn,width,height/*#,total_recursions*/);
				//Mazecopy(cc,wsen,height,width);
			}//(37.67.13.0.0.0)
			else
			{//(37.67.14.0.0.0)
				printMaze(out,wsen,width,height);
				//Mazecopy(cc,wsen,height,width);
			}//(37.67.14.0.0.0)
			break;
		case 8:
			if(alltravshown)
			{//(37.67.15.0.0.0)
				printMazes(out,wsne,sewn, senw,snew,snwe, swne, swen, wsen, wsne, wnse, wnes, wens, wesn, ewsn,ewns, enws, ensw, esnw, eswn, nesw, news, nwes, nwse, nswe, nsew,bnews,bwsne, bswen, bensw, bsenw, bnwse, bwnes, beswn,width,height/*#,total_recursions*/);
				//Mazecopy(cc,wsne,height,width);
			}//(37.67.15.0.0.0)
			else
			{//(37.67.16.0.0.0)
				printMaze(out,wsne,width,height);
				//Mazecopy(cc,wsne,height,width);
			}//(37.67.16.0.0.0)
			break;
		case 9:
			if(alltravshown)
			{//(37.67.17.0.0.0)
				printMazes(out,wnse,sewn, senw,snew,snwe, swne, swen, wsen, wsne, wnse, wnes, wens, wesn, ewsn,ewns, enws, ensw, esnw, eswn, nesw, news, nwes, nwse, nswe, nsew,bnews,bwsne, bswen, bensw, bsenw, bnwse, bwnes, beswn,width,height/*#,total_recursions*/);
				//Mazecopy(cc,wnse,height,width);
			}//(37.67.17.0.0.0)
			else
			{//(37.67.18.0.0.0)
				printMaze(out,wnse,width,height);
				//Mazecopy(cc,wnse,height,width);
			}//(37.67.18.0.0.0)
			break;
		case 10:
			if(alltravshown)
			{//(37.67.19.0.0.0)
				printMazes(out,wnes,sewn, senw,snew,snwe, swne, swen, wsen, wsne, wnse, wnes, wens, wesn, ewsn,ewns, enws, ensw, esnw, eswn, nesw, news, nwes, nwse, nswe, nsew,bnews,bwsne, bswen, bensw, bsenw, bnwse, bwnes, beswn,width,height/*#,total_recursions*/);
				//Mazecopy(cc,wnes,height,width);
			}//(37.67.19.0.0.0)
			else
			{//(37.67.20.0.0.0)
				printMaze(out,wnes,width,height);
				//Mazecopy(cc,wnes,height,width);
			}//(37.67.20.0.0.0)
			break;
		case 11:
			if(alltravshown)
			{//(37.67.21.0.0.0)
				printMazes(out,wens,sewn, senw,snew,snwe, swne, swen, wsen, wsne, wnse, wnes, wens, wesn, ewsn,ewns, enws, ensw, esnw, eswn, nesw, news, nwes, nwse, nswe, nsew,bnews,bwsne, bswen, bensw, bsenw, bnwse, bwnes, beswn,width,height/*#,total_recursions*/);
				//Mazecopy(cc,wens,height,width);
			}//(37.67.21.0.0.0)
			else
			{//(37.67.22.0.0.0)
				printMaze(out,wens,width,height);
				//Mazecopy(cc,wens,height,width);
			}//(37.67.22.0.0.0)
			break;
		case 12:
			if(alltravshown)
			{//(37.67.23.0.0.0)
				printMazes(out,wesn,sewn, senw,snew,snwe, swne, swen, wsen, wsne, wnse, wnes, wens, wesn, ewsn,ewns, enws, ensw, esnw, eswn, nesw, news, nwes, nwse, nswe, nsew,bnews,bwsne, bswen, bensw, bsenw, bnwse, bwnes, beswn,width,height/*#,total_recursions*/);
				//Mazecopy(cc,wesn,height,width);
			}//(37.67.23.0.0.0)
			else
			{//(37.67.24.0.0.0)
				printMaze(out,wesn,width,height);
				//Mazecopy(cc,wesn,height,width);
			}//(37.67.24.0.0.0)
			break;
		case 13:
			if(alltravshown)
			{//(37.67.25.0.0.0)
				printMazes(out,ewsn,sewn, senw,snew,snwe, swne, swen, wsen, wsne, wnse, wnes, wens, wesn, ewsn,ewns, enws, ensw, esnw, eswn, nesw, news, nwes, nwse, nswe, nsew,bnews,bwsne, bswen, bensw, bsenw, bnwse, bwnes, beswn,width,height/*#,total_recursions*/);
				//Mazecopy(cc,ewsn,height,width);
			}//(37.67.25.0.0.0)
			else
			{//(37.67.26.0.0.0)
				printMaze(out,ewsn,width,height);
				//Mazecopy(cc,ewsn,height,width);
			}//(37.67.26.0.0.0)
			break;
		case 14:
			if(alltravshown)
			{//(37.67.27.0.0.0)
				printMazes(out,ewns,sewn, senw,snew,snwe, swne, swen, wsen, wsne, wnse, wnes, wens, wesn, ewsn,ewns, enws, ensw, esnw, eswn, nesw, news, nwes, nwse, nswe, nsew,bnews,bwsne, bswen, bensw, bsenw, bnwse, bwnes, beswn,width,height/*#,total_recursions*/);
				//Mazecopy(cc,ewns,height,width);
			}//(37.67.27.0.0.0)
			else
			{//(37.67.28.0.0.0)
				printMaze(out,ewns,width,height);
				//Mazecopy(cc,ewns,height,width);
			}//(37.67.28.0.0.0)
			break;
		case 15:
			if(alltravshown)
			{//(37.67.29.0.0.0)
				printMazes(out,enws,sewn, senw,snew,snwe, swne, swen, wsen, wsne, wnse, wnes, wens, wesn, ewsn,ewns, enws, ensw, esnw, eswn, nesw, news, nwes, nwse, nswe, nsew,bnews,bwsne, bswen, bensw, bsenw, bnwse, bwnes, beswn,width,height/*#,total_recursions*/);
				//Mazecopy(cc,enws,height,width);
			}//(37.67.29.0.0.0)
			else
			{//(37.67.30.0.0.0)
				printMaze(out,enws,width,height);
				//Mazecopy(cc,enws,height,width);
			}//(37.67.30.0.0.0)
			break;
		case 16:
			if(alltravshown)
			{//(37.67.31.0.0.0)
				printMazes(out,ensw,sewn, senw,snew,snwe, swne, swen, wsen, wsne, wnse, wnes, wens, wesn, ewsn,ewns, enws, ensw, esnw, eswn, nesw, news, nwes, nwse, nswe, nsew,bnews,bwsne, bswen, bensw, bsenw, bnwse, bwnes, beswn,width,height/*#,total_recursions*/);
				//Mazecopy(cc,ensw,height,width);
			}//(37.67.31.0.0.0)
			else
			{//(37.67.32.0.0.0)
				printMaze(out,ensw,width,height);
				//Mazecopy(cc,ensw,height,width);
			}//(37.67.32.0.0.0)
			break;
		case 17:
			if(alltravshown)
			{//(37.67.33.0.0.0)
				printMazes(out,esnw,sewn, senw,snew,snwe, swne, swen, wsen, wsne, wnse, wnes, wens, wesn, ewsn,ewns, enws, ensw, esnw, eswn, nesw, news, nwes, nwse, nswe, nsew,bnews,bwsne, bswen, bensw, bsenw, bnwse, bwnes, beswn,width,height/*#,total_recursions*/);
				//Mazecopy(cc,esnw,height,width);
			}//(37.67.33.0.0.0)
			else
			{//(37.67.34.0.0.0)
				printMaze(out,esnw,width,height);
				//Mazecopy(cc,esnw,height,width);
			}//(37.67.34.0.0.0)
			break;
		case 18:
			if(alltravshown)
			{//(37.67.35.0.0.0)
				printMazes(out,eswn,sewn, senw,snew,snwe, swne, swen, wsen, wsne, wnse, wnes, wens, wesn, ewsn,ewns, enws, ensw, esnw, eswn, nesw, news, nwes, nwse, nswe, nsew,bnews,bwsne, bswen, bensw, bsenw, bnwse, bwnes, beswn,width,height/*#,total_recursions*/);
				//Mazecopy(cc,eswn,height,width);
			}//(37.67.35.0.0.0)
			else
			{//(37.67.36.0.0.0)
				printMaze(out,eswn,width,height);
				//Mazecopy(cc,eswn,height,width);
			}//(37.67.36.0.0.0)
			break;
		case 19:
			if(alltravshown)
			{//(37.67.37.0.0.0)
				printMazes(out,nesw,sewn, senw,snew,snwe, swne, swen, wsen, wsne, wnse, wnes, wens, wesn, ewsn,ewns, enws, ensw, esnw, eswn, nesw, news, nwes, nwse, nswe, nsew,bnews,bwsne, bswen, bensw, bsenw, bnwse, bwnes, beswn,width,height/*#,total_recursions*/);
				//Mazecopy(cc,nesw,height,width);
			}//(37.67.37.0.0.0)
			else
			{//(37.67.38.0.0.0)
				printMaze(out,nesw,width,height);
				//Mazecopy(cc,nesw,height,width);
			}//(37.67.38.0.0.0)
			break;
		case 20:
			if(alltravshown)
			{//(37.67.39.0.0.0)
				printMazes(out,news,sewn, senw,snew,snwe, swne, swen, wsen, wsne, wnse, wnes, wens, wesn, ewsn,ewns, enws, ensw, esnw, eswn, nesw, news, nwes, nwse, nswe, nsew,bnews,bwsne, bswen, bensw, bsenw, bnwse, bwnes, beswn,width,height/*#,total_recursions*/);
				//Mazecopy(cc,news,height,width);
			}//(37.67.39.0.0.0)
			else
			{//(37.67.40.0.0.0)
				printMaze(out,news,width,height);
				//Mazecopy(cc,news,height,width);
			}//(37.67.40.0.0.0)
			break;
		case 21:
			if(alltravshown)
			{//(37.67.41.0.0.0)
				printMazes(out,nwes,sewn, senw,snew,snwe, swne, swen, wsen, wsne, wnse, wnes, wens, wesn, ewsn,ewns, enws, ensw, esnw, eswn, nesw, news, nwes, nwse, nswe, nsew,bnews,bwsne, bswen, bensw, bsenw, bnwse, bwnes, beswn,width,height/*#,total_recursions*/);
				//Mazecopy(cc,nwes,height,width);
			}//(37.67.41.0.0.0)
			else
			{//(37.67.42.0.0.0)
				printMaze(out,nwes,width,height);
				//Mazecopy(cc,nwes,height,width);
			}//(37.67.42.0.0.0)
			break;
		case 22:
			if(alltravshown)
			{//(37.67.43.0.0.0)
				printMazes(out,nwse,sewn, senw,snew,snwe, swne, swen, wsen, wsne, wnse, wnes, wens, wesn, ewsn,ewns, enws, ensw, esnw, eswn, nesw, news, nwes, nwse, nswe, nsew,bnews,bwsne, bswen, bensw, bsenw, bnwse, bwnes, beswn,width,height/*#,total_recursions*/);
				//Mazecopy(cc,nwse,height,width);
			}//(37.67.43.0.0.0)
			else
			{//(37.67.44.0.0.0)
				printMaze(out,nwse,width,height);
				//Mazecopy(cc,nwse,height,width);
			}//(37.67.44.0.0.0)
			break;
		case 23:
			if(alltravshown)
			{//(37.67.45.0.0.0)
				printMazes(out,nswe,sewn, senw,snew,snwe, swne, swen, wsen, wsne, wnse, wnes, wens, wesn, ewsn,ewns, enws, ensw, esnw, eswn, nesw, news, nwes, nwse, nswe, nsew,bnews,bwsne, bswen, bensw, bsenw, bnwse, bwnes, beswn,width,height/*#,total_recursions*/);
				//Mazecopy(cc,nswe,height,width);
			}//(37.67.45.0.0.0)
			else
			{//(37.67.46.0.0.0)
				printMaze(out,nswe,width,height);
				//Mazecopy(cc,nswe,height,width);
			}//(37.67.46.0.0.0)
			break;
		case 24:
			if(alltravshown)
			{//(37.67.47.0.0.0)
				printMazes(out,nsew,sewn, senw,snew,snwe, swne, swen, wsen, wsne, wnse, wnes, wens, wesn, ewsn,ewns, enws, ensw, esnw, eswn, nesw, news, nwes, nwse, nswe, nsew,bnews,bwsne, bswen, bensw, bsenw, bnwse, bwnes, beswn,width,height/*#,total_recursions*/);
				//Mazecopy(cc,nsew,height,width);
			}//(37.67.47.0.0.0)
			else
			{//(37.67.48.0.0.0)
				printMaze(out,nsew,width,height);
				//Mazecopy(cc,nsew,height,width);
			}//(37.67.48.0.0.0)
			break;
		case 25:
			if(alltravshown)
			{//(37.67.49.0.0.0)
				printMazes(out,bnews,sewn, senw,snew,snwe, swne, swen, wsen, wsne, wnse, wnes, wens, wesn, ewsn,ewns, enws, ensw, esnw, eswn, nesw, news, nwes, nwse, nswe, nsew,bnews,bwsne, bswen, bensw, bsenw, bnwse, bwnes, beswn,width,height/*#,total_recursions*/);
				//Mazecopy(cc,bnews,height,width);
			}//(37.67.49.0.0.0)
			else
			{//(37.67.50.0.0.0)
				printMaze(out,bnews,width,height);
				//Mazecopy(cc,bnews,height,width);
			}//(37.67.50.0.0.0)
			break;
		case 26:
			if(alltravshown)
			{//(37.67.51.0.0.0)
				printMazes(out,bwsne,sewn, senw,snew,snwe, swne, swen, wsen, wsne, wnse, wnes, wens, wesn, ewsn,ewns, enws, ensw, esnw, eswn, nesw, news, nwes, nwse, nswe, nsew,bnews,bwsne, bswen, bensw, bsenw, bnwse, bwnes, beswn,width,height/*#,total_recursions*/);
				//Mazecopy(cc,bwsne,height,width);
			}//(37.67.51.0.0.0)
			else
			{//(37.67.52.0.0.0)
				printMaze(out,bwsne,width,height);
				//Mazecopy(cc,bwsne,height,width);
			}//(37.67.52.0.0.0)
			break;
		case 27:
			if(alltravshown)
			{//(37.67.53.0.0.0)
				printMazes(out,bswen,sewn, senw,snew,snwe, swne, swen, wsen, wsne, wnse, wnes, wens, wesn, ewsn,ewns, enws, ensw, esnw, eswn, nesw, news, nwes, nwse, nswe, nsew,bnews,bwsne, bswen, bensw, bsenw, bnwse, bwnes, beswn,width,height/*#,total_recursions*/);
				//Mazecopy(cc,bswen,height,width);
			}//(37.67.53.0.0.0)
			else
			{//(37.67.54.0.0.0)
				printMaze(out,bswen,width,height);
				//Mazecopy(cc,bswen,height,width);
			}//(37.67.54.0.0.0)
			break;
		case 28:
			if(alltravshown)
			{//(37.67.55.0.0.0)
				printMazes(out,bensw,sewn, senw,snew,snwe, swne, swen, wsen, wsne, wnse, wnes, wens, wesn, ewsn,ewns, enws, ensw, esnw, eswn, nesw, news, nwes, nwse, nswe, nsew,bnews,bwsne, bswen, bensw, bsenw, bnwse, bwnes, beswn,width,height/*#,total_recursions*/);
				//Mazecopy(cc,bensw,height,width);
			}//(37.67.55.0.0.0)
			else
			{//(37.67.56.0.0.0)
				printMaze(out,bensw,width,height);
				//Mazecopy(cc,bensw,height,width);
			}//(37.67.56.0.0.0)
			break;
		case 29:
			if(alltravshown)
			{//(37.67.57.0.0.0)
				printMazes(out,bsenw,sewn, senw,snew,snwe, swne, swen, wsen, wsne, wnse, wnes, wens, wesn, ewsn,ewns, enws, ensw, esnw, eswn, nesw, news, nwes, nwse, nswe, nsew,bnews,bwsne, bswen, bensw, bsenw, bnwse, bwnes, beswn,width,height/*#,total_recursions*/);
				//Mazecopy(cc,bsenw,height,width);
			}//(37.67.57.0.0.0)
			else
			{//(37.67.58.0.0.0)
				printMaze(out,bsenw,width,height);
				//Mazecopy(cc,bsenw,height,width);
			}//(37.67.58.0.0.0)
			break;
		case 30:
			if(alltravshown)
			{//(37.67.59.0.0.0)
				printMazes(out,bnwse,sewn, senw,snew,snwe, swne, swen, wsen, wsne, wnse, wnes, wens, wesn, ewsn,ewns, enws, ensw, esnw, eswn, nesw, news, nwes, nwse, nswe, nsew,bnews,bwsne, bswen, bensw, bsenw, bnwse, bwnes, beswn,width,height/*#,total_recursions*/);
				//Mazecopy(cc,bnwse,height,width);
			}//(37.67.59.0.0.0)
			else
			{//(37.67.60.0.0.0)
				printMaze(out,bnwse,width,height);
				//Mazecopy(cc,bnwse,height,width);
			}//(37.67.60.0.0.0)
			break;
		case 31:
			if(alltravshown)
			{//(37.67.61.0.0.0)
				printMazes(out,bwnes,sewn, senw,snew,snwe, swne, swen, wsen, wsne, wnse, wnes, wens, wesn, ewsn,ewns, enws, ensw, esnw, eswn, nesw, news, nwes, nwse, nswe, nsew,bnews,bwsne, bswen, bensw, bsenw, bnwse, bwnes, beswn,width,height/*#,total_recursions*/);
				//Mazecopy(cc,bwnes,height,width);
			}//(37.67.61.0.0.0)
			else
			{//(37.67.62.0.0.0)
				printMaze(out,bwnes,width,height);
				//Mazecopy(cc,bwnes,height,width);
			}//(37.67.62.0.0.0)
			break;
		case 32:
			if(alltravshown)
			{//(37.67.63.0.0.0)
				printMazes(out,beswn,sewn, senw,snew,snwe, swne, swen, wsen, wsne, wnse, wnes, wens, wesn, ewsn,ewns, enws, ensw, esnw, eswn, nesw, news, nwes, nwse, nswe, nsew,bnews,bwsne, bswen, bensw, bsenw, bnwse, bwnes, beswn,width,height/*#,total_recursions*/);
				//Mazecopy(cc,beswn,height,width);
			}//(37.67.63.0.0.0)
			else
			{//(37.67.64.0.0.0)
				printMaze(out,beswn,width,height);
				//Mazecopy(cc,beswn,height,width);
			}//(37.67.64.0.0.0)
			break;
		case 49:
			if(alltravshown)
			{//(37.67.65.0.0.0)
				printMazes(out,bsenw,sewn, senw,snew,snwe, swne, swen, wsen, wsne, wnse, wnes, wens, wesn, ewsn,ewns, enws, ensw, esnw, eswn, nesw, news, nwes, nwse, nswe, nsew,bnews,bwsne, bswen, bensw, bsenw, bnwse, bwnes, beswn,width,height/*#,total_recursions*/);
				//Mazecopy(cc,bsenw,height,width);
			}//(37.67.65.0.0.0)
			else
			{//(37.67.66.0.0.0)
				printMaze(out,bsenw,width,height);
				//Mazecopy(cc,bsenw,height,width);
			}//(37.67.66.0.0.0)
			break;
		}//(37.67.0.0.0.0)
		return 0/*#total_recursions*/;
}//(37.0.0.0.0.0)
void SolverMode(const bool rand)
{//(38.0.0.0.0.0)
	ara count;
	for(int x=0;x<32;x++)
		count[x]=0;
	ifstream in;
	ofstream out;
	//#int total_recursions=0;//this is for my benifit so I can see how many times my methods perform recursions
	if(rand)
	{//(38.1.0.0.0.0)
		int numOfMazes=0;//number of mazes the user wishes to create.
		string str="";//inpit string for 
		cout<<"Solver Menu:\nHow Many mazes would you like to create?\nkeep in mind that very large numbers of mazes will take some time.\nNumber:";
		while (true) 
		{//(38.1.1.0.0.0)
			getline(cin, str);
			stringstream myStream(str);
			if ((myStream >> numOfMazes)&&numOfMazes>=0)
				break;
			cout<<"^invalid^\nNumber:";
		}//(38.1.1.0.0.0)
		if(numOfMazes==0)
			return;
		randommazes(numOfMazes);
		try
		{//(38.1.2.0.0.0)
			in.open("randmaze.in");
		}//(38.1.2.0.0.0)
		catch(const std::exception&)
		{//(38.1.3.0.0.0)
			cout<<"error in opening \"randmaze.in\"";
			return;
		}//(38.1.3.0.0.0)
	}//(38.1.0.0.0.0)
	else
	{//(38.2.0.0.0.0)
		try
		{//(38.2.1.0.0.0)
			in.open("maze.in");
		}//(38.2.1.0.0.0)
		catch(const std::exception&)
		{//(38.2.2.0.0.0)
			cout<<"error in opening \"maze.in\"";
			return;
		}//(38.2.2.0.0.0)
	}//(38.2.0.0.0.0)
	try
	{//(38.3.0.0.0.0)
		out.open("maze.out");
	}//(38.3.0.0.0.0)
	catch(const std::exception&)
	{//(38.4.0.0.0.0)
		cout<<"error in opening \"maze.out\"";
		return;
	}//(38.4.0.0.0.0)
	int choice;
	bool onlyshort, oneatatime,nopath=false;
	cout<<"Solver Menu:\n0) Main Menu\n1) Only write out shortest traversal to file(EXTREME SPEED)\n2) Write out all traversals to file(a little slower)";
	cout<<"\nChoice:";
	string str="";
	while (true) 
	{//(38.5.0.0.0.0)
		getline(cin, str);
		stringstream myStream(str);
		if (myStream >> choice&&(choice<=2&&choice>=0))
			break;
		cout<<"^invalid^\nChoice:";
	}//(38.5.0.0.0.0)
	switch(choice)
	{//(38.6.0.0.0.0)
		case 0:
			return;
		case 1:
			onlyshort=true;
			choice=1;
			break;
		case 2:
			onlyshort=false;
			choice=1;
			break;
		default:
			cout<<"error";
			return;
	}//(38.6.0.0.0.0)
	cout<<"Solver Menu:\n0) Main Menu\n1) Solve one at a time\n2) Solve all now";
	cout<<"\nChoice:";
	while (true) 
	{//(38.7.0.0.0.0)
		getline(cin, str);
		stringstream myStream(str);
		if (myStream >> choice&&(choice<=2&&choice>=0))
			break;
		cout<<"^invalid^\nChoice:";
	}//(38.7.0.0.0.0)
	switch(choice)
	{//(38.8.0.0.0.0)
		case 0:
			return;
		case 1:
			oneatatime=true;
			choice=1;
			break;
		case 2:
			oneatatime=false;
			choice=1;
			break;
		default:
			cout<<"error";
			return;
	}//(38.8.0.0.0.0)
	if(choice==1)
	{//(38.9.0.0.0.0)
		maze cc;
		int h;
		int w;
		int mazenum=1;
		while(!in.eof())//loop to read entire file
		{//(38.9.1.0.0.0)
			h=0;
			w=0;
			in>>h;
			in>>w;
			if(h<=10&&h>0&&w<=10&&w>0)//makes sure that the maze dimensions are acceptable
			{//(38.9.1.1.0.0)
				for(int y=0;y<h;y++)//builds maze
					for(int x=0;x<w;x++)
						in>>cc[x][y];
				cout<<"maze "<<mazenum<<": unsolved\n";
				//printMaze(cout,cc,w,h);
				cout<<"maze "<<mazenum<<": solved\n";
				out<<"maze "<<mazenum<<":\n";
				/*#total_recursions=total_recursions+*/Solve(count,out,!onlyshort,nopath,cc,h,w);
				//printMaze(cout,cc,w,h);
				if(nopath)
					cout<<"no path\n";
				if(oneatatime)
				{//(38.9.1.1.1.0)
					cout<<"Continue?\n1)yes\n2)no\nChoice:";
					string str="";
					while (true) 
					{//(38.9.1.1.1.1)
						getline(cin, str);
						stringstream myStream(str);
						if (myStream >> choice&&(choice==2||choice==1))
							break;
						cout<<"^invalid^\nChoice:";
					}//(38.9.1.1.1.1)
					if(choice==2)
					{//(38.9.1.1.1.2)
						cout<<"you may open the file \"maze.out\" for the solutions\n";
						return;
					}//(38.9.1.1.1.2)
				}//(38.9.1.1.1.0)
				mazenum++;
			}//(38.9.1.1.0.0)
		}//(38.9.1.0.0.0)
	}//(38.9.0.0.0.0)
	out<<"\n";
	for(int x=0;x<32;x++)
	{
		out<<(x+1)<<":"<<count[x]<<" | ";
	}
	//#out<<"\nTotal Recursions performed:"<<total_recursions;
	cout<<"you may open the file \"maze.out\" for the solutions\n";
	in.close();
	out.close();
}//(38.0.0.0.0.0)
int main()
{//(39.0.0.0.0.0)
	cout<<"Welcome to the Maze-O-mazer!\n";
	int choice;
	while(true)
	{//(39.1.0.0.0.0)
		cout<<"Main Menu:\n0)Exit\n1) Solve the preset Mazes from the file \"maze.in\"\n2) Solve random mazes that will be generated in the file \"randmaze.in\"";
		cout<<"\nChoice:";
		string str="";
		while (true) //this loop allows for clumsy user inputs shuch as chars and invalid numbers 
		{//(39.1.1.0.0.0)
			getline(cin, str);
			stringstream myStream(str);
			if (myStream >> choice&&(choice<=2&&choice>=0))
				break;
			cout<<"^invalid^\nChoice:";
		}//(39.1.1.0.0.0)
		switch(choice)
		{//(39.1.2.0.0.0)
			case 1:
				SolverMode(false);
				break;
			case 2:
				SolverMode(true);
				break;
			default:
				cout<<"GoodBye\n";
				return 0;
		}//(39.1.2.0.0.0)
	}//(39.1.0.0.0.0)
}//(39.0.0.0.0.0)
