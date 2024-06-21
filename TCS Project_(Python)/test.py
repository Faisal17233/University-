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
