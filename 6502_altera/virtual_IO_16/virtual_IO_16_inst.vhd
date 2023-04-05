	component virtual_IO_16 is
		port (
			source : out std_logic_vector(15 downto 0);                    -- source
			probe  : in  std_logic_vector(15 downto 0) := (others => 'X')  -- probe
		);
	end component virtual_IO_16;

	u0 : component virtual_IO_16
		port map (
			source => CONNECTED_TO_source, -- sources.source
			probe  => CONNECTED_TO_probe   --  probes.probe
		);

