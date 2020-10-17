library ieee;				   			  
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all; 
use ieee.numeric_std;

entity COMPARATOR is
	port(A, B: in integer range 0 to 100;
    bigger, smaller, equal: out std_logic);
	
end COMPARATOR;
architecture comp of COMPARATOR is 
begin 		  
	bigger<='1' when A>B else '0';
	equal<='1' when A=B else '0';
	smaller<='1' when A<B else '0';	
end comp;