module full_adder_16bit(a, b, cin, sum, cout);
    input[15:0] a, b;
    input cin;
    output[15:0] sum;
    output cout;
    wire c1, c2, c3;

    full_adder_4bit FA4_0(a[3:0], b[3:0], cin, sum[3:0], c1);
    full_adder_4bit FA4_1(a[7:4], b[7:4], c1, sum[7:4], c2);
    full_adder_4bit FA4_2(a[11:8], b[11:8], c2, sum[11:8], c3);
    full_adder_4bit FA4_3(a[15:12], b[15:12], c3, sum[15:12], cout);
endmodule;

module full_adder_4bit(a, b, cin, sum, cout);
    input[3:0] a, b;
    input cin;
    output[3:0] sum;
    output cout;
    wire c1, c2, c3;

    full_adder FA0(a[0], b[0], cin, sum[0], c1);
    full_adder FA1(a[1], b[1], c1, sum[1], c2);
    full_adder FA2(a[2], b[2], c2, sum[2], c3);
    full_adder FA3(a[3], b[3], c3, sum[3], cout);
endmodule;

module full_adder(a, b, cin, sum, cout);
    input a, b, cin;
    output sum, cout;
    reg sum, cout;

    always @(a or b or cin)
    begin
        sum = a ^ b ^ cin;
	cout = (a & b) | (a & cin) | (b & cin);
    end
endmodule
