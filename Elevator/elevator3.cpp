#include "zcommon.acs"
#define GFH 0
#define FFH 10485760
#define SFH 20971520
#define TFH 31457280

int swc=-1;
int sc;
int cfh;
bool move=false;
bool gf,ff,sf,tf=false;
function void hc (void) {
if(move==true) {
null();	
}else {
if(cfh==GFH) {
gf=true;
ff=false;
sf=false;
tf=false;
}
if(cfh==FFH) {
gf=false;
ff=true;
sf=false;
tf=false;
}
if(cfh==SFH) {
gf=false;
ff=false;
sf=true;
tf=false;
}
if(cfh==TFH) {
gf=false;
ff=false;
sf=false;
tf=true;
}
	
}

}

function int null(void)
{
return 1;
}

script 1 enter {
while(1) {
hc();	
cfh=GetSectorFloorZ(1,0,0);	
hc();
delay(1);	
}	

}

script 2 (void) {
if(move==true) {
null();	
}else {
if(swc==3) {
swc=-1;	
}else {
swc++;	
switch (swc) {
case 0:
print(s:"Ground floor");
sc=swc;
break;

case 1:
print(s:"1st floor");
sc=swc;
break;

case 2:
print(s:"2nd floor");
sc=swc;
break;

case 3:
print(s:"3rd floor");
sc=swc;
break;	
}

}
	
}	

}

script 3 (void) {
if(move==true) {
null();	
}else {
switch (sc) {
	
case 0:
if(gf==true) {
	null();	
	print(s:"Elevator already called to ground floor");

}else {
print(s:"Calling elevator to ground floor");	
do {
hc();
delay(100);
if(gf==false) {
Elevator_LowerToNearest(1,11);	
}else {
ACS_Terminate(3,0);
break;	
}
hc();
delay(1);	
}while(gf!=true);
	
}
break;	

case 1:
if(ff==true) {
	null();	
	print(s:"Elevator already called to 1st floor");

}else {
hc();
if(sf==true||tf==true) {
print(s:"Calling elevator to 1st floor");	
do {
delay(130);
hc();	
if(ff==false) {
Elevator_LowerToNearest(1,11);	
}else {
ACS_Terminate(3,0);
break;	
}
hc();

delay(1);	
}while(ff!=true);
}
hc();
if(gf==true) {
hc();
print(s:"Calling elevator to 1st floor");		 
do {
hc();	
delay(100);
if(ff==false) {
Elevator_raiseToNearest(1,11);	
}else {
ACS_Terminate(3,0);	
break;
}
hc();
delay(1);	
}while(ff!=true);
break;
}
	
}	
break;

case 2:
if(sf==true) {
	null();	
	print(s:"Elevator already called to 2nd floor");

}else {
hc();
if(tf==true) {
print(s:"Calling elevator to 2nd floor");	
do {
delay(130);
hc();	
if(sf==false) {
Elevator_LowerToNearest(1,11);	
}else {
ACS_Terminate(3,0);
break;	
}
hc();

delay(1);	
}while(sf!=true);
}
hc();
if(gf==true||ff==true) {
hc();
print(s:"Calling elevator to 1st floor");		 
do {
hc();	
delay(100);
if(sf==false) {
Elevator_raiseToNearest(1,11);	
}else {
ACS_Terminate(3,0);	
break;
}
hc();
delay(1);	
}while(sf!=true);
break;
}
	
}
break;

case 3:

if(tf==true) {
	null();	
	print(s:"Elevator already called to 3rd floor");

}else {
hc();
if(gf==true||ff==true||sf==true) {
print(s:"Calling elevator to 3rd floor");	
do {
delay(130);
hc();	
if(tf==false) {
Elevator_raiseToNearest(1,11);	
}else {
ACS_Terminate(3,0);
break;	
}
hc();
delay(1);	
}while(tf!=true);
}

	
}

break;
}	

}	

}

