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
	process(a,b,c,d,sel)
	begin
		case sel is
			when "00" => output <= a;
			when "01" => output <= b;
			when "10" => output <= c;
			when others => output <= d;
		end case;
	end process;
end arh;
			