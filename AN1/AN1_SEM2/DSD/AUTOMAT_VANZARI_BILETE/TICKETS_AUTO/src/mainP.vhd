library ieee;
use ieee.std_logic_1164.all;


entity ticket_automata is
	port(clk, RESET,en_dist,en_buy,GO,reset_automata : in std_logic;   --, en2, enrest, enSUM: in std_logic;
	s1,s2,s5,s10,s50: in std_logic;
	bilet: out std_logic; 
	o1,o2,o5,o10,o50 : out std_logic_vector(3 downto 0);
	r1,r2,r5,r10,r50 : out std_logic_vector(3 downto 0);
	WARNING: out std_logic;
	WARN : out bit;
	an4,an3,an2,an1,an0:out std_logic_vector(6 downto 0));
end ticket_automata;


architecture behaviour of ticket_automata  is
--1--------------------------------------------------------------------------
component distanta is										 
	port(RESET,s2,s1,s0,clk,en: in std_logic;
	digit0, digit1, digit2 : out std_logic_vector(3 downto 0);
	price: out integer range 0 to 100);
end component distanta;
--2---------------------------------------------------------------------------
component pret_bilet is
port (CLK,RESET,EN,s0,s1,s2: in std_logic;			
      an2,an1,an0 : out std_logic_vector(6 downto 0));
end component pret_bilet;
--3---------------------------------------------------------------------------
component suma_introd is
	port(reset, CLK,s1,s2,s5,s10,s50,en : in std_logic;
	sum: out integer range 0 to 100;
	an0, an1: out std_logic_vector(6 downto 0));	
end component suma_introd;
--4---------------------------------------------------------------------------
component ATM3 is 
	port (reset_aparat,CLK, S1, S2 ,S5 , S10 , S50 ,en ,en_modif : in std_logic;
			e1,e2,e5,e10,e50 : in std_logic_vector(3 downto 0);
	       N1,N2,N5,N10,N50 : out std_logic_vector(3 downto 0));
end component ATM3;
--5---------------------------------------------------------------------------
component verificare is
	port(rst,en_verificare: in std_logic;
	pret, suma : in integer range 0 to 100;
	warning : out bit;
	en_rest :out bit;
	rest: out integer range 0 to 100);
end component verificare;
--6---------------------------------------------------------------------------
component eliberare_rest is
	port(clk: in std_logic;
	 en_rest: in bit;
	 rst: in std_logic;
	 euro1, euro2, euro5, euro10, euro50: in std_logic_vector(3 downto 0);
	 rest: in integer range 0 to 100;  ----dam la rest suma daca vrem sa returnam suma
	 ok,warning,en_modif,en_sum : out std_logic;
	 e1,e2,e5,e10,e50: out std_logic_vector(3 downto 0);
	 o1,o2,o5,o10,o50: out std_logic_vector( 3 downto 0));
 end component eliberare_rest;
 --7--------------------------------------------------------------------------
component afisare_pret is
	port( clk, reset, en, dst2,dst1,dst0: in std_logic;
	anode2, anode1, anode0: out std_logic_vector( 6 downto 0));
end component afisare_pret; 
--8---------------------------------------------------------------------------
component numarator_bilete is
	port( CLK: in STD_LOGIC; 
	nr_bilete : in std_logic_vector(3 downto 0 );
	reset_automata,reset: in std_logic;
	OK,en_modif: in std_logic;
	bilet: out std_logic;
	count : out std_logic_vector(3 downto 0);
	warning,modif: out std_logic
	);
end component numarator_bilete;
--9---------------------------------------------------------------------------
component RETURN_SUM is
	port(clk,undone,reset,en_sum: in std_logic;
    euro1, euro2, euro5, euro10, euro50: in std_logic_vector(3 downto 0);
	sum: in integer range 0 to 100;
	o1,o2,o5,o10,o50: out std_logic_vector(3 downto 0));
end component RETURN_SUM;
-----------------------semnale interne-----------------------------------------

signal dist0, dist1, dist2: std_logic_vector(3 downto 0); 
signal price: integer range 0 to 100;
signal suma: integer range 0 to 100; 
signal N1,N2,N5,N10,N50: std_logic_vector(3 downto 0);
signal rest: integer range 0 to 100; 
signal OK: std_logic;
signal en_modif,en_sum : std_logic; 
signal en_rest : bit;
signal e1,e2,e5,e10,e50 : std_logic_vector(3 downto 0);
signal count : std_logic_vector(3 downto 0);
signal modif : std_logic;
signal undone : std_logic;
--------------------------code--------------------------------------------------
BEGIN
	
  STAGE1 : distanta port map(RESET,s5,s2,s1,clk,en_dist,dist0, dist1, dist2,price);
  STAGE2 : pret_bilet port map(clk,RESET,en_dist,s1,s2,s5,an2,an1,an0); 
  STAGE3 : ATM3 port map(reset_automata,clk,s1,s2,s5,s10,s50,en_buy,en_modif,e1,e2,e5,e10,e50,N1,N2,N5,N10,N50);  
  STAGE4 : suma_introd port map(reset,clk,s1,s2,s5,s10,s50,EN_buy, suma, an3, an4);	
  STAGE6 : verificare port map(RESET,GO,price,suma,WARn,en_rest,rest);
  STAGE7 : eliberare_rest port map(clk,en_rest,RESET,N1,N2,N5,N10,N50,rest,ok,warning,en_modif,en_sum,e1,e2,e5,e10,e50,o1,o2,o5,o10,o50);
  STAGE8 : numarator_bilete port map(clk,count,reset_automata,reset,OK,modif,bilet,count, WARNING,modif); 
  STAGE9 : return_sum port map(clk,undone,RESET,en_sum,N1,N2,N5,N10,N50,suma,r1,r2,r5,r10,r50);
-----------------------------------------------------------------------------
 end behaviour;