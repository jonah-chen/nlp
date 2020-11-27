from os import listdir
s = ""
for i in listdir(path='txt'):
    s += ("\"txt/" + i.replace("'", "\\'").replace('"','\\"') + "\"," + "\n")
f = open("dir.h", "w")
f.write(s)
print(len(listdir(path='txt')))