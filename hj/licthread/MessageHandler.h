#ifndef __MESSAGEHANDLER_H__
#define __MESSAGEHANDLER_H__

#include "Message.h"

class  MessageHandler
{
public:
    MessageHandler();
    virtual ~MessageHandler();
    virtual void onReceiveMessage(Message &msg) = 0;
private:
    //DISABLE_COPY(MessageHandler)
};


#endif // MESSAGEHANDLER_H

