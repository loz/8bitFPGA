import unittest
import cpu

class TestCpu(unittest.TestCase):

  def test_command_lda_immediate(self):
    computer = cpu.Cpu()
    computer.assemble("""lda 123""")
    computer.tick()
    self.assertEqual(computer.registers["A"], 123)

if __name__ == '__main__':
    unittest.main()
