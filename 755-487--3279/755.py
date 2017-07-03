

def getPhoneNumber(phone_str):
    table = {"A":"2", "B":"2", "C":"2", 
         "D":"3", "E":"3", "F":"3",
         "G":"4", "H":"4", "I":"4",
         "J":"5", "K":"5", "L":"5",
         "M":"6", "N":"6", "O":"6",
         "P":"7", "R":"7", "S":"7",
         "T":"8", "U":"8", "V":"8",
         "W":"9", "X":"9", "Y":"9",}
    
    
    phone_dig = ""
    for s in phone_str:   
        if ord(s) >= ord('A') and ord(s) <= ord('Z'):
            phone_dig += table[s]
        elif ord(s) >= ord('0') and ord(s) <= ord('9'):
            phone_dig += s
        if len(phone_dig) == 3:
            phone_dig += '-'
    return phone_dig

directory = int(input())
for i in range(0, directory):
    num = int(input())
    phones_str = list()
    for j in range(0, num):
        phones_str.append([number for number in input()])
    
    phones_dig = list()
    for phone_str in phones_str:
        phones_dig.append(getPhoneNumber(phone_str))
    
    count = dict()
    for phone in phones_dig:
        count[phone] = count.get(phone, 0) + 1
    
    duplicate = False
    for key, value in sorted(count.items()):
        if value > 1:
            print (key, value)
            duplicate = True
    if duplicate == False:
        print ('No duplicates.')
    print ('')    