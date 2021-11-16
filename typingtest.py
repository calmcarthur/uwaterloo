import time
import random

def random_line(fname):
    lines = open(fname).read().splitlines()
    return random.choice(lines)

currentword = str()
counter = 0
other = str()
stopper = 0

input1 = (input("Hello, welcome to Cal's typing test. How many words do you wish to type?   "))

print("Okay! Are you ready?")
time.sleep(1)
print("3")
time.sleep(0.5)
print("2")
time.sleep(0.5)
print("1")
time.sleep(0.5)
print('GO')
time.sleep(1)

input1 = int(input1)
for x in range(0,input1):

    counter +=1
    if counter == 1:
        start = time.time()
    else:
        pass

    currentword = random_line('words.txt') 
    print(currentword, "\t", counter)
    other = input()
    if other == currentword:
        continue
    else:
        while other != currentword:
            stopper += 1
            print(currentword, "\t", counter)
            other = input()


end = time.time()
print("Congratulations and well done!")
time.sleep(1)
print("Your typing speed is:", round((input1*120)/(end-start), 2), "WPM, with", (stopper), "error(s).")