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
    if (tokens[i][0] == "$"):
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

    if (keyword == "iterate"):
        if iter_loop():
            if (tokens[i][0] == ";"):
                i += 1
                return True
        return False


    elif (keyword == "when"):
        if cond_st():
            if (tokens[i][0] == ";"):
                i += 1
                return True

        return False


    elif (keyword == "try"):
        if exception():
            if (tokens[i][0] == ";"):
                i += 1
                return True
        return False


    elif (keyword == "func"):
        if function():
            if (tokens[i][0] == ";"):
                i += 1
                return True
        return False


    elif (keyword in ["class", "abstract"]):
        if Class():
            if (tokens[i][0] == ";"):
                i += 1
                return True
        return False


    elif (keyword == "enum"):
        if enum():
            if (tokens[i][0] == ";"):
                i += 1
                return True
        return False


    elif (keyword == "ret"):
        if ret():
            keyword = tokens[i][0]
            if (keyword == ";"):
                i += 1
                return True
        return False


    elif (keyword == "FlowControl"):
        i += 1
        keyword = tokens[i][0]
        if (keyword == ";"):
            i += 1
            return True
        return False


    elif (keyword == "IncDec"):
        i += 1
        keyword = tokens[i][0]
        if (keyword == "ID"):
            i += 1
            if B5():
                keyword = tokens[i][0]
                if (keyword == ";"):
                    i += 1
                    return True
        return False


    elif (keyword == "DT"):
        i += 1
        if array_def1():
            if (tokens[i][0] == ";"):
                i += 1
                return True
        return False


    elif (keyword == "ID"):
        i += 1
        if array_def():
            if (tokens[i][0] == ";"):
                i += 1
                return True
        #     e =  f"SyntaxError: Missing ';' after the statement at line {tokens[i][2]}"
        #     sys.exit(e)

        # e =  f"SyntaxError: Invalid statement at line {line}"
        # sys.exit(e)

        return False

    return False


def array_decl():
    global i

    if (tokens[i][0] == "["):
        i += 1
        if expression():
            if (tokens[i][0] == "]"):
                i += 1
                if array_decl1():
                    if (tokens[i][0] == "ID"):
                        i += 1
                        if v1():
                            if array_assign():
                                return True

    #                 e =  f"SyntaxError: Missing 'ID' at line {tokens[i][2]}"
    #                 sys.exit(e)

    #         e =  f"SyntaxError: Missing ']' at line {tokens[i][2]}"
    #         sys.exit(e)

    # e =  f"""SyntaxError: Invalid Array Declaration.
    #          Missing '[' at line {tokens[i][2]}"""
    # sys.exit(e)

    return False


def array_decl1():
    global i

    if (tokens[i][0] == "["):
        i += 1
        if expression():
            if (tokens[i][0] == "]"):
                i += 1
                if array_decl1():
                    return True

            # e =  f"SyntaxError: Missing ']' at line {tokens[i][2]}"
            # sys.exit(e)

    elif (tokens[i][0] == "ID"):
        return True

    return False


def v1():
    global i

    if (tokens[i][0] == ","):
        i += 1
        if (tokens[i][0] == "ID"):
            i += 1
            if v1():
                return True

    elif (tokens[i][0] in ["=", ";"]):
        return True

    return False


def array_assign():
    global i

    if (tokens[i][0] == "="):
        i += 1
        if List():
            return True

        elif expression():
            return True

    elif (tokens[i][0] == ";"):
        return True

    return False

def array_def():
    global i

    if (tokens[i][0] == "ID"):
        i += 1
        if B1():
            return True

    elif (tokens[i][0] == "["):
        if array_decl():
            return True

    elif (tokens[i][0] in ["CompAssignment", "=", "," ".", "[", "("]):
        if B2():
            return True

    return False

def array_def1():
    global i

    if (tokens[i][0] == "ID"):
        i += 1
        if B1():
            return True
   #del
    elif (tokens[i][0] == "["):
        if array_decl():
            return True

    return False


def List():
    global i

    def list1():
        global i

        if List():
            if list2():
                return True

        elif expression():
            if list2():
                return True

        return False

    def list2():
        global i

        if (tokens[i][0] == ","):
            i += 1
            if list1():
                return True

        elif (tokens[i][0] == "]"):
            return True

        return False

    def list3():
        global i

        if (tokens[i][0] == "]"):
            return True

        elif list1():
            return True

        return False

    if (tokens[i][0] == "["):
        i += 1
        if list3():
            if (tokens[i][0] == "]"):
                i += 1
                return True

            # e = f"SyntaxError: Missing ']' in list assignment at line {tokens[i][2]}"
            # sys.exit(e)

    return False


def B1():
    global i

    def assign():
        global i
        if (tokens[i][0] == "="):
            i += 1
            if expression():
                return True

    if (tokens[i][0] == ","):
        i += 1
        if (tokens[i][0] == "ID"):
            i += 1
            if B1():
                return True

    elif (tokens[i][0] == "="):
        if assign():
            return True

    elif (tokens[i][0] == ";"):
        return True

    return False


