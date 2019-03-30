#include<math.h>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef struct cat{
	double x,y;
	double F;
	double jarak;
}ketapel;
		
struct compare{
	bool operator()(ketapel a,ketapel b){
		return a.jarak > b.jarak;
	}
};

double BFS(ketapel a, ketapel b, ketapel c){
	double x1=0,y1=0,akum=0;
	if(b.x == a.x || b.y == a.y){
		c.jarak= abs(abs(b.x - a.x) + abs(b.y - a.y));
		akum=abs(c.jarak-a.F);
		if(akum<c.jarak){
			c.jarak=akum+a.jarak;
		}
		else{
			c.jarak+=a.jarak;
		}
	}
	else{
		y1=(b.y-a.y);
		x1=(b.x-a.x);
		c.jarak=(abs(x1)*sqrt(1+ ( (y1/x1)*(y1/x1) )));
		akum=abs(c.jarak-a.F);
		if(akum<c.jarak){
			c.jarak=akum+a.jarak;
		}
		else{
			c.jarak+=a.jarak;
		}
	}
	return c.jarak;
}

int main(){
	int n;
	vector <ketapel> catapul;
	priority_queue <ketapel, vector<ketapel>, compare> prio;
	double p_x,p_y,l_x,l_y,c_x,c_y;
	while(1){
		scanf("%d", &n);
		catapul.resize(n+2);
		scanf("%lf %lf %lf %lf",&catapul[0].x,&catapul[0].y,&catapul[n+1].x,&catapul[n+1].y);
		prio.push(catapul[0]);
		catapul[0].jarak = 0;
		catapul[n+1].jarak = 1000000000.0 * sqrt(2); 
		if(n==-1 && catapul[0].x==-1 && catapul[0].y==-1 && catapul[n+1].x==-1 && catapul[n+1].y== -1){
			break;
		}
		else{
			for(int i=1;i<=n;i++){
				scanf("%lf %lf %lf", &catapul[i].x,&catapul[i].y,&catapul[i].F);	
				catapul[i].jarak =1000000000.0*sqrt(2);
			}
			
			while(!((prio.top().x==catapul[n+1].x) && (prio.top().y ==catapul[n+1].y))){
				ketapel simpan;
				simpan = prio.top();
				prio.pop();
				if(simpan.x == catapul[n+1].x && simpan.y == catapul[n+1].y) break;
				for(int i=1;i<=n+1;i++){
					ketapel tmp;
					tmp = catapul[i];
					tmp.jarak = BFS(simpan,catapul[i],tmp);
					if(tmp.jarak<catapul[i].jarak){
						catapul[i].jarak = tmp.jarak;
						prio.push(catapul[i]);
					}
				}
			}
			ketapel ans;
			ans = prio.top();
			prio.pop();
			printf("%.2lf\n", ans.jarak);
			while(!prio.empty()){
				prio.pop();
			}
		}
	}

return 0;
}
