

#ifndef __VIZDOOM_EXCEPTIONS_H__
#define __VIZDOOM_EXCEPTIONS_H__

#include <exception>
#include <string>

namespace vizdoom{

    class FileDoesNotExistException : public std::exception {
    public:
        FileDoesNotExistException(std::string path): path(path){}
        ~FileDoesNotExistException() throw(){}
        const char* what() const throw();
    private:
        std::string path;
    };

    class MessageQueueException : public std::exception {
    public:
        MessageQueueException(){}
        MessageQueueException(std::string error): error(error){}
        ~MessageQueueException() throw(){}
        const char* what() const throw();
    private:
        std::string error;
    };

    class SharedMemoryException : public std::exception {
    public:
        SharedMemoryException(){}
        SharedMemoryException(std::string error): error(error){}
        ~SharedMemoryException() throw(){}
        const char* what() const throw();
    private:
        std::string error;
    };

    class ViZDoomErrorException : public std::exception {
    public:
        ViZDoomErrorException(){}
        ViZDoomErrorException(std::string error): error(error){}
        ~ViZDoomErrorException() throw(){}
        const char* what() const throw();
    private:
        std::string error;
    };

    class ViZDoomIsNotRunningException : public std::exception {
    public:
        const char* what() const throw();
    };

    class ViZDoomUnexpectedExitException : public std::exception {
    public:
        const char* what() const throw();
    };

    class ViZDoomNoOpenALSoundException : public std::exception {
    public:
        const char* what() const throw();
    };
}

#endif
