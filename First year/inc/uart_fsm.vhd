-- uart_fsm.vhd: UART controller - finite state machine
-- Author(s): Adam Mrkva xmrkva04
-- Date : 02.05.2022

--****************************************************--
	
library ieee;
use ieee.std_logic_1164.all;

--****************************************************--

entity UART_FSM is

port(
   COUNT_BIT  	: in std_logic_vector(3 downto 0);
   INPUT_CLOCK  : in std_logic_vector(4 downto 0);
   RESET   		: in std_logic;
   CLOCK   		: in std_logic;
   DIN  		: in std_logic;
   ENABLE_CNT  	: out std_logic;
   ENABLE_REC 	: out std_logic;
   DOUT_VLD   	: out std_logic
   );
end entity UART_FSM;

--****************************************************--

architecture behavioral of UART_FSM is

type STATES is (AWAIT_SIGNAL , START, RECEIVE_DATA, STOP, VALIDATE_DATA);
signal status : STATES := AWAIT_SIGNAL;	

begin
	--case status is
	--	when START => 
	--		ENABLE_CNT <= '1';
	---		ENABLE_REC <= '1';
	--	when RECEIVE_DATA => 
	--		ENABLE_CNT <= '1';
	--	when VALIDATE_DATA =>
	--		DOUT_VLD <= '1';
	--	when others =>
	--		DOUT_VLD <= '0';
	--		ENABLE_CNT <= '0';
	--		ENABLE_REC <= '0';
	--end case;

	ENABLE_CNT <= '1' when status = START or status = RECEIVE_DATA else '0'; -- Enable INPUT_CLOCK
	ENABLE_REC <= '1' when status = RECEIVE_DATA else '0'; -- Start receiving				
	DOUT_VLD <= '1' when status = VALIDATE_DATA else '0'; -- Data validate
	
process (CLOCK) begin

	if rising_edge (CLOCK) then
	
	    if RESET = '1' then --after reser wait for input
	        status <= AWAIT_SIGNAL;
		
	    else 
			if status = AWAIT_SIGNAL then
				if DIN = '0' then
					status <= START; --if waitin for signal and din is 0, start
				end if;
			
			
			elsif status = START then
				if INPUT_CLOCK = "10111" then
					status <= RECEIVE_DATA; -- if started and clock is at 23, start receiving data
				end if;
			
			
			elsif status = RECEIVE_DATA then
				if COUNT_BIT(3) = '1' then
					status <= STOP; -- if receiving data and wrote 8 bits, stop
				end if;
			
			
			elsif status = STOP then
				if DIN = '1' then
					status <= VALIDATE_DATA; --if stopped and din is set to 1, validate data
				end if;
			
			
			elsif status = VALIDATE_DATA then
				status <= AWAIT_SIGNAL; --if validated data, wait for next
				
			else 
				null;
			end if;
			
		end if;
	end if;
	
end process;    
end behavioral;