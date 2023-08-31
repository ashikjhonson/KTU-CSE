module half_Subtractor(a, b, c);
input a;
input b;
output d;
output b;
assign {b,d} = a-b;
endmodule