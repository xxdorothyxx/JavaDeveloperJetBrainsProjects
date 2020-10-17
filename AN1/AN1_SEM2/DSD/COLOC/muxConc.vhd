library IEEE; 
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL; 
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity mux is
	port(a,b,c,d: in std_logic_vector(3 downto 0);
	sel: in std_logic_vector(1 downto 0);
	output: out std_logic_vector(3 downto 0));
end mux;

architecture arh of mux is
begin
output <= 
		a when sel = "00" else
		b when sel = "01" else
		c when sel = "10" else
		d when sel = "11";	
end arh;
			