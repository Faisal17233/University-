import sys
tokens = None

def Global(token_list):
    global tokens
    tokens = token_list
    return Recursion()

i = 0

def Recursion():
    global i
    if tokens[i][0] == "$":
        return True

    else:
        if Main_Route():
            if Recursion():
                return True

    return False

def Main_Route():
    global i

    class_part = tokens[i][0]
    line = tokens[i][2]

    if class_part == "iterate":
        if iter_loop():
            if tokens[i][0] == ";":
                i += 1
                return True
        return False


    elif class_part == "when":
        if Condition_St():
            if tokens[i][0] == ";":
                i += 1
                return True

        return False

    elif class_part == "func":
        if function():
            if tokens[i][0] == ";":
                i += 1
                return True
        return False

    elif class_part == "ret":
        if Return():
            class_part = tokens[i][0]
            if class_part == ";":
                i += 1
                return True
        return False


    elif class_part == "FlowControl":
        i += 1
        class_part = tokens[i][0]
        if class_part == ";":
            i += 1
            return True
        return False


    elif class_part == "IncDec":
        i += 1
        class_part = tokens[i][0]
        if class_part == "ID":
            i += 1
            if tokens[i][0] in [")",";"]:
                i += 1
                return True
        return False


    elif class_part == "DT":
        i += 1
        if var_DT():
            if tokens[i][0] == ";":
                i += 1
                return True
        return False


    elif class_part == "ID":
        i += 1
        if var_ID():
            if tokens[i][0] == ";":
                i += 1
                return True
        return False

    return False


def var_ID():
    global i

    if tokens[i][0] in ["CompAssignment", "=", ",", "(","IncDec"]:
        if ID2():
            return True

    return False
def var_DT():
    global i

    if tokens[i][0] == "ID":
        i += 1
        if DT2():
            return True

    return False
def DT2():
    global i

    def assign():
        global i
        i += 1
        if expression():
            return True

    if tokens[i][0] == ",":
        i += 1
        if tokens[i][0] == "ID":
            i += 1
            if DT2():
                return True

    elif tokens[i][0] == "=":
        if assign():
            return True

    elif tokens[i][0] == ";":
        return True

    return False
def ID2():
    global i

    def comp_assign():
        global i

        def ca1():
            global i
            if expression():
                return True

            return False

        if tokens[i][0] == "=":
            i += 1
            if ca1():
                return True

        elif tokens[i][0] == "CompAssignment":
            i += 1
            if expression():
                return True

        return False


    if tokens[i][0] in ["CompAssignment", "="]:
        if comp_assign():
            return True

        e = f"SyntaxError: Invalid Assignment Statement at line {tokens[i][2]}"
        sys.exit(e)


    elif tokens[i][0] == ",":
        i += 1
        if tokens[i][0] == "ID":
            i += 1
            if ID2():
                return True
            e = f"SyntaxError: Missing 'ID' after ',' at line {tokens[i][2]}"
            sys.exit(e)



    elif tokens[i][0] == "IncDec":
        i += 1
        return True

    elif tokens[i][0] in [";", ")"]:
        return True

    return False
def arguments():
    global i

    def next():
        global i
        if tokens[i][0] == ")":
            return True

        elif tokens[i][0] == ",":
            i += 1
            if expression():
                if next():
                    return True

        return False

    if tokens[i][0] == ")":
        return True

    elif expression():
        if next():
            return True

    return False
def Statements():
    global i

    def Check():
        global i
        if Main_Route():
            if Check():
                return True

        elif tokens[i][0] == "}":
            return True

        return False

    if tokens[i][0] == "{":
        i += 1
        if Check():
            if tokens[i][0] == "}":
                i += 1
                return True
