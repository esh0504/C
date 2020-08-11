#include <stdio.h>
#include <string.h>
#include <algorithm> 
struct Node { int n; char *p; } v[50]; 
bool cmp(Node &a, Node &b) { return a.n>b.n; } 
int main() {
	char s[50][52];
	int n, i, j, cnt=0;
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		scanf("%s", s[i]);
		v[i].n=strlen(s[i]);
		v[i].p=s[i];
	}
	std::sort(v,v+n,cmp);
	for(i=1;i<n;i++)
		for(j=0;j<i;j++) {
			if(v[j].n&&!strncmp(v[j].p,v[i].p,v[i].n)) {
				cnt++;
				v[i].n=0; break;
			}
		}
	printf("%d\n", n-cnt);
}

