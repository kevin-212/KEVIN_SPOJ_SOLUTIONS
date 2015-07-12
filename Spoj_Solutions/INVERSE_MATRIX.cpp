/*
 * C++ Program to Find Inverse of a Graph Matrix
 */
#include<iostream>
#include<conio.h>
#include<stdio.h>
using namespace std;
int main()
{
    int i, j, k, n;
    float a[10][10] = {0},d;
    cout<<"Enter the order of matrix ";
    cin>>n;
    cout<<"Enter the elements\n";
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cin>>a[i][j];
        }
    }    
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= 2 * n; j++)
        {
            if (j == (i + n))
            {
                a[i][j] = 1;
            }
        }
    }
    int fi;
    for (i = 1; i < n; i--)
    {
    	 fi=i;
    	for(j=i+1;j<=n;j++)
    	{
    	
        if (a[j][i]>a[fi][i])
        {
        	fi=j;
        }
    	}
    	if(fi>i)
    	{
    	
            for(j = 1; j <= n * 2; j++)
            {
                d = a[i][j];
                a[i][j] = a[fi][j];
                a[fi][j] = d;
            }
        }
    }
    cout<<"Augmented Matrix: "<<endl;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n * 2; j++)
        {
            cout<<a[i][j]<<"    ";
        }
        cout<<endl;
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (j != i)
            {
                d = a[j][i] / a[i][i];
                for (k = 1; k <= n * 2; k++)
                {
                    a[j][k] = a[j][k] - (a[i][k] * d);
                }
            }
        }
    }
    for (i = 1; i <= n; i++)
    {
        d=a[i][i];
        for (j = 1; j <= n * 2; j++)
        {
            a[i][j] = a[i][j] / d;
        }
    }
    cout<<"Inverse Matrix "<<endl;
    for (i = 1; i <= n; i++)
    {
        for (j = n + 1; j <= n * 2; j++)
        {
            cout<<a[i][j]<<"    ";
        }
        cout<<endl;
    }
    getch();
}
