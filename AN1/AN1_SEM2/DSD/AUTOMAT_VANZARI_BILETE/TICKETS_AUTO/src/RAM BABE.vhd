LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.STD_LOGIC_UNSIGNED.ALL;

entity myRAM is
	port (ADRESA: in std_logic_vector(2 downto 0);
	E1,E2,E5,E10,E50,BILET: out std_logic_vector(3 downto 0);
	iE1,iE2,iE5,iE10,iE50,iBILET:in std_logic_vector(3 downto 0);
	WE: in std_logic); ---WRITE ENABLE
end myRAM;

architecture ARCH_RAM of myRAM is
type MM is array (5 downto 0) of std_logic_vector(3 downto 0);
signal harta: MM:=("1010", 	  --50 euro   5
				   "1010",    --10 euro   4
				   "1010",    --5 euro	  3
				   "1010",    --2 euro	  2
				   "1010",    --1 euro	  1
				   "1111" );  --bilete	  0
begin
	process(iE1,iE2,iE5,iE10,iE50,iBILET,WE,ADRESA)
	begin
		if WE='1' then
			if ADRESA="101" then
			HARTA(CONV_INTEGER(ADRESA))<=iE50;
			
			elsif ADRESA="100" then
				HARTA(CONV_INTEGER(ADRESA))<=iE10;
				
			elsif ADRESA="011" then
				HARTA(CONV_INTEGER(ADRESA))<=iE5;
				
			elsif ADRESA="010" then
				HARTA(CONV_INTEGER(ADRESA))<=iE2;
				
			elsif ADRESA="001" then
				HARTA(CONV_INTEGER(ADRESA))<=iE1;
			elsif ADRESA="000" then
				HARTA(CONV_INTEGER(ADRESA))<=iBILET;
				end if;
		elsif WE='0' THEN 
			if ADRESA="101" then
			E50<=HARTA(CONV_INTEGER(ADRESA));
			elsif ADRESA="100" then
				E10<=HARTA(CONV_INTEGER(ADRESA));
			elsif ADRESA="011" then
				E5<=HARTA(CONV_INTEGER(ADRESA));
			elsif ADRESA="010" then
				E2<=HARTA(CONV_INTEGER(ADRESA));
			elsif ADRESA="001" then
				E1<=HARTA(CONV_INTEGER(ADRESA));
			elsif ADRESA="000" then
				BILET<=HARTA(CONV_INTEGER(ADRESA));
				end if;
		end if;
	end process;
end ARCH_RAM;