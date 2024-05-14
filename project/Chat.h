// Chat.h
#ifndef CHAT_H
#define CHAT_H

#include "Message.h"
#include <vector>

class Chat {
private:
    std::vector<Message> messages;

public:
    void addMessage(const std::string& sender, const std::string& content);
    void displayChat() const;
};

#endif // CHAT_H
