module half_Adder(a, b, c);
input a;
input b;
output s;
output c;
assign {c,s} = a+b;
endmodule