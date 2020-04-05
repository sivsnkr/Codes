import re
# get all input in a list

fp = open("input.v", "r")

line = fp.readline()

Input = []
Output = []
Wire = []

inp = ""
oup = ""
wire = ""

flag1 = False
flag2 = False
flag3 = False

while line:
    if(re.search("//", line)):
        line = fp.readline()
        continue
    if(re.search("input", line) != None):
        while(re.search(";", line) == None):
            inp += line
            line = fp.readline()
        inp += line
        flag1 = True
    elif(re.search("output", line) != None):
        while(re.search(";", line) == None):
            oup += line
            line = fp.readline()
        oup += line
        flag2 = True
    elif(re.search("wire", line) != None):
        while(re.search(";", line) == None):
            wire += line
            line = fp.readline()
        wire += line
        flag3 = True
    if(flag1 and flag2 and flag3):
        break
    line = fp.readline()

# print(inp, oup, wire)

# line = fp.readline()
# line = fp.readline()
# print(line)


inp = inp.replace("input", '')
inp = inp.replace(";", '')
inp = inp.replace(" ", '')
inp = inp.replace('\n', '')
inp = inp.translate({ord('\n'): None})
inp = inp.split(",")
oup = oup.replace("output", '')
oup = oup.replace(";", '')
oup = oup.replace(" ", '')
oup = oup.replace('\n', '')
oup = oup.translate({ord('\n'): None})
oup = oup.split(",")

wire = wire.replace("wire", '')
wire = wire.replace(";", '')
wire = wire.replace(" ", '')
wire = wire.replace('\n', '')
wire = wire.translate({ord('\n'): None})
wire = wire.split(",")

# print(inp)

# print(oup)

# print(wire)

for i in inp:
    if(len(i) > 0):
        Input.append(i)

for i in oup:
    if(len(i) > 0):
        Output.append(i)

for i in wire:
    if(len(i) > 0):
        Wire.append(i)
print("\nInput----------\n")
print(Input)
print("\nOutput---------\n")
print(Output)
print("\nWire-----------\n")
print(Wire)

probOfWire = dict()

for i in Input:
    probOfWire[i] = 1/2


def proAnd(a):
    product = 1
    for i in a:
        product *= probOfWire[i]
    return product


def probor(a):
    product = 1
    for i in a:
        product *= (1-probOfWire[i])
    return 1-product


def probNand(a):
    return 1-proAnd(a)


def probNor(a):
    return 1-probor(a)


def probXor(a):
    s = 0
    for i in range(0, len(a)):
        product = 1
        for j in range(0, len(a)):
            if(j == i):
                product *= (1-probOfWire[a[i]])
            else:
                product *= probOfWire[a[i]]
        s += product

    return s


def probNot(a):
    return 1-probOfWire[a]


while line:
    if(re.search("//", line) != None):
        line = fp.readline()
        continue
    elif(re.search("nand", line) != None):
        te = line.split("(")
        te = te[1]
        te = te.replace(")", '')
        te = te.replace(";", '')
        te = te.replace(" ", '')
        te = te.replace('\n', '')
        te = te.translate({ord('\n'): None})
        te = te.split(",")
        # print(te)
        key = te[0]
        te.remove(key)
        probOfWire[key] = probNand(te)
        # print(te)
    elif(re.search("and", line) != None):
        te = line.split("(")
        te = te[1]
        te = te.replace(")", '')
        te = te.replace(";", '')
        te = te.replace(" ", '')
        te = te.replace('\n', '')
        te = te.translate({ord('\n'): None})
        te = te.split(",")
        key = te[0]
        te.remove(key)
        probOfWire[key] = proAnd(te)
    elif(re.search("nor", line) != None):
        te = line.split("(")
        te = te[1]
        te = te.replace(")", '')
        te = te.replace(";", '')
        te = te.replace(" ", '')
        te = te.replace('\n', '')
        te = te.translate({ord('\n'): None})
        te = te.split(",")
        key = te[0]
        te.remove(key)
        probOfWire[key] = probNor(te)
    elif(re.search("xor", line) != None):
        te = line.split("(")
        te = te[1]
        te = te.replace(")", '')
        te = te.replace(";", '')
        te = te.replace(" ", '')
        te = te.replace('\n', '')
        te = te.translate({ord('\n'): None})
        te = te.split(",")
        key = te[0]
        te.remove(key)
        probOfWire[key] = probXor(te)
    elif(re.search("or", line) != None):
        te = line.split("(")
        te = te[1]
        te = te.replace(")", '')
        te = te.replace(";", '')
        te = te.replace(" ", '')
        te = te.replace('\n', '')
        te = te.translate({ord('\n'): None})
        te = te.split(",")
        key = te[0]
        te.remove(key)
        probOfWire[key] = probor(te)
    elif(re.search("not", line) != None):
        te = line.split("(")
        te = te[1]
        te = te.replace(")", '')
        te = te.replace(";", '')
        te = te.replace(" ", '')
        te = te.replace('\n', '')
        te = te.translate({ord('\n'): None})
        te = te.split(",")
        key = te[0]
        te.remove(key)
        probOfWire[key] = probNot(te[0])

    line = fp.readline()


# print(probOfWire)


def activityFactor(i):
    return float(i*(1-i))


print("Probability:")

for i in probOfWire:
    print("Probability of wire {} is {}".format(
        i, probOfWire[i]))

print("---------------------")

for i in probOfWire:
    print("Activity factor of wire {} is {}".format(
        i, activityFactor(probOfWire[i])))
