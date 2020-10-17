library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;
use ieee.std_logic_arith.all;
 
 entity eliberare_rest is
	 port(clk: in std_logic;
	 en_rest : in bit;
	 rst : in std_logic;
	 euro1, euro2, euro5, euro10, euro50: in std_logic_vector(3 downto 0);
	 rest: in integer range 0 to 100;
	 ok,warning,en_modif,en_sum: out std_logic;
	 e1,e2,e5,e10,e50 : out std_logic_vector(3 downto 0);
	 o1,o2,o5,o10,o50: out std_logic_vector(3 downto 0));
 end eliberare_rest;
 
 
 architecture rest of eliberare_rest is
 -------semnale interne
 signal nr1,nr2,nr5,nr10,nr50: std_logic_vector(3 downto 0):="0000";
 signal stp: integer range 0 to 1;
 signal irest: integer range 0 to 100; 
 signal ok_rest: std_logic; 
 signal eSum : std_logic:='0';
 ------------------------------------
begin  
	process(rst,en_rest,clk) 
	begin
	if(clk'event and clk='1' and en_rest='1' and rst='0') then  
		if irest=0 and stp=0  then irest<=rest;
	       elsif irest>49 and nr50<euro50 then
			irest<=irest-50;
			nr50<=nr50+"0001"; 
			stp<=1;
		   elsif irest>9 and nr10<euro10 then
			irest<=irest-10;
			nr10<=nr10+"0001"; 
			stp<=1;
		  	
		   elsif irest>4 and nr5<euro5 then
			irest<=irest-5;
			nr5<=nr5+"0001";  
			stp<=1;
		   elsif irest>1 and nr2<euro2 then
			irest<=irest-2;
			nr2<=nr2+"0001"; 
			stp<=1;   
		   elsif irest>0 and nr1<euro1 then
			irest<=irest-1;
			nr1<=nr1+"0001";
			stp<=1; 
		   end if;	
if(irest=0 and stp=1) then 
	ok_rest<='1';
end if;	
if(ok_rest='1') then
	warning<='0';
	o1<=nr1;
	o2<=nr2;
	o5<=nr5;
	o10<=nr10;
	o50<=nr50;
	e1<=euro1-nr1;
	e2<=euro2-nr2;
	e5<=euro5-nr5;
	e10<=euro10-nr10;
	e50<=euro50-nr50;	
	en_modif<='1';
	eSum<='0';
end if;	
if(ok_rest='0') then 
		warning<='1';
	o1<="0000";
	o2<="0000";
	o5<="0000";
	o10<="0000";
	o50<="0000";
	en_modif<='0'; 
	eSum<='1';
end if;	 
ok<=ok_rest; en_sum<=eSum;
end if;	  
if rst='1' then 
	ok<='0';
	warning<='1';
	o1<="0000";
	o2<="0000";
	o5<="0000";
	o10<="0000";
	o50<="0000";
	en_modif<='0'; 
	eSum<='1';
end if;
end process; 

end rest;