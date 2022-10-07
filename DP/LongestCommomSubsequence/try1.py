def countSentences(wordSet,sentences):
#first of all sort ea
#ch word and count every word
    dict={}

    for s in wordSet:
        s="".join(sorted(s))
        if s in dict:
            dict[s]=1+dict[s]
        else:
            dict[s]=1

    arr=[]

    # for every sentence
    for str in sentences:
        word =str.split(' ')
        count=0
        for s in word:
            s="".join(sorted(s))
            if s in dict and dict[s]>1:
                count=count+dict[s]
            arr.append(count)
    return arr
    
# word=[]
# sentences=[]
# n=int(input())
# for i in range(n):
#     str=input()
#     word.append(str)
#     m=int(input())
# for i in range(m):
#     str=input()
#     sentences.append(str)
word=['listen','it', 'is', 'silent']
sentence = 'listen it is silent'
arr=countSentences(word,sentences)
for i in arr:
    print (i)