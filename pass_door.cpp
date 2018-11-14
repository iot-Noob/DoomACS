#include "zcommon.acs"
int top=-1;
int store[2][3]={{4,2,3},{0}};
int num=-1;
function void NumPad(void) {
num++;
if(num==10) {
num=-1;	
}

print(i:num);	
}
function void push(int a) {
if(top==2) {
print(s:"Memory full\n");	
}else {
store[1][++top]=a;
}
print(i:store[1][top]);	
}
function void pop(void) {
if(top==-1) {
print(s:"Invalid Password\n");	
}else {
store[1][top]=0;
top--;
}
	
}
script 1 (void) {
NumPad();	

}
script 2 (void) {
if(num==0) {
for(int r=0;r<3;r++) {
pop();	
}	

}	
if(top==2){
for(int i=0;i<2+1;i++) {
if(store[0][i]==store[1][i]) {
	print(s:"Welcome To Doom");
door_open(1,11,0);

}else {
	for(int h=0;h<3;h++) {
	pop();	
	delay(11);
	}	
}	

}	

}else {
push(num);	
}	

}
