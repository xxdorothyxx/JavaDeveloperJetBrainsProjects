library IEEE ;
USE ieee.std_logic_1164.all;

entity detectorSec is 
	port ( clk: in std_logic;
	reset:in std_logic;
	seq_in: in std_logic;
	seq_out: out std_logic);
end detectorSec;			




architecture detectorSec of detectorSec is
type MOORE_FSM is(One,Zero,OneZero,OneZeroOne,OneZeroOneZero);
	signal current_state,next_state: MOORE_FSM;
	signal count: integer;
begin

process(clk,reset)
begin			  
	if(reset='1' )then
		current_state<=Zero;
		
	elsif(clk'EVENT AND clk='1')then
		current_state<=next_state;
	end if;
	end process;
	
process(current_state,seq_in)
begin
	case(current_state)is
	when Zero=>
	if(seq_in='1') then
	next_state <= One; 
	else
	next_state <= Zero;
	end if;
	when One=>
	if(seq_in='1') then
	next_state <= One;
	else
	next_state<= OneZero;
	end if;
	when OneZero =>
	if(seq_in='1') then
		next_state<= OneZeroOne;
	else
		next_state<= Zero;
	end if;
	when OneZeroOne =>
	if(seq_in ='1') then
	next_state<= One;
	else
	next_state<= OneZeroOneZero; 
	if(count=3)	 then
		count<=0; 
		next_state<=Zero;
		else
	count <= count+1;
	end if;	  
	end if;
	when OneZeroOneZero =>
		if(seq_in ='1') then
		next_state <= One;
		else
		next_state<=Zero;
	end if;
	end case;  
	

	end process;
	
process (current_state)
begin
	case (current_state) is	 
	when Zero =>
	seq_out <='0';
	when One =>
	seq_out <='0';
	when OneZero =>
	seq_out <='0';
	when OneZeroOne =>
	seq_out <='0'; 
	when OneZeroOneZero =>
	seq_out <='1'; 
	end case;
end process;
		
end detectorSec;
