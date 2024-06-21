from Lists import Brackets, Signs, KEYWORDS
from res import ID, integer
from LATokenPart import tokens

def ClassGiver():
    Final = []
    i = 0
    length = len(tokens)
    while i < length:

        token = tokens[i][0]
        line = tokens[i][1]

        temp = ("Invalid Value", token, line)

        # check for alphabetical
        if token[0].isalpha():

            if ID(token):
                temp = ("ID", token, line)
                if token in KEYWORDS:
                    if token == "void":
                        temp = ("void", "void", line)

                    elif token in {"break", "continue"}:
                        temp = ("FlowControl", token, line)

                    elif token == "int":
                        temp = ("DT", token, line)

                    elif token in {"and", "or"}:
                        temp = ("Logical_Op", token, line)

                    elif token == "not":
                        temp = ("Not_Op", token, line)

                    else:
                        temp = (token, token, line)


        elif token[0].isnumeric():
            temp = ("Int_Const", token, line)


        elif token in Brackets:
            temp = (token, token, line)


        elif token in ['+', '-', '*', '/', '^', '%']:

            check = False
            check2 = False
            if i + 1 != length:

                if tokens[i + 1][1] == line:

                    if tokens[i + 1][0] == '=':
                        temp = ("CompAssignment", token + "=", line)
                        check = True

                    elif (token == '+') and (tokens[i + 1][0] == '+'):
                        temp = ("IncDec", "++", line)
                        check = True

                    elif (token == '-') and (tokens[i + 1][0] == '-'):
                        temp = ("IncDec", "--", line)
                        check = True


                    elif (token == '+') or (token == '-'):
                        if Final:

                            if Final[-1][2] == line:
                                if Final[-1][0] not in ["ID", "Int_Const"]:
                                    if integer(tokens[i + 1][0]):
                                        temp = ("Int_Const", token + tokens[i + 1][0], line)
                                        check2 = True

                            else:
                                if integer(tokens[i + 1][0]):
                                    temp = ("Int_Const", token + tokens[i + 1][0], line)
                                    check2 = True
                        else:
                            if integer(tokens[i + 1][0]):
                                temp = ("Int_Const", token + tokens[i + 1][0], line)
                                print("ok")
                                check2 = True

            if not check2:
                if not check:
                    keys = Signs.keys()

                    for key in keys:
                        if token in Signs[key]:
                            temp = (key, token, line)
                            break

                else:
                    tokens.pop(i + 1)
                    length -= 1

            else:
                tokens.pop(i + 1)
                length -= 1


        elif token in ['>', '<', '!']:

            check = False
            if i + 1 != length:

                if tokens[i + 1][1] == line:
                    # if it is >= or <= or !=
                    if tokens[i + 1][0] == '=':
                        temp = ("RelOP", token + "=", line)
                        tokens.pop(i + 1)
                        length -= 1
                        check = True

            if not check:
                # if it is only < or > or !
                temp = ("RelOP", token, line)



        elif token == '=':
            check = False
            if i + 1 != length:

                if tokens[i + 1][1] == line:

                    if tokens[i + 1][0] == '=':
                        temp = ("RelOP", token + "=", line)
                        tokens.pop(i + 1)
                        length -= 1
                        check = True

            if not check:
                temp = ('=', '=', line)

        Final.append(temp)
        i += 1

    try:
        Final.append(("$", "$", Final[-1][-1]))
    except Exception:
        Final.append(("$", "$", 0))
    return Final
