#include "zcommon.acs"
int selector;

int pass[3]={3,2,1};
int entry[3];
int top=-1;

bool accept=false;
bool entered=false;

function void reset(void) {
accept=false;
entered=false;
top=-1;
selector=1;

}

function void freez(void) {
SetPlayerProperty(TRUE, ON, PROP_TOTALLYFROZEN);	
}

function void unfreez(void) {
SetPlayerProperty(TRUE, OFF, PROP_TOTALLYFROZEN);	
}

function int null(void) {
return 1;	
}

function void push(int num) {

if(top==2) {
entered=true;

	
}else {
	
entry[++top]=num;	


}
	
}	

function void pop(void) {

if(top==-1) {
reset();	
SetFont("BIGFONT");
HudMessage(s:"Password reset!!";HUDMSG_FADEOUT,103,CR_GREEN,0.4,0.2,0.2);	
	
}else {
for(int i=2;i>=-1;i--) {
entry[i]=0;	
}	
}	

}

function void check(void) {
if(entered==true) {

for(int i=0;i<=2;i++) {

if(pass[i]==entry[i]) {
accept=true;
SetFont("BIGFONT");
HudMessage(s:"Welcome valid password!!";HUDMSG_FADEOUT,104,CR_GREEN,0.4,0.2,3.55);
	
pop();
unfreez();
ACS_Terminate(1,0);	
}ELSE {	
accept=false;
unfreez();	
SetFont("BIGFONT");
HudMessage(s:"invalid password!!";HUDMSG_FADEOUT,105,CR_GREEN,0.4,0.2,2.55);	
pop();	
ACS_Terminate(1,0);
}
	
}	

	
}

}

function void keypad(void) {
SetFont("BIGFONT");
HudMessage(s:"\t\t\t\t",i:entry[0];HUDMSG_FADEOUT,100,CR_RED,0.4,0.3,0.2);	//Digit 1 display
SetFont("BIGFONT");
HudMessage(s:"\t\t\t\t",i:entry[1];HUDMSG_FADEOUT,200,CR_RED,0.43,0.3,0.2);	//Digit 2 display
SetFont("BIGFONT");
HudMessage(s:"\t\t\t\t",i:entry[2];HUDMSG_FADEOUT,300,CR_RED,0.46,0.3,0.2);	//Digit 3 display

	
SetFont("BIGFONT");
HudMessage(s:"1";HUDMSG_FADEOUT,1,CR_CYAN,0.4,0.4,0.2);	
SetFont("BIGFONT");
HudMessage(s:"2";HUDMSG_FADEOUT,2,CR_CYAN,0.44,0.4,0.3);	
SetFont("BIGFONT");
HudMessage(s:"3";HUDMSG_FADEOUT,3,CR_CYAN,0.49,0.4,0.3);
		
SetFont("BIGFONT");
HudMessage(s:"4";HUDMSG_FADEOUT,4,CR_CYAN,0.4,0.46,0.3);	
SetFont("BIGFONT");
HudMessage(s:"5";HUDMSG_FADEOUT,5,CR_CYAN,0.44,0.46,0.3);	
SetFont("BIGFONT");
HudMessage(s:"6";HUDMSG_FADEOUT,6,CR_CYAN,0.49,0.46,0.3);		
SetFont("BIGFONT");

SetFont("BIGFONT");
HudMessage(s:"7";HUDMSG_FADEOUT,7,CR_CYAN,0.4,0.52,0.3);	
SetFont("BIGFONT");
HudMessage(s:"8";HUDMSG_FADEOUT,8,CR_CYAN,0.44,0.52,0.3);	
SetFont("BIGFONT");
HudMessage(s:"9";HUDMSG_FADEOUT,9,CR_CYAN,0.49,0.52,0.3);		
SetFont("BIGFONT");

HudMessage(s:"Clear";HUDMSG_FADEOUT,10,CR_CYAN,0.4,0.61,0.3);	//Clear

SetFont("BIGFONT");
HudMessage(s:"Accept";HUDMSG_FADEOUT,11,CR_CYAN,0.48,0.61,0.3);	//Accept
SetFont("BIGFONT");
HudMessage(s:"\n\n* Fire to enter value \n\n * up down  and left right arrows to move cursor \n\n * Press jump to exit";HUDMSG_FADEOUT,1067,CR_CYAN,0.1,0.88,0.3);	//Manual

}

