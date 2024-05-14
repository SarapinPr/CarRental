// Chat.cpp
#include "Chat.h"
#include <iostream>

void Chat::addMessage(const std::string& sender, const std::string& content) {
    messages.emplace_back(sender, content);
}

void Chat::displayChat() const {
    std::cout << "----- Chat -----\n";
    for (const auto& message : messages) {
        std::cout << message.sender << ": " << message.content << "\n";
    }
    std::cout << "-----------------\n";
}
