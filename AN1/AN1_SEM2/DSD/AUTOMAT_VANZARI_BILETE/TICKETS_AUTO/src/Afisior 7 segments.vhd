library IEEE;
use IEEE.STD_LOGIC_1164.all;

entity SEVEN_SEGMENT is
	port ( BINARY : in std_logic_vector(3 downto 0);
		       EN,clk : in std_logic;
	       TO_SGM : out std_logic_vector(6 downto 0));
end SEVEN_SEGMENT;	

architecture LED of SEVEN_SEGMENT is
begin	  
	process(BINARY,EN)
	begin
	if (EN='1') then 
	 if BINARY="0000" then TO_SGM <= "0000001";  --digit : 0
  elsif BINARY="0001" then TO_SGm<= "1001111";	 --digit : 1
  elsif BINARY="0010" then TO_SGm<= "0010010";  --digit : 2
  elsif BINARY="0011" then TO_SGm<= "0000110";  --digit : 3
  elsif BINARY="0100" then TO_SGm<= "1001100";  --digit : 4
  elsif BINARY="0101" then TO_SGm<= "0100100";	 --digit : 5
  elsif BINARY="0110" then TO_SGm<= "0100000";  --digit : 6
  elsif BINARY="0111" then TO_SGm<= "0001101";  --digit : 7
  elsif BINARY="1000" then TO_SGm<= "0000000";  --digit : 8
  elsif BINARY="1001" then TO_SGM <="0000100";	--digit : 9 
end if;
elsif EN='0' then to_sgm<="0000001";
end if;
end process;
end LED;