#include<bits/stdc++.h>
int n,ans=0,a[200005],f[200005][2];
int main(){
	int i;
	scanf("%d",&n);
	for (i=1;i<=n;i++){
		scanf("%d",&a[i]);
		f[i][0]=f[i][1]=1;
		if (a[i]>a[i-1]) f[i][0]+=f[i-1][0],f[i][1]+=f[i-1][1];
		if (i>1&&a[i]>a[i-2]&&f[i-2][0]+1>f[i][1]) f[i][1]=f[i-2][0]+1;
		if (f[i][1]>ans) ans=f[i][1];
	}
	printf("%d",ans);
	return 0;
}