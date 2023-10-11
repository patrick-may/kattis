from sys import stdin 

input()
replaces = {
        "at" : "@",
        "At" : "@",
        "AT" : "@",

        "and" : "&",
        "And" : "&",
        "ANd" : "&",
        "AND" : "&",
        
        "one" : "1",
        "One" : "1",
        "ONe" : "1",
        "ONE" : "1",
        
        "won" : "1",
        "Won" : "1",
        "WOn" : "1",
        "WON" : "1",
        
        "to" : "2",
        "To" : "2",
        "TO" : "2",
        "two" : "2",
        "Two" : "2",
        "TWo" : "2",
        "TWO" : "2",
        "too" : "2",
        "Too" : "2",
        "TOo" : "2",
        "TOO" : "2",
        "for" : "4",
        "For" : "4",
        "FOr" : "4",
        "FOR" : "4",
        "four" : "4",
        "Four" : "4",
        "FOur" : "4",
        "FOUr" : "4",
        "FOUR" : "4",
        "eye" : "i",

        "Eye" : "I",
        "EYe" : "I",
        "EYE" : "I",
        "bea" : "b",
        "Bea" : "B",
        "BEa" : "B",
        "BEA" : "B",
        "bee" : "b",
        "Bee" : "B",
        "BEe" : "B",
        "BEE" : "B",
        "be" : "b",
        "Be" : "B",
        "BE" : "B",
        "sea" : "c",
        "Sea" : "C",
        "SEa" : "C",
        "SEA" : "C",
        "see" : "c",
        
        "See" : "C",
        "SEe" : "C",
        "SEE" : "C",
        
        "oh" : "o",
        
        "Oh" : "O",
        "OH" : "O",
        
        "owe" : "o",
        
        "Owe" : "O",
        "OWe" : "O",
        "OWE" : "O",
        
        "are" : "r",
        
        "Are" : "R",
        "ARe" : "R",
        "ARE" : "R",
        
        "you" : "u",
        
        "You" : "U",
        "YOu" : "U",
        "YOU" : "U",
        
        "why" : "y",

        "Why" : "Y",
        "WHy" : "Y",
        "WHY" : "Y",
        }

def fix(line):
    soln = ""
    left = 0
    
    end = len(line)
    while left < end:
        if left < end - 3:
            tok3 = line[left: left + 4]
            if tok3 in replaces.keys():

                soln += replaces[tok3]
                left += 4
                continue
        if left < end - 2:
            tok2 = line[left : left + 3]
            if tok2 in replaces.keys():
                soln += replaces[tok2]
                left += 3 
                continue
        if left < end - 1:
            tok1 = line[left :left + 2]
            if tok1 in replaces.keys():
                soln += replaces[tok1]
                left += 2 
                continue
        soln += line[left]
        left += 1
    
    return soln
       # search curr index out for longest replace  
    """   
    for old, new in replaces.items():
        line = line.replace(old, new)
    print(line)
    
    for word in line.split():
        if word in replaces:
            soln += replaces[word]
        else:
            soln += word
        soln += " "
    """

for line in stdin:
    print(fix(line.strip()))