def iter_loop():
    global i

    def F1():
        global i

        if tokens[i][0] == "DT":
            i += 1
            if tokens[i][0] == "ID":
                i += 1
                if tokens[i][0] == "=":
                    i += 1
                    if expression():
                        return True

        elif tokens[i][0] == "ID":
            i += 1
            if tokens[i][0] == "=":
                i += 1
                if expression():
                   return True

        elif tokens[i][0] == ",":
            return True

        return False

    def F2():
        global i

        if tokens[i][0] == ",":
            return True

        elif expression():
            return True

        return False

    def F3():
        global i

        if tokens[i][0] == "IncDec":
            i += 1
            if tokens[i][0] == "ID":
                i += 1
                return True

        elif tokens[i][0] == "ID":
            i += 1
            if ID2():
                return True

        elif tokens[i][0] == ")":
            return True

        return False

    if tokens[i][0] == "iterate":
        i += 1
        if tokens[i][0] == "(":
            i += 1
            if F1():
                if tokens[i][0] == ",":
                    i += 1
                    if F2():
                        if tokens[i][0] == ",":
                            i += 1
                            if F3():
                                if tokens[i][0] == ")":
                                    i += 1
                                    if Statements():
                                        return True

    return False
def Condition_St():
    global i

    def otherwise():
        global i
        if tokens[i][0] == "otherwise" and tokens[i+1][0] == "when":
            i += 1
            if Condition_St():
                return True
        elif tokens[i][0] == "otherwise":
            i += 1
            if Statements():
                return True

        elif tokens[i][0] == ";":
            return True

        return False

    if tokens[i][0] == "when":
        i += 1
        if tokens[i][0] == "(":
            i += 1
            if expression():
                if tokens[i][0] == ")":
                    i += 1
                    if Statements():
                        if otherwise():
                            return True

    return False
def function():
    global i

    if tokens[i][0] == "func":
        i += 1
        if ReturnType():
            #if tokens[i][0] == "ID":
                i += 1
                if tokens[i][0] == "(":
                    i += 1
                    if parameters():
                        if tokens[i][0] == ")":
                            i += 1
                            if Statements():
                                return True

    raise Exception("Invalid function def.")
def parameters():
    global i
    if tokens[i][0] == ")":
        return True

    elif tokens[i][0] == "DT":
        i += 1
        if ID_Checker():
                i += 1
                if tokens[i][0] == ",":
                    i += 1
                    if parameters():
                        return True
                elif tokens[i][0] == ")":
                    return True
    elif tokens[i][0] == "ID":
            i += 1
            if tokens[i][0] == ",":
                i+=1
                if parameters():
                    return True
            elif tokens[i][0] == ")":
                return True

    raise Exception("Invalid Parameter(s)")
    return False
def ReturnType():
    global i
    if tokens[i][0] == "DT":
        i += 1
        if ID_Checker():
            return True

    elif tokens[i][0] == "void":
        i += 1
        if ID_Checker():
          return True

    raise Exception("Invalid Return Type")
def ID_Checker():
    global i

    if tokens[i][0] == "ID":
        return True

    exp = f"Invalid variable name after {tokens[i - 1][0]}"
    raise Exception(exp)
def Return():
    global i

    def ret1():
        global i


        if tokens[i][0] == ";":
            return True

        elif expression():
            return True

        return False

    if tokens[i][0] == "ret":
        i += 1
        if ret1():
            return True

    return False

