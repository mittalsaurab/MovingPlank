#include<graphics.h>
#include<bits/stdc++.h>
#include<conio.h>
#include<stdio.h>
#include<thread>
using namespace std;

int xin=300,yin=400,xcen=100,ycen=100,r=25,area1,area2;
int step=5,step2=2;
void *p1,*p2;

void drawPlank(){
       setcolor(GREEN);
       setfillstyle(SOLID_FILL,RED);
       rectangle(xin,yin,xin+70,yin+10);
       floodfill(xin+35,yin+5,GREEN);
}

void drawBall(){
    setcolor(WHITE);
    setfillstyle(SOLID_FILL,GREEN);
    circle(xcen,ycen,r);
    floodfill(xcen,ycen,WHITE);
}

void showBall(){
    int t1=1,t2=-1;
    bool f=1;
    int temp1=xcen,temp2=ycen;
    while(true){
        if(xcen-r<=0||xcen+r>=getmaxx()){
            t1*=-1;
        }
        else if(ycen-r<=0){
            t2*=-1;
        }
        else if(xin<xcen&&xin+70>xcen&&ycen+r>=yin){
            t2=-1;
        }
        xcen+=t1*step2; ycen+=t2*step2;

        if(ycen+r>=getmaxy()){
            cout<<"You lost Game"<<endl;
            break;
        }

        putimage(temp1-r,temp2-r, p2, XOR_PUT);
        putimage(xcen-r,ycen-r,p2,XOR_PUT);
        temp1=xcen; temp2=ycen;
        delay(10);
    }
}

void showPlank(){
    drawPlank();
    int temp1=xin,temp2=yin;
    while(true){
        int ch=getche();
        switch(ch){
           case 77: cout<<"right"<<endl;
                    if(xin+70+step<getmaxx()){ xin+=step;
                            putimage(temp1,temp2,p1,XOR_PUT);
                            putimage(xin,yin,p1,XOR_PUT);
                            temp1=xin; temp2=yin;
                    }
                    break;
           case 75: cout<<"left"<<endl;
                    if(xin>step){
                        xin-=step;
                            putimage(temp1,temp2,p1,XOR_PUT);
                            putimage(xin,yin,p1,XOR_PUT);
                            temp1=xin; temp2=yin;
                    }
                    break;
           default:
                    break;
        }
   }
   cout<<"You are exiting programme!"<<endl;
}

void start(){

    cout<<"WELCOME TO PLANK-BALL GAME"<<endl;

    cout<<endl;

    cout<<"USE LEFT AND RIGHT ARROW KEY TO MOVE PLANK"<<endl;

    cout<<endl;

    cout<<"ENTER SPEED OF BALL(1-10):";
    cin>>step2;
    if(step2<=0) step2=1;

    cout<<endl;

    cout<<"ENTER SPEED OF PLANK(1-10):";
    cin>>step;
    if(step<=0) step=3;
    step*=3;
    cout<<"TAKING YOU TO GAME "<<endl;
    return ;
}

int main(){

   int gd = DETECT, gm;

   initgraph(&gd, &gm, "");

   start();

   drawPlank();

   drawBall();

   area1=imagesize(xin,yin,xin+70,yin+10);
   p1=malloc(area1);
   getimage(xin, yin, xin + 70,yin + 10, p1);

   area2=imagesize(xcen-r,ycen-r,xcen+r,ycen+r);
   p2=malloc(area2);
   getimage(xcen-r,ycen-r,xcen+r,ycen+r, p2);

   thread T1(showBall);
   thread T2(showPlank);

    T2.join();
    T1.join();

    //getch();
   closegraph();
}
