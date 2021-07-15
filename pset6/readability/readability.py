
# L is the average number of letters per 100 words in the text -> L = 100 * ( # of letters / # of words )
# S is the average number of sentences per 100 words in the text -> S = 100 * ( # of sentences / # of words )
# index = 0.0588 * L - 0.296 * S - 15.8

# Sentence you should consider any sequence of characters that ends with a . or a ! or a ? to be a sentence
# Word any sequence of characters separated by a space to be a word
#
def main():
    """ stuff """
    text = input("Text: ")
    numOfWords = len(text.split(" "))
    numOfletts = 0
    #count exactly how many letters there are
    tmpstr = "abcdefghijklmnopqrstuvwxyz"
    for words in text.split(" "):
        words = words.strip(". !,?")


        for char in tmpstr:
            numOfletts += (words.lower()).count(char)

    numOfSentences = text.count(".") + text.count("!") + text.count("?")


    l = 100 * ( numOfletts / numOfWords)
    s = 100 * ( numOfSentences / numOfWords)
    index = 0.0588 * l - 0.296 * s - 15.8
    grade = round(index)
    print("Grade ", end="" )
    if grade > 15:
        print("16+")
    elif grade < 1 :
        print("Before Grade 1")
    else:
        print(grade)






if __name__ == "__main__":
    main()