def B2():
    global i

    def comp_assign():
        global i

        def ca1():
            global i
            if List():
                return True
            elif expression():
                return True

            return False

        if (tokens[i][0] == "="):
            i += 1
            if ca1():
                return True

        elif (tokens[i][0] == "CompAssignment"):
            i += 1
            if expression():
                return True

        return False

    def B8():
        global i

        if (tokens[i][0] == "."):
            i += 1
            if (tokens[i][0] == "ID"):
                i += 1
                if B2():
                    return True

            e = f"SyntaxError: Missing 'ID' after '.' at line {tokens[i][2]}"
            sys.exit(e)


        elif (tokens[i][0] in ["CompAssignment", "="]):
            if comp_assign():
                return True

            e = f"SyntaxError: Invalid Assignment Statement at line {tokens[i][2]}"
            sys.exit(e)


        elif (tokens[i][0] in [";", ")"]):
            return True

        return False

    def B9():
        global i

        if (tokens[i][0] == "."):
            i += 1
            if (tokens[i][0] == "ID"):
                i += 1
                if B2():
                    return True

            e = f"SyntaxError: Missing 'ID' after '.' at line {tokens[i][2]}"
            sys.exit(e)

        elif (tokens[i][0] == "["):
            if array_index():
                if B8():
                    return True
            e = f"SyntaxError: Invalid ArrayIndex at line {tokens[i][2]}"
            sys.exit(e)

        elif (tokens[i][0] in [";", ")"]):
            return True

        return False

    if (tokens[i][0] in ["CompAssignment", "="]):
        if comp_assign():
            return True

        e = f"SyntaxError: Invalid Assignment Statement at line {tokens[i][2]}"
        sys.exit(e)


    elif (tokens[i][0] == ","):
        i += 1
        if (tokens[i][0] == "ID"):
            i += 1
            if B2():
                return True
            e = f"SyntaxError: Missing 'ID' after ',' at line {tokens[i][2]}"
            sys.exit(e)


    elif (tokens[i][0] == "."):
        i += 1
        if (tokens[i][0] == "ID"):
            i += 1
            if B2():
                return True

        e = f"SyntaxError: Missing 'ID' after '.' at line {tokens[i][2]}"
        sys.exit(e)


    elif (tokens[i][0] == "["):
        if array_index():
            if B8():
                return True

        e = f"SyntaxError: Invalid ArrayIndex at line {tokens[i][2]}"
        sys.exit(e)

    elif (tokens[i][0] == "IncDec"):
        i += 1
        return True

    elif (tokens[i][0] == "("):
        i += 1
        if arguments():
            if (tokens[i][0] == ")"):
                i += 1
                if B9():
                    return True

            e = f"SyntaxError: Missing ')' after function arguments at line {tokens[i][2]}"
            sys.exit(e)

        e = f"SyntaxError: Invalid function arguments at line {tokens[i][2]}"
        sys.exit(e)

    elif (tokens[i][0] in [";", ")"]):
        return True

    return False


def B5():
    global i

    def B6():
        global i
        if (tokens[i][0] == "."):
            i += 1
            if (tokens[i][0] == "ID"):
                i += 1
                if B5():
                    return True

        elif (tokens[i][0] in [";", ")"]):
            return True

        return False

    def B7():
        global i
        if (tokens[i][0] == "."):
            i += 1
            if (tokens[i][0] == "ID"):
                i += 1
                if B5():
                    return True

        elif (tokens[i][0] == "["):
            if array_index():
                if B6():
                    return True

        elif (tokens[i][0] in [";", ")"]):
            return True

        return False

    if (tokens[i][0] == "."):
        i += 1
        if (tokens[i][0] == "ID"):
            if B5():
                return True

    elif (tokens[i][0] == "["):
        if array_index():
            if B6():
                return True

    elif (tokens[i][0] == "("):
        i += 1
        if arguments():
            if (tokens[i][0] == ")"):
                i += 1
                if B7():
                    return True


    elif (tokens[i][0] in [";", ")"]):
        return True

    return False


def array_index():
    global i

    def Slice():
        global i
        if (tokens[i][0] == ":"):
            i += 1
            if expression():
                if step():
                    return True

            # e = f"SyntaxError: Invalid List Slicing at line {tokens[i][2]}"
            # sys.exit(e)

        elif (tokens[i][0] == "]"):
            return True

    def step():
        global i
        if (tokens[i][0] == ":"):
            i += 1
            if expression():
                return True


        elif (tokens[i][0] == "]"):
            return True

        return False

    def array_index1():
        global i

        if (tokens[i][0] == "["):
            i += 1
            if (tokens[i][0] == "]"):
                return True

            elif expression():
                if Slice():
                    if (tokens[i][0] == "]"):
                        i += 1
                        if array_index1():
                            return True

                    # e = f"SyntaxError: Missing ']' in after index at line {tokens[i][2]}"
                    # sys.exit(e)

        elif (tokens[i][0] in [";", "=", "CompAssignment", ".", "IncDec", "PlusMinus", ")", "RelOP", "Logical_Op"]) or (tokens[i][1] in ["and", "or"]):
            return True

        return False

    if (tokens[i][0] == "["):
        i += 1
        if (tokens[i][0] == "]"):
            return True

        elif expression():
            if Slice():
                if (tokens[i][0] == "]"):
                    i += 1
                    if array_index1():
                        return True

            #         e = f"SyntaxError: Invalid index at line {tokens[i][2]}"
            #         sys.exit(e)

            #     e = f"SyntaxError: Missing ']' after index at line {tokens[i][2]}"
            #     sys.exit(e)

            # e = f"SyntaxError: Invalid Slicing at line {tokens[i][2]}"
            # sys.exit(e)

    elif (tokens[i][0] in [";", "=", "CompAssignment", ".", "IncDec", "PlusMinus", ")", "RelOP", "Logical_Op"]) or (tokens[i][1] in ["and", "or"]):
        return True

    return False


def arguments():
    global i

    def next():
        global i
        if (tokens[i][0] == ")"):
            return True

        elif (tokens[i][0] == ","):
            i += 1
            if expression():
                if next():
                    return True

        return False

    if (tokens[i][0] == ")"):
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

    if (tokens[i][0] == "{"):
        i += 1
        if MST():
            if (tokens[i][0] == "}"):
                i += 1
                return True

def iter_loop():
    global i

    def F1():
        global i

        if (tokens[i][0] == "DT"):
            i += 1
            if (tokens[i][0] == "ID"):
                i += 1
                if C1():
                    return True

        elif (tokens[i][0] == "ID"):
            i += 1
            if C2():
                return True

        elif (tokens[i][0] == ","):
            return True

        return False

    def C1():
        global i

        if (tokens[i][0] == "="):
            i += 1
            if expression():
                return True

        elif (tokens[i][0] == ","):
            return True

        return False

    def C2():
        global i

        if (tokens[i][0] == "="):
            i += 1
            if expression():
                return True

        elif (tokens[i][0] == "ID"):
            i += 1
            if C3():
                return True

        elif (tokens[i][0] == ","):
            return True

        return False

    def C3():
        global i

        if (tokens[i][0] == "="):
            i += 1
            if expression():
                return True

        elif (tokens[i][0] == ","):
            return True

        return False

    def F2():
        global i

        if (tokens[i][0] == ","):
            return True

        elif expression():
            return True

        return False

    def F3():
        global i

        if (tokens[i][0] == "IncDec"):
            i += 1
            if (tokens[i][0] == "ID"):
                i += 1
                if B5():
                    return True

        elif (tokens[i][0] == "ID"):
            i += 1
            if B2():
                return True

        elif (tokens[i][0] == ")"):
            return True

        return False

    if (tokens[i][0] == "iterate"):
        i += 1
        if (tokens[i][0] == "("):
            i += 1
            if F1():
                if (tokens[i][0] == ","):
                    i += 1
                    if F2():
                        if (tokens[i][0] == ","):
                            i += 1
                            if F3():
                                if (tokens[i][0] == ")"):
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
        elif (tokens[i][0] == "otherwise"):
            i += 1
            if body():
                return True

        elif (tokens[i][0] == ";"):
            return True

        return False

    if (tokens[i][0] == "when"):
        i += 1
        if (tokens[i][0] == "("):
            i += 1
            if expression():
                if (tokens[i][0] == ")"):
                    i += 1
                    if body():
                        if otherwise():
                            return True

    return False


