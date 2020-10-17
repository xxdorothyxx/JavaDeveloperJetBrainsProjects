library IEEE;	   

use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all;
use IEEE.std_logic_unsigned.all;

entity RegistruSHR is
	generic (N:natural:=7);
	port( inRegister :in bit_vector(N-1 downto 0);	
	clk :in bit;		  
	outRegister :out bit_vector(N-1 downto 0);
	reset: in bit;
	load: in bit;
	value:in bit;
	DumpedBit: out bit;
	Shift:in bit);
	
end RegistruSHR;				 


architecture Behave of RegistruSHR is	   
signal NewBitValue: bit;
begin 
process(clk,reset,load,value,shift) 
variable Nume: bit_vector (N-1 downto 0);
begin	
	if shift = '1' then
	NewBitValue<=value;
    end if;
		
		if CLK'EVENT and clk='1'  then		
		
		if (reset='1' and load='0'and shift='0')	then
		for i in 0 to N-1 loop
			Nume(i) :='0';		 
	    end loop;	
			
		end if;
			
		if (reset='0' and load='1'and shift='0')	then
		for i in 0 to N-1 loop
			Nume(i) :=inRegister(i);		 
	    end loop;
		end if;
		
		if (shift='1'and reset='0'and load='0')	then
		DumpedBit<=Nume(0);
		
		for i in 0 to N-2 loop
			 Nume(i):=Nume(i+1);
		end loop;
		Nume(N-1):=NewBitValue;
		end if;
		
		end if;
	outRegister<=Nume;	
	end process;
	
end  Behave;
