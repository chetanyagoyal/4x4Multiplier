module fulladder
(
 	input x_fa,
 	input y_fa,
 	input cin_fa,
 	output sum_fa, 
 	output carry_fa
);
 
assign {carry_fa, sum_fa} =  cin_fa + y_fa + x_fa;
endmodule

module halfadder
(
	input a_ha,
	input b_ha,
	output sum_ha,
	output carry_ha
);

assign sum_ha = a_ha ^ b_ha;
assign carry_ha = a_ha & b_ha;
endmodule

module mult(product0,product1,product2,product3,product4,product5,product6,product7, A0,A1,A2,A3,B0,B1,B2,B3);

input A0;
input B0;
input A1;
input B1;
input A2;
input B2;
input A3;
input B3;
output product0;
output product1;
output product2;
output product3;
output product4;
output product5;
output product6;
output product7;

wire cha1, sfa1, cfa1, sfa2, cfa2, sfa3, cfa3, sfa4, cfa4, sfa5, cfa5, cfa6, cfa7, cha4, cha3, cha2, sha2;

assign product0 = (A0 & B0);
halfadder h1((A0 & B1),    (A1 & B0), product1, cha1);
fulladder f1((A1 & B1),    (A2 & B0), cha1, sfa1, cfa1);
fulladder f2((A2 & B1),    (A3 & B0), cfa1, sfa2, cfa2);
halfadder h2((A3 & B1), 	     	      cfa2, sha2, cha2);
halfadder h3((A0 & B2), 	        sfa1, product2, cha3);
fulladder f3((A1 & B2), 	        cha3, sfa2, sfa3, cfa3);
fulladder f4((A2 & B2), 	        sha2, cfa3, sfa4, cfa4);
fulladder f5((A3 & B2), 	        cha2, cfa4, sfa5, cfa5);
halfadder h4((A0 & B3), 	        sfa3, product3, cha4);
fulladder f6((A1 & B3),       cha4, sfa4, product4, cfa6);
fulladder f7((A2 & B3),       cfa6, sfa5, product5, cfa7);
fulladder f8((A3 & B3), cfa5, cfa7, product6, product7);
endmodule

