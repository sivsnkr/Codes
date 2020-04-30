def isp(t):
    l = 0
    r = len(t)-1
    while(l < r):
        if(t[l]!=t[r]):
            return False
        l+=1
        r-=1
    return True

while(True):
    t = input()
    if(t!="DONE"):
        t = t.replace(".","")
        t = t.replace(",","")
        t = t.replace("!","")
        t = t.replace("?","")
        t = t.replace(" ","")
        t = t.lower()
        if(isp(t)):
            print("You won't be eaten!")
        else:
            print("Uh oh..")
    else:
        break
