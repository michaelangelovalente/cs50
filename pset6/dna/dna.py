import csv
import sys
#
def main():
    if len(sys.argv) != 3:
    # Usage: python dna.py data.csv sequence.txt
        #print("Usage: python dna.py data.csv sequence.txt")#
        sys.exit("Usage: python dna.py data.csv sequence.txt")

    mainSTR = []
    sequenceSTR = {} # used for second phase, when analysing dna sequence
    #create the "main" database with STRs saved in memory
    firstline = []
    with open(sys.argv[1]) as file:

        firstline = file.readline().split(",")
        firstline[len(firstline) -1] = firstline[len(firstline) -1][:-1]


        reader = csv.reader(file)

        #Loading memory with STRs
        for row in reader:
            tmp = {}
            for word in firstline:
                if word == "name":
                    tmp[word] = ""
                else:
                    tmp[word] = -1

            for i in range(0 , len(row)):
                if i == 0:
                    #adding names to mainSTR
                    """"""
                    tmp[firstline[i]] = row[i]
                else:
                    #adding STRs to mainSTR
                    """"""
                    tmp[firstline[i]] = int(row[i] )
            mainSTR.append(tmp)






    #Loading memory with empty dictionary. This will be used in the "second phase"
    #when analysing the dna sequence
    for word in firstline:
        if word == "name":
            sequenceSTR[word] = ""
        else:
            sequenceSTR[word] = -1
    #Checking if unkown dna sequence is contained in memory
    with open(sys.argv[2]) as file:
        dnaSequence = file.readline()
        #print(dnaSequence)
        for strs in firstline[1:]:
            #print(strs)
            #print( matchFinder(dnaSequence, strs))
            sequenceSTR[strs] = matchFinder(dnaSequence, strs)



    #Checking for matches between dna sequences in database and the unkown sequence
    for people in mainSTR:
        flag = True
        for key in people:
            if ( sequenceSTR[key] != people[key] ) and (key != 'name'):
                flag = False
                break

        if flag:
            sequenceSTR['name'] = people['name']

    if(sequenceSTR['name'] == ''):
        print("No match")
    else:
        print(sequenceSTR['name'])

# ????????????
def matchFinder(sequence, str):
    """ """
    ctr = 0
    i = 0
    max = 0
    while( i<len(sequence)):
        if(sequence[i:i+len(str)] == str):
            ctr+=1
            i = i + len(str)
            if(ctr > max):
                max = ctr
        else:
            ctr = 0
            i+=1





    return max




if __name__ == "__main__":
    main()
