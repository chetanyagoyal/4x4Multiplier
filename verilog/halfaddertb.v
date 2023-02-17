`timescale 1ns / 1ps 

module halfaddertb;

initial 
begin
	$dumpfile("halfaddertb.vcd");
	$dumpvars(0, halfaddertb);
end

reg input1;
reg input2;

wire sumOut;
wire carryOut;

halfadder uut
(
	.a(input1),
	.b(input2),
	.sum(sumOut),
	.carry(carryOut)
);

initial 
begin
	input1 = 0;
	input2 = 0;
	#40;
	input1 = 1;
	input2 = 1;
	#40;
	input1 = 1;
	input2 = 0;
	#40;
	input1 = 0;
	input2 = 1;
	#40;
	input1 = 0;
	input2 = 0;
	#40;
	input1 = 1;
	input2 = 1;
	#40;
	input1 = 1;
	input2 = 0;
	#40;
	input1 = 0;
	input2 = 1;
	#40;s
end

initial 
begin 
	$monitor("time = %2d, A = %1b, B = %1b, Carry = %1b, Sum = %1b", $time, input1, input2, 		carryOut, sumOut);
end

endmodule



