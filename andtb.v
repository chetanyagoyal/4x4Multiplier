`timescale 1ns / 1ps 

module andtb; 

initial begin
$dumpfile("andtb.vcd"); 
$dumpvars(0, andtb);
end

reg input1;
reg input2; 

wire out;

and2 uut
(
	.a(input1), 
	.b(input2), 
	.andOut(out)
);

initial 
begin
	input1 = 0;
	input2 = 0;
	#20;
	input1 = 1;
	input2 = 1;
	#20;
	input1 = 1;
	input2 = 0;
	#20;
	input1 = 0;
	input2 = 1;
	#40;
end

initial 
begin 
	$monitor("time = %2d, A = %1b, B = %1b, AND = %1b", $time, input1, input2, out);
end

endmodule