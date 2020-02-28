#include "zcommon.acs"
#define BFH -14155776
#define FFH 7340032
#define SFH 19922944
#define TFH 32505856

function void killer(void) {
if(ThingCountSector(0,9000,2)>0&&GetSectorFloorZ(4,0,0)<=-11993088&&getactorz(9000)<=-15204352) { //basement killer
Thing_Destroy(9000,0,2);
PRINTBOLD(s:"\cr DONT STAND UNDER THE ELEVATOR!!");	
}
	
}


bool bf,ff,sf,tf;


script 1 OPEN {
ChangeSky("CLOUDY","");	
}

function int null(void)  {
return 1;	

}
int ph;
bool move=false;

int cfh;
int total;
script 2 enter {	
Thing_ChangeTID(0,9000);
While(1) {		
cfh=GetSectorFloorZ(4,0,0);	
killer();
if(cfh==BFH) {
bf=true;
ff=false;
sf=false;
tf=false;		
}
if(cfh==FFH) {
bf=FALSE;
ff=TRUE;
sf=false;
tf=false;		
}
if(cfh==SFH) {
bf=FALSE;
ff=FALSE;
sf=TRUE;
tf=false;		
}
if(cfh==TFH) {
bf=FALSE;
ff=FALSE;
sf=false;
tf=TRUE;		
}
killer();
delay(1);	
}
		
}

int sw=-1;

script 3 (void) {
sw++;
if(sw==4) {
sw=-1;	
}
switch (sw) {
case 0:
print(s:"Basement");
break;

case 1:
print(s:"1st floor");
break;

case 2:
print(s:"2nd floor");
break;

case 3:
print(s:"3rd floor");
break;
default:
printbold(s:"\crWelcome to Motel Doom elevator service\n\n \crSelect floor rom that switch and use second seitch to call elevator\n\n \cr have a nice day!!");
break;
}
	
}

script 4 (void) {
if(move==true) {
null();	
}else {
switch (sw) {

case 0: //basement
if(bf==true) {
print(s:"Elevator is here!!");	
}else {

if(ff==true||sf==true||tf==true) {
do {
delay(31);	
if(bf==true) {
break;	
}else {
Elevator_LowerToNearest(4,11);	
}		
Delay(5);	
}while(bf!=true);	
}	
}
break;

case 1: //1st floor
if(ff==true) {
print(s:"Elevator is here!!");	
}else {

if(sf==true||tf==true) {
do {
delay(31);		
if(ff==true) {
break;	
}else {
Elevator_LowerToNearest(4,11);	
}		
Delay(5);	
}while(ff!=true);	
}	
if(bf==true) {
do {
delay(31);	
if(ff==true) {
break;	
}else {
Elevator_raiseToNearest(4,11);	
}		
Delay(5);	
}while(ff!=true);	
}	

}
break;


case 2://2nd floor
if(sf==true) {
print(s:"Elevator is here!!");	
}else {

if(tf==true) {
do {
delay(31);
if(sf==true) {
break;	
}else {
Elevator_LowerToNearest(4,11);	
}		
Delay(5);	
}while(sf!=true);	
}	
if(bf==true||ff==true) {
do {
delay(31);	
if(sf==true) {
break;	
}else {
Elevator_raiseToNearest(4,11);	
}		
Delay(5);	
}while(sf!=true);	
}	

}
break;

case 3: //3rd floor
if(tf==true) {
print(s:"Elevator is here!!");	
}else {

if(bf==true||ff==true||sf==true) {
do {
delay(31);	
if(tf==true) {
break;	
}else {
Elevator_raiseToNearest(4,11);	
}		
Delay(5);	
}while(tf!=true);	
}	
	
}
break;
	
}	
	
}
		
}

