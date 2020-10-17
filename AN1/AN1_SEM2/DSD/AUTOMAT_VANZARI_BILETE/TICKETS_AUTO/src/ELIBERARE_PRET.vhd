library IEEE;
use IEEE. std_logic_1164.all;
use ieee.std_logic_unsigned.all;
use ieee.std_logic_arith.all;

entity RETURN_SUM is
	port(clk,undone,reset,en_sum: in std_logic;
    euro1, euro2, euro5, euro10, euro50: in std_logic_vector(3 downto 0);
	sum: in integer range 0 to 100;
	o1,o2,o5,o10,o50: out std_logic_vector(3 downto 0));
end RETURN_SUM;

architecture BEHAVIOUR of RETURN_SUM is
--internal signals--------------------------------------------------------
signal nr1,nr2,nr5,nr10,nr50: std_logic_vector(3 downto 0):="0000";	
signal ok1: std_logic:='0';
signal stp: integer:=0;
signal isum: integer range 0 to 100;
--code--------------------------------------------------------------------
begin  
process(clk) 
begin
if(clk='1' and clk'event and (undone='1' or RESET='1' or en_sum='0')) then   
	if (isum=0 and stp=0)  then
		isum<=sum; 
	elsif isum>49 and nr50<euro50 then
		isum<=isum-50;
		nr50<=nr50+"0001"; 
		stp<=1;	
	elsif isum>9 and nr10<euro10 then
		isum<=isum-10;
		nr10<=nr10+"0001"; 
		stp<=1;
	elsif isum>4 and nr5<euro5 then
		isum<=isum-5;
		nr5<=nr5+"0001";  
		stp<=1;
	elsif isum>1 and nr2<euro2 then
		isum<=isum-2;
		nr2<=nr2+"0001"; 
		stp<=1;   
	elsif isum>0 and nr1<euro1 then
		isum<=isum-1;
		nr1<=nr1+"0001";
		stp<=1;      
	end if;  
if(isum=0 and stp=1 and en_sum='1') then 
	o1<=nr1;
	o2<=nr2;
	o5<=nr5;
	o10<=nr10;
	o50<=nr50; 
end if;	   
end if;
end process;
end BEHAVIOUR;	   
	