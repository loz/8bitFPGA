import unittest
import cpu

class TestCpu(unittest.TestCase):

  def test_command_lda_immediate(self):
    computer = cpu.Cpu()
    computer.assemble("""lda #123""")
    computer.tick()
    self.assertEqual(computer.registers["A"], 123)
  
  def test_command_lda_absolute(self):
    computer = cpu.Cpu()
    computer.assemble("""lda 55""")
    computer.rom[55] = 456;
    computer.tick()
    self.assertEqual(computer.registers["A"], 456)

  def test_command_ADD_immediate(self):
    computer = cpu.Cpu()
    computer.assemble("""lda #55
add #123""")
    computer.tick()
    computer.tick()
    self.assertEqual(computer.registers["A"], 55+123)

  def test_command_ADD_absolute(self):
    computer = cpu.Cpu()
    computer.assemble("""lda #55
add 456""")
    computer.rom[456] = 123;
    computer.tick()
    computer.tick()
    self.assertEqual(computer.registers["A"], 55+123)

  def test_command_ADD_sets_carry_bit(self):
    computer = cpu.Cpu()
    computer.assemble("""lda #255
add 456""")
    computer.rom[456] = 1;
    computer.tick()
    computer.tick()
    self.assertEqual(computer.registers["A"], 0)
    self.assertEqual(computer.registers["C"], 1)

if __name__ == '__main__':
    unittest.main()