def exception():
    global i

    def more_except():
        global i

        if (tokens[i][0] == "except"):
            i += 1
            if (tokens[i][0] == "("):
                i += 1
                if error():
                    if (tokens[i][0] == ")"):
                        i += 1
                        if body():
                            if more_except():
                                return True

        elif (tokens[i][0] == ";"):
            return True

        return False

    def error():
        global i

        exception_types = [
            "SyntaxError",
            "NameError",
            "TypeError",
            "ValueError",
            "IndexError",
            "ZeroDivisionError",
            "ArithmeticError",
            "TypeError",
            "NotImplementedError",
            "PermissionError",
            "RecursionError",
            "ERROR"
        ]

        if (tokens[i][0] in exception_types):
            i += 1
            if more_error():
                return True

        return False

    def more_error():
        global i

        if (tokens[i][0] == "Logical_Op"):
            i += 1
            if error():
                if more_error():
                    return True

        elif (tokens[i][0] == ")"):
            return True

        return False

    if (tokens[i][0] == "try"):
        i += 1
        if body():
            if (tokens[i][0] == "except"):
                i += 1
                if (tokens[i][0] == "("):
                    i += 1
                    if error():
                        if (tokens[i][0] == ")"):
                            i += 1
                            if body():
                                if more_except():
                                    return True

    return False


def function():
    global i

    if (tokens[i][0] == "func"):
        i += 1
        if ret_type():
            if (tokens[i][0] == "ID"):
                i += 1
                if (tokens[i][0] == "("):
                    i += 1
                    if parameters():
                        if (tokens[i][0] == ")"):
                            i += 1
                            if body():
                                return True

    raise Exception("Invalid function def.")


def parameters():
    global i
    if (tokens[i][0] == ")"):
        return True

    elif (tokens[i][0] in ["ID", "DT"]):
        i += 1
        if rt():
            if (tokens[i][0] == "ID"):
                i += 1
                if param():
                    return True

    raise Exception("Invalid Parameter(s)")
    return False


def ret_type():
    global i
    if (tokens[i][0] in ["ID", "DT"]):
        i += 1
        if rt():
            return True

    elif (tokens[i][0] == "None"):
        i += 1
        return True

    raise Exception("Invalid Return Type")


def rt():
    global i
    if (tokens[i][0] == "["):
        i += 1
        if (tokens[i][0] == "]"):
            i += 1
            return rt()

    elif (tokens[i][0] == "ID"):
        return True

    exp = f"Invalid Value after {tokens[i - 1][0]}"
    raise Exception(exp)


def param():
    global i
    if (tokens[i][0] == ","):
        i += 1
        if param1():
            return True

    elif (tokens[i][0] == ")"):
        return True

    raise Exception("Invalid Parameter(s)")


def param1():
    global i
    if (tokens[i][0] in ["ID", "DT"]):
        i += 1
        if rt():
            if (tokens[i][0] == "ID"):
                i += 1
                if param():
                    return True

    return False
    raise Exception("Invalid Parameter(s)")


def enum():
    global i

    def enum_values():
        global i
        if (tokens[i][0] == "ID"):
            i += 1
            if ev1():
                if ev():
                    return True

        elif (tokens[i][0] == "]"):
            return True

        return False

    def ev1():
        global i
        if (tokens[i][0] == "="):
            i += 1
            if (tokens[i][0] == "Int_Const"):
                i += 1
                return True

        elif (tokens[i][0] in [",", "]"]):
            return True

        return False

    def ev():
        global i
        if (tokens[i][0] == ","):
            i += 1
            if (tokens[i][0] == "ID"):
                i += 1
                if ev1():
                    if ev():
                        return True

        elif (tokens[i][0] in ["]", ";"]):
            return True

    def enum_assign():
        global i
        if (tokens[i][0] == "ID"):
            i += 1
            if ev2():
                return True

        elif (tokens[i][0] == ";"):
            return True

        return False

    def ev2():
        global i
        if (tokens[i][0] == ","):
            i += 1
            if (tokens[i][0] == "ID"):
                i += 1
                if ev2():
                    return True

        elif (tokens[i][0] == ";"):
            return True

        return False

    if (tokens[i][0] == "enum"):
        i += 1
        if (tokens[i][0] == "ID"):
            i += 1
            if (tokens[i][0] == "["):
                i += 1
                if enum_values():
                    if (tokens[i][0] == "]"):
                        i += 1
                        if enum_assign():
                            return True

    return False


def ret():
    global i

    def ret1():
        global i

        if (tokens[i][0] == "None"):
            i += 1
            return True

        elif (tokens[i][0] == ";"):
            return True

        elif expression():
            return True

        return False

    if (tokens[i][0] == "ret"):
        i += 1
        if ret1():
            return True

    return False


