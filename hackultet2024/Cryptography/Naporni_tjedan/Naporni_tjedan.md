# Naporni tjedan (150 points)

For this task we were given a chat between two people. 
The chat was encrypted with one-time pad which means that the key
is as long as the message itself and message is encrypted using message XOR key.
We were given a hint that the key was not changed during the whole conversation
and that the last message was the flag. We were also given the context of the conversation.

With that information we used python script with the following code:

```python
def binary_to_ascii(binary_string):
    chunks = [binary_string[i:i+8] for i in range(0, len(binary_string), 8)]
    return ''.join([chr(int(chunk, 2)) for chunk in chunks])

def xor(binary_string1, binary_string2):
    return ''.join(str(int(x) ^ int(y)) for x, y in zip(binary_string1, binary_string2))

known_message = "Evo sretna zastavica"
known_message = ''.join(format(ord(i), '08b') for i in known_message)
known_message = known_message.ljust(128, '1')[:256]
encrypted_messages = [
    "000110000000111000011111010010010000001100001111010000010101010000000110010011000001101001000001000100000000111001010010000001000000000000000010000011010000000000000000",
    "000001010001001100010001000001110000101101001010000010000100010000001100000000010000011000000000000110100000111001010010000111110000110000001110000010110000001100011110",
    "000000100000000001010000000001000000000100001101000101000000000000001101000011010000011101000001000001110100111100000001000110110001101100011110000100110101101100010111",
    "000011010100010100010100000010000000010001001010000100010100110000000000000101100100100101011010000101010001110000000110000110110100100100000010000011110101111000000000",
    "000000010000101000000010000010000000001101001010000011110100000100011001000001010001101001000001000000000000011001010010000110000000100000001110000001010001001000010001",
    "000011010100010100011110000000000001110100011110000000000000000000000110000000100000110101000001010101000001110000000000000100010001110100000010000001010100000000011110",
    "000001000001001100010001000001010000111101001010000101010101001000001100000011100000100001010100000111010100111100010001000100010100100100000001000000110101101100010110",
    "000010010001001100011111010010010001110100011000000001000101010000000111000011010100100101011010000101010001110000000110000101010001111100000101000010010000000000000101",
    "000011110011000100110110010110110101111001011000010101010111101101011011010110100101111000011001010001010101111001000111010001100101101001010101010110010101010001100010"
]

potential_keys = [xor(message, known_message) for message in encrypted_messages]
real_results = []

for key in potential_keys:
    print("current key: ", key)
    for message in encrypted_messages:
        print("current encrypted_message: ", message)
        ascii_decrypted = binary_to_ascii(xor(key, message))
        if "CTF" in ascii_decrypted:
            real_results.append(ascii_decrypted)
        print("ascii: ", ascii_decrypted)
        print()


print("Real results:")
print(real_results)
```

Script takes the known message and XOR-s them with all known messages to get the potential keys.
Then it XOR-s the potential keys with all encrypted messages and checks if the decrypted message contains "CTF".
We also print all decrypted messages to see if we can guess one of the messages for next iteration.

We started with known message "CTF2024[" and from context of the messages we found out
that one message is "Evo sretna zastavica" and when we decrypted with that we got the flag CTF2024[267911523935]