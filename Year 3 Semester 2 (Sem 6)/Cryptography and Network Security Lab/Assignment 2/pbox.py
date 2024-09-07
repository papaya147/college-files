def apply(pbox, code):
    output = []
    for i in pbox:
        output.append(code[i - 1])

    return output


pbox_raw = input("enter p-box substituition array: ").split()
pbox_joined = ",".join(pbox_raw)
pbox = eval(f"[{pbox_joined}]")

code_raw = input("enter code to substitute: ").split()
code_joined = ",".join(code_raw)
code = eval(f"[{code_joined}]")

print(f"ouput from p-box application: {apply(pbox, code)}")
