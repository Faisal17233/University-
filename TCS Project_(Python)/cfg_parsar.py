import sys

tokens = None

def SynAnalyzer(token_list):
    global tokens
    tokens = token_list
    return start()


error_list = []

i = 0


def start():
    global i
    if tokens[i][0] == "$":
        return True

    else:
        if SST():
            if start():
                return True

    return False
    # e =  f"SyntaxError: Invalid Statement at line {tokens[i][2]}"
    # sys.exit(e)

def SST():
    global i

    keyword = tokens[i][0]
    line = tokens[i][2]

    if keyword == "iterate":
        if iter_loop():
            if tokens[i][0] == ";":
                i += 1
                return True
        return False


    elif keyword == "when":
        if cond_st():
            if tokens[i][0] == ";":
                i += 1
                return True

        return False

    elif keyword == "func":
        if function():
            if tokens[i][0] == ";":
                i += 1
                return True
        return False

    elif keyword == "ret":
        if ret():
            keyword = tokens[i][0]
            if keyword == ";":
                i += 1
                return True
        return False


    elif keyword == "FlowControl":
        i += 1
        keyword = tokens[i][0]
        if keyword == ";":
            i += 1
            return True
        return False


    elif keyword == "IncDec":
        i += 1
        keyword = tokens[i][0]
        if keyword == "ID":
            i += 1
            if tokens[i][0] in [")",";"]:
                i += 1
                return True
        return False


    elif keyword == "DT":
        i += 1
        if array_def1():
            if tokens[i][0] == ";":
                i += 1
                return True
        return False


    elif keyword == "ID":
        i += 1
        if array_def():
            if tokens[i][0] == ";":
                i += 1
                return True
        #     e =  f"SyntaxError: Missing ';' after the statement at line {tokens[i][2]}"
        #     sys.exit(e)

        # e =  f"SyntaxError: Invalid statement at line {line}"
        # sys.exit(e)

        return False

    return False

def array_def():
    global i

    if tokens[i][0] in ["CompAssignment", "=", ",", "(","IncDec"]:
        if B2():
            return True

    return False

def array_def1():
    global i

    if tokens[i][0] == "ID":
        i += 1
        if B1():
            return True

    return False


def B1():# checks data declaration and initialization
    global i

    def assign():
        global i
        # if tokens[i][0] == "=":
        i += 1
        if expression():
            return True

    if tokens[i][0] == ",":
        i += 1
        if tokens[i][0] == "ID":
            i += 1
            if B1():
                return True

    elif tokens[i][0] == "=":
        if assign():
            return True

    elif tokens[i][0] == ";":
        return True

    return False

# same as B1, difference is it is only called when variable is not declared so IncDec and CompAssignment is also allowed
def B2():
    global i

    def comp_assign():
        global i

        def ca1():
            global i
            # if List():
            #     return True
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
            if B2():
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


def body():
    global i

    def MST():
        global i
        if SST():
            if MST():
                return True

        elif tokens[i][0] == "}":
            return True

        return False

    if tokens[i][0] == "{":
        i += 1
        if MST():
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

    # def C1():
    #     global i
    #
    #     if tokens[i][0] == "=":
    #         i += 1
    #         if expression():
    #             return True
    #
    #
    #     return False


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
            if B2():
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
                                    if body():
                                        return True

    return False


def cond_st():
    global i

    def otherwise():
        global i
        if tokens[i][0] == "otherwise" and tokens[i+1][0] == "when":
            i += 1
            if cond_st():
                return True
        elif tokens[i][0] == "otherwise":
            i += 1
            if body():
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
                    if body():
                        if otherwise():
                            return True

    return False


def function():
    global i

    if tokens[i][0] == "func":
        i += 1
        if ret_type():
            #if tokens[i][0] == "ID":
                i += 1
                if tokens[i][0] == "(":
                    i += 1
                    if parameters():
                        if tokens[i][0] == ")":
                            i += 1
                            if body():
                                return True

    raise Exception("Invalid function def.")

# checks the parameters of function
def parameters():
    global i
    if tokens[i][0] == ")":
        return True

    elif tokens[i][0] == "DT":
        i += 1
        if rt():
            # if tokens[i][0] == "ID":
                i += 1
                if tokens[i][0] == ",":
                    i += 1
                    if parameters():
                        return True
                elif tokens[i][0] == ")":
                    return True
    # checks if ID is directly given
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

#checks the return type that is mentioned after func in first line
def ret_type():
    global i
    if tokens[i][0] == "DT":
        i += 1
        if rt():
            return True

    elif tokens[i][0] == "void":
        i += 1
        if rt():
          return True

    raise Exception("Invalid Return Type")

# just checks the function name
def rt():
    global i

    if tokens[i][0] == "ID":
        return True

    exp = f"Invalid variable name after {tokens[i - 1][0]}"
    raise Exception(exp)


def ret():
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