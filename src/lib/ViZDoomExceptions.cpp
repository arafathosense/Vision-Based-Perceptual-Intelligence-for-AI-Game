#include "ViZDoomExceptions.h"
#include <cstring>

namespace vizdoom {

    /* FileDoesNotExistException */
    const char *FileDoesNotExistException::what() const throw() {
        std::string what = std::string("File \"") + this->path + "\" does not exist.";
        return strdup(what.c_str());
    }

    /* MessageQueueException */
    const char *MessageQueueException::what() const throw() {
        if (this->error.length()) return this->error.c_str();
        else return "Unknown message queue error.";
    }

    /* SharedMemoryException */
    const char *SharedMemoryException::what() const throw() {
        if (this->error.length()) return this->error.c_str();
        else return "Unknown shared memory error.";
    }

    /* ViZDoomErrorException */
    const char *ViZDoomErrorException::what() const throw() {
        if (this->error.length()) return this->error.c_str();
        else return "Controlled ViZDoom instance unknown error.";
    }

    /* ViZDoomIsNotRunningException */
    const char *ViZDoomIsNotRunningException::what() const throw() {
        return "Controlled ViZDoom instance is not running or not ready.";
    }

    /* ViZDoomUnexpectedExitException */
    const char *ViZDoomUnexpectedExitException::what() const throw() {
        return "Controlled ViZDoom instance exited unexpectedly.";
    }

    /* ViZDoomNoOpenALSoundException */
    const char *ViZDoomNoOpenALSoundException::what() const throw() {
        return "Controlled ViZDoom instance requires OpenAL sound, however it was not correctly initialized.";
    }

}