#ifndef FOLDER
#define FOLDER

class Message;

class Folder {
    friend bool operator== (const Folder& lhs, const Folder rhs) { return lhs.msgs == rhs.msgs;}
    public:
        explicit Folder()
        :msgs(set<Message*>()) {}
        Folder(const Folder&); //big three
        Folder& operator= (const Folder&);
        ~Folder();
        void add_msg(Message*); //不能是const 
        void rm_msg(Message*);
        size_t size() {return msgs.size();}
        set<Message*> show_msgs() {return msgs;}
    private:
        set<Message*> msgs;
        void add_to_msgs(const Folder&); //为了拷贝构造和拷贝赋值 拷贝folder意味着新folder包含所有原folder的消息 原folder的所有消息都新增一个folder
        void rm_from_msgs(); //为了析构 销毁一个folder意味着 自动销毁该folder前 folder所含的所有消息都删除该所在folder
};

#endif