// based on mealy fsm
module LevelToPulse_stimulus;
    reg clk; 
    reg level; 
    reg reset; 
    wire pulse; 

    LevelToPulse ltp_fsm(level, clk, reset, pulse); 

    initial 
    begin 
        $display("\t\t  Time  Level  Pulse\n"); 
	$monitor("%d      %d      %d", $time, level, pulse); 
    end 

    initial
    begin 
        clk = 1'b0; 
  	level = 1'b0; 
  	reset = 1'b0;

  	#20 reset = 1'b1; 
	#10 reset = 1'b0;

  	#30 level = 1; #200 level = 0;
	#160 level = 1; #40 level = 0;
	#40 level = 1;
  	#200 $finish; 
    end

    always
        #20 clk = ~clk;
endmodule 
