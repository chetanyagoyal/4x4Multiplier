`timescale 1us / 1ns

module multtb;

initial 
begin
	$dumpfile("multtb.vcd");
	$dumpvars(0, multtb);
end

reg inA0; reg inA1; reg inA2; reg inA3; reg inB0; reg inB1; reg inB2; reg inB3;
wire p0; wire p1; wire p2; wire p3; wire p4; wire p5; wire p6; wire p7;

mult uut
(

	.product0(p0),
	.product1(p1),
	.product2(p2),
	.product3(p3),
	.product4(p4),
	.product5(p5),
	.product6(p6),
	.product7(p7),
	.A0(inA0),
	.A1(inA1), 
	.A2(inA2), 
	.A3(inA3), 
	.B0(inB0), 
	.B1(inB1), 
	.B2(inB2), 
	.B3(inB3)  
);
initial begin 
inB3=1'b0;
#128; 
inB3=~inB3;
#128
$stop();
end
initial begin inB2=1'b0; 
forever 
#64 
inB2=~inB2;
end
initial begin inB1=1'b0;
forever 
#32 
inB1=~inB1;
end
initial begin inB0=1'b0; 
forever 
#16 
inB0=~inB0;
end
initial begin inA3=1'b0;
forever 
#8 
inA3=~inA3;
end
initial begin inA2=1'b0; 
forever 
#4 
inA2=~inA2;
end
initial begin inA1=1'b0;
forever 
#2 
inA1=~inA1;
end
initial begin inA0=1'b0; 
forever 
#1 
inA0=~inA0;
end

initial 
begin
	$monitor("time = %2d, P0 = %1b, P1 = %1b, P2 = %1b, P3 = %1b, P4 = %1b, P5 = %1b, P6 = %1b, P7 = %1b", $time, p0, p1, p2, p3, p4, p5, p6, p7);
end

endmodule