def expression():
    def Or():
        global i
        if (tokens[i][0] == "Logical_Op" and tokens[i][1] == "or"):
            i += 1
            if And():
                if Or():
                    return True

        elif (tokens[i][0] in [")", ";", ",", ":", "]"]):  # follow of expression
            return True

        return False

    def And():
        if RelOp():
            if And1():
                return True
        return False

    def And1():
        global i
        if (tokens[i][0] == "Logical_Op" and tokens[i][1] == "and"):
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
        if (tokens[i][0] == "RelOP"):
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
        if (tokens[i][0] == "PlusMinus"):
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
        if (tokens[i][0] in ["DivMod", "*"]):
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

            def D1():
                global i
                if (tokens[i][0] == "."):
                    i += 1
                    if (tokens[i][0] == "ID"):
                        i += 1
                        if D():
                            return True

                elif (tokens[i][0] in ["DivMod", "*", "PlusMinus", ")", "RelOP", ";", ",", ":", "]"]) or (tokens[i][1] in ["or", "and"]):
                    return True

                return False

            def D2():
                global i
                if (tokens[i][0] == "."):
                    i += 1
                    if (tokens[i][0] == "ID"):
                        i += 1
                        if D():
                            return True

                elif (tokens[i][0] == "["):
                    if array_index():
                        if D1():
                            return True

                elif (tokens[i][0] in ["DivMod", "*", "PlusMinus", ")", "RelOP", ";", ",", ":", "]"]) or (tokens[i][1] in ["or", "and"]):
                    return True

                return False

            if (tokens[i][0] == "."):
                i += 1
                if (tokens[i][0] == "ID"):
                    if D():
                        return True

            elif (tokens[i][0] == "["):
                if array_index():
                    if D1():
                        return True

            elif (tokens[i][0] == "("):
                i += 1
                if arguments():
                    if (tokens[i][0] == ")"):
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

                if (tokens[i][0] == "."):
                    i += 1
                    if (tokens[i][0] == "ID"):
                        i += 1
                        if A():
                            return True

                elif (tokens[i][0] == "["):
                    if array_index():
                        if A3():
                            return True

                elif (tokens[i][0] in ["DivMod", "*", "PlusMinus", ")", "RelOP", ";", ",", ":", "]"]) or (tokens[i][1] in ["or", "and"]):
                    return True

                return False

            def A2():
                global i

                if (tokens[i][0] == "."):
                    i += 1
                    if (tokens[i][0] == "ID"):
                        i += 1
                        if A():
                            return True

                elif (tokens[i][0] == "IncDec"):
                    i += 1
                    return True


                elif (tokens[i][0] in ["DivMod", "*", "PlusMinus", ")", "RelOP", ";", ",", ":", "]"]) or (tokens[i][1] in ["or", "and"]):
                    return True

                return False

            def A3():
                global i

                if (tokens[i][0] == "."):
                    i += 1
                    if (tokens[i][0] == "ID"):
                        i += 1
                        if A():
                            return True


                elif (tokens[i][0] in ["DivMod", "*", "PlusMinus", ")", "RelOP", ";", ",", ":", "]"]) or (tokens[i][1] in ["or", "and"]):
                    return True

                return False

            if (tokens[i][0] == "IncDec"):
                i += 1
                return True

            elif (tokens[i][0] == "("):
                i += 1
                if arguments():
                    if (tokens[i][0] == ")"):
                        i += 1
                        if A1():
                            return True

            elif (tokens[i][0] == "["):
                if array_index():
                    if A2():
                        return True

            elif (tokens[i][0] == "."):
                i += 1
                if (tokens[i][0] == "ID"):
                    i += 1
                    if A():
                        return True

            elif (tokens[i][0] in ["DivMod", "*", "PlusMinus", ")", "RelOP", ";", ",", ":", "]"]) or (tokens[i][1] in ["or", "and"]):
                return True

            return False

        if (tokens[i][0] in ["Bool_Const", "Int_Const", "Float_Const", "Str_Const", "Char_Const"]):
            i += 1
            return True

        elif (tokens[i][0] == "ID"):
            i += 1
            if A():
                return True

        elif (tokens[i][0] == "("):
            i += 1
            if expression():
                if (tokens[i][0] == ")"):
                    i += 1
                    return True

        elif (tokens[i][1] == "!"):
            i += 1
            if EndPoint():
                return True

        elif (tokens[i][0] == "IncDec"):
            i += 1
            if (tokens[i][0] == "ID"):
                if D():
                    return True

        return False

    if And():
        if Or():
            return True

    e = f"SyntaxError: Invalid 'expression' at line {tokens[i][2]}"
    sys.exit(e)


# =====================================
#     --------CLASS------
# =====================================

def Class():
    global i

    def abstract():
        global i

        if (tokens[i][0] == "abstract"):
            i += 1
            return True

        elif (tokens[i][0] == "class"):
            return True

        return False

    def inherit():
        global i

        if (tokens[i][0] == "inherits"):
            i += 1
            if (tokens[i][0] == "ID"):
                i += 1
                return True

        elif (tokens[i][0] == "{"):
            return True

        return False

    def class_main_body():
        global i

        def class_main_MST():
            global i
            if class_main_SST():
                if class_main_MST():
                    return True

            elif (tokens[i][0] == "}"):
                return True

            return False

        if (tokens[i][0] == "{"):
            i += 1
            if class_main_MST():
                if (tokens[i][0] == "}"):
                    i += 1
                    return True

                e = "SyntaxError: Missing '}' at line " + f"{tokens[i][2]}"
                sys.exit(e)

            e = f"SyntaxError: Invalid statement at line {tokens[i][2]}"
            sys.exit(e)

        e = "SyntaxError: Missing '{' at line " + f"{tokens[i][2]}"
        sys.exit(e)

    if abstract():
        if (tokens[i][0] == "class"):
            i += 1
            if (tokens[i][0] == "ID"):
                i += 1
                if inherit():
                    if class_main_body():
                        return True

                e = f"SyntaxError: Invalid statement after 'class ID' at line {tokens[i][2]}"
                sys.exit(e)

            e = f"SyntaxError: Missing 'ID' after 'class' keyword at line {tokens[i][2]}"
            sys.exit(e)

        e = f"SyntaxError: Missing 'class' keyword at line {tokens[i][2]}"
        sys.exit(e)

    return False


def class_main_SST():
    global i

    line = tokens[i][2]

    if (tokens[i][0] == "construct"):
        if constructor():
            if (tokens[i][0] == ";"):
                i += 1
                return True

            e = f"SyntaxError: Missing ';' after 'constructor' statement at line {tokens[i][2]}"
            sys.exit(e)

        e = f"SyntaxError: Invalid 'constructor' statement at line {line}"
        sys.exit(e)


    elif (tokens[i][0] == "enum"):
        if enum():
            if (tokens[i][0] == ";"):
                i += 1
                return True

            e = f"SyntaxError: Missing ';' after 'enum' statement at line {tokens[i][2]}"
            sys.exit(e)

        e = f"SyntaxError: Invalid 'enum' statement at line {line}"
        sys.exit(e)


    elif (tokens[i][0] in ["static", "virtual", "func"]):
        if class_function():
            if (tokens[i][0] == ";"):
                i += 1
                return True

            e = f"SyntaxError: Missing ';' after 'enum' statement at line {tokens[i][2]}"
            sys.exit(e)

        e = f"SyntaxError: Invalid 'function' statement at line {line}"
        sys.exit(e)


    elif (tokens[i][0] == "AccessModifier"):
        i += 1
        if (tokens[i][0] == ":"):
            i += 1
            return True

        e = f"SyntaxError: Missing ':' after 'AccessModifier' keyword at line {tokens[i][2]}"
        sys.exit(e)


    elif Class():
        if (tokens[i][0] == ";"):
            i += 1
            return True

        e = f"SyntaxError: Missing ';' after 'class' statement at line {tokens[i][2]}"
        sys.exit(e)


    elif (tokens[i][0] == "IncDec"):
        i += 1
        if (tokens[i][0] == "ID"):
            i += 1
            if class_B5():
                if (tokens[i][0] == ";"):
                    i += 1
                    return True

                e = f"SyntaxError: Missing ';' after 'IncDec' statement at line {tokens[i][2]}"
                sys.exit(e)

        e = f"SyntaxError: Missing 'ID' after 'IncDec' operator at line {tokens[i][2]}"
        sys.exit(e)


    elif (tokens[i][0] == "ID"):
        i += 1
        if class_array_def():
            if (tokens[i][0] == ";"):
                i += 1

            e = f"SyntaxError: Missing ';' after the statement at line {tokens[i][2]}"
            sys.exit(e)


    elif (tokens[i][0] == "DT"):
        i += 1
        if class_array_def1():
            if (tokens[i][0] == ";"):
                i += 1

            e = f"SyntaxError: Missing ';' after the statement at line {tokens[i][2]}"
            sys.exit(e)

    return False


