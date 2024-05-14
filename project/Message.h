// Message.h
#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>

class Message {
public:
    std::string sender;
    std::string content;

    Message(const std::string& sender, const std::string& content);
};

#endif // MESSAGE_H
