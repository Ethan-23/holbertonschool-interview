#!/usr/bin/python3
"""UTF-8 Validation"""


def validUTF8(data):
    """
    data - incoming list of integers to validate
    Return: True if data is a valid UTF-8 encoding, else return False
    """
    check = 0
    for i in range(len(data)):
        binary = toBinary(data[i])
        if check == 0:
            while binary[check] == '1':
                check += 1
        else:
            if binary[0] != '1' and binary[1] != '0':
                return False
            check -= 1
    return True


def toBinary(number):
    """
    number - input to conver to 8 bit binary
    """
    return format(number, "08b")
