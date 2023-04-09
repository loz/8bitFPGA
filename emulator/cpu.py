class Cpu:
   def __init__(self):
      self.registers = {
        "A": 0,
        "B": 0,
        "X": 0,
        "Y": 0,
        "C": 0,
        "Z": 0
      }
      self.rom = [0] * 8192
      self.ip = 8000 #rom mapped to 8000

   def assemble(self, code):
      loc = 0;
      lines = code.split('\n')
      for line in lines:
	loc = self.assemble_line(line, loc)

   def assemble_line(self, line, loc):
      op, arg = line.split(' ')
      if op == 'lda':
         self.rom[loc] = 0x00
         self.rom[loc+1] = int(arg)
         loc += 2
      return loc

   def tick(self):
      op = self.fetch_byte()
      if op == 0x00: #LDA
         arg = self.fetch_byte()
         self.registers["A"] = arg

   def fetch_byte(self):
      b = self.rom[self.ip-8000]
      self.ip += 1
      return b


