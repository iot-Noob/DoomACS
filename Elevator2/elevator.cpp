#include "zcommon.acs"
#define GFH 0
#define FFH 12582912
#define SFH 27262976

function int null (void) {
return 1;	
}

int cfh;

bool gf,ff,sf;

bool move=false;

script 1 enter {
while(1) {
cfh=GetSectorFloorZ(2,0,0);	
if(cfh==GFH) {
gf=true;
ff=false;
sf=false;	
}
if(cfh==FFH) {
gf=false;
ff=true;
sf=false;	
}
if(cfh==SFH) {
gf=FALSE;
ff=false;
sf=TRUE;	
}
delay(1);	
}	
}

int sw=0;

script 2 (void) {
sw++;		
if(sw==3) {
sw=0;	
}
	
}

script 3 (void) {

if(move==true) {

null();	

} else {

switch (sw) {

case 0: //ground floor

if(gf==true) {

print(s:"Elevator is called already open door");
delay(55);
Polyobj_DoorSlide(1,20,128,90,77);
Polyobj_DoorSlide(2,-20,128,90,77);	

}else {
	
if(ff==true || sf==true) {
print(s:"calling elevatorground floor");
do {
move=true;	
if(gf==true) {

break;

}else {

Elevator_LowerToNearest(2,22);	
	
}

delay(1);
	
}while(gf!=true);
delay(40);
Polyobj_DoorSlide(1,20,128,90,77);
Polyobj_DoorSlide(2,-20,128,90,77);
move=false;
	
}	
	
}

break;

case 1: //1st floor

if(ff==true) {

print(s:"Elevator is called already open door");
delay(55);
Polyobj_DoorSlide(1,20,128,90,77);
Polyobj_DoorSlide(2,-20,128,90,77);	

}else {
	
if(gf==true) {
print(s:"calling elevator to 1st floor");
do {
delay(30);	
move=true;	
if(ff==true) {

break;

}else {

Elevator_RaiseToNearest(2,22);	
	
}

delay(1);
	
}while(ff!=true);
delay(40);
move=false;
Polyobj_DoorSlide(1,20,128,90,77);
Polyobj_DoorSlide(2,-20,128,90,77);

	
}	

if(sf==true) {
print(s:"calling elevator to 1st floor");
do {
	delay(30);
move=true;	
if(ff==true) {

break;

}else {

Elevator_lowerToNearest(2,22);	
	
}

delay(1);
	
}while(ff!=true);
move=false;
delay(40);
Polyobj_DoorSlide(1,20,128,90,77);
Polyobj_DoorSlide(2,-20,128,90,77);

	
}
	
}


break;

case 2: //2nd floor rooftop

if(sf==true) {

print(s:"Elevator is called already open door");
delay(55);
Polyobj_DoorSlide(1,20,128,90,77);
Polyobj_DoorSlide(2,-20,128,90,77);	

}else {
	
if(gf==true || ff==true) {
print(s:"calling elevator to 2nd  floor");
do {
move=true;	
if(sf==true) {

break;

}else {

Elevator_raiseToNearest(2,22);	
	
}

delay(1);
	
}while(sf!=true);
delay(40);
Polyobj_DoorSlide(1,20,128,90,77);
Polyobj_DoorSlide(2,-20,128,90,77);
move=false;
	
}	
	
}

break;
	
}	

}
	
}

script 4 (void) { //outer sw gf
sw=0;
ACS_Execute(3,0,0,0,0);		
}

script 5 (void) { //outer sw ff
sw=1;
ACS_Execute(3,0,0,0,0);		
}

script 6 (void) { //outer sw sf
sw=2;
ACS_Execute(3,0,0,0,0);		
}