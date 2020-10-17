library IEEE;
use IEEE.std_logic_1164.all;
-- Design a circuit that signals the apparition of the following bitstring: “00100”. One bit is received in each clock cycle.  

entity subiect is
	
	port(
	a : in std_logic;
	y : out std_logic;
	clk : in std_logic);
end subiect;

architecture arch of subiect is

signal vector : std_logic_vector(4 downto 0);

begin
	
	process(clk, a)
	begin
		
		if clk'event and clk = '1' then	  
			vector(3 downto 0) <= vector(4 downto 1);
			vector(4) <= a;
		end if;
		
		if vector = "00100" then  
			Y <= '1';
		else
			Y <= '0';
		end if;
			
	end process;
	
end arch;