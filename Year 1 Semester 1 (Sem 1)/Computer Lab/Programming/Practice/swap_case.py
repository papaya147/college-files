def swap_case(s):
    lets = list(s)
    out = []
    for let in lets:
        if let.isupper():
            out.append(let.lower())
        elif let.islower():
            out.append(let.upper())
        else:
            out.append(let)
    return ''.join(out)

if __name__ == '__main__':
    s = input()
    result = swap_case(s)
    print(result)