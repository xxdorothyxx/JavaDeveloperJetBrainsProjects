library IEEE;
use IEEE.STD_LOGIC_1164.all;

entity PAYING is
	port( CLK,S1,S2,S5,S10,S50,EN : in std_logic;
		  an1,an0 : out std_logic_vector( 6 downto 0));
end PAYING;

architecture BEHAVIOUR of PAYING is	
-----------------------------------------------------------
begin
	-- DISPLAYING THE MONEY INTRODUCED PROCESS
	DISPLAY : process(CLK,EN)
	begin		
		if((CLK = '1' and CLK'EVENT) and EN = '0') then	
			if S1 = '1'	then
		       an0   <= "1001111"; 
			elsif S2 = '1' then 
			   an0<="0010010";
		    elsif S5 = '1' then
				an0<="0100100";
			else
				 an0<="0000001";
		end if;
	   end if;
	   if((CLK = '1' and CLK'EVENT) and EN = '0') then	
			if S10 = '1'	then
		       an1   <= "1001111"; 
			elsif S50 = '1' then 
			   an1<="0100100";
			else
				 an1<="0000001";
		end if;
	   end if;
	end process DISPLAY;
end BEHAVIOUR;
	