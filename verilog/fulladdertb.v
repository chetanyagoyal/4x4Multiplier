`timescale 1ns / 1ps 
 
module fulladdertb; 

initial begin
$dumpfile("fulladdertb.vcd"); 
$dumpvars(0, fulladdertb);
end

reg input1;
reg input2;
reg carryin;
 
wire out;
wire carryout;
 
 
fulladder uut (
.x(input1),
.y(input2),
.cin(carryin),
.A(out),
.cout(carryout)
);
 
initial
begin
	input1 = 0;
	input2 = 0;
	carryin = 0;
	#20; 
	input1 = 1;
	#20; 
	input2 = 1;
	#20; 
	input1 = 0;
	#20; 
	carryin = 1;
	#20; 
	input2= 0;
	#20; 
	input1= 1; 
	#20; 
	input2= 1;
	#40;
end
 
 
initial
begin
$monitor("time = %2d, CIN =%1b, IN1=%1b, IN2=%1b, COUT=%1b, OUT=%1b", $time,carryin,input2, input1,carryout,out);
end
 
endmodule
