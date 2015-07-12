int dp[2001][2001];
int func(int h,int a)
{
	int h1=h,a1=a;
	if(dp[h][a]!=0)
	return dp[h][a];
	int count=0;
	while(true)
	{
		h+=3;
		a+=2;
		count++;
		if(h<=5)
		break;
		if(h<=20)
		{
			if(a<=10)
			break;
			h-=5;
			a-=10;
			count++;
			continue;
		}
		else
		{
			if(a<=10)
			{
				h-=20;
				a+=5;
				count++;
			}
			else
			{
				count+=max(func(h-20,a+5),func(h-5,a-10));
				count++;
				break;
			}
		}
	}
	return dp[h1][a1]=count;
}
