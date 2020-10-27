module full_adder_16bit_stimulus;
    reg[15:0] a, b;
    reg cin;
    wire[15:0] sum;
    wire cout;

    full_adder_16bit dut(a, b, cin, sum, cout);

    initial
    begin
        a='h158A; b='h7095; cin=0;
        #200 $finish;
    end

    always
    begin
        #60 a='h52AF; #60 a='hB903; #60 a='h158A; 
    end

    always 
    begin
        #20 b='h9A4E; #20 b='hC6BD; #20 b='h7095; 
    end

    always 
        #10 cin = ~cin;

    initial
        $monitor($time, " A=%b, B=%b, Cin=%b, sum= %b, cout=%b", a, b, cin, sum, cout);

/* 
 * Refer to testbench(https://www.edaplayground.com/x/39kK) checking and matching for wave forms and I added $monitor statement.
 * The [ full_adder_16bit.v ] src_code is different and I wrote it myself.
 */ 

endmodule;
