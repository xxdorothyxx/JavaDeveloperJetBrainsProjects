--Design a 16 (locations) X 4-bit memory that has 1 asynchronous input port (for write) and 2 synchronous output (read) ports. 
library IEEE;	   
use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all;
use IEEE.std_logic_unsigned.all;

entity colocviuDsd is
	port( add1 : in std_logic_vector( 0 to 3);  
		 add2 : in std_logic_vector( 0 to 3);  
	input : in std_logic_vector( 0 to 3);
	we : in std_logic;
	clk : in std_logic;
	re : in std_logic;
	o1 : out std_logic_vector( 0 to 3);
	o2 : out std_logic_vector ( 0 to 3));
end colocviuDsd;



architecture colocviuDsd of colocviuDsd is
type matrix is array (15 downto 0) of std_logic_vector(3 downto 0);
signal mem: matrix;
begin
   process(clk,we)
   begin
	   if(we='1')  then
		   mem(conv_integer(add1))<=input;
	   else
		   if(clk'event and clk='1' and re='1') then
			   o1<=mem(conv_integer(add1));
			   o2<=mem(conv_integer(add2));
		   end if;
	   end if;
	   end process;

end colocviuDsd;
