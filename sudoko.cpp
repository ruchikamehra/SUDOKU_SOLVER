#include<iostream>
using namespace std;
void enter_sudoku(int su[][9])
{
    int i,j;
  for(i=0; i<9; i++)
        {
            for(j=0; j<9; j++)
            {
                cin>>su[i][j];
            }
        }

}
bool check_sudoku(int su[][9])
{
  int row=0,col=0,i,j,m,n;
  while(row<=8 && col<=9)
  {
	for(i=0;i<9;i++)
	{
		if(su[row][i]>0)
		{
			for(j=0;j<9;j++)
			{
				if(su[row][i]==su[row][j] && i!=j)
				{
					return false;
				}
			}
		}
	}
	for(i=0;i<9;i++)
	{
		if(su[i][col]>0)
		{
			for(j=0;j<9;j++)
			{
				if(su[i][col]==su[j][col] && i!=j)
				{
					return false;
				}
			}
		}
	}

	int sr=row-row%3;
	int sc=col-col%3;

	for(i=sr;i<sr+3;i++)
	{
		for(j=sc;j<sc+3;j++)
		{
			if(su[i][j]>0)
			{
				for(m=sr;m<sr+3;m++)
				{
					for(n=sc;n<sc+3;n++)
					{
						if(su[i][j]==su[m][n] && i!=m && j!=n)
						{
							return false;
						}
					}
				}
			}
		}
	}

	row++;
	col++;
  }

  return true;
}

bool unfilled_space(int su[][9], int &row, int & col)
{
  for(row=0; row<9; row++)
        {
            for(col=0; col<9; col++)
            {
                if(su[row][col]==0)
                    return true;
            }
        }
        return false;
}
bool checkrow( int su[][9],int x,int row)
{
    int i;
    for(i=0; i<9; i++)
    {
        if(su[row][i]==x)
            return false;
    }
    return true;
}
bool checkcol(int su[][9],int x,int col)
{
    int i;
    for(i=0; i<9; i++)
    {
        if(su[i][col]==x)
            return false;
    }
    return true;
}
bool checkbox(int su[][9],int row1,int col1,int x)
{
    int i,j;
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            if(su[i+row1][j+col1]==x)
                return false;
        }
    }
    return true;
}
bool check_condition(int su[][9],int row,int col,int x)
{
     if(checkrow(su,x,row)== true && checkcol(su,x,col)== true && checkbox(su,row-(row%3),col-(col%3),x)==true)
                        {
                            return true;
                        }
                        return false;
}

bool sudoku(int su[][9])
{
    int row,col,x;
    if(!unfilled_space(su,row,col))
        return true;
    for(x=1;x<=9;x++)
    {
         checkrow(su,x,row);
         checkcol(su,x,col);
         checkbox(su,row-(row%3),col-(col%3),x);
         if(check_condition(su,row,col,x)==true)
         {
             su[row][col]=x;
            if(sudoku(su))
               return true;
           su[row][col]=0;

    }
}
return false;
}


    int main()
    {
        int i,j;
        int  su[9][9];
        enter_sudoku(su);
        if(check_sudoku(su)==true)
        {
            if(sudoku(su)==true)
            {
        for(i=0;i<9;i++)
        {
            for(j=0;j<9;j++)
            {
                cout<<su[i][j]<<" ";
            }
            cout<<endl;
        }
            }
           else{
            cout<<"no solution for this sudoku";

        }
        }
        else
        {
            cout<<"invalid sudoku ,kindly enter a correct sudoku";
            while(!check_sudoku(su))
		{
		    enter_sudoku(su);
		}
        if(check_sudoku(su))
	    {
       	    if(sudoku(su))
       	    {
		        for(i=0;i<9;i++)
        {
            for(j=0;j<9;j++)
            {
                cout<<su[i][j]<<" ";
            }
            cout<<endl;
        }
         	}
       	    else
	        {
	     	    cout<<"Solution does not exist!! Try another sudoku..\n";
         	}
        }
	}
	return 0;
        }


