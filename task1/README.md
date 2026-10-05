# Task 1: Endianness

## What is Endianness?

Computers store numbers bigger than one byte as a sequence of bytes. Therefore, someone has to decide in which order they go into memory. 
The decision has been made is called endianness. Let's take the 32-bit number `0x12345678`.
Its bytes are `12` `34` `56` `78`, where `12` is the most significant one. 
A big-endian machine puts `12` at the lowest address. However, a little-endian machine puts `78` there:

| Address       | +0   | +1   | +2   | +3   |
|---------------|------|------|------|------|
| Big-endian    | `12` | `34` | `56` | `78` |
| Little-endian | `78` | `56` | `34` | `12` |

## Where can we see them?

Nowadays, we can say that most desktop and mobile hardware is little-endian. For example: x86, x86-64, RISC-V and ARM in its usual configuration. 
Nevertheless, we can observe big-endian in older SPARC and PowerPC systems. Several chips, such as ARM, MIPS and PowerPC, can be switched between little and big-endian. Moreover, network protocols and Java class files utilize big-endian. It does not matter whether it is little-endian or big-endian in a single machine. We notice the problem
when data leaves the machine. We know that when data leaves the machine, it is sent over a socket, saved into a binary file, shared with hardware registers.

## What do I think about it?

I do not think either order is really better. Both big and little endians have advantages. Let's first focus on little-endiannes:
- a number sits at the same address no matter how wide you read it;
- converting between 8, 16 and 32 bits is easy;
- addition can start from the first byte, which is where the carry starts.

Now, let's focus on big-endianness:
- the bytes in a dump look like the number you would write on paper;
- comparing two byte strings gives the same result as comparing the numbers.

From my perspective, a common mistake is to write a `struct` straight to a file/socket. It works on the developer's machine; however, it silently breaks on another one without giving any compiler warning. Consequently, I think a sensible approach is to define always the order of the byte of a file format/protocol. Furthermore, nowadays, it is unfortunate that network byte order is big-endian while almost every machine is little-endian. Ultimately, endianness is only about the order of bytes.
