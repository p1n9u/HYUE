module SR_Latch_stimulus;
wire q, qbar;   reg set, reset; 
SR_latch m1(q, qbar, ~set, ~reset);
initial 
begin 
  	$monitor($time, " set = %b,   	reset= %b, %b\n",set,reset,q); 
	set = 0; reset = 0; 
	#5 reset = 1; 
	#5 reset = 0; 
	#5 set = 1; 
end 
endmodule 