script 1 (int bt){
freez();	
reset();
while (true) {

bt=GetPlayerInput(-1,INPUT_BUTTONS);

keypad();

if(bt==BT_ATTACK) {

if(selector==1) {
	
push(1);		
	
}else if(selector==2) {

push(2);	
	
}else if(selector==3) {

push(3);		
	
}else if(selector==4) {

push(4);		
	
}else if(selector==5) {

push(5);		
	
}else if(selector==6) {

push(6);		
	
}else if(selector==7) {

push(7);		
	
}else if(selector==8) {

push(8);		
	
}else if(selector==9) {

push(9);		
	
}else if(selector==10) {

pop();	
reset();

}else if(selector==11) {
push("");
check();

}
	
	
}

if(bt==BT_FORWARD) {

selector-=3;

if(selector<0) {
selector=10;	
}
	
}else if(bt==BT_BACK) {

selector+=3;

if(selector>10) {
selector=1;	
}
	
}else if(bt==BT_LEFT) {

selector--;

if(selector>10) {
selector=1;	
}
	
}else if(bt==BT_Right) {

selector++;

if(selector>11) {
selector=1;	
}
	
}else if(bt==BT_JUMP){
unfreez();
reset();
terminate;	
}

if(selector==1) {
	
SetFont("BIGFONT");
HudMessage(s:"1";HUDMSG_FADEOUT,1,CR_GREEN,0.4,0.4,0.1);		
	
}else if(selector==2) {

SetFont("BIGFONT");
HudMessage(s:"2";HUDMSG_FADEOUT,2,CR_GREEN,0.44,0.4,0.1);	
	
}else if(selector==3) {

SetFont("BIGFONT");
HudMessage(s:"3";HUDMSG_FADEOUT,3,CR_GREEN,0.49,0.4,0.1);	
	
}else if(selector==4) {

SetFont("BIGFONT");

HudMessage(s:"4";HUDMSG_FADEOUT,4,CR_GREEN,0.4,0.46,0.3);	

	
}else if(selector==5) {

SetFont("BIGFONT");
HudMessage(s:"5";HUDMSG_FADEOUT,5,CR_GREEN,0.44,0.46,0.3);	
	
	
}else if(selector==6) {

SetFont("BIGFONT");
HudMessage(s:"6";HUDMSG_FADEOUT,6,CR_GREEN,0.49,0.46,0.3);		
	
}else if(selector==7) {

SetFont("BIGFONT");
HudMessage(s:"7";HUDMSG_FADEOUT,7,CR_GREEN,0.4,0.52,0.3);		
	
}else if(selector==8) {

SetFont("BIGFONT");
HudMessage(s:"8";HUDMSG_FADEOUT,8,CR_GREEN,0.44,0.52,0.3);		
	
}else if(selector==9) {

SetFont("BIGFONT");
HudMessage(s:"9";HUDMSG_FADEOUT,9,CR_GREEN,0.49,0.52,0.3);		
	
}else if(selector==10) {

SetFont("BIGFONT");

HudMessage(s:"Clear";HUDMSG_FADEOUT,10,CR_green,0.4,0.61,0.3);
	
}else if(selector==11) {
SetFont("BIGFONT");
HudMessage(s:"Accept";HUDMSG_FADEOUT,11,CR_BLUE,0.48,0.61,0.3);	//Accept	
}

delay(5);	
}
unfreez();	
}

script 2 enter {

while (true) {
if(accept==true) {
Door_Open(1,11,0);
Terminate;	
}else {
null();
}

delay(1);	
}
	
}