def expression():
    def Or():
        global i
        if tokens[i][0] == "Logical_Op" and tokens[i][1] == "or":
            i += 1
            if And():
                if Or():
                    return True

        elif tokens[i][0] in [")", ";", ",", ":", "]"]:  # follow of expression
            return True

        return False

    def And():
        if RelOp():
            if And1():
                return True
        return False

    def And1():
        global i
        if tokens[i][0] == "Logical_Op" and tokens[i][1] == "and":
            i += 1
            if RelOp():
                if And1():
                    return True

        elif (tokens[i][0] in [")", ";", ",", ":", "]"]) or (tokens[i][1] == "or"):  # follow of expression
            return True

        return False

    def RelOp():
        if PM():
            if RelOp1():
                return True
        return False

    def RelOp1():#checks if it is a relation(>) or a variable initialization
        global i
        if tokens[i][0] == "RelOP":
            i += 1
            if PM():
                if RelOp1():
                    return True

        elif (tokens[i][0] in [")", ";", ",", ":", "]"]) or (tokens[i][1] in ["or", "and"]):  # follow of expression
            return True

        return False

    def PM():
        if MDM():
            if PM1():
                return True
        return False

    def PM1():# checks if it is plus minus or initialization
        global i
        if tokens[i][0] == "PlusMinus":
            i += 1
            if MDM():
                if PM1():
                    return True

        elif (tokens[i][0] in [")", "RelOP", ";", ",", ":", "]"]) or (tokens[i][1] in ["or", "and"]):  # follow of expression
            return True

        return False

    def MDM():
        if EndPoint():
            if MDM1():
                return True
        return False

    def MDM1():# checks if it is variable declaration and initialization
        global i
        if tokens[i][0] in ["DivMod", "*"]:
            i += 1
            if EndPoint():
                if MDM1():
                    return True

        elif (tokens[i][0] in ["PlusMinus", ")", "RelOP", ";", ",", ":", "]"]) or (tokens[i][1] in ["or", "and"]):  # follow of expression
            return True

        return False

    def EndPoint():
        global i

        def D():
            global i


            def D2():
                global i
                if tokens[i][0] == ".":
                    i += 1
                    if tokens[i][0] == "ID":
                        i += 1
                        if D():
                            return True


                elif (tokens[i][0] in ["DivMod", "*", "PlusMinus", ")", "RelOP", ";", ",", ":", "]"]) or (tokens[i][1] in ["or", "and"]):
                    return True

                return False

            if tokens[i][0] == ".":
                i += 1
                if tokens[i][0] == "ID":
                    if D():
                        return True


            elif tokens[i][0] == "(":
                i += 1
                if arguments():
                    if tokens[i][0] == ")":
                        i += 1
                        if D2():
                            return True


            elif (tokens[i][0] in ["DivMod", "*", "PlusMinus", ")", "RelOP", ";", ",", ":", "]"]) or (tokens[i][1] in ["or", "and"]):
                return True

            return False

        def A():
            global i

            def A1():
                global i

                if tokens[i][0] == ".":
                    i += 1
                    if tokens[i][0] == "ID":
                        i += 1
                        if A():
                            return True


                elif (tokens[i][0] in ["DivMod", "*", "PlusMinus", ")", "RelOP", ";", ",", ":", "]"]) or (tokens[i][1] in ["or", "and"]):
                    return True

                return False


            if tokens[i][0] == "IncDec":
                i += 1
                return True

            elif tokens[i][0] == "(":
                i += 1
                if arguments():
                    if tokens[i][0] == ")":
                        i += 1
                        if A1():
                            return True


            elif tokens[i][0] == ".":
                i += 1
                if tokens[i][0] == "ID":
                    i += 1
                    if A():
                        return True

            elif (tokens[i][0] in ["DivMod", "*", "PlusMinus", ")", "RelOP", ";", ",", ":", "]"]) or (tokens[i][1] in ["or", "and"]):
                return True

            return False

        if tokens[i][0] in ["Int_Const"]:
            i += 1
            return True

        elif tokens[i][0] == "ID":
            i += 1
            if A():
                return True

        elif tokens[i][0] == "(":
            i += 1
            if expression():
                if tokens[i][0] == ")":
                    i += 1
                    return True

        elif tokens[i][1] == "!":
            i += 1
            if EndPoint():
                return True

        elif tokens[i][0] == "IncDec":
            i += 1
            if tokens[i][0] == "ID":
                if D():
                    return True

        return False

    if And():
        if Or():
            return True

    e = f"SyntaxError: Invalid 'expression' at line {tokens[i][2]}"
    sys.exit(e)
