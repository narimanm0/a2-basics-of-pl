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