def class_B1():
    global i

    def class_assign():
        global i
        if (tokens[i][0] == "="):
            i += 1
            if class_expression():
                return True

    if (tokens[i][0] == ","):
        i += 1
        if (tokens[i][0] == "ID"):
            i += 1
            if class_B1():
                return True

    elif (tokens[i][0] == "="):
        if class_assign():
            return True

    elif (tokens[i][0] == ";"):
        return True

    return False


def class_B2():
    global i

    def class_comp_assign():
        global i

        def ca1():
            global i
            if class_List():
                return True
            elif class_expression():
                return True

            return False

        if (tokens[i][0] == "="):
            i += 1
            if ca1():
                return True

        elif (tokens[i][0] == "CompAssignment"):
            i += 1
            if class_expression():
                return True

        return False

    def B8():
        global i

        if (tokens[i][0] == "."):
            i += 1
            if (tokens[i][0] == "ID"):
                i += 1
                if class_B2():
                    return True

        elif (tokens[i][0] in ["CompAssignment", "="]):
            if class_comp_assign():
                return True

        # elif (tokens[i][0] in [";", ")"]):
        #     return True

        return False

    def B9():
        global i

        if (tokens[i][0] == "."):
            i += 1
            if (tokens[i][0] == "ID"):
                i += 1
                if class_B2():
                    return True

        elif (tokens[i][0] == "["):
            if class_array_index():
                if B8():
                    return True

        # elif (tokens[i][0] in [";", ")"]):
        #     return True

        return False

    if (tokens[i][0] in ["CompAssignment", "="]):
        if class_comp_assign():
            return True

    elif (tokens[i][0] == ","):
        i += 1
        if (tokens[i][0] == "ID"):
            i += 1
            if class_B2():
                return True

    elif (tokens[i][0] == "."):
        i += 1
        if (tokens[i][0] == "ID"):
            i += 1
            if class_B2():
                return True

    elif (tokens[i][0] == "["):
        if class_array_index():
            if B8():
                return True

    elif (tokens[i][0] == "IncDec"):
        i += 1
        return True

    elif (tokens[i][0] == "("):
        i += 1
        if class_arguments():
            if (tokens[i][0] == ")"):
                i += 1
                if B9():
                    return True

    # elif (tokens[i][0] in [";", ")"]):
    #     return True

    return False


def class_B5():
    global i

    def class_B6():
        global i
        if (tokens[i][0] == "."):
            i += 1
            if (tokens[i][0] == "ID"):
                i += 1
                if class_B5():
                    return True

        elif (tokens[i][0] in [";", ")"]):
            return True

        return False

    def class_B7():
        global i
        if (tokens[i][0] == "."):
            i += 1
            if (tokens[i][0] == "ID"):
                i += 1
                if class_B5():
                    return True

        elif (tokens[i][0] == "["):
            if class_array_index():
                if class_B6():
                    return True

        # elif (tokens[i][0] in [";", ")"]):
        #     return True

        return False

    if (tokens[i][0] == "."):
        i += 1
        if (tokens[i][0] == "ID"):
            if class_B5():
                return True

    elif (tokens[i][0] == "["):
        if class_array_index():
            if class_B6():
                return True

    elif (tokens[i][0] == "("):
        i += 1
        if class_arguments():
            if (tokens[i][0] == ")"):
                i += 1
                if class_B7():
                    return True


    elif (tokens[i][0] in [";", ")"]):
        return True

    return False


def constructor():
    global i

    if (tokens[i][0] == "construct"):
        i += 1
        if (tokens[i][0] == "ID"):
            i += 1
            if (tokens[i][0] == "("):
                i += 1
                if parameters():
                    if (tokens[i][0] == ")"):
                        i += 1
                        if class_body():
                            return True

                    e = f"SyntaxError: Missing ')' at line {tokens[i][2]}"
                    sys.exit(e)

            e = f"SyntaxError: Missing '(' at line {tokens[i][2]}"
            sys.exit(e)

        e = f"SyntaxError: Missing 'ID' after 'construct' keyword at line {tokens[i][2]}"
        sys.exit(e)

    return False


def class_function():
    global i

    def sv():
        global i
        if (tokens[i][0] in ["static", "virtual"]):
            i += 1
            return True

        elif (tokens[i][0] == "func"):
            return True

        return False

    def override():
        global i

        if (tokens[i][0] == "override"):
            return True
        elif (tokens[i][0] == "{"):
            return True

        return False

    if sv():
        if (tokens[i][0] == "func"):
            i += 1
            if ret_type():
                if (tokens[i][0] == "ID"):
                    i += 1
                    if (tokens[i][0] == "("):
                        i += 1
                        if parameters():
                            if (tokens[i][0] == ")"):
                                i += 1
                                if override():
                                    if class_body():
                                        return True

                            e = f"SyntaxError: Missing ')' after 'func ID' at line {tokens[i][2]}"
                            sys.exit(e)

                    e = f"SyntaxError: Missing '(' after 'func ID' at line {tokens[i][2]}"
                    sys.exit(e)

                e = f"SyntaxError: 'ID' missing in func def at line {tokens[i][2]}"
                sys.exit(e)

        e = f"SyntaxError: 'func' keyword missing at line {tokens[i][2]}"
        sys.exit(e)

    return False


