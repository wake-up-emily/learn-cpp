#include "message.h"

inline Message::Message(const Message& rhs)
: content(rhs.content), folders(rhs.folders) {add_to_folders(rhs);}

inline Message::Message(Message&& rhs)
: content(std::move(rhs.content)) {move_folders(&rhs);} 

inline Message& Message::operator=(const Message& rhs) {
    remove_from_folders();
    content = rhs.content;
    folders = rhs.folders;
    add_to_folders(rhs);
    return *this;
}

inline Message& Message::operator=(Message&& rhs) {
    if (this != &rhs) {
        remove_from_folders();
        content = std::move(rhs.content);
        move_folders(&rhs);
    }
    return *this;
}

inline void Message::move_folders(Message* m) {
    folders = std::move(m->folders);
    for (auto f: folders) {
        f->rm_msg(m);
        f->add_msg(this);
    }
    m->folders.clear();
}

inline Message::~Message() {
    remove_from_folders();
}

inline void Message::add_folder(Folder* f) {
    folders.insert(f);
}

inline void Message::rm_folder(Folder* f) {
    folders.erase(f);
}

