module OR(a, b, c);
    input a;
    input b;
    output c;
    reg c;
    always@(a,b)
    c <=(a | b);
endmodule