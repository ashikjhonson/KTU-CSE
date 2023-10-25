module NOT(a, c);
    input a;
    output c;
    reg c;
    always@(a)
    c <=(~a);
endmodule