

import os
import sys




def compare(a, A):
    return (a == A.upper() or a.upper() == A)
    

def react(new):
    
    old = ""
    while(new!=old):
        old = new
        for i in range(0, 26):
            new = new.replace(chr(ord("A")+i) + chr(ord("a")+i), "")
            new = new.replace(chr(ord("a")+i) + chr(ord("A")+i), "")

    return len(new)
    


if __name__ == "__main__":
    txt = ""
    ln = 1000000
    with open(os.path.join(os.path.dirname(sys.argv[0]), 'input.txt')) as file:
        for line in file:
            txt = line;

    # part 1
    print(react(txt))

    # part 2
    zzz = ""
    lowestln = ln
    for i in range(0, 26):
        zzz = txt.replace((chr(ord("A")+i)), "")
        zzz = zzz.replace((chr(ord("a")+i)), "")
        ln = react(zzz)
        if (ln < lowestln):
            lowestln = ln
    
    print(lowestln)


    


