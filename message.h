#ifndef MESSAGE
#define MESSAGE

#include <set>
#include <string>
using namespace std;

class Folder;

class Message {
    friend class Folder;
    public:
        explicit Message(const string& s = string())
        : content(s) {}
        Message(const Message&); //big three
        Message& operator= (const Message&);
        Message(Message&&);
        Message& operator=(Message&&);
        ~Message();
        void save(Folder&); //面向使用者的接口 捆绑两个操作: msg新增一个指定的folder 该folder新增此msg
        void remove(Folder&); //面向使用者的接口 捆绑两个操作: msg删除一个所在folder 该folder删除此消息
        bool operator< (const Message& rhs) const { return content < rhs.content;}
        void add_folder(Folder*);
        void rm_folder(Folder*);
        string& show_content() {return content;}
    private:
        string content;
        set<Folder*> folders; //保存含有此消息的所有folder
        void add_to_folders(const Message&); //为了拷贝构造和拷贝赋值 拷贝消息意味着在含有原消息的所有folder都新增一条消息
        void remove_from_folders(); //为了析构 析构一条消息意味着在含有原消息的所有folder都删除此消息
        void move_folders(Message*);
};

#endif