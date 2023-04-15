	component virtualprobe_16bit is
		port (
			probe : in std_logic_vector(15 downto 0) := (others => 'X')  -- probe
		);
	end component virtualprobe_16bit;

	u0 : component virtualprobe_16bit
		port map (
			probe => CONNECTED_TO_probe  -- probes.probe
		);

