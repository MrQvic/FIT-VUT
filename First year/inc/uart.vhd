-- uart.vhd	: UART controller - receiving part
-- Author(s): Adam Mrkva xmrkva04
-- Date 	: 02.05.2022
--
--****************************************************--

library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

--****************************************************--

entity UART_RX is 
port(	
	RST      : in std_logic;
	DIN      : in std_logic;
	DOUT     : out std_logic_vector(7 downto 0);
	DOUT_VLD : out std_logic;
	CLK      : in std_logic
);
end UART_RX;  

--****************************************************--

architecture behavioral of UART_RX is
signal COUNT_BIT     : std_logic_vector(3 downto 0);
signal ENABLE_REC      : std_logic;
signal ENABLE_CNT      : std_logic;
signal DATA_IS_VALID  : std_logic;
signal INPUT_CLOCK     : std_logic_vector(4 downto 0);

begin
	-- FSM import 
	FSM: entity work.UART_FSM(behavioral)
	port map (
		CLOCK => CLK,
		RESET => RST,
		DIN => DIN,
		INPUT_CLOCK => INPUT_CLOCK,
		COUNT_BIT => COUNT_BIT,
		ENABLE_REC=> ENABLE_REC,
		ENABLE_CNT => ENABLE_CNT,
		DOUT_VLD => DATA_IS_VALID	
	);
	
	process (CLK) begin
	if rising_edge(CLK) then
		DOUT_VLD <= DATA_IS_VALID;
		
		if RST = '1' then --reset clock and bit counter
			INPUT_CLOCK <= "00000";
			COUNT_BIT <= "0000";
		end if;
		
		if ENABLE_CNT = '1' then
			INPUT_CLOCK <= INPUT_CLOCK + 1; --inc clock
		else
			INPUT_CLOCK <= "00000"; --restart clock
		end if;
		
		if DATA_IS_VALID = '1' then
			INPUT_CLOCK <= "00001"; --if validated data, start again
		end if;
		
		if ENABLE_REC = '0' then
			COUNT_BIT <= "0000"; --restart counting
		end if;

			if ENABLE_REC = '1' then --if start receiving flag is set, start
				if INPUT_CLOCK = "01111" or INPUT_CLOCK = "11000" then --if clock is 24 or 15
					INPUT_CLOCK <= "00000"; --reset
					
					if COUNT_BIT = "0111" then
						DOUT(7) <= DIN;				--last bit
						
					elsif COUNT_BIT = "0110" then
						DOUT(6) <= DIN;
					
					elsif COUNT_BIT = "0101" then
						DOUT(5) <= DIN;
						
					elsif COUNT_BIT = "0100" then
						DOUT(4) <= DIN;
						
					elsif COUNT_BIT = "0011" then
						DOUT(3) <= DIN;
						
					elsif COUNT_BIT = "0010" then
						DOUT(2) <= DIN;
						
					elsif COUNT_BIT = "0001" then
						DOUT(1) <= DIN;
													
					elsif COUNT_BIT = "0000" then	
						DOUT(0) <= DIN; 			--first bit
						
					else
						null;
						
					end if;
					
					COUNT_BIT <= COUNT_BIT + 1; --inc bit counter after each bit to correct position
				end if;
			end if;	
		end if;
	end process;	
end behavioral;