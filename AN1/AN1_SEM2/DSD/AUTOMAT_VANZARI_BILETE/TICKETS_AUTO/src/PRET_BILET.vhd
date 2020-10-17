library IEEE;
use IEEE.STD_LOGIC_1164.all;

entity PRET_BILET is
	port (CLK,RESET,EN,s0,s1,s2: in std_logic;			
	      an2,an1,an0 : out std_logic_vector(6 downto 0));
end PRET_BILET;

architecture BEHAVIOUR of PRET_BILET is	
--internal signals
signal n2,n1,n0 : std_logic_vector(3 downto 0);
--------afis7sgm
component SEVEN_SEGMENT is
	port ( BINARY : in std_logic_vector(3 downto 0);
		   EN ,clk: in std_logic;
	       TO_SGM : out std_logic_vector(6 downto 0));
end component SEVEN_SEGMENT;
--------numerele
component distanta is
	port(RESET,s2,s1,s0,clk,en: in std_logic;
	digit0, digit1, digit2 : out std_logic_vector(3 downto 0);
	price: out integer range 0 to 100);
end component distanta;
begin		
	L1 : distanta port map (RESET,s2,s1,s0,clk,en,n0,n1,n2);
	L2 : SEVEN_SEGMENT port map (n0,en,clk,an0);
	L3 : SEVEN_SEGMENT port map (n1,en,clk,an1);
	L4 : SEVEN_SEGMENT port map (n2,en,clk,an2); 
end BEHAVIOUR;

	


	