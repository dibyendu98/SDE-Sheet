#include<iostream>
#include<vector>
using namespace std;


void NaiveApproach(vector<vector<int>> &arr)
{

    for(int i=0;i<arr.size();i++)
    {
        for(int j=0;j<arr[i].size();j++)
        {
            if(arr[i][j]==0)
            {
                // marking the row of the o element as -1

                for(int k=0;k<arr[i].size();k++) arr[i][k]=-1;

                // marking the col of the o element as -1

                for(int k=0;k<arr.size();k++) arr[k][j]=-1;
                

            }
        }
    }

    // converting all -1 to 0

    for(int i=0;i<arr.size();i++)
    {
        for(int j=0;j<arr[i].size();j++)
        {
            if(arr[i][j]==-1)arr[i][j]=0;
        }
    }
}

// Better Approach using 2 extra array

void Better(vector<vector<int>> &arr)
{
    int r=arr.size();
    int c=arr[0].size();
    vector<int>row(r,0);
    vector<int>col(c,0);

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(arr[i][j]==0)
                {
                    row[i]=1;
                    col[j]=1;
                }
        }
    }

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(row[i] || col[j])
               arr[i][j]=0;
        }
    }

//   for(int num : row)cout<<num<<" ";

//   for(int num : col)cout<<num<<" ";


}


void optimized(vector<vector<int>> & arr)
{
    int col=0;

    int r=arr.size();
    int c=arr[0].size();


    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(arr[i][j]==0)
            {
                if(j==0)
                  col=1;
                else
                arr[0][j]=0;

               arr[i][0]=0;
            }
        }
    }

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(arr[i][0]==0 || arr[0][j]==0 || (j==0 && col==1))
                arr[i][j]=0;
        }
    }
}

void show(vector<vector<int>> &arr)
{
    for(vector<int> t:arr)
    {
        for(int num:t)cout<<num<<" ";
        cout<<endl;
    }
}

int main()
{
   
    vector<vector<int>> arr={{1 ,1, 1,1},
                             {1 , 0 ,1,1},
                             {1 , 1 , 1,0}};
    // int row,col;
    // cin>>row>>col;
    // row=3;
    // col=3;
    // arr


    // for(int i=0;i<row;i++)
    // {
    //     vector<int>temp(col,0);
    //     for(int j=0;j<col;j++)
    //     {
    //         cin>>temp[j];
    //     }
    //     arr.push_back(temp);
    // }


cout<<"Input Matrix :=> "<<endl;
show(arr);

// NaiveApproach(arr);
// Better(arr);
optimized(arr);

cout<<"Modified Matrix :=> "<<endl;
show(arr);


    


    return 0;
}
