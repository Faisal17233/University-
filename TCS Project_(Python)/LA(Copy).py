from Lists import Punctuators, Signs, KEYWORDS, SimpleArithOps, SimpleRelOps

from res import ID, integer

from LATokenPart import tokens


def LexAnalyzer():
    classTokens = []
    i = 0
    length = len(tokens)
    while i < length:

        value = tokens[i][0]
        line = tokens[i][1]

        temp = ("Invalid Value", value, line)

        # check for alphabetical
        if value[0].isalpha():

            if ID(value):
                temp = ("ID", value, line)
                if value in KEYWORDS:
                    if value == "void":
                        temp = ("void", "void", line)

                    elif value in {"break", "continue"}:
                        temp = ("FlowControl", value, line)

                    elif value == "int":
                        temp = ("DT", value, line)

                    elif value in {"and", "or"}:
                        temp = ("Logical_Op", value, line)

                    elif value == "not":
                        temp = ("Not_Op", value, line)

                    else:
                        temp = (value, value, line)


        # check for constant int number
        elif value[0].isnumeric():
            temp = ("Int_Const", value, line)

        # check punctuators
        elif value in Punctuators:
            temp = (value, value, line)


        # check all Assignment Ops
        elif value in ['+', '-', '*', '/', '^', '%']:

            change = False
            plus_minus_mergerd = False
            if i + 1 != length:

                if tokens[i + 1][1] == line:
                    # if it is ==
                    if tokens[i + 1][0] == '=':
                        temp = ("CompAssignment", value + "=", line)
                        change = True
                    # if it is ++
                    elif (value == '+') and (tokens[i + 1][0] == '+'):
                        temp = ("IncDec", "++", line)
                        change = True
                    # if it is --
                    elif (value == '-') and (tokens[i + 1][0] == '-'):
                        temp = ("IncDec", "--", line)
                        change = True

                    # if it is -3 or +45
                    elif (value == '+') or (value == '-'):
                        if classTokens:
                            # checking if it is like this (b = b - 4) or (b = 3 - 4)
                            # in both of these cases we have to save - and 4 as seperate tokens so we check that
                            if classTokens[-1][2] == line:
                                # if it is (a = -1) or (3 * -3) so we need to combine and then save (-3)
                                if classTokens[-1][0] not in ["ID", "Int_Const"]:
                                    if integer(tokens[i + 1][0]):
                                        temp = ("Int_Const", value + tokens[i + 1][0], line)
                                        plus_minus_mergerd = True
                            # if there is +1 or -3 in the start of a line
                            else:
                                if integer(tokens[i + 1][0]):
                                    temp = ("Int_Const", value + tokens[i + 1][0], line)
                                    plus_minus_mergerd = True
                        # same thing as before else but only if it is in the first line
                        else:
                            if integer(tokens[i + 1][0]):
                                temp = ("Int_Const", value + tokens[i + 1][0], line)
                                print("ok")
                                plus_minus_mergerd = True

            if not plus_minus_mergerd:
                if not change:
                    keys = Signs.keys()

                    for key in keys:
                        if value in Signs[key]:
                            temp = (key, value, line)
                            break

                else:
                    tokens.pop(i + 1)
                    length -= 1

            else:
                tokens.pop(i + 1)
                length -= 1


        # check all Relational Ops
        elif value in ['>', '<', '!']:

            change = False
            if i + 1 != length:

                if tokens[i + 1][1] == line:
                    # if it is >= or <= or !=
                    if tokens[i + 1][0] == '=':
                        temp = ("RelOP", value + "=", line)
                        tokens.pop(i + 1)
                        length -= 1
                        change = True

            if not change:
                # if it is only < or > or !
                temp = ("RelOP", value, line)



        elif value == '=':
            change = False
            if i + 1 != length:

                if tokens[i + 1][1] == line:

                    if tokens[i + 1][0] == '=':
                        temp = ("RelOP", value + "=", line)
                        tokens.pop(i + 1)
                        length -= 1
                        change = True

            if not change:
                temp = ('=', '=', line)

        classTokens.append(temp)
        i += 1

    try:
        classTokens.append(("$", "$", classTokens[-1][-1]))
    except Exception:
        classTokens.append(("$", "$", 0))
    return classTokens