def tb():
    global i
    if (tokens[i][0] == "ClassReference"):
        i += 1
        if (tokens[i][0] == "."):
            i += 1
            return True

    if (tokens[i][0] == "ID"):
        return True

    return False


def tb1():
    global i
    if (tokens[i][0] == "ClassReference"):
        i += 1
        if (tokens[i][0] == "."):
            i += 1
            return True

    return False


def class_body():
    global i

    def class_MST():
        global i
        if class_SST():
            if class_MST():
                return True

        elif (tokens[i][0] == "}"):
            return True

        return False

    if (tokens[i][0] == "{"):
        i += 1
        if class_MST():
            if (tokens[i][0] == "}"):
                i += 1
                return True

            e = "SyntaxError: Missing '}' at line " + f"{tokens[i][2]}"
            sys.exit(e)

        e = f"SyntaxError: Invalid statement at line {tokens[i][2]}"
        sys.exit(e)

    e = "SyntaxError: Missing '{' at line " + f"{tokens[i][2]}"
    sys.exit(e)


def class_SST():
    global i

    keyword = tokens[i][0]
    line = tokens[i][2]

    if (keyword == "iterate"):
        if class_iter_loop():
            if (tokens[i][0] == ";"):
                i += 1
                return True

            e = f"SyntaxError: Missing ';' after 'iterate loop' statement at line {tokens[i][2]}"
            sys.exit(e)

        e = f"SyntaxError: Invalid 'iterate loop' statement at line {line}"
        sys.exit(e)


    elif (keyword == "when"):
        if class_cond_st():
            if (tokens[i][0] == ";"):
                i += 1
                return True

            e = f"SyntaxError: Missing ';' after 'when condition' statement at line {tokens[i][2]}"
            sys.exit(e)

        e = f"SyntaxError: Invalid 'when condition' statement at line {line}"
        sys.exit(e)


    elif (keyword == "try"):
        if class_exception():
            if (tokens[i][0] == ";"):
                i += 1
                return True

            e = f"SyntaxError: Missing ';' after 'exception' statement at line {tokens[i][2]}"
            sys.exit(e)

        e = f"SyntaxError: Invalid 'exception' statement at line {line}"
        sys.exit(e)


    elif (keyword == "func"):
        if class_function2():
            if (tokens[i][0] == ";"):
                i += 1
                return True

            e = f"SyntaxError: Missing ';' after 'function' statement at line {tokens[i][2]}"
            sys.exit(e)

        e = f"SyntaxError: Invalid 'function' statement at line {line}"
        sys.exit(e)


    elif (keyword in ["class", "abstract"]):
        if Class():
            if (tokens[i][0] == ";"):
                i += 1
                return True
            e = f"SyntaxError: Missing ';' after 'class' statement at line {tokens[i][2]}"
            sys.exit(e)

        e = f"SyntaxError: Invalid 'class' statement at line {line}"
        sys.exit(e)


    elif (keyword == "enum"):
        if enum():
            if (tokens[i][0] == ";"):
                i += 1
                return True
            e = f"SyntaxError: Missing ';' after 'enum' statement at line {tokens[i][2]}"
            sys.exit(e)

        e = f"SyntaxError: Invalid 'enum' statement at line {line}"
        sys.exit(e)


    elif (keyword == "ret"):
        if class_ret():
            keyword = tokens[i][0]
            if (keyword == ";"):
                i += 1
                return True
            e = f"SyntaxError: Missing ';' after 'ret' statement at line {tokens[i][2]}"
            sys.exit(e)

        e = f"SyntaxError: Invalid 'ret' statement at line {line}"
        sys.exit(e)

        return False


    elif (keyword == "FlowControl"):
        i += 1
        keyword = tokens[i][0]
        if (keyword == ";"):
            i += 1
            return True
        e = f"SyntaxError: Missing ';' after 'FlowControl' statement at line {tokens[i][2]}"
        sys.exit(e)

        return False


    elif (keyword == "IncDec"):
        i += 1
        keyword = tokens[i][0]
        if tb():
            if (keyword == "ID"):
                i += 1
                if class_B5():
                    keyword = tokens[i][0]
                    if (keyword == ";"):
                        i += 1
                        return True

                    e = f"SyntaxError: Missing ';' after 'IncDec' statement at line {tokens[i][2]}"
                    sys.exit(e)

                e = f"SyntaxError: Invalid statement at line {line}"
                sys.exit(e)

        e = f"SyntaxError: Missing 'ID' after 'IncDec' Operator at line {tokens[i][2]}"
        sys.exit(e)

        return False


    elif (keyword == "DT"):
        i += 1
        if class_array_def1():
            if (tokens[i][0] == ";"):
                i += 1
                return True

            e = f"SyntaxError: Missing ';' after the statement at line {tokens[i][2]}"
            sys.exit(e)

        e = f"SyntaxError: Invalid statement at line {line}"
        sys.exit(e)

        return False


    elif (keyword == "ID"):
        i += 1
        if class_array_def():
            if (tokens[i][0] == ";"):
                i += 1
                return True
            e = f"SyntaxError: Missing ';' after the statement at line {tokens[i][2]}"
            sys.exit(e)

        e = f"SyntaxError: Invalid statement at line {line}"
        sys.exit(e)

        return False


    elif tb1():
        if (keyword == "ID"):
            i += 1
            if class_B2():
                if (tokens[i][0] == ";"):
                    i += 1
                    return True
                e = f"SyntaxError: Missing ';' after the statement at line {tokens[i][2]}"
                sys.exit(e)

            e = f"SyntaxError: Invalid statement at line {line}"
            sys.exit(e)

            return False

    return False


def class_function2():
    global i

    if (tokens[i][0] == "func"):
        i += 1
        if ret_type():
            if (tokens[i][0] == "ID"):
                i += 1
                if (tokens[i][0] == "("):
                    i += 1
                    if parameters():
                        if (tokens[i][0] == ")"):
                            i += 1
                            if class_body():
                                return True

                        e = f"SyntaxError: Missing ')' after 'func ID' at line {tokens[i][2]}"
                        sys.exit(e)

                e = f"SyntaxError: Missing '(' after 'func ID' at line {tokens[i][2]}"
                sys.exit(e)

            e = f"SyntaxError: 'ID' missing in func def at line {tokens[i][2]}"
            sys.exit(e)

    return False


def class_ret():
    global i

    def class_ret1():
        global i

        if (tokens[i][0] == "None"):
            i += 1
            return True

        elif (tokens[i][0] == ";"):
            return True

        elif class_expression():
            return True

        return False

    if (tokens[i][0] == "ret"):
        i += 1
        if class_ret1():
            return True

    return False


