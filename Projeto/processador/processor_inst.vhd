	component processor is
		port (
			clk_clk                          : in  std_logic                    := 'X';             -- clk
			pio_0_external_connection_export : out std_logic_vector(3 downto 0);                    -- export
			pio_1_external_connection_export : in  std_logic_vector(3 downto 0) := (others => 'X')  -- export
		);
	end component processor;

	u0 : component processor
		port map (
			clk_clk                          => CONNECTED_TO_clk_clk,                          --                       clk.clk
			pio_0_external_connection_export => CONNECTED_TO_pio_0_external_connection_export, -- pio_0_external_connection.export
			pio_1_external_connection_export => CONNECTED_TO_pio_1_external_connection_export  -- pio_1_external_connection.export
		);

