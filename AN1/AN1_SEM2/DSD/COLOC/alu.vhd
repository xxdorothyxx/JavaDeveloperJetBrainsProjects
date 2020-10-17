-------------------------------------------------------------------------------
--
-- Title       : col
-- Design      : colocviu
-- Author      : Radu
-- Company     : Student
--
-------------------------------------------------------------------------------
--
-- File        : C:\My_Designs\colocviu\colocviu\src\col.vhd
-- Generated   : Thu May 28 13:46:37 2020
-- From        : interface description file
-- By          : Itf2Vhdl ver. 1.22
--
-------------------------------------------------------------------------------
--
-- Description : 
--
-------------------------------------------------------------------------------

--{{ Section below this comment is automatically maintained
--   and may be overwritten
--{entity {col} architecture {col}}

--26.	Design a 4-bit ALU (for 2 numbers) that allows the following operations: +/-/logical and/ <<1. Use only sequential statements.

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;
use IEEE.std_logic_unsigned.all;
	
entity col is 
	
	port(A,B: in std_logic_vector (3 downto 0);
	op: in std_logic_vector (1 downto 0);
	
	F: out std_logic_vector (3 downto 0));
	
end col;

--}} End of automatically maintained section

architecture alu of col is
begin

	process(op)
	begin
	case op is
		when "00" =>
		F <= A + B;	 
		when "01" =>
		F <= A - B;
		when "10" =>
		F <= A and B;
		when others =>
		F <= A(2 downto 0) & '0';
	end case;
	end process;

end alu;
