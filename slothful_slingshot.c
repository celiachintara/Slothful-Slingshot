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
....
...
....
....

return 0;
}
