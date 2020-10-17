library IEEE;
use IEEE.STD_LOGIC_1164.all;
use IEEE.STD_LOGIC_UNSIGNED.all;

entity numarator_bilete is
	port( CLK: in STD_LOGIC; 
	nr_bilete : in std_logic_vector(3 downto 0 );
	reset_automata,reset: in std_logic;
	OK,en_modif: in std_logic;
	bilet: out std_logic;
	count : out std_logic_vector(3 downto 0);
	warning,modif,undone: out std_logic
	);
end numarator_bilete; 

architecture counter of numarator_bilete is
-----------------internal signals----------------
signal icount : std_logic_vector(3 downto 0);
signal ibilet : bit:='0'; 
-----------------------code----------------------
begin  										  
process(clk) 
begin	 
	if(clk='1' and clk'event and ok='1' and reset_automata='0' and ibilet='0' and reset='0') then
	if 	(en_modif='1') then 
		count<=nr_bilete-"0001"; 
	else count<="1110"; 	
	end if;
	if (nr_bilete = "0001" and en_modif = '1') THEN
		warning<='1'; bilet<='0'; modif <= '0';	  undone<='1';
	elsif(ok='1') then
		warning<='0'; bilet<='1';  modif<='1'; ibilet<='1'; undone<='0';
	end if;	
	end if;	
	if reset_automata = '1' then count <= "1111"; modif<='0'; bilet<='0'; undone<='0'; end if;
	if reset='1' then bilet<='0'; undone <='0'; end if;
end process;
end counter;