	component virtual_IO_8_bit is
		port (
			source : out std_logic_vector(7 downto 0);                    -- source
			probe  : in  std_logic_vector(7 downto 0) := (others => 'X')  -- probe
		);
	end component virtual_IO_8_bit;

	u0 : component virtual_IO_8_bit
		port map (
			source => CONNECTED_TO_source, -- sources.source
			probe  => CONNECTED_TO_probe   --  probes.probe
		);

