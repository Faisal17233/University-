import re


def ID(name: str) -> bool:
    letter = r'[a-zA-Z]'
    number = r'[0-9]'

    pattern = rf'({letter})|({letter}({letter}|{number}|_){{0,28}}{letter})'
    match = re.fullmatch(pattern, name)
    if match:
        return True
    else:
        return False


def integer(name: str) -> bool:
    pattern = r'[+-]?[0-9]+'

    match = re.fullmatch(pattern, name)
    if match:
        return True
    else:
        return False
