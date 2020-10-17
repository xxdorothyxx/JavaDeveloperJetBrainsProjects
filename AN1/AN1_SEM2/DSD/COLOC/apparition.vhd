library IEEE;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;
--16.	Design a circuit that counts the number of apparitions of the following
--bitstring: “0011”. One bit is received in each clock cycle. The maximum number of occurrences is 15.  
entity colocviu is
	port(x:in std_logic;
	clock:in std_logic;
	y:out std_logic_vector(3 downto 0);
	detect:out std_logic);
end colocviu;

architecture col of colocviu is	 
signal count:integer:=1;
signal intermediar:std_logic_vector(3 downto 0):="0000";
begin 
	process(clock,x)
	begin  
	if clock'event and clock='1'then
		intermediar(2 downto 0)<=intermediar(3 downto 1);
		intermediar(3)<=x;
		if intermediar="0011" then
			detect<='1';
			count<=count+1;
			if(count=15) then 
				count<=0;
				intermediar<="0000";
			end if;
	  else
		  detect<='0';
	 end if;	 
	 y<=intermediar; 
end if;
	 end process;	
		
end col;
