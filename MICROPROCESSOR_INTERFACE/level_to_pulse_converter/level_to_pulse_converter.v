module LevelToPulse(level, clk, reset, pulse);
    input level;
    input clk;
    input reset;
    output pulse;
    reg pulse;
    reg prestate, nextstate;

    parameter s0=0, s1=1;

    always @(posedge clk, posedge reset)
        if (reset)
	    prestate <= s0;
        else
	    prestate <= nextstate;

    always @(prestate, level)
    begin
        nextstate = prestate;
	pulse = 1'b0;
	case(prestate)
 	    s0: 
	        if(level)
 		begin
 		    pulse = 1'b1; nextstate = s1;
 	        end
 	    s1: 
		if(~level)
 		    nextstate = s0;
 	endcase
    end
endmodule 
