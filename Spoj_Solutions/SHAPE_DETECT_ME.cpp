#include<stdio.h>
#include<stdlib.h>

#define MAX(a,b) (a)>=(b)?(a):(b)
#define MIN(a,b) (a)<=(b)?(a):(b)
#define ABS(a) ((a)>=0?(a):-(a))

#define Get getchar_unlocked()
int getInt(int *n)
{
	char c=0; *n=0;
    while(c<33) { c=Get; if(c==EOF) return -1; }
	while(c>='0' && c<='9') { *n = 10 * (*n) + c-'0'; c=Get; }
	return c=='\n' || c==EOF;
}

typedef struct { int b,g,r; } Pixel;
Pixel **P;
int M,N,**F,*Diff_X,*Diff_Y;

int getInput()
{
	P = (Pixel**) malloc(5000*sizeof(Pixel*));
	P[0] = (Pixel*) malloc(5000*sizeof(Pixel));
	int i=0,flag=0; M=0;
	while(flag<=1)
	{
		flag=getInt(&P[M][i].b);
        if(flag==-1) break;
        getInt(&P[M][i].g);
		flag=getInt(&P[M][i++].r);
		if(flag)
		{
			N=i; M++; i=0;
			P[M] = (Pixel*) malloc(N*sizeof(Pixel));
		}
	}
	F = (int**) malloc(M*sizeof(int*));
	for(i=0;i<M;i++) F[i] = (int*) malloc(N*sizeof(int));
	Diff_X = (int*) malloc(M*sizeof(int));
	Diff_Y = (int*) malloc(N*sizeof(int));
}

int Compare(int r1,int g1,int b1,int r2,int g2,int b2)
{
	int r=ABS(r1-r2),g=ABS(g1-g2),b=ABS(b1-b2);
	int diff=MAX(r,g); diff=MAX(diff,b);
	return diff<60;       // this one may be adjusted too
}

int SimilarPixels(int x,int y)
{
	int i,j,c=0;
	for(i=-1;i<=1;i++)
		for(j=-1;j<=1;j++)
			c+=Compare(P[x][y].r,P[x][y].g,P[x][y].b,P[x+i][y+j].r,P[x+i][y+j].g,P[x+i][y+j].b);
	return c-1;
}

double dev; int symmetric;            // these factors will be used to determine shape

int CheckUniformness(int *A,int s,int e)   // this function calculates these necessary variables
{
    double mean=0; dev=0; int count=0,i,j;
    for(i=s;i<=e;i++) if(A[i]) { mean+=A[i]; count++; }
    mean/=count;
    for(i=s;i<=e;i++) if(A[i]) { double z=A[i]-mean; if(z<0) z=-z; dev+=z; }
    dev/=count;
    symmetric=0; double dev2=0; int count2=0;
    for(i=s,j=e;i<=e && j>=s;)
    {
        if(!A[i]) { i++; continue; }
        if(!A[j]) { j--; continue; }
        dev2 += ABS(A[i]-A[j]);
        count2++; i++; j--;
    }
    dev2/=count2;
    if(dev2<2) symmetric=1;     // adjust this value, if needed
}

int solve()
{
	int i,j,min_X=M-1,max_X=0,min_Y=N-1,max_Y=0;
	for(i=0;i<N;i++) F[0][i]=F[M-1][i]=8;
	for(i=0;i<M;i++) F[i][0]=F[i][N-1]=8;
	for(i=1;i<M-1;i++)
		for(j=1;j<N-1;j++)
		{
			F[i][j]=SimilarPixels(i,j);
			if(F[i][j]<8)
			{
				min_X=MIN(min_X,i); max_X=MAX(max_X,i);
				min_Y=MIN(min_Y,j); max_Y=MAX(max_Y,j);
			}
		}
    if(min_X==M-1 && max_X==0)        // whole image is of one color i.e. a box
    {
        printf("box\n"); return;
    }
	for(i=min_X;i<=max_X;i++)
	{
		int miny=N-1,maxy=0;
		for(j=0;j<N;j++)
			if(F[i][j]<8) { miny=MIN(miny,j); maxy=MAX(maxy,j); }
		Diff_X[i]=maxy-miny; if(Diff_X[i]<0) Diff_X[i]=0;
	}
	for(j=min_Y;j<=max_Y;j++)
	{
		int minx=M-1,maxx=0;
		for(i=0;i<M;i++)
			if(F[i][j]<8) { minx=MIN(minx,i); maxx=MAX(maxx,i); }
		Diff_Y[j]=maxx-minx; if(Diff_Y[j]<0) Diff_Y[j]=0;
	}
    double d1,d2; int s1,s2;
    CheckUniformness(Diff_X,min_X,max_X); d1=dev; s1=symmetric;
    CheckUniformness(Diff_Y,min_Y,max_Y); d2=dev; s2=symmetric;
    if(d1<2 && d2<2) printf("box\n");     // try adjusting these values, if needed
    else if(s1 && s2)
    {
        double z1=d1-d2; if(z1<0) z1=-z1;
        int z2=(max_Y-min_Y)-(max_X-min_X); if(z2<0) z2=-z2;
        printf("%s\n",(z2<=3 || z1>=15)?"circle":"ellipse");    // try adjusting this one too
    }
    else printf("triangle\n");
}

int main()
{
	getInput();
	solve();
	return 0;
}
