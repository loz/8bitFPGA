create_clock -period 20.0 -name system_clock [get_ports clk]
create_clock -name btn_clk -period 100000000 -waveform {0 50000000} [get_ports key1]
set_input_delay -clock btn_clk -max 50 [get_ports key1]