#include "folder.h"
#include "message.cpp"

inline void Folder::add_to_msgs(const Folder& f) {
    for (auto m:f.msgs) {
        m->add_folder(this);
    }
}

inline void Folder::rm_from_msgs() {
    for (auto m:msgs) {
        m->rm_folder(this);
    }
}

inline Folder::Folder(const Folder& f) 
: msgs(f.msgs) {add_to_msgs(f);}

inline Folder& Folder::operator= (const Folder& f) {
    if (this != &f) {
        rm_from_msgs();
        msgs = f.msgs;
        add_to_msgs(f);
    }
    return *this;
}

inline void Folder::add_msg(Message* msg) {
    msgs.insert(msg);
}

inline void Folder::rm_msg(Message* msg) {
    msgs.erase(msg);
}

inline Folder::~Folder() {
    for (auto m:msgs) {
        m->rm_folder(this);
    }
}

inline void Message::save(Folder& f) {
    folders.insert(&f);
    f.add_msg(this);
}

inline void Message::remove(Folder& f) {
    folders.erase(&f);
    f.rm_msg(this);
}

inline void Message::add_to_folders(const Message& msg) {
    for (auto f : msg.folders) {
        f->add_msg(this);
    }
}

inline void Message::remove_from_folders() {
    for (auto f : folders) {
        f->rm_msg(this);
    }
}