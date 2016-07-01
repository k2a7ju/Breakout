

#include<stdio.h>
#include<stdlib.h>
#include<eggx.h>

int win;
int t=0,s=0;
int x=13,y=10;//ボールの座標
double xz=10,yz=10;//ボールの傾き
int w,h,color_r[6],color_p[6],color_y[6],color_g[6],color_b[6];
int count;
int fl[6],fl1[6],fl2[6],fl3[6],fl4[6];
int p,c,o;
double a[6]={9,90,171,252,333,414};//赤ブロックのx座標
double a1[6]={9,90,171,252,333,414};
double a2[6]={9,90,171,252,333,414};
double a3[6]={9,90,171,252,333,414};
double a4[6]={9,90,171,252,333,414};
double b[6],b1[6],b2[6],b3[6],b4[6];//すべてのブロックのy座標

int ball(void);
int kabe(void);
int block_Red(void);
int block_Pink(void);
int block_Yellow(void);
int block_Green(void);
int block_Blue(void);
int board(void);

int main(){
	
	win=gopen(500,500);
	winname(win,"Breakout-kai");
	gsetnonblock(ENABLE);
	
	
	for(count=0;count<6;count++){
		color_r[count]=2;
		color_p[count]=6;
		color_y[count]=7;
		color_g[count]=11;
		color_b[count]=4;
		fl[count]=0;
		fl1[count]=0;
		fl2[count]=0;
		fl3[count]=0;
		fl4[count]=0;
		b[count]=480;
		b1[count]=470;
		b2[count]=460;
		b3[count]=450;
		b4[count]=440;
	}
	
	p=1;
	
	while(p){
		
		
		ball();
		kabe();
		block_Red();
		block_Pink();
		block_Yellow();
		block_Green();
		block_Blue();
		board();
		
		
		msleep(40);
		gclr(win);
	}
	
	if(p==0 && c==1){
		
		gclr(win);
		while(1){
			newpen(win,7);
			drawstr(win,180,250,150,0,"GAME CLEAR");
		}
	}
	
	if(p==0 && o==1){
		
		gclr(win);
		while(1){
			newpen(win,2);
			drawstr(win,180,250,150,0,"GAME OVER");
		}
	}
	
	exit(0);
}


/*ボールの表示*/
int ball(void){
	
	newpen(win,1);
	fillcirc(win,x,y,6,6);
	y+=yz;
	x+=xz;
	
	return 0;
}



/*壁の表示*/
int kabe(void){
	
	if(x>487){//右の壁に当たった時
		x=488;
		xz*=-1;
	}
	else if(y>481){//上の壁に当たった時
		y=482;
		yz*=-1;
	}
	else if(x<13){//左の壁に当たった時
		x=12;
		xz*=-1;
	}
	else if(y<-10){//下の壁に当たった時
		x=-11;
		p=0;
		o=1;
	}
	
	return 0;
}


/*ブロックの表示*/

