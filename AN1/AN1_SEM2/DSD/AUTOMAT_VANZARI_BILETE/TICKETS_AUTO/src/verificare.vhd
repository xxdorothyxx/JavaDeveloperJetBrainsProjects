library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;


entity verificare is
	port(rst,en_verificare : in std_logic;
	pret, suma : in integer range 0 to 100;
	warning : out bit;
	en_rest : out bit;
	rest: out integer range 0 to 100);
end verificare;

architecture verif of verificare is
---------------internal signals----------------------
signal big, small, equall: std_logic:='0';
signal ienable : bit;
signal irest : integer range 0 to 100;
---------------components----------------------------
component COMPARATOR is
	port(A, B: in integer range 0 to 100;
	     bigger, smaller, equal: out std_logic);
end component ;
BEGIN
 L1: COMPARATOR port map(suma, pret, big, small, equall);
rest<=suma-pret when ( big = '1' or equall='1') and (en_verificare = '1' and rst='0');	
process(big,small,equall,en_verificare,rst)
begin
 if ( big = '1' or equall='1') and (en_verificare = '1' and rst='0' ) then   en_rest<='1'; warning<='0';  end if;
 if (small='1' and en_verificare = '1')	or rst='1' then en_rest<='0'; end if; 
 if (small='1' and en_verificare = '1') then warning<='1';	 end if;
end process; 
end verif;