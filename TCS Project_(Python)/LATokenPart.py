word_breaker = {' ', '(', ')', '{', '}', '\n', '\t', ',', ';', '#', '+', '-', '^', '/', '*', '%', '=', '!', '<', '>', }
avoid = {' ', '\n', '\t'}
tokens = []


with open("code.txt", 'r') as code:
    token = ""
    for line_no, line in enumerate(code):
        i = 0
        length = len(line)

        token = ""
        while i < length:
            word = line[i]

            if word == '#':
                if token:
                    tokens.append([token, line_no + 1])
                break

            elif word in word_breaker:
                if token:
                    tokens.append([token, line_no + 1])
                    token = ""
                if word not in avoid:
                    tokens.append([word, line_no + 1])

                i += 1
                continue

            token += word
            i += 1

    if token:
        tokens.append([token, line_no + 1])