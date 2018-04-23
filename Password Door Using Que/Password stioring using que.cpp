#include "zcommon.acs"
str msg="Message box reset to default";
function void Poly(int po,int speed) {
polyobj_doorswing(po,speed,60,88);
}
#define ARRAYSIZE 3
INT Stored[ARRAYSIZE]={2,3,4};
int front=-1;
int rear=-1;
int Data[ARRAYSIZE];
int UserInp=-1;
function void Input(void) {
if(rear>=2) {
    print(s:"Memory full!!\n Try to empty it or enter valid password");
    front=-1;
    rear=-1;
    }else {
    Data[++rear]=UserInp;
    print(s:"You entered ",i:Data[rear]);
    }
}

function void Remove(void) {
if(front==rear) {
print(s:"Que is empty!!");

    }else {
    Data[front]=0;
    front--;
    }
}
function void NumPad(void) {
IF(UserInp==9){
UserInp=-1;
    }else {
    ++UserInp;
    print(i:UserInp);
    }   
}
bool IsCorrect=false;
script 1 (void)     {
    if(rear==2) {
    for(int i=0;i<rear+1;i++) {
    if(Data[i]==Stored[i]) {
        print(s:"Welcome!!\n\nDoor to my home is always open for you");
        IsCorrect=true;
        }else {
        print(s:msg);
        reset();
            }
    }
    }else {
    Input();
    IsCorrect=false;
    }
    if(IsCorrect==true) {
    poly(1,-11);
       poly(2,11);
    }else {
    null();
    }
    if(UserInp==0) {
    reset();
    }
}

function int null(void) {
return 0;
}
script 2 (void) {
NumPad();
}
function void reset (void) {
for(int i=0;i<5;i++) {
    Remove();
    }
    front=-1;
    rear=-1;
    print(s:msg);
    IsCorrect=false;
}