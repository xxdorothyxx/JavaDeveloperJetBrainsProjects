library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity distanta is
	port(RESET,s2,s1,s0,clk,en: in std_logic;
	digit0, digit1, digit2 : out std_logic_vector(3 downto 0);
	price: out integer range 0 to 100);
end distanta;

architecture distanta_introdusa of distanta is		  
--------------internal signals-------------------------------
signal d0,d1,d2: std_logic_vector(3 downto 0):="0000";
shared variable pret: integer range 0 to 100;				  
begin
----SUTE
process(clk,reset,en) 
begin
if(clk='1' and clk'event and en = '1' ) then
	if (s2='1' and s1='0' and s0='0' and RESET='0') then
		d2<="0001";
		pret:=pret+100;
	end if;
	end if;
    if RESET='1' then d2<="0000"; pret:=0; 
	end if;
end process;
digit2<=d2; 
-----ZECI
process(clk,reset,en)
begin
if(clk='1' and clk'event and en ='1') then
		if (s1 = '1' and d1<"1001" and s2='0' and s0='0' and RESET='0') then
		d1<=d1+"0001";
		pret:=pret+10;
		elsif (s1='1' and s2='0' and s0='0' and RESET='0') then d1<="0000"; pret:= pret-90;
		end if;
		end if;
		if RESET='1' then d1<="0000"; pret:=0;
	end if;   
end process;
digit1<=d1;
------UNITATI
process(clk,reset,en)   
begin
if(clk='1' and clk'event and en = '1') then
	if(s0='1' and d0<"1001" and s2='0' and s1='0' and RESET='0') then
		d0<=d0+"0001";
		pret:=pret+1;			  
	elsif (s1='0' and s2='0' and s0='1' and RESET='0') then d0<="0000"; pret:= pret-9;	
	end if;	
	end if;
	if RESET='1' then d0<="0000"; pret:=0;
	end if;			   
price<=pret;
end process;
digit0<=d0;   						 
end distanta_introdusa;