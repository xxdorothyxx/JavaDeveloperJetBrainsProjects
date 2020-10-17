library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_unsigned.all;

entity ATM3 is 
	port (reset_aparat,CLK, S1, S2 ,S5 , S10 , S50 , EN,en_modif : in std_logic;
			e1,e2,e5,e10,e50 : in std_logic_vector(3 downto 0);
	       N1,N2,N5,N10,N50 : out std_logic_vector(3 downto 0));
end ATM3;

architecture BEHAVIOUR of ATM3 is  
signal int1,int2,int5,int10,int50 : std_logic_vector (3 downto 0):="1010";
begin 	
-------------------------- EURO1--------------------------------------------------
process (en,s1,s2,s5,s10,s50,en_modif,clk) 
variable modiff: bit :='0';
begin 
	if(clk'event and clk='1') then 
	if (reset_aparat='1') then int1 <="1010"; 
	 elsif(en_modif='1' and modiff='0') then int1<=e1; modiff:='1'; 
		 elsif (EN = '1' and s1='1' and s2='0' and s5='0' and s10='0' and s50='0') then	
			 int1<=int1+"0001";  
	end if;
	n1<=int1;
	end if;
	end process;		
-------------------------- EURO2--------------------------------------------------
process (en,s1,s2,s5,s10,s50,en_modif,clk) 	 
variable modiff: bit :='0';
begin 
	if(clk'event and clk='1') then 
	if (reset_aparat='1') then int2 <="1010"; 
		elsif(en_modif='1'and modiff='0') then int2<=e2; modiff:='1';
		 elsif (EN = '1' and s1='0' and s2='1' and s5='0' and s10='0' and s50='0') then	
			 int2<=int2+"0001";  
	--end if;
	end if;
	n2<=int2;
	end if;
	end process;
-------------------------- EURO5--------------------------------------------------
process (en,s1,s2,s5,s10,s50,en_modif,clk) 
variable modiff: bit :='0';
begin 
	if(clk'event and clk='1') then 
	if (reset_aparat='1') then int5 <="1010"; 
		elsif(en_modif='1'and modiff='0') then int5<=e5; modiff := '1';
		 elsif (EN = '1' and s1='0' and s2='0' and s5='1' and s10='0' and s50='0') then	
			 int5<=int5+"0001";  
	end if;
	n5<=int5;
	end if;
	end process;
-------------------------- EURO10--------------------------------------------------
process (en,s1,s2,s5,s10,s50,en_modif,clk) 
variable modiff: bit :='0';
begin 
	if(clk'event and clk='1') then 
	if (reset_aparat='1') then int10 <="1010"; 
		elsif(en_modif='1'and modiff='0') then int10<=e10; modiff := '1';
		 elsif (EN = '1' and s1='0' and s2='0' and s5='0' and s10='1' and s50='0') then	
			 int10<=int10+"0001";  
	end if;
	n10<=int10;
	end if;
	end process;
-------------------------- EURO50--------------------------------------------------
process (en,s1,s2,s5,s10,s50,en_modif,clk) 
variable modiff: bit :='0';
begin 
	if(clk'event and clk='1') then 
	if (reset_aparat='1') then int50 <="1010"; 
		elsif(en_modif='1'and modiff='0') then int50<=e50; modiff:='1';
		 elsif (EN = '1' and s1='0' and s2='0' and s5='0' and s10='0' and s50='1') then	
			 int50<=int50+"0001";  
	end if;
	n50<=int50;
	end if;
	end process;
END BEHAVIOUR;