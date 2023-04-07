import time
import serial
import sys

# configure the serial connections (the parameters differs on the device you are connecting to)
ser = serial.Serial(
    port='/dev/tty.usbserial-14240',
    baudrate=115200
    #,
    #parity=serial.PARITY_ODD,
    #stopbits=serial.STOPBITS_TWO,
    #bytesize=serial.SEVENBITS
)

binfile = sys.argv[1]
print "Sending", binfile, "to UART"
start_addr = 0

def send_word(w):
  upr = (w >> 8) & 0xFF
  lwr = w & 0xFF
  send_byte(upr)
  send_byte(lwr)

def send_byte(b):
  print '{:#04x}'.format(b),
  ser.write(b);
  ser.flush()

with open(binfile, 'rb') as f:
  data = f.read()
  bytes = (ord(b) for b in data)
  addr = start_addr
  print "Sending Start..", len(data), 'bytes'
  send_byte(0xFF)
  send_word(len(data))
  print '---'
  for b in bytes:
    send_word(addr)
    send_byte(b)
    print ''
    sys.stdout.flush()
    addr += 1