def class_iter_loop():
    global i

    def F1():
        global i

        if (tokens[i][0] == "DT"):
            i += 1
            if (tokens[i][0] == "ID"):
                i += 1
                if C1():
                    return True

        # elif (tokens[i][0] == "ID"):
        #     i += 1
        #     if C2():
        #         return True

        elif tb():
            if (tokens[i][0] == "ID"):
                i += 1
                if C2():
                    return True

        elif (tokens[i][0] == ","):
            return True

        return False

    def C1():
        global i

        if (tokens[i][0] == "="):
            i += 1
            if class_expression():
                return True

        elif (tokens[i][0] == ","):
            return True

        return False

    def C2():
        global i

        if (tokens[i][0] == "="):
            i += 1
            if class_expression():
                return True

        elif (tokens[i][0] == "ID"):
            i += 1
            if C3():
                return True

        elif (tokens[i][0] == ","):
            return True

        return False

    def C3():
        global i

        if (tokens[i][0] == "="):
            i += 1
            if class_expression():
                return True

        elif (tokens[i][0] == ","):
            return True

        return False

    def F2():
        global i

        if (tokens[i][0] == ","):
            return True

        elif class_expression():
            return True

        return False

    def F3():
        global i

        if (tokens[i][0] == "IncDec"):
            i += 1
            if tb():
                if (tokens[i][0] == "ID"):
                    i += 1
                    if class_B5():
                        return True

        elif (tokens[i][0] == "ID"):
            i += 1
            if class_B2():
                return True

        elif tb1():
            if (tokens[i][0] == "ID"):
                i += 1
                if class_B2():
                    return True

        elif (tokens[i][0] == ")"):
            return True

        return False

    if (tokens[i][0] == "iterate"):
        i += 1
        if (tokens[i][0] == "("):
            i += 1
            if F1():
                if (tokens[i][0] == ","):
                    i += 1
                    if F2():
                        if (tokens[i][0] == ","):
                            i += 1
                            if F3():
                                if (tokens[i][0] == ")"):
                                    i += 1
                                    if class_body():
                                        return True

    return False


def class_cond_st():
    global i

    def class_otherwise():
        global i

        if (tokens[i][0] == "otherwise"):
            i += 1
            if class_body():
                return True

        elif (tokens[i][0] == ";"):
            return True

        return False

    if (tokens[i][0] == "when"):
        i += 1
        if (tokens[i][0] == "("):
            i += 1
            if class_expression():
                if (tokens[i][0] == ")"):
                    i += 1
                    if class_body():
                        if class_otherwise():
                            return True

    return False


def class_exception():
    global i

    def more_except():
        global i

        if (tokens[i][0] == "except"):
            i += 1
            if (tokens[i][0] == "("):
                i += 1
                if error():
                    if (tokens[i][0] == ")"):
                        i += 1
                        if class_body():
                            if more_except():
                                return True

        elif (tokens[i][0] == ";"):
            return True

        return False

    def error():
        global i

        exception_types = [
            "SyntaxError",
            "NameError",
            "TypeError",
            "ValueError",
            "IndexError",
            "ZeroDivisionError",
            "ArithmeticError",
            "TypeError",
            "NotImplementedError",
            "PermissionError",
            "RecursionError",
            "ERROR"
        ]

        if (tokens[i][0] in exception_types):
            i += 1
            if more_error():
                return True

        return False

    def more_error():
        global i

        if (tokens[i][0] == "Logical_Op"):
            i += 1
            if error():
                if more_error():
                    return True

        elif (tokens[i][0] == ")"):
            return True

        return False

    if (tokens[i][0] == "try"):
        i += 1
        if class_body():
            if (tokens[i][0] == "except"):
                i += 1
                if (tokens[i][0] == "("):
                    i += 1
                    if error():
                        if (tokens[i][0] == ")"):
                            i += 1
                            if class_body():
                                if more_except():
                                    return True

    return False


def class_array_index():
    global i

    def Slice():
        global i
        if (tokens[i][0] == ":"):
            i += 1
            if class_expression():
                if step():
                    return True

        elif (tokens[i][0] == "]"):
            return True

    def step():
        global i
        if (tokens[i][0] == ":"):
            i += 1
            if class_expression():
                return True

        elif (tokens[i][0] == "]"):
            return True

        return False

    def array_index1():
        global i

        if (tokens[i][0] == "["):
            i += 1
            if (tokens[i][0] == "]"):
                return True

            elif class_expression():
                if Slice():
                    if (tokens[i][0] == "]"):
                        i += 1
                        if array_index1():
                            return True

        elif (tokens[i][0] in [",", ";", "=", "CompAssignment", ".", "IncDec", "PlusMinus", ")", "RelOP", "Logical_Op"]) or (tokens[i][1] in ["and", "or"]):
            return True

        return False

    if (tokens[i][0] == "["):
        i += 1
        if (tokens[i][0] == "]"):
            return True

        elif class_expression():
            if Slice():
                if (tokens[i][0] == "]"):
                    i += 1
                    if array_index1():
                        return True

    elif (tokens[i][0] in [";", "=", "CompAssignment", ".", "IncDec", "PlusMinus", ")", "RelOP", "Logical_Op"]) or (tokens[i][1] in ["and", "or"]):
        return True

    return False


def class_arguments():
    global i

    def next():
        global i
        if (tokens[i][0] == ")"):
            return True

        elif (tokens[i][0] == ","):
            i += 1
            if class_expression():
                if next():
                    return True

        return False

    if (tokens[i][0] == ")"):
        return True

    elif class_expression():
        if next():
            return True

    return False


