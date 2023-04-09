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
      obyte = 0x00
      abyte = 0x00
      if op == 'lda':
         if arg.startswith('#'):
            abyte = int(arg.replace('#',''))
         else:
            obyte = 0x01
            abyte = int(arg)
      elif op == 'add':
         if arg.startswith('#'):
            obyte = 0x02
            abyte = int(arg.replace('#', ''))
         else:
            obyte = 0x03
            abyte = int(arg)
      self.rom[loc] = obyte
      self.rom[loc+1] = abyte
      loc += 2
      return loc

   def tick(self):
      op = self.fetch_byte()
      if op == 0x00: #LDA-immediate
         arg = self.fetch_byte()
         self.registers["A"] = arg
      elif op == 0x01: #LDA-absolute
         arg = self.fetch_byte()
         self.registers["A"] = self.rom[arg]
      elif op == 0x02: #ADD-immediate
         arg = self.fetch_byte()
         result = self.registers["A"] + arg
         if result > 255:
            result = result % 256
            self.registers["C"] = 1
         else:
            self.registers["C"] = 0
         self.registers["A"] = result
      elif op == 0x03: #ADD-immediate
         arg = self.fetch_byte()
         result = self.registers["A"] + self.rom[arg]
         if result > 255:
            result = result % 256
            self.registers["C"] = 1
         else:
            self.registers["C"] = 0
         self.registers["A"] = result

   def fetch_byte(self):
      b = self.rom[self.ip-8000]
      self.ip += 1
      return b


