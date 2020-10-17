library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity vhdl_binary_counter is
   port(CLK, CLR,en_check : in std_logic;  
   		en_bilet : out std_logic;
		Q : out std_logic_vector(3 downto 0));
end vhdl_binary_counter;

architecture bhv of vhdl_binary_counter is
signal tmp: std_logic_vector(3 downto 0):="1111";
begin
process (CLK, CLR,en_check)
begin	
if(en_check='1')
if (CLR=’1') then
tmp <= "1111";
elsif (CLK’event and CLK='1') then
tmp <= tmp - 1;
end if;	 
end if;
end process;
Q <= tmp;
end bhv;