def class_expression():
    def Or():
        global i
        if (tokens[i][0] == "Logical_Op" and tokens[i][1] == "or"):
            i += 1
            if And():
                if Or():
                    return True

        elif (tokens[i][0] in [")", ";", ",", ":", "]"]):  # follow of expression
            return True

        return False

    def And():
        if RelOp():
            if And1():
                return True
        return False

    def And1():
        global i
        if (tokens[i][0] == "Logical_Op" and tokens[i][1] == "and"):
            i += 1
            if RelOp():
                if And1():
                    return True

        elif (tokens[i][0] in [")", ";"], ",", ":", "]") or (tokens[i][1] == "or"):  # follow of expression
            return True

        return False

    def RelOp():
        if PM():
            if RelOp1():
                return True
        return False

    def RelOp1():
        global i
        if (tokens[i][0] == "RelOP"):
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

    def PM1():
        global i
        if (tokens[i][0] == "PlusMinus"):
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

    def MDM1():
        global i
        if (tokens[i][0] in ["DivMod", "*"]):
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

            def D1():
                global i
                if (tokens[i][0] == "."):
                    i += 1
                    if (tokens[i][0] == "ID"):
                        i += 1
                        if D():
                            return True

                elif (tokens[i][0] in ["DivMod", "*", "PlusMinus", ")", "RelOP", ";", ",", ":", "]"]) or (tokens[i][1] in ["or", "and"]):
                    return True

                return False

            def D2():
                global i
                if (tokens[i][0] == "."):
                    i += 1
                    if (tokens[i][0] == "ID"):
                        i += 1
                        if D():
                            return True

                elif (tokens[i][0] == "["):
                    if class_array_index():
                        if D1():
                            return True

                elif (tokens[i][0] in ["DivMod", "*", "PlusMinus", ")", "RelOP", ";", ",", ":", "]"]) or (tokens[i][1] in ["or", "and"]):
                    return True

                return False

            if (tokens[i][0] == "."):
                i += 1
                if (tokens[i][0] == "ID"):
                    if D():
                        return True

            elif (tokens[i][0] == "["):
                if class_array_index():
                    if D1():
                        return True

            elif (tokens[i][0] == "("):
                i += 1
                if class_arguments():
                    if (tokens[i][0] == ")"):
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

                if (tokens[i][0] == "."):
                    i += 1
                    if (tokens[i][0] == "ID"):
                        i += 1
                        if A():
                            return True

                elif (tokens[i][0] == "["):
                    if class_array_index():
                        if A3():
                            return True

                elif (tokens[i][0] in ["DivMod", "*", "PlusMinus", ")", "RelOP", ";", ",", ":", "]"]) or (tokens[i][1] in ["or", "and"]):
                    return True

                return False

            def A2():
                global i

                if (tokens[i][0] == "."):
                    i += 1
                    if (tokens[i][0] == "ID"):
                        i += 1
                        if A():
                            return True

                elif (tokens[i][0] == "IncDec"):
                    i += 1
                    return True


                elif (tokens[i][0] in ["DivMod", "*", "PlusMinus", ")", "RelOP", ";", ",", ":", "]"]) or (tokens[i][1] in ["or", "and"]):
                    return True

                return False

            def A3():
                global i

                if (tokens[i][0] == "."):
                    i += 1
                    if (tokens[i][0] == "ID"):
                        i += 1
                        if A():
                            return True


                elif (tokens[i][0] in ["DivMod", "*", "PlusMinus", ")", "RelOP", ";", ",", ":", "]"]) or (tokens[i][1] in ["or", "and"]):
                    return True

                return False

            if (tokens[i][0] == "IncDec"):
                i += 1
                return True

            elif (tokens[i][0] == "("):
                i += 1
                if class_arguments():
                    if (tokens[i][0] == ")"):
                        i += 1
                        if A1():
                            return True

            elif (tokens[i][0] == "["):
                if class_array_index():
                    if A2():
                        return True

            elif (tokens[i][0] == "."):
                i += 1
                if (tokens[i][0] == "ID"):
                    i += 1
                    if A():
                        return True

            elif (tokens[i][0] in ["DivMod", "*", "PlusMinus", ")", "RelOP", ";", ",", ":", "]"]) or (tokens[i][1] in ["or", "and"]):
                return True

            return False

        if (tokens[i][0] in ["Bool_Const", "Int_Const", "Float_Const", "Str_Const", "Char_Const"]):
            i += 1
            return True

        # elif (tokens[i][0] == "ID"):
        #     i += 1
        #     if A():
        #         return True

        elif tb():
            if (tokens[i][0] == "ID"):
                i += 1
                if A():
                    return True

        elif (tokens[i][0] == "("):
            i += 1
            if class_expression():
                if (tokens[i][0] == ")"):
                    i += 1
                    return True

        elif (tokens[i][1] == "!"):
            i += 1
            if EndPoint():
                return True

        elif (tokens[i][0] == "IncDec"):
            i += 1
            if tb():
                if (tokens[i][0] == "ID"):
                    if D():
                        return True

        return False

    if And():
        if Or():
            return True

    e = f"SyntaxError: Invalid 'expression' at line {tokens[i][2]}"
    sys.exit(e)


def class_array_decl():
    global i

    if (tokens[i][0] == "["):
        i += 1
        if class_expression():
            if (tokens[i][0] == "]"):
                i += 1
                if class_array_decl1():
                    if (tokens[i][0] == "ID"):
                        i += 1
                        if class_v1():
                            if class_array_assign():
                                return True

    return False


def class_array_decl1():
    global i

    if (tokens[i][0] == "["):
        i += 1
        if class_expression():
            if (tokens[i][0] == "]"):
                i += 1
                if class_array_decl1():
                    return True

    elif (tokens[i][0] == "ID"):
        return True

    return False


def class_v1():
    global i

    if (tokens[i][0] == ","):
        i += 1
        if (tokens[i][0] == "ID"):
            i += 1
            if class_v1():
                return True

    elif (tokens[i][0] in ["=", ";"]):
        return True

    return False


def class_array_def():
    global i

    if (tokens[i][0] == "ID"):
        i += 1
        if class_B1():
            return True

    elif class_array_decl():
        return True

    elif (tokens[i][0] in ["CompAssignment", "=", "," ".", "[", "("]):
        if class_B2():
            return True

    return False


def class_array_def1():
    global i

    if (tokens[i][0] == "ID"):
        i += 1
        if class_B1():
            return True

    elif class_array_decl():
        return True

    return False


def class_array_assign():
    global i

    if (tokens[i][0] == "="):
        i += 1
        if class_List():
            return True

    elif (tokens[i][0] == ";"):
        return True

    return False


def class_List():
    global i

    def class_list1():
        global i

        if class_List():
            if class_list2():
                return True

        elif class_expression():
            if class_list2():
                return True

        return False

    def class_list2():
        global i

        if (tokens[i][0] == ","):
            i += 1
            if class_list1():
                return True

        elif (tokens[i][0] == "]"):
            return True

        return False

    def class_list3():
        global i

        if (tokens[i][0] == "]"):
            return True

        elif class_list1():
            return True

        return False

    if (tokens[i][0] == "["):
        i += 1
        if class_list3():
            if (tokens[i][0] == "]"):
                i += 1
                return True

    return False