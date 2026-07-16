# Bits Manipulation Cryptography
## Version Alpha-1.1.0

# What is Is?
This is a bit manipulation key-based cryptography.

# Cryptography Types
## T1x1 (Type 1 per 1)
Receives a plain text file and a 8 bits key. And exits a encrypted text.<br>
Modify only one bit from each byte<br>
->Can be decrypted without the key<-.<br>

## T1x1s (T1x1 Secure)
Works as the Same Way as T1x1 but, secure.<br>
->Can't be decrypted without the key<-.<br>

## T8x8 (Type 8 per 8)
Works similarly to T1x1, but modifing the byte completely.<br>
Modify all the eight bits from each byte (based on the key)<br>
->Can be decrypted without the key<-.<br>

## T16x16 (Type 16 per 16)
Is the T8x8 but with a 16 bits key
Is Secure even without the 's'

## T8x8s (T8x8 Secure)
Is the T8x8 but secure.<br>
->Can't be decrypted without the key<-.<br>

## T1x1/T8x8 + Inverted
Is the t1/t8 but invert all bits value.<br>
1 become 0.<br>
and 0 become 1.<br>
in all bytes.<br>

## T1x1s/T8x8s + Inverted
Is the same thing, but secure.<br>

## Twisted
It suffle the bytes, one is encrypted with t1x1s other with inverted.<br>

## FOR MORE INFORMATION: Check the "logics.txt"

# main File
The main file contains a software ready to encrypt or decrypt files with all the cryptographys.<br>

# Extra
This project is in Alpha release, so the code is officialy not good enough.<br>
In future releases this will change. I will impruve the code to turn them more efficient.<br>