int block_Red(void){
	
	w=80;
	h=9;
	
	int hi=470;
	
	newpen(win,color_r[0]);
	fillrect(win,a[0],b[0],w,h);
	newpen(win,color_r[1]);
	fillrect(win,a[1],b[1],w,h);
	newpen(win,color_r[2]);
	fillrect(win,a[2],b[2],w,h);
	newpen(win,color_r[3]);
	fillrect(win,a[3],b[3],w,h);
	newpen(win,color_r[4]);
	fillrect(win,a[4],b[4],w,h);
	newpen(win,color_r[5]);
	fillrect(win,a[5],b[5],w,h);
	
	
	if(fl[0]==0 && y>=hi && x>=a[0] && x<a[0]+81){
		y=hi+1;
		yz*=-1.0;
		fl[0]=1;
		a[0]=-1000;
		b[0]=0;
		newpen(win,0);
		fillrect(win,a[0],b[0],w,h);
		if(fl[0]==1 && fl[1]==1 && fl[2]==1 && fl[3]==1 && fl[4]==1 && fl[5]==1){
			p=0;
			c=1;
		}
	}
	
	if(fl[1]==0 && y>=hi && x>=a[1] && x<a[1]+81){
		y=hi+1;
		yz*=-1.0;
		fl[1]=1;
		a[1]=-1000;
		b[1]=0;
		newpen(win,0);
		fillrect(win,a[1],b[1],w,h);
		if(fl[0]==1 && fl[1]==1 && fl[2]==1 && fl[3]==1 && fl[4]==1 && fl[5]==1){
			p=0;
			c=1;
		}
	}
	
	if(fl[2]==0 && y>=hi && x>=a[2] && x<a[2]+81){
		y=hi+1;
		yz*=-1.0;
		fl[2]=1;
		a[2]=-1000;
		b[2]=0;
		newpen(win,0);
		fillrect(win,a[2],b[2],w,h);
		if(fl[0]==1 && fl[1]==1 && fl[2]==1 && fl[3]==1 && fl[4]==1 && fl[5]==1){
			p=0;
			c=1;
		}
	}
	
	if(fl[3]==0 && y>=hi && x>=a[3] && x<a[3]+81){
		y=hi+1;
		yz*=-1.0;
		fl[3]=1;
		a[3]=-1000;
		b[3]=0;
		newpen(win,0);
		fillrect(win,a[3],b[3],w,h);
		if(fl[0]==1 && fl[1]==1 && fl[2]==1 && fl[3]==1 && fl[4]==1 && fl[5]==1){
			p=0;
			c=1;
		}
	}
	
	if(fl[4]==0 && y>=hi && x>=a[4] && x<a[4]+81){
		y=hi+1;
		yz*=-1.0;
		fl[4]=1;
		a[4]=-1000;
		b[4]=0;
		newpen(win,0);
		fillrect(win,a[4],b[4],w,h);
		if(fl[0]==1 && fl[1]==1 && fl[2]==1 && fl[3]==1 && fl[4]==1 && fl[5]==1){
			p=0;
			c=1;
		}
	}
	
	if(fl[5]==0 && y>=hi && x>=a[5] && x<a[5]+81){
		y=hi+1;
		yz*=-1.0;
		fl[5]=1;
		a[5]=-1000;
		b[5]=0;
		newpen(win,0);
		fillrect(win,a[5],b[5],w,h);
		if(fl[0]==1 && fl[1]==1 && fl[2]==1 && fl[3]==1 && fl[4]==1 && fl[5]==1){
			p=0;
			c=1;
		}
	}
	
	return 0;
	
}

int block_Pink(void){
	
	w=80;
	h=9;
	
	int hi=460;
	
	newpen(win,color_p[0]);
	fillrect(win,a1[0],b1[0],w,h);
	newpen(win,color_p[1]);
	fillrect(win,a1[1],b1[1],w,h);
	newpen(win,color_p[2]);
	fillrect(win,a1[2],b1[2],w,h);
	newpen(win,color_p[3]);
	fillrect(win,a1[3],b1[3],w,h);
	newpen(win,color_p[4]);
	fillrect(win,a1[4],b1[4],w,h);
	newpen(win,color_p[5]);
	fillrect(win,a1[5],b1[5],w,h);
	
	
	if(fl1[0]==0 && y>=hi && x>=a1[0] && x<a1[0]+81){
		yz*=-1.0;
		fl1[0]=1;
		a1[0]=-1000;
		b1[0]=0;
		newpen(win,0);
		fillrect(win,a1[0],b1[0],w,h);
	}
	
	if(fl1[1]==0 && y>=hi && x>=a1[1] && x<a1[1]+81){
		yz*=-1.0;
		fl1[1]=1;
		a1[1]=-1000;
		b1[1]=0;
		newpen(win,0);
		fillrect(win,a1[1],b1[1],w,h);
	}
	
	if(fl1[2]==0 && y>=hi && x>=a1[2] && x<a1[2]+81){
		yz*=-1.0;
		fl1[2]=1;
		a1[2]=-1000;
		b1[2]=0;
		newpen(win,0);
		fillrect(win,a1[2],b1[2],w,h);
	}
	
	if(fl1[3]==0 && y>=hi && x>=a1[3] && x<a1[3]+81){
		yz*=-1.0;
		fl1[3]=1;
		a1[3]=-1000;
		b1[3]=0;
		newpen(win,0);
		fillrect(win,a1[3],b1[3],w,h);
	}
	
	if(fl1[4]==0 && y>=hi && x>=a1[4] && x<a1[4]+81){
		yz*=-1.0;
		fl1[4]=1;
		a1[4]=-1000;
		b1[4]=0;
		newpen(win,0);
		fillrect(win,a1[4],b1[4],w,h);
	}
	
	if(fl1[5]==0 && y>=hi && x>=a1[5] && x<a1[5]+81){
		yz*=-1.0;
		fl1[5]=1;
		a1[5]=-1000;
		b1[5]=0;
		newpen(win,0);
		fillrect(win,a1[5],b1[5],w,h);
	}
	
	return 0;
	
}

