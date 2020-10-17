--Design a FSM that has the following behavior:
--It has 4 states; It stays one clock cycle in the first and the second states, 
--then 4 cycles in the 3-rd state and 2 clock cycles in the last state.
--It only goes to the second state if an enable signal is active.
	--The FSM outputs the value of the counter in each of last two states (for the first 2 the output is 0).
library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all;
use IEEE.std_logic_unsigned.all;

entity colocv is   
	port(clk:in std_logic;
	z:out std_logic_vector(0 to 3);
	enable:in std_logic);
	
end colocv;

architecture behav of colocv is	 

type stare is( unu,doi,trei,patru);
signal current_state:stare;	 


begin	
	process(clk) 
	variable count:std_logic_vector(0 to 3):="0000";
	begin		
		if(clk'event and clk='1') then
			count:=count+1;	
			
		if(count="0001") then 
			current_state<=unu;
			z<=count;
		elsif(count="0010" and enable='1') then
			current_state<=doi;	 
			z<=count;	 
		elsif(count>="0010" and count<="0110") then
			current_state<=trei;
			Z<=count;		   
		elsif(count>="0110" and count<="1000") then
			current_state<=patru;
			Z<=count;
		end if;
		if (count = "1000") then
			count:="0000";
		end if;
	end if;	
 	end process;
		
end behav  ;