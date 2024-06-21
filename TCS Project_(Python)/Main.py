import sys
import os

current_dir = os.path.dirname(os.path.realpath(__file__))
parent_dir = os.path.dirname(current_dir)
sys.path.append(parent_dir)

def Token_Verify(tokens):
    for token in tokens:
        if len(token[0]) >= 7:
            if token[0][:7]=="Invalid":
                sys.exit(f"LexicalError: Invalid Token {token[1]} at line {token[2]}")


import LexicalAnalyze
import Syntex_Checker

tokenize = LexicalAnalyze.ClassGiver()
Token_Verify(tokenize)
Answer = Syntex_Checker.Global(tokenize)
if (Answer):
    print("Syntax is correct")
else:
    print("SyntaxError")