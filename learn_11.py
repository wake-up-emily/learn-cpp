

def count_word(file):
    word_list = {}
    with open(file,'r') as f:
        text = f.read().replace('\n',' ')
        words = text.split(' ')
        for word in words:
            if word in word_list:
                word_list[word] += 1
            else:
                word_list[word] = 1
                
    for k,v in word_list.items():
        print(k,v)

def count_word_2(file):
    word_list = {}
    with open(file,'r') as f:
        text = f.read().replace('\n',' ')
        words = text.split(' ')
        for word in words:
            word = word.replace(".","").lower()
            if word in word_list:
                word_list[word] += 1
            else:
                word_list[word] = 1
                
    for k,v in word_list.items():
        print(k,v)

if __name__ == "__main__":
    file = "data.txt"
    count_word_2(file)



    