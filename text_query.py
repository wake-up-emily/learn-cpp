
class Text_query:
    def __init__(self,file_name):
        self.lines = []
        self.words = {}
        self.initialize(file_name)

    def initialize(self,file_name):
        with open(file_name) as f:
            row_lines = f.readlines()
            if row_lines:
                line_num = 1
                for line in row_lines:
                    line = line.replace('\n','')
                    self.lines.append(line)
                    print(line)
                    row_words = line.lower().replace('.','').split(' ')
                    for word in row_words:
                        if word in self.words:
                            self.words[word].append(line_num)
                        else:
                            self.words[word] = [line_num]
                    line_num += 1
                else:
                    print("no data")

    def query(self,file):
        with open(file,'r') as f:
            words = f.read().replace('\n',' ').split(' ')
            if words:
                for word in words:
                    if word not in self.words:
                        print("not found")
                    else:
                        line_nums = self.words[word]
                        if_single = 's' if len(line_nums) > 1 else ''
                        print("{0} occurs {1} time{2}".format(word,len(line_nums),if_single))
                        for line in line_nums:
                            print("(line {0}) {1}".format(line,self.lines[line-1]))
            else:
                print("no target words")
            

tq = Text_query("data.txt")
print(tq.words)
print(tq.lines)
tq.query('query_words.txt')
            

    