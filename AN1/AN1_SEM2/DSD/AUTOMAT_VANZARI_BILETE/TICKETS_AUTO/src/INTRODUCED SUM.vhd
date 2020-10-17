library IEEE;
use IEEE.STD_LOGIC_1164.all;
use IEEE.STD_LOGIC_UNSIGNED.all;

entity suma_introd is
	port( reset,CLK,s1,s2,s5,s10,s50,en : in std_logic;
	sum: out integer range 0 to 100;
	an0, an1: out std_logic_vector(6 downto 0));	
end suma_introd; 


architecture suma of suma_introd is
signal nr1, nr2, nr5, nr10, nr50: std_logic_vector(3 downto 0);
shared variable suma: integer:=0;
begin
	process(clk,s1,s2,s5,s10,s50,en,reset) 
	begin
		if (en='1' and clk='1' and clk'event and suma<100) then
			if (s1='1' and s2='0' and s5='0' and s10='0' and s50='0') then suma:=suma+1; an0<="1001111";	an1<="0000001";
			elsif (s1='0' and s2='1' and s5='0' and s10='0' and s50='0') then suma:=suma+2;	an0<="0010010"; an1<="0000001";
			elsif (s1='0' and s2='0' and s5='1' and s10='0' and s50='0') then suma:=suma+5;	an0<="0100100";	an1<="0000001";
			elsif (s1='0' and s2='0' and s5='0' and s10='1' and s50='0') then suma:=suma+10; an1<="1001111"; an0<="0000001";
			elsif (s1='0' and s2='0' and s5='0' and s10='0' and s50='1')  then suma:=suma+50; an1<="0100100"; an0<="0000001";
			end if;
		END IF;
	  IF reset='1' then an0<="0000001"; an1<="0000001"; suma:=0;
			end if;
	sum<=suma;
	end process;
	
	end suma;