int block_Yellow(void){
	
	
	w=80;
	h=9;
	
	int hi=450;
	
	newpen(win,color_y[0]);
	fillrect(win,a2[0],b2[0],w,h);
	newpen(win,color_y[1]);
	fillrect(win,a2[1],b2[1],w,h);
	newpen(win,color_y[2]);
	fillrect(win,a2[2],b2[2],w,h);
	newpen(win,color_y[3]);
	fillrect(win,a2[3],b2[3],w,h);
	newpen(win,color_y[4]);
	fillrect(win,a2[4],b2[4],w,h);
	newpen(win,color_y[5]);
	fillrect(win,a2[5],b2[5],w,h);
	
	
	if(fl2[0]==0 && y>=hi && x>=a2[0] && x<a2[0]+81){
		yz*=-1.0;
		fl2[0]=1;
		a2[0]=-1000;
		b2[0]=0;
		newpen(win,0);
		fillrect(win,a2[0],b2[0],w,h);
	}
	
	if(fl2[1]==0 && y>=hi && x>=a2[1] && x<a2[1]+81){
		yz*=-1.0;
		fl2[1]=1;
		a2[1]=-1000;
		b2[1]=0;
		newpen(win,0);
		fillrect(win,a2[1],b2[1],w,h);
	}
	
	if(fl2[2]==0 && y>=hi && x>=a2[2] && x<a2[2]+81){
		yz*=-1.0;
		fl2[2]=1;
		a2[2]=-1000;
		b2[2]=0;
		newpen(win,0);
		fillrect(win,a2[2],b2[2],w,h);
	}
	
	if(fl2[3]==0 && y>=hi && x>=a2[3] && x<a2[3]+81){
		yz*=-1.0;
		fl2[3]=1;
		a2[3]=-1000;
		b2[3]=0;
		newpen(win,0);
		fillrect(win,a2[3],b2[3],w,h);
	}
	
	if(fl2[4]==0 && y>=hi && x>=a2[4] && x<a2[4]+81){
		yz*=-1.0;
		fl2[4]=1;
		a2[4]=-1000;
		b2[4]=0;
		newpen(win,0);
		fillrect(win,a2[4],b2[4],w,h);
	}
	
	if(fl2[5]==0 && y>=hi && x>=a2[5] && x<a2[5]+81){
		yz*=-1.0;
		fl2[5]=1;
		a2[5]=-1000;
		b2[5]=0;
		newpen(win,0);
		fillrect(win,a2[5],b2[5],w,h);
	}
	
	return 0;
	
	
	
}

int block_Green(void){
	
	w=80;
	h=9;
	
	int hi=440;
	
	newpen(win,color_g[0]);
	fillrect(win,a3[0],b3[0],w,h);
	newpen(win,color_g[1]);
	fillrect(win,a3[1],b3[1],w,h);
	newpen(win,color_g[2]);
	fillrect(win,a3[2],b3[2],w,h);
	newpen(win,color_g[3]);
	fillrect(win,a3[3],b3[3],w,h);
	newpen(win,color_g[4]);
	fillrect(win,a3[4],b3[4],w,h);
	newpen(win,color_g[5]);
	fillrect(win,a3[5],b3[5],w,h);
	
	
	if(fl3[0]==0 && y>=hi && x>=a3[0] && x<a3[0]+81){
		y=hi+1;
		yz*=-1.0;
		fl3[0]=1;
		a3[0]=-1000;
		b3[0]=0;
		newpen(win,0);
		fillrect(win,a3[0],b3[0],w,h);
		
	}
	
	if(fl3[1]==0 && y>=hi && x>=a3[1] && x<a3[1]+81){
		y=hi+1;
		yz*=-1.0;
		fl3[1]=1;
		a3[1]=-1000;
		b3[1]=0;
		newpen(win,0);
		fillrect(win,a3[1],b3[1],w,h);
	}
	
	if(fl3[2]==0 && y>=hi && x>=a3[2] && x<a3[2]+81){
		y=hi+1;
		yz*=-1.0;
		fl3[2]=1;
		a3[2]=-1000;
		b3[2]=0;
		newpen(win,0);
		fillrect(win,a3[2],b3[2],w,h);
	}
	
	if(fl3[3]==0 && y>=hi && x>=a3[3] && x<a3[3]+81){
		y=hi+1;
		yz*=-1.0;
		fl3[3]=1;
		a3[3]=-1000;
		b3[3]=0;
		newpen(win,0);
		fillrect(win,a3[3],b3[3],w,h);
	}
	
	if(fl3[4]==0 && y>=hi && x>=a3[4] && x<a3[4]+81){
		y=hi+1;
		yz*=-1.0;
		fl3[4]=1;
		a3[4]=-1000;
		b3[4]=0;
		newpen(win,0);
		fillrect(win,a3[4],b3[4],w,h);
	}
	
	if(fl3[5]==0 && y>=hi && x>=a3[5] && x<a3[5]+81){
		y=hi+1;
		yz*=-1.0;
		fl3[5]=1;
		a3[5]=-1000;
		b3[5]=0;
		newpen(win,0);
		fillrect(win,a3[5],b3[5],w,h);
	}
	
	return 0;
	
}

