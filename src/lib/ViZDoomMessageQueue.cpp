#include "ViZDoomMessageQueue.h"
#include "ViZDoomExceptions.h"

namespace vizdoom {

    MessageQueue::MessageQueue(std::string name) : name(name) {
        this->init();
    }

    MessageQueue::~MessageQueue() {
        this->close();
    }

    void MessageQueue::init() {
        try {
            bip::message_queue::remove(this->name.c_str());
            this->mq = new bip::message_queue(bip::open_or_create, this->name.c_str(), MQ_MAX_MSG_NUM, sizeof(Message));
        }
        catch(bip::interprocess_exception& ex) {
            throw MessageQueueException(std::string("Failed to create message queues: ") + std::string(ex.what()));
        }
        catch (...) {
            throw MessageQueueException("Failed to create message queues for unknown reason.");
        }
    }

    void MessageQueue::close() {
        bip::message_queue::remove(this->name.c_str());
        if (this->mq) {
            delete this->mq;
            this->mq = nullptr;
        }
    }

    void MessageQueue::send(uint8_t code, const char *command) {
        Message msg;
        msg.code = code;
        if (command) strncpy(msg.command, command, MQ_MAX_CMD_LEN);

        try {
            this->mq->send(&msg, sizeof(Message), 0);
        }
        catch(bip::interprocess_exception& ex) {
            throw MessageQueueException(std::string("Failed to send message: ") + std::string(ex.what()));
        }
        catch (...) {
            throw MessageQueueException("Failed to send message for unknown reason.");
        }
    }

    Message MessageQueue::receive() {
        Message msg;

        unsigned int priority;
        size_t size;

        try {
            this->mq->receive(&msg, sizeof(Message), size, priority);
        }
        catch(bip::interprocess_exception& ex) {
            throw MessageQueueException(std::string("Failed to receive message: ") + std::string(ex.what()));
        }
        catch (...) {
            throw MessageQueueException("Failed to receive message for unknown reason.");
        }

        return msg;
    }

}