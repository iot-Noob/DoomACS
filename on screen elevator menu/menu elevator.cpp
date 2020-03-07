#include "zcommon.acs"
int hf[3],cfh,counter=0;
bool gf,ff,sf,move=false;

function int null(void) {
return 1;	
}

function void ele_door(void) {
Polyobj_DoorSlide(1,-11,128,89,88);
Polyobj_DoorSlide(2,11,128,89,88);		
}

function void ele_trainner(void) {

hf[0]=GetSectorFloorZ(1,0,0);
hf[1]=GetSectorFloorZ(3,0,0);
hf[2]=GetSectorFloorZ(4,0,0);	
}

script 1 enter {

ele_trainner();
while(1) {
//print(i:hf[0],i:hf[1],i:hf[2]);	
cfh=GetSectorFloorZ(2,0,0);	
delay(1);	
}	
}

script 2 enter {
while(1) {
if(cfh==hf[0]) {
gf=true;
ff=false;
sf=false;	
}
if(cfh==hf[1]) {
gf=false;
ff=true;
sf=false;	
}
if(cfh==hf[2]) {
gf=false;
ff=false;
sf=true;	
}
	
delay(1);	
}	
}




Script 2 (int buttons) //elevator menu
{
   int elemenu= 1;
   GiveInventory("PowerFrozen",1);
   setplayerproperty(0,1,PROP_TOTALLYFROZEN);
   fadeto(0,0,0,0.4,1.0);

   SETFONT("BIGFONT");

   hudmessage(s: "Ground Floor";
            HUDMSG_FADEOUT, 1, CR_GOLD, 0.4, 0.45, 60.0);
   hudmessage(s: "1st floor";
            HUDMSG_FADEOUT, 2, CR_GOLD, 0.4, 0.5, 60.0);
   hudmessage(s: "2nd floor";
            HUDMSG_FADEOUT, 3, CR_GOLD, 0.4, 0.55, 60.0);
   hudmessage(s: "Cancel";
            HUDMSG_FADEOUT, 4, CR_GOLD, 0.4, 0.6, 60.0);


   hudmessage(s: "Use forward/backward to move and Fire to select";
            HUDMSG_FADEOUT, 5, CR_BLUE, 0.5, 0.8, 60.0);


   while (True)
      {
      buttons = GetPlayerInput(0, INPUT_BUTTONS);

         if (buttons & BT_ATTACK)
            {
                  if ( elemenu == 1)
                     {
						if(move==true) {
						null();	
						}else {
							if(gf==true) {
							hudmessage(s: "Ground floor door opening!!";
                           HUDMSG_FADEINOUT, 6, CR_GREEN, 0.5, 0.6, 3.0, 0.5, 0.5);
						   
						ele_door();	
							}else {
								
							if(ff==true||sf==true) {
								hudmessage(s: "calling elevator to ground floor!!";
                           HUDMSG_FADEINOUT, 6, CR_RED, 0.5, 0.6, 3.0, 0.5, 0.5);
							move=true;
							do {
								ACS_Terminate(786,0);
							delay(22);	
							if(gf==true) {
							break;
							
							}else {
							Elevator_LowerToNearest(2,11);	
							}	
							}while(gf!=true);
							delay(33);
							move=false;
							ele_door();	
							}
								
							}
						}
                        
                     }
                  else if ( elemenu == 2)
                     {
                     if(move==true) {
						 null();
					 }else {
						  if(ff==true) {
						   hudmessage(s: "2nd floor arrived door_opening";
                           HUDMSG_FADEINOUT, 6, CR_BLUE, 0.5, 0.6, 3.0, 0.5, 0.5);
						ele_door();	
						}else {
						if(gf==true) {
						move=true;
						do {
							ACS_Terminate(786,0);
						delay(22);	
						if(ff==true) {
						break;	
						ACS_Execute(786,0);
						}else {
						Elevator_raiseToNearest(2,11);	
						}	
						}while(ff!=true);
						delay(33);
						move=false;
						ele_door();	
						}else {

						if(sf==true) {
						move=true;
						do {
							ACS_Terminate(786,0);
						delay(22);	
						if(ff==true) {
						break;	
						}else {
						Elevator_lowerToNearest(2,11);	
						}	
						}while(ff!=true);
						delay(33);
						move=false;
						ele_door();	
						}
							
						}
							
						}
					 }
                       
                     }
                  else if ( elemenu == 3)
                     {
						if(move==true) {
							null();
						}else {
						if(sf==true) {
					ele_door();	
					}else {
					if(gf==true||ff==true) {
					move=true;
					do {
						ACS_Terminate(786,0);
					delay(22);	
					if(sf==true) {
					break;	
					}else {
					Elevator_raiseToNearest(2,11);	
					}	
					}while(gf!=true);
					delay(33);
					move=false;
					ele_door();	
					}
						
					}	
						}
						
                     }

                  else
                     {}

                  fadeto(0,0,0,0.0,1.0);
                  delay(25);
                  TakeInventory("PowerFrozen",1);
                  setplayerproperty(0,0,PROP_TOTALLYFROZEN);
                  hudmessage(s: ""; HUDMSG_Plain, 1, 1, 0.0, 0.0, 1);
                  hudmessage(s: ""; HUDMSG_Plain, 2, 1, 0.0, 0.0, 1);
                  hudmessage(s: ""; HUDMSG_Plain, 3, 1, 0.0, 0.0, 1);
                  hudmessage(s: ""; HUDMSG_Plain, 4, 1, 0.0, 0.0, 1);
                  hudmessage(s: ""; HUDMSG_Plain, 5, 1, 0.0, 0.0, 1);
                  terminate;
            }

         else if (buttons & BT_FORWARD)
            {
                elemenu =  elemenu-1;
               if ( elemenu < 1)
                  {
                      elemenu= 4;
                  }
            }

         else if (buttons & BT_BACK)
            {
                elemenu=  elemenu+1;
               if ( elemenu> 4)
                  {
                      elemenu = 1;
                  }
            }

                  if ( elemenu == 1)
            {
            hudmessage(s: ">>";
               HUDMSG_FADEOUT, 6, CR_GREEN, 0.2, 0.45, 1.0);
            }
         else if ( elemenu == 2)
            {
            hudmessage(s: ">>";
               HUDMSG_FADEOUT, 6, CR_GREEN, 0.2, 0.5, 1.0);
            }
         else if ( elemenu == 3)
            {
            hudmessage(s: ">>";
               HUDMSG_FADEOUT, 6, CR_GREEN, 0.2, 0.55, 1.0);
            }
         else if ( elemenu == 4)
            {
            hudmessage(s: ">>";
               HUDMSG_FADEOUT, 6, CR_GREEN, 0.2, 0.6, 1.0);
            }

         delay(5);

      }
}