int block_Blue(void){
	
	w=80;
	h=9;
	
	int hi=430;
	
	newpen(win,color_b[0]);
	fillrect(win,a4[0],b4[0],w,h);
	newpen(win,color_b[1]);
	fillrect(win,a4[1],b4[1],w,h);
	newpen(win,color_b[2]);
	fillrect(win,a4[2],b4[2],w,h);
	newpen(win,color_b[3]);
	fillrect(win,a4[3],b4[3],w,h);
	newpen(win,color_b[4]);
	fillrect(win,a4[4],b4[4],w,h);
	newpen(win,color_b[5]);
	fillrect(win,a4[5],b4[5],w,h);
	
	
	if(fl4[0]==0 && y>=hi && x>=a4[0] && x<a4[0]+81){
		y=hi+1;
		yz*=-1.0;
		fl4[0]=1;
		a4[0]=-1000;
		b4[0]=0;
		newpen(win,0);
		fillrect(win,a4[0],b4[0],w,h);
		
	}
	
	if(fl4[1]==0 && y>=hi && x>=a4[1] && x<a4[1]+81){
		y=hi+1;
		yz*=-1.0;
		fl4[1]=1;
		a4[1]=-1000;
		b4[1]=0;
		newpen(win,0);
		fillrect(win,a4[1],b4[1],w,h);
	}
	
	if(fl4[2]==0 && y>=hi && x>=a4[2] && x<a4[2]+81){
		y=hi+1;
		yz*=-1.0;
		fl4[2]=1;
		a4[2]=-1000;
		b4[2]=0;
		newpen(win,0);
		fillrect(win,a4[2],b4[2],w,h);
	}
	
	if(fl4[3]==0 && y>=hi && x>=a4[3] && x<a4[3]+81){
		y=hi+1;
		yz*=-1.0;
		fl4[3]=1;
		a4[3]=-1000;
		b4[3]=0;
		newpen(win,0);
		fillrect(win,a4[3],b4[3],w,h);
	}
	
	if(fl4[4]==0 && y>=hi && x>=a4[4] && x<a4[4]+81){
		y=hi+1;
		yz*=-1.0;
		fl4[4]=1;
		a4[4]=-1000;
		b4[4]=0;
		newpen(win,0);
		fillrect(win,a4[4],b4[4],w,h);
	}
	
	if(fl4[5]==0 && y>=hi && x>=a4[5] && x<a4[5]+81){
		y=hi+1;
		yz*=-1.0;
		fl4[5]=1;
		a4[5]=-1000;
		b4[5]=0;
		newpen(win,0);
		fillrect(win,a4[5],b4[5],w,h);
	}
	
	return 0;
	
	
}

int board(void){
	
	int code;
	static float code_x=100.0,code_y=30.0;
	newpen(win,1);
	fillrect(win,code_x,code_y,110,15);
	code=ggetch();
	if(code!=-1){
		//printf("%d\n",code);
		if(code==28){
			if(code_x<=375){
				code_x=code_x+15;
			}
			
		}
		else if(code==29){
			
			if(code_x>=10){
				code_x=code_x-15;
			}
			
		}
	}
	
	if(y<=59 && x>=code_x && x<=code_x+100){//バーに当たった時
		y=59;
		yz*=-1;
	}
	
	
	return 0;
}
