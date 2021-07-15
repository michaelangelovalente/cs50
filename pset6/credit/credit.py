# we ask that your program’s last line of output be AMEX\n or MASTERCARD\n or VISA\n or INVALID\n

# American Express uses 15-digit numbers
# MasterCard uses 16-digit numbers
# Visa uses 13- and 16-digit numbers.

# American Express numbers start with 34 or 37;
# MasterCard numbers start with 51, 52, 53, 54, or 55
# Visa numbers start with 4.
def main():



    creditNumber = input("Number: ")
    #if not creditNumber.isdigit() or not( len(creditNumber) >=13 and len(creditNumber) <= 16 ) or not(luhnsAlgo(creditNumber)):
    if not ( creditNumber.isdigit() or ( len(creditNumber) >=13 and len(creditNumber) <= 16 ) or (luhnsAlgo(creditNumber)) ):
        """ Invalid """
        print("INVALID")
        exit()


    if int(creditNumber[0:2]) == 34 or int(creditNumber[0:2]) == 37:
       """ AMEX """
       print("AMEX")

    elif int(creditNumber[0:2]) >= 51 and int(creditNumber[0:2]) <= 55:
        """ MASTERCARD """
        print("MASTERCARD")

    elif int(creditNumber[0]) == 4:
        """ VISA """
        print("VISA")
    else:
        print("INVALID")





#Checks whether the credit card has a valid number.
#Returns False if the credit card number is invalid, True otherwise.
def luhnsAlgo( creditN ):
    strlen = len(creditN) - 1
    tmp = 0
    for i in range( strlen, -1, -1):

        if (strlen - i)%2 == 1:
            """ odd """
            oddN = int( creditN[i] ) * 2
            if oddN > 9:
                oddN = int((oddN/10)) + (oddN % 10)
            tmp += oddN

        else:
            """ even"""
            tmp += int( creditN[i] )

    if tmp%10 == 0:
        return True

    return False

if __name__ == "__main__":
    main()