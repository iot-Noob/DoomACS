#include "zcommon.acs"
#define SN 9000

int hour=2;
int min=1;
int sec=8;
str message="Time left to die!!";
str color=CR_GREEN;

function int null(void) {
return 1;	
}

function void box(void) {
setfont("BIGFONT");
HudMessagebold(s:"-------------------------------------------";HUDMSG_FADEOUT,5,CR_BRICK,0.2,0.23,5.0); 
HudMessagebold(s:"-------------------------------------------";HUDMSG_FADEOUT,6,CR_BRICK,0.2,0.33,5.0); 
		
}

function void digit(void){
box();	
setfont("BIGFONT");
HudMessagebold(s:message;HUDMSG_FADEOUT,4,CR_GREY,0.2,0.26,5.0); //title

setfont("BIGFONT");
HudMessagebold(i:hour,s:" : ";HUDMSG_FADEOUT,1,color,0.22,0.3,5.0); //Hour	

setfont("BIGFONT");
HudMessagebold(i:min,s:" : ";HUDMSG_FADEOUT,2,color,0.25,0.3,5.0); //Min

setfont("BIGFONT");
HudMessagebold(i:sec;HUDMSG_FADEOUT,3,color,0.28,0.3,5.0); //second



}

function void countdown(void) {

if(sec==0) {
sec=59;	
min-=1;
if(min==0&&hour>0) {
min=59;
hour-=1;	
}
}else {
sec--;	
}	

if(hour>0&&min>0&&sec>0) {
color=cr_green;	
}else if(min>0&&sec>0) {
color=cr_yellow;	
}else if(sec>0) {
color=cr_red;	
}


	
}

script SN enter{

do {
	
digit();

if(hour==0&&min==0&&sec==0) {
delay(11);	
Thing_Damage(0,900000,1);	
terminate;	
}else {
countdown();	
}

delay(35);	
	
}while(true);



	
}


