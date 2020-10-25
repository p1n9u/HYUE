module full_adder_16bit_stimulus;

reg[15:0] a, b;
reg cin;
wire[15:0] sum;
wire cout;


full_adder_16bit dut(a, b, cin, sum, cout);

initial
begin
a='h158A; b='h7095; cin=0;	// Initialize A, B, Cin
    #200 $finish;	// At t=200 end simulation
end

always begin	// Change A every 60 ns
    #60 a='h52AF; #60 a='hB903; #60 a='h158A; 
end

always begin	// Change B every 20 ns
    #20 b='h9A4E; #20 b='hC6BD; #20 b='h7095; 
end

always #10 cin = ~cin;	// Invert Cin every 10 ns

initial
begin
$monitor($time, " A=%b, B=%b, Cin=%b, sum= %b, cout=%b", a, b, cin, sum, cout);
end

/* 
Refer to testbench(https://www.edaplayground.com/x/39kK) checking and matching for wave forms
and I added $monitor statement.
The [ full_adder_16bit.v ] src_code is different and I wrote it myself.
*/ 

endmodule;