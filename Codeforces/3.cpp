#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
const long long si=2e5+10;
vector<int>graphh[si];
vector<int>flag(si,0);

void bfs(int deg)
{
	queue<int>q;
	q.push(deg); flag[deg]=1;
	while(!q.empty())
	{
		int g=q.front(); q.pop();
		for(int i=0; i<graphh[g].size(); i++)
		{
			if(flag[graphh[g][i]]==0)
			{
				cout<<g<<" "<<graphh[g][i]<<"\n";
				flag[graphh[g][i]]=1;
				q.push(graphh[g][i]);
			}
		}
	}
}

int main()
{
	cin>>n>>m; int x,y;
	for(int i=1; i<=m; i++)
	{
		cin>>x>>y; graphh[x].push_back(y);
		graphh[y].push_back(x);
	}
    
	int maxx=0,deg=0;
	for(int i=1; i<=n; i++)
	{
		if(graphh[i].size()>maxx)
		{
			maxx=graphh[i].size();
			deg=i;
		}
	}
	bfs(deg);
}



/*
int main()
{
	int n,k; cin>>n>>k;
	ll d[n]; int c=0;
	for(int i=0; i<n; i++)
	{
		cin>>d[i]; d[i]=d[i]%k; if(d[i]==0) c++;
	}

	sort(d,d+n);
	int i=0,j=n-1,count=(c/2)*2;
	while(i<j)
	{
		if(d[i]+d[j]>k) j--;
		else if(d[i]+d[j]<k) i++;
		else { count+=2; i++; j--; }
	}
	cout<<count<<endl;
}
*/


/*
int main()
{
	string t1,t2;
	cin>>t1; cin>>t2;
	int h1=(t1[0]-'0')*10+(t1[1]-'0');
	int m1=(t1[3]-'0')*10+(t1[4]-'0');

	int h2=(t2[0]-'0')*10+(t2[1]-'0');
	int m2=(t2[3]-'0')*10+(t2[4]-'0');

	int t11=h1*60+m1,t22=h2*60+m2;
	int ans=t11+(t22-t11)/2;

	int ansh=ans/60,ansm=ans%60;

	// cout<<ansh<<" "<<ansm<<"\n";
	string s="";
	if(ansh/10 == 0)
	{
		s+="0"; s+=to_string(ansh);
	}else s+=to_string(ansh);

	s+=":";
	if(ansm/10 == 0)
	{
		s+="0"; s+=to_string(ansm);
	}else s+=to_string(ansm);
	cout<<s<<endl;
}
*/